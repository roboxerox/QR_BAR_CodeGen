// -*- mode:c++; tab-width:2; indent-tabs-mode:nil; c-basic-offset:2 -*-
#ifndef __CODE_39_READER_H__
#define __CODE_39_READER_H__
/*
 *  Code39Reader.h
 *  zqrdecode
 *
 */

#include <zqrdecode/oned/OneDReader.h>
#include <zqrdecode/common/BitArray.h>
#include <zqrdecode/Result.h>

namespace zqrdecode {
namespace oned {

/**
 * <p>Decodes Code 39 barcodes. This does not support "Full ASCII Code 39" yet.</p>
 * Ported form Java (author Sean Owen)
 * @author Lukasz Warchol
 */
class Code39Reader : public OneDReader {
private:
  bool usingCheckDigit;
  bool extendedMode;
  std::string decodeRowResult;
  std::vector<int> counters;
			
  void init(bool usingCheckDigit = false, bool extendedMode = false);

  static std::vector<int> findAsteriskPattern(Ref<BitArray> row,
                                              std::vector<int>& counters);
  static int toNarrowWidePattern(std::vector<int>& counters);
  static char patternToChar(int pattern);
  static Ref<String> decodeExtended(std::string encoded);
			
  void append(char* s, char c);

public:
  Code39Reader();
  Code39Reader(bool usingCheckDigit_);
  Code39Reader(bool usingCheckDigit_, bool extendedMode_);
			
  Ref<Result> decodeRow(int rowNumber, Ref<BitArray> row);
};

}
}

#endif
