// -*- mode:c++; tab-width:2; indent-tabs-mode:nil; c-basic-offset:2 -*-
/*
 *  LuminanceSource.cpp
 *  zqrdecode
 *
 */

#include <sstream>
#include <zqrdecode/LuminanceSource.h>
#include <zqrdecode/InvertedLuminanceSource.h>
#include <zqrdecode/common/IllegalArgumentException.h>

using zqrdecode::Ref;
using zqrdecode::LuminanceSource;

LuminanceSource::LuminanceSource(int width_, int height_) :width(width_), height(height_) {}

LuminanceSource::~LuminanceSource() {}

bool LuminanceSource::isCropSupported() const {
  return false;
}

Ref<LuminanceSource> LuminanceSource::crop(int, int, int, int) const {
  throw IllegalArgumentException("This luminance source does not support cropping.");
}

bool LuminanceSource::isRotateSupported() const {
  return false;
}

Ref<LuminanceSource> LuminanceSource::rotateCounterClockwise() const {
  throw IllegalArgumentException("This luminance source does not support rotation.");
}

LuminanceSource::operator std::string() const {
  ArrayRef<char> row;
  std::ostringstream oss;
  for (int y = 0; y < getHeight(); y++) {
    row = getRow(y, row);
    for (int x = 0; x < getWidth(); x++) {
      int luminance = row[x] & 0xFF;
      char c;
      if (luminance < 0x40) {
        c = '#';
      } else if (luminance < 0x80) {
        c = '+';
      } else if (luminance < 0xC0) {
        c = '.';
      } else {
        c = ' ';
      }
      oss << c;
    }
    oss << '\n';
  }
  return oss.str();
}

Ref<LuminanceSource> LuminanceSource::invert() const {

  // N.B.: this only works because we use counted objects with the
  // count in the object. This is _not_ how things like shared_ptr
  // work. They do not allow you to make a smart pointer from a native
  // pointer more than once. If we ever switch to (something like)
  // shared_ptr's, the luminace source is going to have keep a weak
  // pointer to itself from which it can create a strong pointer as
  // needed. And, FWIW, that has nasty semantics in the face of
  // exceptions during construction.

  return Ref<LuminanceSource>
      (new InvertedLuminanceSource(Ref<LuminanceSource>(const_cast<LuminanceSource*>(this))));
}
