// -*- mode:c++; tab-width:2; indent-tabs-mode:nil; c-basic-offset:2 -*-
/*
 *  DetectorResult.cpp
 *  zqrdecode
 *
 */

#include <zqrdecode/common/DetectorResult.h>

namespace zqrdecode {

DetectorResult::DetectorResult(Ref<BitMatrix> bits,
                               ArrayRef< Ref<ResultPoint> > points)
  : bits_(bits), points_(points) {
}

Ref<BitMatrix> DetectorResult::getBits() {
  return bits_;
}

ArrayRef< Ref<ResultPoint> > DetectorResult::getPoints() {
  return points_;
}

}
