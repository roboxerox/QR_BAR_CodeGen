// -*- mode:c++; tab-width:2; indent-tabs-mode:nil; c-basic-offset:2 -*-
/*
 *  Decoder.cpp
 *  zqrdecode
 */

#include <zqrdecode/qrcode/decoder/Decoder.h>
#include <zqrdecode/qrcode/decoder/BitMatrixParser.h>
#include <zqrdecode/qrcode/ErrorCorrectionLevel.h>
#include <zqrdecode/qrcode/Version.h>
#include <zqrdecode/qrcode/decoder/DataBlock.h>
#include <zqrdecode/qrcode/decoder/DecodedBitStreamParser.h>
#include <zqrdecode/ReaderException.h>
#include <zqrdecode/ChecksumException.h>
#include <zqrdecode/common/reedsolomon/ReedSolomonException.h>

using zqrdecode::qrcode::Decoder;
using zqrdecode::DecoderResult;
using zqrdecode::Ref;

// VC++
using zqrdecode::ArrayRef;
using zqrdecode::BitMatrix;

Decoder::Decoder() :
  rsDecoder_(GenericGF::QR_CODE_FIELD_256) {
}

void Decoder::correctErrors(ArrayRef<char> codewordBytes, int numDataCodewords) {
  int numCodewords = codewordBytes->size();
  ArrayRef<int> codewordInts(numCodewords);
  for (int i = 0; i < numCodewords; i++) {
    codewordInts[i] = codewordBytes[i] & 0xff;
  }
  int numECCodewords = numCodewords - numDataCodewords;

  try {
    rsDecoder_.decode(codewordInts, numECCodewords);
  } catch (ReedSolomonException const& ignored) {
    (void)ignored;
    throw ChecksumException();
  }

  for (int i = 0; i < numDataCodewords; i++) {
    codewordBytes[i] = (char)codewordInts[i];
  }
}

Ref<DecoderResult> Decoder::decode(Ref<BitMatrix> bits) {
  // Construct a parser and read version, error-correction level
  BitMatrixParser parser(bits);

  // std::cerr << *bits << std::endl;

  Version *version = parser.readVersion();
  ErrorCorrectionLevel &ecLevel = parser.readFormatInformation()->getErrorCorrectionLevel();


  // Read codewords
  ArrayRef<char> codewords(parser.readCodewords());


  // Separate into data blocks
  std::vector<Ref<DataBlock> > dataBlocks(DataBlock::getDataBlocks(codewords, version, ecLevel));


  // Count total number of data bytes
  int totalBytes = 0;
  for (size_t i = 0; i < dataBlocks.size(); i++) {
    totalBytes += dataBlocks[i]->getNumDataCodewords();
  }
  ArrayRef<char> resultBytes(totalBytes);
  int resultOffset = 0;


  // Error-correct and copy data blocks together into a stream of bytes
  for (size_t j = 0; j < dataBlocks.size(); j++) {
    Ref<DataBlock> dataBlock(dataBlocks[j]);
    ArrayRef<char> codewordBytes = dataBlock->getCodewords();
    int numDataCodewords = dataBlock->getNumDataCodewords();
    correctErrors(codewordBytes, numDataCodewords);
    for (int i = 0; i < numDataCodewords; i++) {
      resultBytes[resultOffset++] = codewordBytes[i];
    }
  }

  return DecodedBitStreamParser::decode(resultBytes,
                                        version,
                                        ecLevel,
                                        DecodedBitStreamParser::Hashtable());
}

