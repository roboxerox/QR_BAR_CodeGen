// -*- mode:c++; tab-width:2; indent-tabs-mode:nil; c-basic-offset:2 -*-
#ifndef __PDF417_READER_H__
#define __PDF417_READER_H__

/*
 *  PDF417Reader.h
 *  zqrdecode
 *
 * */

#include <zqrdecode/Reader.h>
#include <zqrdecode/pdf417/decoder/Decoder.h>
#include <zqrdecode/DecodeHints.h>

namespace zqrdecode {
namespace pdf417 {


class PDF417Reader : public Reader {
 private:
  decoder::Decoder decoder;
			
  static Ref<BitMatrix> extractPureBits(Ref<BitMatrix> image);
  static int moduleSize(ArrayRef<int> leftTopBlack, Ref<BitMatrix> image);
  static int findPatternStart(int x, int y, Ref<BitMatrix> image);
  static int findPatternEnd(int x, int y, Ref<BitMatrix> image);

 public:
  Ref<Result> decode(Ref<BinaryBitmap> image, DecodeHints hints);
  void reset();
};

}
}

#endif // __PDF417_READER_H__
