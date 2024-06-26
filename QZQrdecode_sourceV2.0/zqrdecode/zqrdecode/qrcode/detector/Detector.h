// -*- mode:c++; tab-width:2; indent-tabs-mode:nil; c-basic-offset:2 -*-
#ifndef __DETECTOR_H__
#define __DETECTOR_H__

/*
 *  Detector.h
 *  zqrdecode
 *
 */

#include <zqrdecode/common/Counted.h>
#include <zqrdecode/common/DetectorResult.h>
#include <zqrdecode/common/BitMatrix.h>
#include <zqrdecode/qrcode/detector/AlignmentPattern.h>
#include <zqrdecode/common/PerspectiveTransform.h>
#include <zqrdecode/ResultPointCallback.h>
#include <zqrdecode/qrcode/detector/FinderPatternInfo.h>

namespace zqrdecode {

class DecodeHints;

namespace qrcode {

class Detector : public Counted {
private:
  Ref<BitMatrix> image_;
  Ref<ResultPointCallback> callback_;

protected:
  Ref<BitMatrix> getImage() const;
  Ref<ResultPointCallback> getResultPointCallback() const;

  static Ref<BitMatrix> sampleGrid(Ref<BitMatrix> image, int dimension, Ref<PerspectiveTransform>);
  static int computeDimension(Ref<ResultPoint> topLeft, Ref<ResultPoint> topRight, Ref<ResultPoint> bottomLeft,
                              float moduleSize);
  float calculateModuleSize(Ref<ResultPoint> topLeft, Ref<ResultPoint> topRight, Ref<ResultPoint> bottomLeft);
  float calculateModuleSizeOneWay(Ref<ResultPoint> pattern, Ref<ResultPoint> otherPattern);
  float sizeOfBlackWhiteBlackRunBothWays(int fromX, int fromY, int toX, int toY);
  float sizeOfBlackWhiteBlackRun(int fromX, int fromY, int toX, int toY);
  Ref<AlignmentPattern> findAlignmentInRegion(float overallEstModuleSize, int estAlignmentX, int estAlignmentY,
      float allowanceFactor);
  Ref<DetectorResult> processFinderPatternInfo(Ref<FinderPatternInfo> info);
public:
  virtual Ref<PerspectiveTransform> createTransform(Ref<ResultPoint> topLeft, Ref<ResultPoint> topRight, Ref <
      ResultPoint > bottomLeft, Ref<ResultPoint> alignmentPattern, int dimension);

  Detector(Ref<BitMatrix> image);
  Ref<DetectorResult> detect(DecodeHints const& hints);


};
}
}

#endif // __DETECTOR_H__
