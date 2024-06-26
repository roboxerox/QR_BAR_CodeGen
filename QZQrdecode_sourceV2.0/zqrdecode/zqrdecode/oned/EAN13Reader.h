// -*- mode:c++; tab-width:2; indent-tabs-mode:nil; c-basic-offset:2 -*-
#ifndef __EAN_13_READER_H__
#define __EAN_13_READER_H__

/*
 *  EAN13Reader.h
 *  zqrdecode
 *
 */

#include <zqrdecode/oned/UPCEANReader.h>
#include <zqrdecode/Result.h>

namespace zqrdecode {
namespace oned {

class EAN13Reader : public UPCEANReader {
private:
  std::vector<int> decodeMiddleCounters;
  static void determineFirstDigit(std::string& resultString,
                                  int lgPatternFound);

public:
  EAN13Reader();

  int decodeMiddle(Ref<BitArray> row,
                   Range const& startRange,
                   std::string& resultString);

  BarcodeFormat getBarcodeFormat();
};

}
}

#endif
