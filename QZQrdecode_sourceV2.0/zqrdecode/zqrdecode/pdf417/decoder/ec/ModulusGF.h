#ifndef __MODULUS_GF_PDF_H__
#define __MODULUS_GF_PDF_H__


#include <zqrdecode/common/Counted.h>
#include <zqrdecode/common/Array.h>
#include <zqrdecode/common/DecoderResult.h>
#include <zqrdecode/common/BitMatrix.h>

namespace zqrdecode {
namespace pdf417 {
namespace decoder {
namespace ec {

class ModulusPoly;

/**
 * <p>A field based on powers of a generator integer, modulo some modulus.</p>
 *
 * @author Sean Owen
 * @see com.google.zqrdecode.common.reedsolomon.GenericGF
 */
class ModulusGF {

  public: 
	static ModulusGF PDF417_GF;

  private:
	ArrayRef<int> expTable_;
	ArrayRef<int> logTable_;
	Ref<ModulusPoly> zero_;
	Ref<ModulusPoly> one_;
	int modulus_;

  public:
	ModulusGF(int modulus, int generator);
	Ref<ModulusPoly> getZero();
	Ref<ModulusPoly> getOne();
	Ref<ModulusPoly> buildMonomial(int degree, int coefficient);

	int add(int a, int b);
	int subtract(int a, int b);
	int exp(int a);
	int log(int a);
	int inverse(int a);
	int multiply(int a, int b);
	int getSize();
  
};

}
}
}
}

#endif /* __MODULUS_GF_PDF_H__ */
