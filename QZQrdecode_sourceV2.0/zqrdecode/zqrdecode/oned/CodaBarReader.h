// -*- mode:c++; tab-width:2; indent-tabs-mode:nil; c-basic-offset:2 -*-
#ifndef __CODA_BAR_READER_H__
#define __CODA_BAR_READER_H__


#include <zqrdecode/oned/OneDReader.h>
#include <zqrdecode/common/BitArray.h>
#include <zqrdecode/Result.h>

namespace zqrdecode {
namespace oned {

class CodaBarReader : public OneDReader {
private:
  static const int MAX_ACCEPTABLE;
  static const int PADDING;

  // Keep some instance variables to avoid reallocations
  std::string decodeRowResult;
  std::vector<int> counters;
  int counterLength;

public:
  CodaBarReader();

  Ref<Result> decodeRow(int rowNumber, Ref<BitArray> row);
  
  void validatePattern(int start);

private:
  void setCounters(Ref<BitArray> row);
  void counterAppend(int e);
  int findStartPattern();
  
  static bool arrayContains(char const array[], char key);

  int toNarrowWidePattern(int position);
};

}
}

#endif
