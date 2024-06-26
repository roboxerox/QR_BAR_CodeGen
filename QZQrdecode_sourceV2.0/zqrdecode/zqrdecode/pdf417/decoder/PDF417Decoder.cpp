

#include <zqrdecode/pdf417/PDF417Reader.h>
#include <zqrdecode/pdf417/decoder/Decoder.h>
#include <zqrdecode/pdf417/decoder/BitMatrixParser.h>
#include <zqrdecode/pdf417/decoder/DecodedBitStreamParser.h>
#include <zqrdecode/ReaderException.h>
#include <zqrdecode/common/reedsolomon/ReedSolomonException.h>

using zqrdecode::pdf417::decoder::Decoder;
using zqrdecode::pdf417::decoder::ec::ErrorCorrection;
using zqrdecode::Ref;
using zqrdecode::DecoderResult;

// VC++

using zqrdecode::BitMatrix;
using zqrdecode::DecodeHints;
using zqrdecode::ArrayRef;

const int Decoder::MAX_ERRORS = 3;
const int Decoder::MAX_EC_CODEWORDS = 512;

Ref<DecoderResult> Decoder::decode(Ref<BitMatrix> bits, DecodeHints const& hints) {
  (void)hints;
  // Construct a parser to read the data codewords and error-correction level
  BitMatrixParser parser(bits);
  ArrayRef<int> codewords(parser.readCodewords());
  if (codewords->size() == 0) {
    throw FormatException("PDF:Decoder:decode: cannot read codewords");
  }

  int ecLevel = parser.getECLevel();
  int numECCodewords = 1 << (ecLevel + 1);
  ArrayRef<int> erasures = parser.getErasures();

  correctErrors(codewords, erasures, numECCodewords);
  verifyCodewordCount(codewords, numECCodewords);

  // Decode the codewords
  return DecodedBitStreamParser::decode(codewords);
}

/**
 * Verify that all is OK with the codeword array.
 *
 * @param codewords
 * @return an index to the first data codeword.
 * @throws FormatException
 */
void Decoder::verifyCodewordCount(ArrayRef<int> codewords, int numECCodewords) {
  int cwsize = codewords->size();
  if (cwsize < 4) {
    // Codeword array size should be at least 4 allowing for
    // Count CW, At least one Data CW, Error Correction CW, Error Correction CW
    throw FormatException("PDF:Decoder:verifyCodewordCount: codeword array too small!");
  }
  // The first codeword, the Symbol Length Descriptor, shall always encode the total number of data
  // codewords in the symbol, including the Symbol Length Descriptor itself, data codewords and pad
  // codewords, but excluding the number of error correction codewords.
  int numberOfCodewords = codewords[0];
  if (numberOfCodewords > cwsize) {
    throw FormatException("PDF:Decoder:verifyCodewordCount: bad codeword number descriptor!");
  }
  if (numberOfCodewords == 0) {
    // Reset to the length of the array - 8 (Allow for at least level 3 Error Correction (8 Error Codewords)
    if (numECCodewords < cwsize) {
      codewords[0] = cwsize - numECCodewords;
    } else {
      throw FormatException("PDF:Decoder:verifyCodewordCount: bad error correction cw number!");
    }
  }
}

/**
 * Correct errors whenever it is possible using Reed-Solomom algorithm
 *
 * @param codewords, erasures, numECCodewords
 * @return 0.
 * @throws FormatException
 */
void Decoder::correctErrors(ArrayRef<int> codewords,
                            ArrayRef<int> erasures, int numECCodewords) {
  if (erasures->size() > numECCodewords / 2 + MAX_ERRORS ||
      numECCodewords < 0 || numECCodewords > MAX_EC_CODEWORDS) {
    throw FormatException("PDF:Decoder:correctErrors: Too many errors or EC Codewords corrupted");
  }

  Ref<ErrorCorrection> errorCorrection(new ErrorCorrection);
  errorCorrection->decode(codewords, numECCodewords, erasures);

  // 2012-06-27 HFN if, despite of error correction, there are still codewords with invalid
  // value, throw an exception here:
  for (int i = 0; i < codewords->size(); i++) {
    if (codewords[i]<0) {
      throw FormatException("PDF:Decoder:correctErrors: Error correction did not succeed!");
    }
  }
}
