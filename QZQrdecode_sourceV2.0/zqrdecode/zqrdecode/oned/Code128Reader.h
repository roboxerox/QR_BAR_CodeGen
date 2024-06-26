// -*- mode:c++; tab-width:2; indent-tabs-mode:nil; c-basic-offset:2 -*-
#ifndef __CODE_128_READER_H__
#define __CODE_128_READER_H__


#include <zqrdecode/oned/OneDReader.h>
#include <zqrdecode/common/BitArray.h>
#include <zqrdecode/Result.h>

namespace zqrdecode {
namespace oned {

class Code128Reader : public OneDReader {
private:
  static const int MAX_AVG_VARIANCE;
  static const int MAX_INDIVIDUAL_VARIANCE;

  static std::vector<int> findStartPattern(Ref<BitArray> row);
  static int decodeCode(Ref<BitArray> row,
                        std::vector<int>& counters,
                        int rowOffset);
			
public:
  Ref<Result> decodeRow(int rowNumber, Ref<BitArray> row);
  Code128Reader();
  ~Code128Reader();

  BarcodeFormat getBarcodeFormat();
};

}
}

#endif
