// -*- mode:c++; tab-width:2; indent-tabs-mode:nil; c-basic-offset:2 -*-
#ifndef __GREYSCALE_ROTATED_LUMINANCE_SOURCE__
#define __GREYSCALE_ROTATED_LUMINANCE_SOURCE__
/*
 *  GreyscaleRotatedLuminanceSource.h
 *  zqrdecode
 *
 */


#include <zqrdecode/LuminanceSource.h>

namespace zqrdecode {

class GreyscaleRotatedLuminanceSource : public LuminanceSource {
 private:
  typedef LuminanceSource Super;
  ArrayRef<char> greyData_;
  const int dataWidth_;
  const int left_;
  const int top_;

public:
  GreyscaleRotatedLuminanceSource(ArrayRef<char> greyData, int dataWidth, int dataHeight,
      int left, int top, int width, int height);

  ArrayRef<char> getRow(int y, ArrayRef<char> row) const;
  ArrayRef<char> getMatrix() const;
};

}

#endif
