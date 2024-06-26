// -*- mode:c++; tab-width:2; indent-tabs-mode:nil; c-basic-offset:2 -*-
#ifndef __DECODED_BIT_STREAM_PARSER_PD_H__
#define __DECODED_BIT_STREAM_PARSER_PD_H__



#include <bigint/BigInteger.hh>
#include <zqrdecode/common/Array.h>
#include <zqrdecode/common/Str.h>
#include <zqrdecode/common/DecoderResult.h>

namespace zqrdecode {
namespace pdf417 {

class DecodedBitStreamParser {
 protected:
  enum Mode {
    ALPHA,
    LOWER,
    MIXED,
    PUNCT,
    ALPHA_SHIFT,
    PUNCT_SHIFT
  };

 private:
  
  static const int TEXT_COMPACTION_MODE_LATCH;
  static const int BYTE_COMPACTION_MODE_LATCH;
  static const int NUMERIC_COMPACTION_MODE_LATCH;
  static const int BYTE_COMPACTION_MODE_LATCH_6;
  static const int BEGIN_MACRO_PDF417_CONTROL_BLOCK;
  static const int BEGIN_MACRO_PDF417_OPTIONAL_FIELD;
  static const int MACRO_PDF417_TERMINATOR;
  static const int MODE_SHIFT_TO_BYTE_COMPACTION_MODE;
  static const int MAX_NUMERIC_CODEWORDS;

  static const int PL;
  static const int LL;
  static const int AS;
  static const int ML;
  static const int AL;
  static const int PS;
  static const int PAL;
  static const int EXP900_SIZE;

  static const char PUNCT_CHARS[];
  static const char MIXED_CHARS[];
 
  static ArrayRef<BigInteger> EXP900;
  static ArrayRef<BigInteger> initEXP900();
  
  static int textCompaction(ArrayRef<int> codewords, int codeIndex, Ref<String> result);
  static void decodeTextCompaction(ArrayRef<int> textCompactionData,
                                   ArrayRef<int> byteCompactionData,
                                   int length,
                                   Ref<String> result);
  static int byteCompaction(int mode, ArrayRef<int> codewords, int codeIndex, Ref<String> result);
  static int numericCompaction(ArrayRef<int> codewords, int codeIndex, Ref<String> result);
  static Ref<String> decodeBase900toBase10(ArrayRef<int> codewords, int count);

 public:
  DecodedBitStreamParser();
  static Ref<DecoderResult> decode(ArrayRef<int> codewords);
};

} /* namespace pdf417 */
} /* namespace zqrdecode */

#endif // __DECODED_BIT_STREAM_PARSER_PD_H__
