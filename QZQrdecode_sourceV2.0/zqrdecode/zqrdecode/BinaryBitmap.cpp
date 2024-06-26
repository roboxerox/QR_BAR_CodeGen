// -*- mode:c++; tab-width:2; indent-tabs-mode:nil; c-basic-offset:2 -*-

#include <zqrdecode/BinaryBitmap.h>

using zqrdecode::Ref;
using zqrdecode::BitArray;
using zqrdecode::BitMatrix;
using zqrdecode::LuminanceSource;
using zqrdecode::BinaryBitmap;
	
// VC++
using zqrdecode::Binarizer;

BinaryBitmap::BinaryBitmap(Ref<Binarizer> binarizer) : binarizer_(binarizer) {
}
	
BinaryBitmap::~BinaryBitmap() {
}
	
Ref<BitArray> BinaryBitmap::getBlackRow(int y, Ref<BitArray> row) {
  return binarizer_->getBlackRow(y, row);
}
	
Ref<BitMatrix> BinaryBitmap::getBlackMatrix() {
  return binarizer_->getBlackMatrix();
}
	
int BinaryBitmap::getWidth() const {
  return getLuminanceSource()->getWidth();
}
	
int BinaryBitmap::getHeight() const {
  return getLuminanceSource()->getHeight();
}
	
Ref<LuminanceSource> BinaryBitmap::getLuminanceSource() const {
  return binarizer_->getLuminanceSource();
}
	

bool BinaryBitmap::isCropSupported() const {
  return getLuminanceSource()->isCropSupported();
}

Ref<BinaryBitmap> BinaryBitmap::crop(int left, int top, int width, int height) {
  return Ref<BinaryBitmap> (new BinaryBitmap(binarizer_->createBinarizer(getLuminanceSource()->crop(left, top, width, height))));
}

bool BinaryBitmap::isRotateSupported() const {
  return getLuminanceSource()->isRotateSupported();
}

Ref<BinaryBitmap> BinaryBitmap::rotateCounterClockwise() {
  return Ref<BinaryBitmap> (new BinaryBitmap(binarizer_->createBinarizer(getLuminanceSource()->rotateCounterClockwise())));
}
