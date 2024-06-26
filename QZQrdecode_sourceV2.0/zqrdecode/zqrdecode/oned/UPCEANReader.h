// -*- mode:c++; tab-width:2; indent-tabs-mode:nil; c-basic-offset:2 -*-
#ifndef __UPC_EAN_READER_H__
#define __UPC_EAN_READER_H__

#include <zqrdecode/oned/OneDReader.h>
#include <zqrdecode/common/BitArray.h>
#include <zqrdecode/Result.h>

namespace zqrdecode {
namespace oned {

class UPCEANReader : public OneDReader {
 private:
  std::string decodeRowStringBuffer;
  // UPCEANExtensionSupport extensionReader;
  // EANManufacturerOrgSupport eanManSupport;

  static const int MAX_AVG_VARIANCE;
  static const int MAX_INDIVIDUAL_VARIANCE;

  static Range findStartGuardPattern(Ref<BitArray> row);

  virtual Range decodeEnd(Ref<BitArray> row, int endStart);

  static bool checkStandardUPCEANChecksum(Ref<String> const& s);

  static Range findGuardPattern(Ref<BitArray> row,
                                int rowOffset,
                                bool whiteFirst,
                                std::vector<int> const& pattern,
                                std::vector<int>& counters);


protected:
  static const std::vector<int> START_END_PATTERN;
  static const std::vector<int> MIDDLE_PATTERN;

  static const std::vector<int const*> L_PATTERNS;
  static const std::vector<int const*> L_AND_G_PATTERNS;

  static Range findGuardPattern(Ref<BitArray> row,
                                int rowOffset,
                                bool whiteFirst,
                                std::vector<int> const& pattern);

public:
  UPCEANReader();

  virtual int decodeMiddle(Ref<BitArray> row,
                           Range const& startRange,
                           std::string& resultString) = 0;

  virtual Ref<Result> decodeRow(int rowNumber, Ref<BitArray> row);
  virtual Ref<Result> decodeRow(int rowNumber, Ref<BitArray> row, Range const& range);

  static int decodeDigit(Ref<BitArray> row,
                         std::vector<int>& counters,
                         int rowOffset,
                         std::vector<int const*> const& patterns);

  virtual bool checkChecksum(Ref<String> const& s);

  virtual BarcodeFormat getBarcodeFormat() = 0;
  virtual ~UPCEANReader();

  friend class MultiFormatUPCEANReader;
};

}
}

#endif
