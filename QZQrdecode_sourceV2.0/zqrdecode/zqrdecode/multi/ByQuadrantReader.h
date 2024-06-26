#ifndef __BY_QUADRANT_READER_H__
#define __BY_QUADRANT_READER_H__

#include <zqrdecode/Reader.h>
#include <zqrdecode/BinaryBitmap.h>
#include <zqrdecode/Result.h>
#include <zqrdecode/DecodeHints.h>

namespace zqrdecode {
namespace multi {

class ByQuadrantReader : public Reader {
  private:
    Reader& delegate_;

  public:
    ByQuadrantReader(Reader& delegate);
    virtual ~ByQuadrantReader();
    virtual Ref<Result> decode(Ref<BinaryBitmap> image);
    virtual Ref<Result> decode(Ref<BinaryBitmap> image, DecodeHints hints);
};

}
}

#endif // __BY_QUADRANT_READER_H__
