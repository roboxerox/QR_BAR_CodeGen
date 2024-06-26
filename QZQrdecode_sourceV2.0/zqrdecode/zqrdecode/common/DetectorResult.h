#ifndef __DETECTOR_RESULT_H__
#define __DETECTOR_RESULT_H__

/*
 *  DetectorResult.h
 *  zqrdecode
 *
 */

#include <zqrdecode/common/Counted.h>
#include <zqrdecode/common/Array.h>
#include <zqrdecode/common/BitMatrix.h>
#include <zqrdecode/ResultPoint.h>

namespace zqrdecode {

class DetectorResult : public Counted {
private:
  Ref<BitMatrix> bits_;
  ArrayRef< Ref<ResultPoint> > points_;

public:
  DetectorResult(Ref<BitMatrix> bits, ArrayRef< Ref<ResultPoint> > points);
  Ref<BitMatrix> getBits();
  ArrayRef< Ref<ResultPoint> > getPoints();
};

}

#endif // __DETECTOR_RESULT_H__
