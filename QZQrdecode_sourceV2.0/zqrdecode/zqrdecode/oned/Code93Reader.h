// -*- mode:c++; tab-width:2; indent-tabs-mode:nil; c-basic-offset:2 -*-
#ifndef __CODE_93_READER_H__
#define __CODE_93_READER_H__
/*
 *  Code93Reader.h
 *  zqrdecode
 *
 */

#include <zqrdecode/oned/OneDReader.h>
#include <zqrdecode/common/BitArray.h>
#include <zqrdecode/Result.h>

namespace zqrdecode {
namespace oned {

/**
 * <p>Decodes Code 93 barcodes. This does not support "Full ASCII Code 93" yet.</p>
 * Ported form Java (author Sean Owen)
 * @author Lukasz Warchol
 */
class Code93Reader : public OneDReader {
public:
  Code93Reader();
  Ref<Result> decodeRow(int rowNumber, Ref<BitArray> row);

private:
  std::string decodeRowResult;
  std::vector<int> counters;

  Range findAsteriskPattern(Ref<BitArray> row);

  static int toPattern(std::vector<int>& counters);
  static char patternToChar(int pattern);
  static Ref<String> decodeExtended(std::string const& encoded);
  static void checkChecksums(std::string const& result);
  static void checkOneChecksum(std::string const& result,
                               int checkPosition,
                               int weightMax);
};

}
}

#endif
