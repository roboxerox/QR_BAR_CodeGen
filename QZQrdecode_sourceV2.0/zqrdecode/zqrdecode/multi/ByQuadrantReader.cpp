

#include <zqrdecode/multi/ByQuadrantReader.h>
#include <zqrdecode/ReaderException.h>

namespace zqrdecode {
namespace multi {

ByQuadrantReader::ByQuadrantReader(Reader& delegate) : delegate_(delegate) {}

ByQuadrantReader::~ByQuadrantReader(){}

Ref<Result> ByQuadrantReader::decode(Ref<BinaryBitmap> image){
  return decode(image, DecodeHints::DEFAULT_HINT);
}

Ref<Result> ByQuadrantReader::decode(Ref<BinaryBitmap> image, DecodeHints hints){
  int width = image->getWidth();
  int height = image->getHeight();
  int halfWidth = width / 2;
  int halfHeight = height / 2;
  Ref<BinaryBitmap> topLeft = image->crop(0, 0, halfWidth, halfHeight);
  try {
    return delegate_.decode(topLeft, hints);
  } catch (ReaderException const& re) {
    (void)re;
    // continue
  }

  Ref<BinaryBitmap> topRight = image->crop(halfWidth, 0, halfWidth, halfHeight);
  try {
    return delegate_.decode(topRight, hints);
  } catch (ReaderException const& re) {
    (void)re;
    // continue
  }

  Ref<BinaryBitmap> bottomLeft = image->crop(0, halfHeight, halfWidth, halfHeight);
  try {
    return delegate_.decode(bottomLeft, hints);
  } catch (ReaderException const& re) {
    (void)re;
    // continue
  }

  Ref<BinaryBitmap> bottomRight = image->crop(halfWidth, halfHeight, halfWidth, halfHeight);
  try {
    return delegate_.decode(bottomRight, hints);
  } catch (ReaderException const& re) {
    (void)re;
    // continue
  }

  int quarterWidth = halfWidth / 2;
  int quarterHeight = halfHeight / 2;
  Ref<BinaryBitmap> center = image->crop(quarterWidth, quarterHeight, halfWidth, halfHeight);
  return delegate_.decode(center, hints);
}

} // End zqrdecode::multi namespace
} // End zqrdecode namespace
