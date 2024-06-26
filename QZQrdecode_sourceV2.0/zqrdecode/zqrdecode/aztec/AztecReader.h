// -*- mode:c++; tab-width:2; indent-tabs-mode:nil; c-basic-offset:2 -*-
/*
 *  AztecReader.h
 *  zqrdecode
 *
 */

#include <zqrdecode/Reader.h>
#include <zqrdecode/aztec/decoder/Decoder.h>
#include <zqrdecode/DecodeHints.h>

#ifndef ZQrdecodeWidget_AztecReader_h
#define ZQrdecodeWidget_AztecReader_h

namespace zqrdecode {
namespace aztec {
        
class AztecReader : public Reader {
 private:
  Decoder decoder_;
            
 protected:
  Decoder &getDecoder();
            
 public:
  AztecReader();
  virtual Ref<Result> decode(Ref<BinaryBitmap> image);
  virtual Ref<Result> decode(Ref<BinaryBitmap> image, DecodeHints hints);
  virtual ~AztecReader();
};
        
}
}

#endif
