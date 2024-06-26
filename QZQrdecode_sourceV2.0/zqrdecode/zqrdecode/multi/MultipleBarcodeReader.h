#ifndef __MULTIPLE_BARCODE_READER_H__
#define __MULTIPLE_BARCODE_READER_H__



#include <zqrdecode/common/Counted.h>
#include <zqrdecode/Result.h>
#include <zqrdecode/BinaryBitmap.h>
#include <zqrdecode/DecodeHints.h>
#include <vector>

namespace zqrdecode {
namespace multi {

class MultipleBarcodeReader : public Counted {
  protected:
    MultipleBarcodeReader() {}
  public:
    virtual std::vector<Ref<Result> > decodeMultiple(Ref<BinaryBitmap> image);
    virtual std::vector<Ref<Result> > decodeMultiple(Ref<BinaryBitmap> image, DecodeHints hints) = 0;
    virtual ~MultipleBarcodeReader();
};

}
}

#endif // __MULTIPLE_BARCODE_READER_H__
