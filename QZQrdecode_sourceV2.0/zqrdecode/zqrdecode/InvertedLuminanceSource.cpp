// -*- mode:c++; tab-width:2; indent-tabs-mode:nil; c-basic-offset:2 -*-


#include <zqrdecode/ZQrdecode.h>
#include <zqrdecode/InvertedLuminanceSource.h>

using zqrdecode::boolean;
using zqrdecode::Ref;
using zqrdecode::ArrayRef;
using zqrdecode::LuminanceSource;
using zqrdecode::InvertedLuminanceSource;

InvertedLuminanceSource::InvertedLuminanceSource(Ref<LuminanceSource> const& delegate_)
    : Super(delegate_->getWidth(), delegate_->getHeight()), delegate(delegate_) {}  

ArrayRef<char> InvertedLuminanceSource::getRow(int y, ArrayRef<char> row) const {
  row = delegate->getRow(y, row);
  int width = getWidth();
  for (int i = 0; i < width; i++) {
    row[i] = (byte) (255 - (row[i] & 0xFF));
  }
  return row;
}

ArrayRef<char> InvertedLuminanceSource::getMatrix() const {
  ArrayRef<char> matrix = delegate->getMatrix();
  int length = getWidth() * getHeight();
  ArrayRef<char> invertedMatrix(length);
  for (int i = 0; i < length; i++) {
    invertedMatrix[i] = (byte) (255 - (matrix[i] & 0xFF));
  }
  return invertedMatrix;
}

zqrdecode::boolean InvertedLuminanceSource::isCropSupported() const {
  return delegate->isCropSupported();
}

Ref<LuminanceSource> InvertedLuminanceSource::crop(int left, int top, int width, int height) const {
  return Ref<LuminanceSource>(new InvertedLuminanceSource(delegate->crop(left, top, width, height)));
}

boolean InvertedLuminanceSource::isRotateSupported() const {
  return delegate->isRotateSupported();
}

Ref<LuminanceSource> InvertedLuminanceSource::invert() const {
  return delegate;
}

Ref<LuminanceSource> InvertedLuminanceSource::rotateCounterClockwise() const {
  return Ref<LuminanceSource>(new InvertedLuminanceSource(delegate->rotateCounterClockwise()));
}

