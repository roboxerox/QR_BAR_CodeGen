// -*- mode:c++; tab-width:2; indent-tabs-mode:nil; c-basic-offset:2 -*-
/*
 *  Detector.h
 *  zqrdecode
 *
 */

#ifndef __ZQRDECODE_AZTEC_DETECTOR_DETECTOR_H__
#define __ZQRDECODE_AZTEC_DETECTOR_DETECTOR_H__

#include <vector>

#include <zqrdecode/common/BitArray.h>
#include <zqrdecode/ResultPoint.h>
#include <zqrdecode/common/BitMatrix.h>
#include <zqrdecode/DecodeHints.h>
#include <zqrdecode/aztec/AztecDetectorResult.h>

namespace zqrdecode {
namespace aztec {

class Point : public Counted {
 private:
  const int x;
  const int y;
            
 public:
  Ref<ResultPoint> toResultPoint() { 
    return Ref<ResultPoint>(new ResultPoint(float(x), float(y)));
  }
            
  Point(int ax, int ay) : x(ax), y(ay) {}

  int getX() const { return x; }
  int getY() const { return y; }
};
        
class Detector : public Counted {
            
 private:
  Ref<BitMatrix> image_;
            
  bool compact_;
  int nbLayers_;
  int nbDataBlocks_;
  int nbCenterLayers_;
  int shift_;
            
  void extractParameters(std::vector<Ref<Point> > bullEyeCornerPoints);
  ArrayRef< Ref<ResultPoint> > getMatrixCornerPoints(std::vector<Ref<Point> > bullEyeCornerPoints);
  static void correctParameterData(Ref<BitArray> parameterData, bool compact);
  std::vector<Ref<Point> > getBullEyeCornerPoints(Ref<Point> pCenter);
  Ref<Point> getMatrixCenter();
  Ref<BitMatrix> sampleGrid(Ref<BitMatrix> image,
                            Ref<ResultPoint> topLeft,
                            Ref<ResultPoint> bottomLeft,
                            Ref<ResultPoint> bottomRight,
                            Ref<ResultPoint> topRight);
  void getParameters(Ref<BitArray> parameterData);
  Ref<BitArray> sampleLine(Ref<Point> p1, Ref<Point> p2, int size);
  bool isWhiteOrBlackRectangle(Ref<Point> p1,
                               Ref<Point> p2,
                               Ref<Point> p3,
                               Ref<Point> p4);
  int getColor(Ref<Point> p1, Ref<Point> p2);
  Ref<Point> getFirstDifferent(Ref<Point> init, bool color, int dx, int dy);
  bool isValid(int x, int y);
  static float distance(Ref<Point> a, Ref<Point> b);
            
 public:
  Detector(Ref<BitMatrix> image);
  Ref<AztecDetectorResult> detect();
};

}
}

#endif
