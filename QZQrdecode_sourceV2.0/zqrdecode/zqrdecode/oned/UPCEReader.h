// -*- mode:c++; tab-width:2; indent-tabs-mode:nil; c-basic-offset:2 -*-
#ifndef __UPC_E_READER_H__
#define __UPC_E_READER_H__


#include <zqrdecode/oned/UPCEANReader.h>
#include <zqrdecode/Result.h>

namespace zqrdecode {
namespace oned {

class UPCEReader : public UPCEANReader {
private:
  std::vector<int> decodeMiddleCounters;
  static bool determineNumSysAndCheckDigit(std::string& resultString, int lgPatternFound);

protected:
  Range decodeEnd(Ref<BitArray> row, int endStart);
  bool checkChecksum(Ref<String> const& s);
public:
  UPCEReader();

  int decodeMiddle(Ref<BitArray> row, Range const& startRange, std::string& resultString);
  static Ref<String> convertUPCEtoUPCA(Ref<String> const& upce);

  BarcodeFormat getBarcodeFormat();
};

}
}

#endif
