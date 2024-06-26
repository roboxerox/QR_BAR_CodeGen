#ifndef __DECOCER_PDF_H__
#define __DECOCER_PDF_H__

/*
 *  Decoder.h
 *  zqrdecode
 *
 */

#include <zqrdecode/pdf417/decoder/ec/ErrorCorrection.h>
#include <zqrdecode/pdf417/decoder/ec/ModulusGF.h>
#include <zqrdecode/common/Counted.h>
#include <zqrdecode/common/Array.h>
#include <zqrdecode/common/DecoderResult.h>
#include <zqrdecode/common/BitMatrix.h>


namespace zqrdecode {
namespace pdf417 {
namespace decoder {

/**
 * <p>The main class which implements PDF417 Code decoding -- as
 * opposed to locating and extracting the PDF417 Code from an image.</p>
 *
 * <p> 2012-06-27 HFN Reed-Solomon error correction activated, see class PDF417RSDecoder. </p>
 * <p> 2012-09-19 HFN Reed-Solomon error correction via ErrorCorrection/ModulusGF/ModulusPoly. </p>
 */

class Decoder {
private:
  static const int MAX_ERRORS;
  static const int MAX_EC_CODEWORDS;

  void correctErrors(ArrayRef<int> codewords,
		ArrayRef<int> erasures, int numECCodewords);
  static void verifyCodewordCount(ArrayRef<int> codewords, int numECCodewords);

public:

  Ref<DecoderResult> decode(Ref<BitMatrix> bits, DecodeHints const &hints);
};

}
}
}

#endif // __DECOCER_PDF_H__
