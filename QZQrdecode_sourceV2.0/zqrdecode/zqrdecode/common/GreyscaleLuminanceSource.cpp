// -*- mode:c++; tab-width:2; indent-tabs-mode:nil; c-basic-offset:2 -*-
/*
 *  GreyscaleLuminanceSource.cpp
 *  zqrdecode
 *
 */

#include <zqrdecode/common/GreyscaleLuminanceSource.h>
#include <zqrdecode/common/GreyscaleRotatedLuminanceSource.h>
#include <zqrdecode/common/IllegalArgumentException.h>

using zqrdecode::Ref;
using zqrdecode::ArrayRef;
using zqrdecode::LuminanceSource;
using zqrdecode::GreyscaleLuminanceSource;

GreyscaleLuminanceSource::
GreyscaleLuminanceSource(ArrayRef<char> greyData,
                         int dataWidth, int dataHeight,
                         int left, int top,
                         int width, int height) 
    : Super(width, height),
      greyData_(greyData),
      dataWidth_(dataWidth), dataHeight_(dataHeight),
      left_(left), top_(top) {

  if (left + width > dataWidth || top + height > dataHeight || top < 0 || left < 0) {
    throw IllegalArgumentException("Crop rectangle does not fit within image data.");
  }
}

ArrayRef<char> GreyscaleLuminanceSource::getRow(int y, ArrayRef<char> row) const {
  if (y < 0 || y >= this->getHeight()) {
    throw IllegalArgumentException("Requested row is outside the image.");
  }
  int width = getWidth();
  if (!row || row->size() < width) {
    ArrayRef<char> temp (width);
    row = temp;
  }
  int offset = (y + top_) * dataWidth_ + left_;
  memcpy(&row[0], &greyData_[offset], width);
  return row;
}

ArrayRef<char> GreyscaleLuminanceSource::getMatrix() const {
  int size = getWidth() * getHeight();
  ArrayRef<char> result (size);
  if (left_ == 0 && top_ == 0 && dataWidth_ == getWidth() && dataHeight_ == getHeight()) {
    memcpy(&result[0], &greyData_[0], size);
  } else {
    for (int row = 0; row < getHeight(); row++) {
      memcpy(&result[row * getWidth()], &greyData_[(top_ + row) * dataWidth_ + left_], getWidth());
    }
  }
  return result;
}

Ref<LuminanceSource> GreyscaleLuminanceSource::rotateCounterClockwise() const {
  // Intentionally flip the left, top, width, and height arguments as
  // needed. dataWidth and dataHeight are always kept unrotated.
  Ref<LuminanceSource> result ( 
      new GreyscaleRotatedLuminanceSource(greyData_,
                                          dataWidth_, dataHeight_,
                                          top_, left_, getHeight(), getWidth()));
  return result;
}
