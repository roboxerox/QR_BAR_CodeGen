#ifndef __REED_SOLOMON_DECODER_H__
#define __REED_SOLOMON_DECODER_H__

/*
 *  ReedSolomonDecoder.h
 *  zqrdecode
 *
 */

#include <memory>
#include <vector>
#include <zqrdecode/common/Counted.h>
#include <zqrdecode/common/Array.h>
#include <zqrdecode/common/reedsolomon/GenericGFPoly.h>
#include <zqrdecode/common/reedsolomon/GenericGF.h>

namespace zqrdecode {
class GenericGFPoly;
class GenericGF;

class ReedSolomonDecoder {
private:
  Ref<GenericGF> field;
public:
  ReedSolomonDecoder(Ref<GenericGF> fld);
  ~ReedSolomonDecoder();
  void decode(ArrayRef<int> received, int twoS);
  std::vector<Ref<GenericGFPoly> > runEuclideanAlgorithm(Ref<GenericGFPoly> a, Ref<GenericGFPoly> b, int R);

private:
  ArrayRef<int> findErrorLocations(Ref<GenericGFPoly> errorLocator);
  ArrayRef<int> findErrorMagnitudes(Ref<GenericGFPoly> errorEvaluator, ArrayRef<int> errorLocations);
};
}

#endif // __REED_SOLOMON_DECODER_H__
