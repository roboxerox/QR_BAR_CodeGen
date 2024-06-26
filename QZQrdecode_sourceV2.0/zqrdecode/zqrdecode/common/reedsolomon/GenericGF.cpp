// -*- mode:c++; tab-width:2; indent-tabs-mode:nil; c-basic-offset:2 -*-
/*
 *  GenericGF.cpp
 *  zqrdecode
 *
 */

#include <iostream>
#include <zqrdecode/common/reedsolomon/GenericGF.h>
#include <zqrdecode/common/reedsolomon/GenericGFPoly.h>
#include <zqrdecode/common/IllegalArgumentException.h>

using zqrdecode::GenericGF;
using zqrdecode::GenericGFPoly;
using zqrdecode::Ref;

Ref<GenericGF> GenericGF::AZTEC_DATA_12(new GenericGF(0x1069, 4096, 1));
Ref<GenericGF> GenericGF::AZTEC_DATA_10(new GenericGF(0x409, 1024, 1));
Ref<GenericGF> GenericGF::AZTEC_DATA_6(new GenericGF(0x43, 64, 1));
Ref<GenericGF> GenericGF::AZTEC_PARAM(new GenericGF(0x13, 16, 1));
Ref<GenericGF> GenericGF::QR_CODE_FIELD_256(new GenericGF(0x011D, 256, 0));
Ref<GenericGF> GenericGF::DATA_MATRIX_FIELD_256(new GenericGF(0x012D, 256, 1));
Ref<GenericGF> GenericGF::AZTEC_DATA_8 = DATA_MATRIX_FIELD_256;
Ref<GenericGF> GenericGF::MAXICODE_FIELD_64 = AZTEC_DATA_6;
  
namespace {
  int INITIALIZATION_THRESHOLD = 0;
}
  
GenericGF::GenericGF(int primitive_, int size_, int b)
  : size(size_), primitive(primitive_), generatorBase(b), initialized(false) {
  if (size <= INITIALIZATION_THRESHOLD) {
    initialize();
  }
}
  
void GenericGF::initialize() {
  expTable.resize(size);
  logTable.resize(size);
    
  int x = 1;
    
  for (int i = 0; i < size; i++) {
    expTable[i] = x;
    x <<= 1; // x = x * 2; we're assuming the generator alpha is 2
    if (x >= size) {
      x ^= primitive;
      x &= size-1;
    }
  }
  for (int i = 0; i < size-1; i++) {
    logTable[expTable[i]] = i;
  }
  //logTable[0] == 0 but this should never be used
  zero =
    Ref<GenericGFPoly>(new GenericGFPoly(Ref<GenericGF>(this), ArrayRef<int>(new Array<int>(1))));
  zero->getCoefficients()[0] = 0;
  one =
    Ref<GenericGFPoly>(new GenericGFPoly(Ref<GenericGF>(this), ArrayRef<int>(new Array<int>(1))));
  one->getCoefficients()[0] = 1;
  initialized = true;
}
  
void GenericGF::checkInit() {
  if (!initialized) {
    initialize();
  }
}
  
Ref<GenericGFPoly> GenericGF::getZero() {
  checkInit();
  return zero;
}
  
Ref<GenericGFPoly> GenericGF::getOne() {
  checkInit();
  return one;
}
  
Ref<GenericGFPoly> GenericGF::buildMonomial(int degree, int coefficient) {
  checkInit();
    
  if (degree < 0) {
    throw IllegalArgumentException("Degree must be non-negative");
  }
  if (coefficient == 0) {
    return zero;
  }
  ArrayRef<int> coefficients(new Array<int>(degree + 1));
  coefficients[0] = coefficient;
    
  return Ref<GenericGFPoly>(new GenericGFPoly(Ref<GenericGF>(this), coefficients));
}
  
int GenericGF::addOrSubtract(int a, int b) {
  return a ^ b;
}
  
int GenericGF::exp(int a) {
  checkInit();
  return expTable[a];
}
  
int GenericGF::log(int a) {
  checkInit();
  if (a == 0) {
    throw IllegalArgumentException("cannot give log(0)");
  }
  return logTable[a];
}
  
int GenericGF::inverse(int a) {
  checkInit();
  if (a == 0) {
    throw IllegalArgumentException("Cannot calculate the inverse of 0");
  }
  return expTable[size - logTable[a] - 1];
}
  
int GenericGF::multiply(int a, int b) {
  checkInit();
    
  if (a == 0 || b == 0) {
    return 0;
  }
    
  return expTable[(logTable[a] + logTable[b]) % (size - 1)];
  }
    
int GenericGF::getSize() {
  return size;
}

int GenericGF::getGeneratorBase() {
  return generatorBase;
}
