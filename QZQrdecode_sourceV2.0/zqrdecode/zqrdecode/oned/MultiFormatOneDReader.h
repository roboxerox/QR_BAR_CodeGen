#ifndef __MULTI_FORMAT_ONED_READER_H__
#define __MULTI_FORMAT_ONED_READER_H__
/*
 *  MultiFormatOneDReader.h
 *  zqrdecode
 *
 */

#include <zqrdecode/oned/OneDReader.h>

namespace zqrdecode {
  namespace oned {
    class MultiFormatOneDReader : public OneDReader {

    private:
      std::vector<Ref<OneDReader> > readers;
    public:
      MultiFormatOneDReader(DecodeHints hints);

      Ref<Result> decodeRow(int rowNumber, Ref<BitArray> row);
    };
  }
}

#endif
