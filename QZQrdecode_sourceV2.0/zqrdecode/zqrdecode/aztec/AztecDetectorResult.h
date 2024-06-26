// -*- mode:c++; tab-width:2; indent-tabs-mode:nil; c-basic-offset:2 -*-
/*
 *  AtztecDetecorResult.h
 *  zqrdecode
 *
 */

#include <zqrdecode/common/DetectorResult.h>

#ifndef ZQrdecodeWidget_AtztecDetecorResult_h
#define ZQrdecodeWidget_AtztecDetecorResult_h

namespace zqrdecode {
namespace aztec {

class AztecDetectorResult : public DetectorResult {
 private:
  bool compact_;
  int nbDatablocks_, nbLayers_;
 public:
  AztecDetectorResult(Ref<BitMatrix> bits, 
                      ArrayRef< Ref<ResultPoint> > points,
                      bool compact,
                      int nbDatablocks,
                      int nbLayers);
  bool isCompact();
  int getNBDatablocks();
  int getNBLayers();
};

}
}

#endif
