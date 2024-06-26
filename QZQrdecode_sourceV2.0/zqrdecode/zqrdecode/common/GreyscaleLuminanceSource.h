// -*- mode:c++; tab-width:2; indent-tabs-mode:nil; c-basic-offset:2 -*-
#ifndef __GREYSCALE_LUMINANCE_SOURCE__
#define __GREYSCALE_LUMINANCE_SOURCE__
/*
 *  GreyscaleLuminanceSource.h
 *  zqrdecode
 *
 */

#include <zqrdecode/LuminanceSource.h>

namespace zqrdecode {

class GreyscaleLuminanceSource : public LuminanceSource {

private:
  typedef LuminanceSource Super;
  ArrayRef<char> greyData_;
  const int dataWidth_;
  const int dataHeight_;
  const int left_;
  const int top_;

public:
  GreyscaleLuminanceSource(ArrayRef<char> greyData, int dataWidth, int dataHeight, int left,
                           int top, int width, int height);

  ArrayRef<char> getRow(int y, ArrayRef<char> row) const;
  ArrayRef<char> getMatrix() const;

  bool isRotateSupported() const {
    return true;
  }

  Ref<LuminanceSource> rotateCounterClockwise() const;
};

}

#endif
