#ifndef __ALIGNMENT_PATTERN_FINDER_H__
#define __ALIGNMENT_PATTERN_FINDER_H__

/*
 *  AlignmentPatternFinder.h
 *  zqrdecode
 *
 */

#include "AlignmentPattern.h"
#include <zqrdecode/common/Counted.h>
#include <zqrdecode/common/BitMatrix.h>
#include <zqrdecode/ResultPointCallback.h>
#include <vector>

namespace zqrdecode {
namespace qrcode {

class AlignmentPatternFinder : public Counted {
private:
  static int CENTER_QUORUM;
  static int MIN_SKIP;
  static int MAX_MODULES;

  Ref<BitMatrix> image_;
  std::vector<AlignmentPattern *> *possibleCenters_;
  int startX_;
  int startY_;
  int width_;
  int height_;
  float moduleSize_;

  static float centerFromEnd(std::vector<int> &stateCount, int end);
  bool foundPatternCross(std::vector<int> &stateCount);

  float crossCheckVertical(int startI, int centerJ, int maxCount, int originalStateCountTotal);

  Ref<AlignmentPattern> handlePossibleCenter(std::vector<int> &stateCount, int i, int j);

public:
  AlignmentPatternFinder(Ref<BitMatrix> image, int startX, int startY, int width, int height,
                         float moduleSize, Ref<ResultPointCallback>const& callback);
  ~AlignmentPatternFinder();
  Ref<AlignmentPattern> find();
  
private:
  AlignmentPatternFinder(const AlignmentPatternFinder&);
  AlignmentPatternFinder& operator =(const AlignmentPatternFinder&);
  
  Ref<ResultPointCallback> callback_;
};
}
}

#endif // __ALIGNMENT_PATTERN_FINDER_H__
