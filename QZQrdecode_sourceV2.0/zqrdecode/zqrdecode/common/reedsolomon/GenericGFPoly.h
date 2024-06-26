// -*- mode:c++; tab-width:2; indent-tabs-mode:nil; c-basic-offset:2 -*-
/*
 *  GenericGFPoly.h
 *  zqrdecode
 *
 */

#ifndef GENERICGFPOLY_H
#define GENERICGFPOLY_H

#include <vector>
#include <zqrdecode/common/Array.h>
#include <zqrdecode/common/Counted.h>

namespace zqrdecode {

class GenericGF;
  
class GenericGFPoly : public Counted {
private:
  Ref<GenericGF> field_;
  ArrayRef<int> coefficients_;
    
public:
  GenericGFPoly(Ref<GenericGF> field, ArrayRef<int> coefficients);
  ArrayRef<int> getCoefficients();
  int getDegree();
  bool isZero();
  int getCoefficient(int degree);
  int evaluateAt(int a);
  Ref<GenericGFPoly> addOrSubtract(Ref<GenericGFPoly> other);
  Ref<GenericGFPoly> multiply(Ref<GenericGFPoly> other);
  Ref<GenericGFPoly> multiply(int scalar);
  Ref<GenericGFPoly> multiplyByMonomial(int degree, int coefficient);
  std::vector<Ref<GenericGFPoly> > divide(Ref<GenericGFPoly> other);
    

};

}

#endif //GENERICGFPOLY_H
