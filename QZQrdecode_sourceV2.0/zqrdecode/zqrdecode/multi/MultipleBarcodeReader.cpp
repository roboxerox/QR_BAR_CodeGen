

#include <zqrdecode/multi/MultipleBarcodeReader.h>

namespace zqrdecode {
namespace multi {

MultipleBarcodeReader::~MultipleBarcodeReader() { }

std::vector<Ref<Result> > MultipleBarcodeReader::decodeMultiple(Ref<BinaryBitmap> image) {
  return decodeMultiple(image, DecodeHints::DEFAULT_HINT);
}

} // End zqrdecode::multi namespace
} // End zqrdecode namespace
