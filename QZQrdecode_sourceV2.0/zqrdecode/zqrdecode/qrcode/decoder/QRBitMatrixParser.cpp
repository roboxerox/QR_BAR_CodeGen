/*
 *  BitMatrixParser.cpp
 *  zqrdecode
 *
 */

#include <zqrdecode/qrcode/decoder/BitMatrixParser.h>
#include <zqrdecode/qrcode/decoder/DataMask.h>


namespace zqrdecode {
namespace qrcode {

int BitMatrixParser::copyBit(size_t x, size_t y, int versionBits) {
  return bitMatrix_->get(x, y) ? (versionBits << 1) | 0x1 : versionBits << 1;
}

BitMatrixParser::BitMatrixParser(Ref<BitMatrix> bitMatrix) :
    bitMatrix_(bitMatrix), parsedVersion_(0), parsedFormatInfo_() {
  size_t dimension = bitMatrix->getHeight();
  if ((dimension < 21) || (dimension & 0x03) != 1) {
    throw ReaderException("Dimension must be 1 mod 4 and >= 21");
  }
}

Ref<FormatInformation> BitMatrixParser::readFormatInformation() {
  if (parsedFormatInfo_ != 0) {
    return parsedFormatInfo_;
  }

  // Read top-left format info bits
  int formatInfoBits1 = 0;
  for (int i = 0; i < 6; i++) {
    formatInfoBits1 = copyBit(i, 8, formatInfoBits1);
  }
  // .. and skip a bit in the timing pattern ...
  formatInfoBits1 = copyBit(7, 8, formatInfoBits1);
  formatInfoBits1 = copyBit(8, 8, formatInfoBits1);
  formatInfoBits1 = copyBit(8, 7, formatInfoBits1);
  // .. and skip a bit in the timing pattern ...
  for (int j = 5; j >= 0; j--) {
    formatInfoBits1 = copyBit(8, j, formatInfoBits1);
  }

  // Read the top-right/bottom-left pattern
  int dimension = bitMatrix_->getHeight();
  int formatInfoBits2 = 0;
  int jMin = dimension - 7;
  for (int j = dimension - 1; j >= jMin; j--) {
    formatInfoBits2 = copyBit(8, j, formatInfoBits2);
  }
  for (int i = dimension - 8; i < dimension; i++) {
    formatInfoBits2 = copyBit(i, 8, formatInfoBits2);
  }

  parsedFormatInfo_ = FormatInformation::decodeFormatInformation(formatInfoBits1,formatInfoBits2);
  if (parsedFormatInfo_ != 0) {
    return parsedFormatInfo_;
  }
  throw ReaderException("Could not decode format information");
}

Version *BitMatrixParser::readVersion() {
  if (parsedVersion_ != 0) {
    return parsedVersion_;
  }

  int dimension = bitMatrix_->getHeight();

  int provisionalVersion = (dimension - 17) >> 2;
  if (provisionalVersion <= 6) {
    return Version::getVersionForNumber(provisionalVersion);
  }

  // Read top-right version info: 3 wide by 6 tall
  int versionBits = 0;
  for (int y = 5; y >= 0; y--) {
    int xMin = dimension - 11;
    for (int x = dimension - 9; x >= xMin; x--) {
      versionBits = copyBit(x, y, versionBits);
    }
  }

  parsedVersion_ = Version::decodeVersionInformation(versionBits);
  if (parsedVersion_ != 0 && parsedVersion_->getDimensionForVersion() == dimension) {
    return parsedVersion_;
  }

  // Hmm, failed. Try bottom left: 6 wide by 3 tall
  versionBits = 0;
  for (int x = 5; x >= 0; x--) {
    int yMin = dimension - 11;
    for (int y = dimension - 9; y >= yMin; y--) {
      versionBits = copyBit(x, y, versionBits);
    }
  }

  parsedVersion_ = Version::decodeVersionInformation(versionBits);
  if (parsedVersion_ != 0 && parsedVersion_->getDimensionForVersion() == dimension) {
    return parsedVersion_;
  }
  throw ReaderException("Could not decode version");
}

ArrayRef<char> BitMatrixParser::readCodewords() {
  Ref<FormatInformation> formatInfo = readFormatInformation();
  Version *version = readVersion();


  // Get the data mask for the format used in this QR Code. This will exclude
  // some bits from reading as we wind through the bit matrix.
  DataMask &dataMask = DataMask::forReference((int)formatInfo->getDataMask());
  //	cout << (int)formatInfo->getDataMask() << endl;
  int dimension = bitMatrix_->getHeight();
  dataMask.unmaskBitMatrix(*bitMatrix_, dimension);


  //		cerr << *bitMatrix_ << endl;
  //	cerr << version->getTotalCodewords() << endl;

  Ref<BitMatrix> functionPattern = version->buildFunctionPattern();


  //	cout << *functionPattern << endl;

  bool readingUp = true;
  ArrayRef<char> result(version->getTotalCodewords());
  int resultOffset = 0;
  int currentByte = 0;
  int bitsRead = 0;
  // Read columns in pairs, from right to left
  for (int x = dimension - 1; x > 0; x -= 2) {
    if (x == 6) {
      // Skip whole column with vertical alignment pattern;
      // saves time and makes the other code proceed more cleanly
      x--;
    }
    // Read alternatingly from bottom to top then top to bottom
    for (int counter = 0; counter < dimension; counter++) {
      int y = readingUp ? dimension - 1 - counter : counter;
      for (int col = 0; col < 2; col++) {
        // Ignore bits covered by the function pattern
        if (!functionPattern->get(x - col, y)) {
          // Read a bit
          bitsRead++;
          currentByte <<= 1;
          if (bitMatrix_->get(x - col, y)) {
            currentByte |= 1;
          }
          // If we've made a whole byte, save it off
          if (bitsRead == 8) {
            result[resultOffset++] = (char)currentByte;
            bitsRead = 0;
            currentByte = 0;
          }
        }
      }
    }
    readingUp = !readingUp; // switch directions
  }

  if (resultOffset != version->getTotalCodewords()) {
    throw ReaderException("Did not read all codewords");
  }
  return result;
}

}
}
