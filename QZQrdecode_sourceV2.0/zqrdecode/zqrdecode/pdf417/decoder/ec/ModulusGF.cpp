
#include <zqrdecode/pdf417/decoder/ec/ModulusGF.h>
#include <zqrdecode/pdf417/decoder/ec/ModulusPoly.h>

using zqrdecode::Ref;
using zqrdecode::pdf417::decoder::ec::ModulusGF;
using zqrdecode::pdf417::decoder::ec::ModulusPoly;

/**
 * The central Modulus Galois Field for PDF417 with prime number 929
 * and generator 3.
 */
ModulusGF ModulusGF::PDF417_GF(929,3);


/**
 * <p>A field based on powers of a generator integer, modulo some modulus.</p>
 *
 * @author Sean Owen
 * @see com.google.zqrdecode.common.reedsolomon.GenericGF
 */
 
ModulusGF::ModulusGF(int modulus, int generator)
    : modulus_(modulus) {
	expTable_ = new Array<int>(modulus_);
	logTable_ = new Array<int>(modulus_);
  int x = 1,i;
  for (i = 0; i < modulus_; i++) {
    expTable_[i] = x;
    x = (x * generator) % modulus_;
  }
  for (i = 0; i < modulus_-1; i++) {
    logTable_[expTable_[i]] = i;
  }
  // logTable[0] == 0 but this should never be used
	ArrayRef<int>aZero(new Array<int>(1)),aOne(new Array<int>(1));
	aZero[0]=0;aOne[0]=1;
  zero_ = new ModulusPoly(*this, aZero);
  one_ = new ModulusPoly(*this, aOne);
}
 
Ref<ModulusPoly> ModulusGF::getZero() {
  return zero_;
}

Ref<ModulusPoly> ModulusGF::getOne() {
  return one_;
}

Ref<ModulusPoly> ModulusGF::buildMonomial(int degree, int coefficient)
{
  if (degree < 0) {
    throw IllegalArgumentException("monomial: degree < 0!");
  }
  if (coefficient == 0) {
    return zero_;
  }
	int nCoefficients = degree + 1;
  ArrayRef<int> coefficients (new Array<int>(nCoefficients));
  coefficients[0] = coefficient;
	Ref<ModulusPoly> result(new ModulusPoly(*this,coefficients));
  return result;
}

 

int ModulusGF::add(int a, int b) {
  return (a + b) % modulus_;
}

int ModulusGF::subtract(int a, int b) {
  return (modulus_ + a - b) % modulus_;
}

int ModulusGF::exp(int a) {
  return expTable_[a];
}

int ModulusGF::log(int a) {
  if (a == 0) {
    throw IllegalArgumentException("log of zero!");
  }
  return logTable_[a];
}

int ModulusGF::inverse(int a) {
  if (a == 0) {
    throw IllegalArgumentException("inverse of zero!");;
  }
  return expTable_[modulus_ - logTable_[a] - 1];
}

int ModulusGF::multiply(int a, int b) {
  if (a == 0 || b == 0) {
    return 0;
  }
  return expTable_[(logTable_[a] + logTable_[b]) % (modulus_ - 1)];
}

int ModulusGF::getSize() {
  return modulus_;
}
