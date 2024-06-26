#ifndef __DECODER_DM_H__
#define __DECODER_DM_H__

/*
 *  Decoder.h
 *  zqrdecode
 *
 */

#include <zqrdecode/common/reedsolomon/ReedSolomonDecoder.h>
#include <zqrdecode/common/Counted.h>
#include <zqrdecode/common/Array.h>
#include <zqrdecode/common/DecoderResult.h>
#include <zqrdecode/common/BitMatrix.h>


namespace zqrdecode {
namespace datamatrix {

class Decoder {
private:
  ReedSolomonDecoder rsDecoder_;

  void correctErrors(ArrayRef<char> bytes, int numDataCodewords);

public:
  Decoder();

  Ref<DecoderResult> decode(Ref<BitMatrix> bits);
};

}
}

#endif // __DECODER_DM_H__
