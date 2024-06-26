// -*- mode:c++; tab-width:2; indent-tabs-mode:nil; c-basic-offset:2 -*-
/*
 *  Decoder.h
 *  zqrdecode
 *
 */

#ifndef __ZQRDECODE_AZTEC_DECODER_DECODER_H__
#define __ZQRDECODE_AZTEC_DECODER_DECODER_H__

#include <zqrdecode/common/BitMatrix.h>
#include <zqrdecode/common/Str.h>
#include <zqrdecode/aztec/AztecDetectorResult.h>

namespace zqrdecode {

class DecoderResult;
        
namespace aztec {

class Decoder : public Counted {
 private:
  enum Table {
    UPPER,
    LOWER,
    MIXED,
    DIGIT,
    PUNCT,
    BINARY
  };
            
  static Table getTable(char t);
  static const char* getCharacter(Table table, int code);
            
  int numCodewords_;
  int codewordSize_;
  Ref<AztecDetectorResult> ddata_;
  int invertedBitCount_;
            
  Ref<String> getEncodedData(Ref<BitArray> correctedBits);
  Ref<BitArray> correctBits(Ref<BitArray> rawbits);
  Ref<BitArray> extractBits(Ref<BitMatrix> matrix);
  static Ref<BitMatrix> removeDashedLines(Ref<BitMatrix> matrix);
  static int readCode(Ref<BitArray> rawbits, int startIndex, int length);
            
            
 public:
  Decoder();
  Ref<DecoderResult> decode(Ref<AztecDetectorResult> detectorResult);
};
        
}
}

#endif
