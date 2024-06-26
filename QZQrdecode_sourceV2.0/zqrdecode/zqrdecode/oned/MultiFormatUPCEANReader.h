// -*- mode:c++; tab-width:2; indent-tabs-mode:nil; c-basic-offset:2 -*-
#ifndef __MULTI_FORMAT_UPC_EAN_READER_H__
#define __MULTI_FORMAT_UPC_EAN_READER_H__
/*
 *  MultiFormatUPCEANReader.h
 *  zqrdecode
 *
 */

#include <zqrdecode/oned/OneDReader.h>

namespace zqrdecode {
namespace oned {

class UPCEANReader;

class MultiFormatUPCEANReader : public OneDReader {
private:
    std::vector< Ref<UPCEANReader> > readers;
public:
    MultiFormatUPCEANReader(DecodeHints hints);
    Ref<Result> decodeRow(int rowNumber, Ref<BitArray> row);
};

}
}

#endif
