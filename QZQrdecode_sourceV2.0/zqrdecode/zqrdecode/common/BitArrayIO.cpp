
#include <zqrdecode/common/BitArray.h>

using zqrdecode::BitArray;
using std::ostream;

ostream& zqrdecode::operator << (ostream& os, BitArray const& ba) {
  for (int i = 0, size = ba.getSize(); i < size; i++) {
    if ((i & 0x07) == 0) {
      os << ' ';
    }
    os << (ba.get(i) ? 'X' : '.');
  }
  return os;
}
