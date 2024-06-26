#ifndef __MULTI_FORMAT_READER_H__
#define __MULTI_FORMAT_READER_H__

/*
 *  MultiFormatBarcodeReader.h
 *  zqrdecode
 *
 */

 
#include <zqrdecode/Reader.h>
#include <zqrdecode/common/BitArray.h>
#include <zqrdecode/Result.h>
#include <zqrdecode/DecodeHints.h>

namespace zqrdecode {
  class MultiFormatReader : public Reader {
  private:
    Ref<Result> decodeInternal(Ref<BinaryBitmap> image);
  
    std::vector<Ref<Reader> > readers_;
    DecodeHints hints_;

  public:
    MultiFormatReader();
    
    Ref<Result> decode(Ref<BinaryBitmap> image);
    Ref<Result> decode(Ref<BinaryBitmap> image, DecodeHints hints);
    Ref<Result> decodeWithState(Ref<BinaryBitmap> image);
    void setHints(DecodeHints hints);
    ~MultiFormatReader();
  };
}

#endif
