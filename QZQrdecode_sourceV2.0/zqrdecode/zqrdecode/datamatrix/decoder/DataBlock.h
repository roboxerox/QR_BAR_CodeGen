#ifndef __DATA_BLOCK_DM_H__
#define __DATA_BLOCK_DM_H__

/*
 *  DataBlock.h
 *  zqrdecode
 *
 */

#include <vector>
#include <zqrdecode/common/Counted.h>
#include <zqrdecode/common/Array.h>
#include <zqrdecode/datamatrix/Version.h>

namespace zqrdecode {
namespace datamatrix {

class DataBlock : public Counted {
private:
  int numDataCodewords_;
  ArrayRef<char> codewords_;

  DataBlock(int numDataCodewords, ArrayRef<char> codewords);

public:  
  static std::vector<Ref<DataBlock> > getDataBlocks(ArrayRef<char> rawCodewords, Version *version);

  int getNumDataCodewords();
  ArrayRef<char> getCodewords();
};

}
}

#endif // __DATA_BLOCK_DM_H__
