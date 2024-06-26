// -*- mode:c++; tab-width:2; indent-tabs-mode:nil; c-basic-offset:2 -*-
#ifndef __FINDER_PATTERN_FINDER_H__
#define __FINDER_PATTERN_FINDER_H__

/*
 *  FinderPatternFinder.h
 *  zqrdecode
 *
 */

#include <zqrdecode/qrcode/detector/FinderPattern.h>
#include <zqrdecode/qrcode/detector/FinderPatternInfo.h>
#include <zqrdecode/common/Counted.h>
#include <zqrdecode/common/BitMatrix.h>
#include <zqrdecode/ResultPointCallback.h>
#include <vector>

namespace zqrdecode {

class DecodeHints;

namespace qrcode {

class FinderPatternFinder {
private:
  static int CENTER_QUORUM;

protected:
  static int MIN_SKIP;
  static int MAX_MODULES;

  Ref<BitMatrix> image_;
  std::vector<Ref<FinderPattern> > possibleCenters_;
  bool hasSkipped_;

  Ref<ResultPointCallback> callback_;
  mutable int crossCheckStateCount[5];

  /** stateCount must be int[5] */
  static float centerFromEnd(int* stateCount, int end);
  static bool foundPatternCross(int* stateCount);

  float crossCheckVertical(size_t startI, size_t centerJ, int maxCount, int originalStateCountTotal);
  float crossCheckHorizontal(size_t startJ, size_t centerI, int maxCount, int originalStateCountTotal);

  /** stateCount must be int[5] */
  bool handlePossibleCenter(int* stateCount, size_t i, size_t j);
  int findRowSkip();
  bool haveMultiplyConfirmedCenters();
  std::vector<Ref<FinderPattern> > selectBestPatterns();
  static std::vector<Ref<FinderPattern> > orderBestPatterns(std::vector<Ref<FinderPattern> > patterns);

  Ref<BitMatrix> getImage();
  std::vector<Ref<FinderPattern> >& getPossibleCenters();

  bool crossCheckDiagonal(int startI, int centerJ, int maxCount, int originalStateCountTotal) const;
  int *getCrossCheckStateCount() const;

public:
  static float distance(Ref<ResultPoint> p1, Ref<ResultPoint> p2);
  FinderPatternFinder(Ref<BitMatrix> image, Ref<ResultPointCallback>const&);
  Ref<FinderPatternInfo> find(DecodeHints const& hints);
};
}
}

#endif // __FINDER_PATTERN_FINDER_H__
