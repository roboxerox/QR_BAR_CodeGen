#ifndef __DATA_MASK_H__
#define __DATA_MASK_H__

/*
 *  DataMask.h
 *  zqrdecode
 *
 */

#include <zqrdecode/common/Array.h>
#include <zqrdecode/common/Counted.h>
#include <zqrdecode/common/BitMatrix.h>

#include <vector>

namespace zqrdecode {
namespace qrcode {

class DataMask : public Counted {
private:
  static std::vector<Ref<DataMask> > DATA_MASKS;

protected:

public:
  static int buildDataMasks();
  DataMask();
  virtual ~DataMask();
  void unmaskBitMatrix(BitMatrix& matrix, size_t dimension);
  virtual bool isMasked(size_t x, size_t y) = 0;
  static DataMask& forReference(int reference);
};

}
}

#endif // __DATA_MASK_H__
