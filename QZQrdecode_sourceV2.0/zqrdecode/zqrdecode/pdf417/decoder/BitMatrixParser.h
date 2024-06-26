#ifndef __BIT_MATRIX_PARSER__PDF_H__
#define __BIT_MATRIX_PARSER__PDF_H__

/*
 *  BitMatrixParser.h / PDF417
 *  zqrdecode
 */

#include <zqrdecode/ReaderException.h>
#include <zqrdecode/FormatException.h>
#include <zqrdecode/common/BitMatrix.h>
#include <zqrdecode/common/Counted.h>
#include <zqrdecode/common/Array.h>
#include <stdint.h>

namespace zqrdecode {
namespace pdf417 {
namespace decoder {

class BitMatrixParser : public Counted {
private:
  static const int MAX_ROWS;
  // Maximum Codewords (Data + Error)
  static const int MAX_CW_CAPACITY;
  static const int MODULES_IN_SYMBOL;

  Ref<BitMatrix> bitMatrix_;
  int rows_; /* = 0 */
  int leftColumnECData_; /* = 0 */
  int rightColumnECData_; /* = 0 */
  /* added 2012-06-22 HFN */
  int aLeftColumnTriple_[3];
  int aRightColumnTriple_[3];
  int eraseCount_; /* = 0 */
  ArrayRef<int> erasures_;
  int ecLevel_; /* = -1 */

public:
  static const int SYMBOL_TABLE[];
  static const int SYMBOL_TABLE_LENGTH;
  static const int CODEWORD_TABLE[];
  
public:
  BitMatrixParser(Ref<BitMatrix> bitMatrix);
  ArrayRef<int> getErasures() const {return erasures_;}
  int getECLevel() const {return ecLevel_;}
  int getEraseCount() const {return eraseCount_;}
  ArrayRef<int> readCodewords(); /* throw(FormatException) */
  static int getCodeword(int64_t symbol, int *pi = NULL);

private:
  bool VerifyOuterColumns(int rownumber);
  static ArrayRef<int> trimArray(ArrayRef<int> array, int size);
  static int findCodewordIndex(int64_t symbol);

  
  int processRow(int rowNumber,
                ArrayRef<int> codewords, int next);
  
  int processRow(ArrayRef<int> rowCounters, int rowNumber, int rowHeight,
    ArrayRef<int> codewords, int next); /* throw(FormatException)  */ 
protected:
  bool IsEqual(int &a, int &b, int rownumber);
};
 
}
}
}

#endif // __BIT_MATRIX_PARSER__PDF_H__
