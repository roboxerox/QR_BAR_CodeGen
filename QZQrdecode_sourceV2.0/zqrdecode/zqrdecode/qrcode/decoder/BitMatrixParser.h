#ifndef __BIT_MATRIX_PARSER_H__
#define __BIT_MATRIX_PARSER_H__

/*
 *  BitMatrixParser.h
 *  zqrdecode
 *
 */

#include <zqrdecode/ReaderException.h>
#include <zqrdecode/common/BitMatrix.h>
#include <zqrdecode/common/Counted.h>
#include <zqrdecode/common/Array.h>
#include <zqrdecode/qrcode/Version.h>
#include <zqrdecode/qrcode/FormatInformation.h>

namespace zqrdecode {
namespace qrcode {

class BitMatrixParser : public Counted {
private:
  Ref<BitMatrix> bitMatrix_;
  Version *parsedVersion_;
  Ref<FormatInformation> parsedFormatInfo_;

  int copyBit(size_t x, size_t y, int versionBits);

public:
  BitMatrixParser(Ref<BitMatrix> bitMatrix);
  Ref<FormatInformation> readFormatInformation();
  Version *readVersion();
  ArrayRef<char> readCodewords();

private:
  BitMatrixParser(const BitMatrixParser&);
  BitMatrixParser& operator =(const BitMatrixParser&);
  
};

}
}

#endif // __BIT_MATRIX_PARSER_H__
