// -*- mode:c++; tab-width:2; indent-tabs-mode:nil; c-basic-offset:2 -*-
#ifndef __EAN_8_READER_H__
#define __EAN_8_READER_H__

/*
 *  EAN8Reader.h
 *  zqrdecode
 *
 */

#include <zqrdecode/oned/UPCEANReader.h>
#include <zqrdecode/Result.h>

namespace zqrdecode {
namespace oned {

class EAN8Reader : public UPCEANReader {
 private:
  std::vector<int> decodeMiddleCounters;

 public:
  EAN8Reader();

  int decodeMiddle(Ref<BitArray> row,
                   Range const& startRange,
                   std::string& resultString);

  BarcodeFormat getBarcodeFormat();
};

}
}

#endif
