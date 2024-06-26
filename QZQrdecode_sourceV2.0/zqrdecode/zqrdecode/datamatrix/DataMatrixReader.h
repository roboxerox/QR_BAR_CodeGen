#ifndef __DATA_MATRIX_READER_H__
#define __DATA_MATRIX_READER_H__

/*
 *  DataMatrixReader.h
 *  zqrdecode
 *
 */

#include <zqrdecode/Reader.h>
#include <zqrdecode/DecodeHints.h>
#include <zqrdecode/datamatrix/decoder/Decoder.h>

namespace zqrdecode {
namespace datamatrix {

class DataMatrixReader : public Reader {
private:
  Decoder decoder_;

public:
  DataMatrixReader();
  virtual Ref<Result> decode(Ref<BinaryBitmap> image, DecodeHints hints);
  virtual ~DataMatrixReader();

};

}
}

#endif // __DATA_MATRIX_READER_H__
