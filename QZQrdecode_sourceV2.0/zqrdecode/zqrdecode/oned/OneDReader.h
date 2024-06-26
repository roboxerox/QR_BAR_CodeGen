// -*- mode:c++; tab-width:2; indent-tabs-mode:nil; c-basic-offset:2 -*-
#ifndef __ONED_READER_H__
#define __ONED_READER_H__

/*
 *  OneDReader.h
 *  zqrdecode
 *
 */

#include <zqrdecode/Reader.h>

namespace zqrdecode {
namespace oned {

class OneDReader : public Reader {
private:
  Ref<Result> doDecode(Ref<BinaryBitmap> image, DecodeHints hints);

protected:
  static const int INTEGER_MATH_SHIFT = 8;

  struct Range {
  private:
    int data[2];
  public:
    Range() {}
    Range(int zero, int one) {
      data[0] = zero;
      data[1] = one;
    }
    int& operator [] (int index) {
      return data[index];
    }
    int const& operator [] (int index) const {
      return data[index];
    }
  };

  static int patternMatchVariance(std::vector<int>& counters,
                                  std::vector<int> const& pattern,
                                  int maxIndividualVariance);
  static int patternMatchVariance(std::vector<int>& counters,
                                  int const pattern[],
                                  int maxIndividualVariance);

protected:
  static const int PATTERN_MATCH_RESULT_SCALE_FACTOR = 1 << INTEGER_MATH_SHIFT;

public:

  OneDReader();
  virtual Ref<Result> decode(Ref<BinaryBitmap> image, DecodeHints hints);

  // Implementations must not throw any exceptions. If a barcode is not found on this row,
  // a empty ref should be returned e.g. return Ref<Result>();
  virtual Ref<Result> decodeRow(int rowNumber, Ref<BitArray> row) = 0;

  static void recordPattern(Ref<BitArray> row,
                            int start,
                            std::vector<int>& counters);
  virtual ~OneDReader();
};

}
}

#endif
