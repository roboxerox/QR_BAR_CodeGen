// -*- mode:c++; tab-width:2; indent-tabs-mode:nil; c-basic-offset:2 -*-
#ifndef __GENERIC_MULTIPLE_BARCODE_READER_H__
#define __GENERIC_MULTIPLE_BARCODE_READER_H__

#include <zqrdecode/multi/MultipleBarcodeReader.h>
#include <zqrdecode/Reader.h>

namespace zqrdecode {
namespace multi {

class GenericMultipleBarcodeReader : public MultipleBarcodeReader {
 private:
  static Ref<Result> translateResultPoints(Ref<Result> result, 
                                           int xOffset, 
                                           int yOffset);
  void doDecodeMultiple(Ref<BinaryBitmap> image, 
                        DecodeHints hints, 
                        std::vector<Ref<Result> >& results, 
                        int xOffset, 
                        int yOffset,
                        int currentDepth);
  Reader& delegate_;
  static const int MIN_DIMENSION_TO_RECUR = 100;
  static const int MAX_DEPTH = 4;

 public:
  GenericMultipleBarcodeReader(Reader& delegate);
  virtual ~GenericMultipleBarcodeReader();
  virtual std::vector<Ref<Result> > decodeMultiple(Ref<BinaryBitmap> image, DecodeHints hints);
};

}
}

#endif // __GENERIC_MULTIPLE_BARCODE_READER_H__
