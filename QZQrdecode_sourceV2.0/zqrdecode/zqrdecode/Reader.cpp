/*
 *  Reader.cpp
 *  zqrdecode
 *
 */

#include <zqrdecode/Reader.h>

namespace zqrdecode {

Reader::~Reader() { }

Ref<Result> Reader::decode(Ref<BinaryBitmap> image) {
  return decode(image, DecodeHints::DEFAULT_HINT);
}

}
