// -*- mode:c++; tab-width:2; indent-tabs-mode:nil; c-basic-offset:2 -*-
#ifndef __LUMINANCESOURCE_H__
#define __LUMINANCESOURCE_H__
/*
 *  LuminanceSource.h
 *  zqrdecode
 *
 */

#include <zqrdecode/common/Counted.h>
#include <zqrdecode/common/Array.h>
#include <string.h>

namespace zqrdecode {

class LuminanceSource : public Counted {
 private:
  const int width;
  const int height;

 public:
  LuminanceSource(int width, int height);
  virtual ~LuminanceSource();

  int getWidth() const { return width; }
  int getHeight() const { return height; }

  // Callers take ownership of the returned memory and must call delete [] on it themselves.
  virtual ArrayRef<char> getRow(int y, ArrayRef<char> row) const = 0;
  virtual ArrayRef<char> getMatrix() const = 0;

  virtual bool isCropSupported() const;
  virtual Ref<LuminanceSource> crop(int left, int top, int width, int height) const;

  virtual bool isRotateSupported() const;

  virtual Ref<LuminanceSource> invert() const;
  
  virtual Ref<LuminanceSource> rotateCounterClockwise() const;

  operator std::string () const;
};

}

#endif /* LUMINANCESOURCE_H_ */
