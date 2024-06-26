// -*- mode:c++; tab-width:2; indent-tabs-mode:nil; c-basic-offset:2 -*-

#ifndef __ERROR_CORRECTION_PDF_H__
#define __ERROR_CORRECTION_PDF_H__


#include <zqrdecode/common/Counted.h>
#include <zqrdecode/common/Array.h>
#include <zqrdecode/common/DecoderResult.h>
#include <zqrdecode/common/BitMatrix.h>
#include <zqrdecode/pdf417/decoder/ec/ModulusGF.h>
#include <zqrdecode/pdf417/decoder/ec/ModulusPoly.h>
#include <zqrdecode/common/reedsolomon/ReedSolomonException.h>

namespace zqrdecode {
namespace pdf417 {
namespace decoder {
namespace ec {


/**
 * <p>PDF417 error correction implementation.</p>
 *
 * <p>This <a href="http://en.wikipedia.org/wiki/Reed%E2%80%93Solomon_error_correction#Example">example</a>
 * is quite useful in understanding the algorithm.</p>
 *
 * @author Sean Owen
 * @see com.google.zqrdecode.common.reedsolomon.ReedSolomonDecoder
 */
class ErrorCorrection: public Counted {

 private:
  ModulusGF &field_;

 public:
  ErrorCorrection();
  void decode(ArrayRef<int> received,
              int numECCodewords,
              ArrayRef<int> erasures);

 private:
  std::vector<Ref<ModulusPoly> > runEuclideanAlgorithm(Ref<ModulusPoly> a, Ref<ModulusPoly> b, int R);

  ArrayRef<int> findErrorLocations(Ref<ModulusPoly> errorLocator);
  ArrayRef<int> findErrorMagnitudes(Ref<ModulusPoly> errorEvaluator,
                                    Ref<ModulusPoly> errorLocator,
                                    ArrayRef<int> errorLocations);
};

}
}
}
}

#endif /* __ERROR_CORRECTION_PDF_H__ */
