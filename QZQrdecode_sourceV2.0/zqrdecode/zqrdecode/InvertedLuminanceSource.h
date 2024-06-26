// -*- mode:c++; tab-width:2; indent-tabs-mode:nil; c-basic-offset:2 -*-
#ifndef __INVERTEDLUMINANCESOURCE_H__
#define __INVERTEDLUMINANCESOURCE_H__


#include <zqrdecode/ZQrdecode.h>
#include <zqrdecode/LuminanceSource.h>

namespace zqrdecode {

class InvertedLuminanceSource : public LuminanceSource {
private:
  typedef LuminanceSource Super;
  const Ref<LuminanceSource> delegate;

public:
  InvertedLuminanceSource(Ref<LuminanceSource> const&);

  ArrayRef<char> getRow(int y, ArrayRef<char> row) const;
  ArrayRef<char> getMatrix() const;

  boolean isCropSupported() const;
  Ref<LuminanceSource> crop(int left, int top, int width, int height) const;

  boolean isRotateSupported() const;

  virtual Ref<LuminanceSource> invert() const;

  Ref<LuminanceSource> rotateCounterClockwise() const;
};

}

#endif /* INVERTEDLUMINANCESOURCE_H_ */
