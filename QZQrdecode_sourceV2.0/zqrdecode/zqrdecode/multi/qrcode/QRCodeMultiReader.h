#ifndef __QRCODE_MULTI_READER_H__
#define __QRCODE_MULTI_READER_H__


#include <zqrdecode/multi/MultipleBarcodeReader.h>
#include <zqrdecode/qrcode/QRCodeReader.h>

namespace zqrdecode {
namespace multi {

class QRCodeMultiReader: public zqrdecode::qrcode::QRCodeReader, public MultipleBarcodeReader {
  public:
    QRCodeMultiReader();
    virtual ~QRCodeMultiReader();
    virtual std::vector<Ref<Result> > decodeMultiple(Ref<BinaryBitmap> image, DecodeHints hints);
};

}
}

#endif // __QRCODE_MULTI_READER_H__
