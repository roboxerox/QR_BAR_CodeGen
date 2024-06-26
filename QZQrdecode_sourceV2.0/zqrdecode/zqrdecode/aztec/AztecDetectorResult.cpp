// -*- mode:c++; tab-width:2; indent-tabs-mode:nil; c-basic-offset:2 -*-
/*
 *  AtztecDetecorResult.cpp
 *  zqrdecode
 *
 */

#include <zqrdecode/aztec/AztecDetectorResult.h>

using zqrdecode::aztec::AztecDetectorResult;

// VC++
using zqrdecode::Ref;
using zqrdecode::ArrayRef;
using zqrdecode::BitMatrix;
using zqrdecode::ResultPoint;


AztecDetectorResult::AztecDetectorResult(Ref<BitMatrix> bits,
                                         ArrayRef< Ref<ResultPoint> > points,
                                         bool compact,
                                         int nbDatablocks,
                                         int nbLayers)
  : DetectorResult(bits, points),
    compact_(compact),
    nbDatablocks_(nbDatablocks),
    nbLayers_(nbLayers) {
    }
        
bool AztecDetectorResult::isCompact() {
  return compact_;
}
        
int AztecDetectorResult::getNBDatablocks() {
  return nbDatablocks_;
}
        
int AztecDetectorResult::getNBLayers() {
  return nbLayers_;
}
