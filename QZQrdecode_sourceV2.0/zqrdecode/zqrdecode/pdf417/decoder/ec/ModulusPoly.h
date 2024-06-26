#ifndef __MODULUS_GFPOLY_PDF_H__
#define __MODULUS_GFPOLY_PDF_H__


#include <zqrdecode/common/Counted.h>
#include <zqrdecode/common/Array.h>
#include <zqrdecode/common/DecoderResult.h>
#include <zqrdecode/common/BitMatrix.h>

namespace zqrdecode {
namespace pdf417 {
namespace decoder {
namespace ec {

class ModulusGF;

/**
 * @author Sean Owen
 * @see com.google.zqrdecode.common.reedsolomon.GenericGFPoly
 */
class ModulusPoly: public Counted {

  private:
	ModulusGF &field_;
	ArrayRef<int> coefficients_;
  public:
	ModulusPoly(ModulusGF& field, ArrayRef<int> coefficients);
	~ModulusPoly();
	ArrayRef<int> getCoefficients();
	int getDegree();
	bool isZero();
	int getCoefficient(int degree);
	int evaluateAt(int a);
	Ref<ModulusPoly> add(Ref<ModulusPoly> other);
	Ref<ModulusPoly> subtract(Ref<ModulusPoly> other);
	Ref<ModulusPoly> multiply(Ref<ModulusPoly> other);
	Ref<ModulusPoly> negative();
	Ref<ModulusPoly> multiply(int scalar);
	Ref<ModulusPoly> multiplyByMonomial(int degree, int coefficient);
	std::vector<Ref<ModulusPoly> > divide(Ref<ModulusPoly> other);
	#if 0
    public String toString();
	#endif
};

}
}
}
}

#endif /* __MODULUS_GFPOLY_PDF_H__ */
