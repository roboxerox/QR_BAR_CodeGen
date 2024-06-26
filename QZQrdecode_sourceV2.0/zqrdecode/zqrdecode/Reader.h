#ifndef __READER_H__
#define __READER_H__

/*
 *  Reader.h
 *  zqrdecode
 *
 */

#include <zqrdecode/BinaryBitmap.h>
#include <zqrdecode/Result.h>
#include <zqrdecode/DecodeHints.h>

namespace zqrdecode {

 class Reader : public Counted {
  protected:
   Reader() {}
  public:
   virtual Ref<Result> decode(Ref<BinaryBitmap> image);
   virtual Ref<Result> decode(Ref<BinaryBitmap> image, DecodeHints hints) = 0;
   virtual ~Reader();
};

}

#endif // __READER_H__
