// -*- mode:c++; tab-width:2; indent-tabs-mode:nil; c-basic-offset:2 -*-
#ifndef __BIT_MATRIX_H__
#define __BIT_MATRIX_H__

/*
 *  BitMatrix.h
 *  zqrdecode
 *
 */

#include <zqrdecode/common/Counted.h>
#include <zqrdecode/common/BitArray.h>
#include <zqrdecode/common/Array.h>
#include <limits>

namespace zqrdecode {

class BitMatrix : public Counted {
public:
  static const int bitsPerWord = std::numeric_limits<unsigned int>::digits;

private:
  int width;
  int height;
  int rowSize;
  ArrayRef<int> bits;

#define ZX_LOG_DIGITS(digits) \
    ((digits == 8) ? 3 : \
     ((digits == 16) ? 4 : \
      ((digits == 32) ? 5 : \
       ((digits == 64) ? 6 : \
        ((digits == 128) ? 7 : \
         (-1))))))

  static const int logBits = ZX_LOG_DIGITS(bitsPerWord);
  static const int bitsMask = (1 << logBits) - 1;

public:
  BitMatrix(int dimension);
  BitMatrix(int width, int height);

  ~BitMatrix();

  bool get(int x, int y) const {
    int offset = y * rowSize + (x >> logBits);
    return ((((unsigned)bits[offset]) >> (x & bitsMask)) & 1) != 0;
  }

  void set(int x, int y) {
    int offset = y * rowSize + (x >> logBits);
    bits[offset] |= 1 << (x & bitsMask);
  }

  void flip(int x, int y);
  void clear();
  void setRegion(int left, int top, int width, int height);
  Ref<BitArray> getRow(int y, Ref<BitArray> row);

  int getWidth() const;
  int getHeight() const;

  ArrayRef<int> getTopLeftOnBit() const;
  ArrayRef<int> getBottomRightOnBit() const;

  friend std::ostream& operator<<(std::ostream &out, const BitMatrix &bm);
  const char *description();

private:
  inline void init(int, int);

  BitMatrix(const BitMatrix&);
  BitMatrix& operator =(const BitMatrix&);
};

}

#endif // __BIT_MATRIX_H__
