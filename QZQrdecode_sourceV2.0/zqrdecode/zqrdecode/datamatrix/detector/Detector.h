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
#include <zqrdecode/common/PerspectiveTransform.h>
#include <zqrdecode/common/detector/WhiteRectangleDetector.h>

namespace zqrdecode {
namespace datamatrix {

class ResultPointsAndTransitions: public Counted {
  private:
    Ref<ResultPoint> to_;
    Ref<ResultPoint> from_;
    int transitions_;

  public:
    ResultPointsAndTransitions();
    ResultPointsAndTransitions(Ref<ResultPoint> from, Ref<ResultPoint> to, int transitions);
    Ref<ResultPoint> getFrom();
    Ref<ResultPoint> getTo();
    int getTransitions();
};

class Detector: public Counted {
  private:
    Ref<BitMatrix> image_;

  protected:
    Ref<BitMatrix> sampleGrid(Ref<BitMatrix> image, int dimensionX, int dimensionY,
        Ref<PerspectiveTransform> transform);

    void insertionSort(std::vector<Ref<ResultPointsAndTransitions> >& vector);

    Ref<ResultPoint> correctTopRightRectangular(Ref<ResultPoint> bottomLeft,
        Ref<ResultPoint> bottomRight, Ref<ResultPoint> topLeft, Ref<ResultPoint> topRight,
        int dimensionTop, int dimensionRight);
    Ref<ResultPoint> correctTopRight(Ref<ResultPoint> bottomLeft, Ref<ResultPoint> bottomRight,
        Ref<ResultPoint> topLeft, Ref<ResultPoint> topRight, int dimension);
    bool isValid(Ref<ResultPoint> p);
    int distance(Ref<ResultPoint> a, Ref<ResultPoint> b);
    Ref<ResultPointsAndTransitions> transitionsBetween(Ref<ResultPoint> from, Ref<ResultPoint> to);
    int min(int a, int b) {
      return a > b ? b : a;
    }
    /**
     * Ends up being a bit faster than round(). This merely rounds its
     * argument to the nearest int, where x.5 rounds up.
     */
    int round(float d) {
      return (int) (d + 0.5f);
    }

  public:
    Ref<BitMatrix> getImage();
    Detector(Ref<BitMatrix> image);

    virtual Ref<PerspectiveTransform> createTransform(Ref<ResultPoint> topLeft,
        Ref<ResultPoint> topRight, Ref<ResultPoint> bottomLeft, Ref<ResultPoint> bottomRight,
        int dimensionX, int dimensionY);

    Ref<DetectorResult> detect();

  private:
    int compare(Ref<ResultPointsAndTransitions> a, Ref<ResultPointsAndTransitions> b);
};

}
}

#endif // __DETECTOR_H__
