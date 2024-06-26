#ifndef __BIT_MATRIX_PARSER_DM_H__
#define __BIT_MATRIX_PARSER_DM_H__

/*
 *  BitMatrixParser.h
 *  zqrdecode
 *
 */

#include <zqrdecode/ReaderException.h>
#include <zqrdecode/common/BitMatrix.h>
#include <zqrdecode/common/Counted.h>
#include <zqrdecode/common/Array.h>
#include <zqrdecode/datamatrix/Version.h>

namespace zqrdecode {
namespace datamatrix {

class BitMatrixParser : public Counted {
private:
  Ref<BitMatrix> bitMatrix_;
  Ref<Version> parsedVersion_;
  Ref<BitMatrix> readBitMatrix_;

  int copyBit(size_t x, size_t y, int versionBits);

public:
  BitMatrixParser(Ref<BitMatrix> bitMatrix);
  Ref<Version> readVersion(Ref<BitMatrix> bitMatrix);
  ArrayRef<char> readCodewords();
  bool readModule(int row, int column, int numRows, int numColumns);

private:
  int readUtah(int row, int column, int numRows, int numColumns);
  int readCorner1(int numRows, int numColumns);
  int readCorner2(int numRows, int numColumns);
  int readCorner3(int numRows, int numColumns);
  int readCorner4(int numRows, int numColumns);
  Ref<BitMatrix> extractDataRegion(Ref<BitMatrix> bitMatrix);
};

}
}

#endif // __BIT_MATRIX_PARSER_DM_H__
