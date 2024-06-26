// -*- mode:c++; tab-width:2; indent-tabs-mode:nil; c-basic-offset:2 -*-
#ifndef __QR_CODE_READER_H__
#define __QR_CODE_READER_H__

/*
 *  QRCodeReader.h
 *  zqrdecode
 *
 */

#include <zqrdecode/Reader.h>
#include <zqrdecode/qrcode/decoder/Decoder.h>
#include <zqrdecode/DecodeHints.h>

namespace zqrdecode {
namespace qrcode {
		
class QRCodeReader : public Reader {
 private:
  Decoder decoder_;
			
 protected:
  Decoder& getDecoder();

 public:
  QRCodeReader();
  virtual ~QRCodeReader();
			
  Ref<Result> decode(Ref<BinaryBitmap> image, DecodeHints hints);
};

}
}

#endif // __QR_CODE_READER_H__
