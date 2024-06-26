// -*- mode:c++; tab-width:2; indent-tabs-mode:nil; c-basic-offset:2 -*-
#ifndef __ITF_READER_H__
#define __ITF_READER_H__


#include <zqrdecode/oned/OneDReader.h>
#include <zqrdecode/common/BitArray.h>
#include <zqrdecode/Result.h>

namespace zqrdecode {
namespace oned {

class ITFReader : public OneDReader {
private:
  enum {MAX_AVG_VARIANCE = (unsigned int) (PATTERN_MATCH_RESULT_SCALE_FACTOR * 420/1000)};
  enum {MAX_INDIVIDUAL_VARIANCE = (int) (PATTERN_MATCH_RESULT_SCALE_FACTOR * 780/1000)};
  // Stores the actual narrow line width of the image being decoded.
  int narrowLineWidth;
			
  Range decodeStart(Ref<BitArray> row);
  Range decodeEnd(Ref<BitArray> row);
  static void decodeMiddle(Ref<BitArray> row, int payloadStart, int payloadEnd, std::string& resultString);
  void validateQuietZone(Ref<BitArray> row, int startPattern);
  static int skipWhiteSpace(Ref<BitArray> row);
			
  static Range findGuardPattern(Ref<BitArray> row, int rowOffset, std::vector<int> const& pattern);
  static int decodeDigit(std::vector<int>& counters);
			
  void append(char* s, char c);
public:
  Ref<Result> decodeRow(int rowNumber, Ref<BitArray> row);
  ITFReader();
  ~ITFReader();
};

}
}

#endif
