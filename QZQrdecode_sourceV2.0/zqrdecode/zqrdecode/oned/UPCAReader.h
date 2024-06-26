// -*- mode:c++; tab-width:2; indent-tabs-mode:nil; c-basic-offset:2 -*-
#ifndef __UPCA_READER_H__
#define __UPCA_READER_H__
/*
 *  UPCAReader.h
 *  zqrdecode
 *
 */

#include <zqrdecode/oned/EAN13Reader.h>
#include <zqrdecode/DecodeHints.h>

namespace zqrdecode {
namespace oned {

class UPCAReader : public UPCEANReader {

private:
  EAN13Reader ean13Reader;
  static Ref<Result> maybeReturnResult(Ref<Result> result);

public:
  UPCAReader();

  int decodeMiddle(Ref<BitArray> row, Range const& startRange, std::string& resultString);

  Ref<Result> decodeRow(int rowNumber, Ref<BitArray> row);
  Ref<Result> decodeRow(int rowNumber, Ref<BitArray> row, Range const& startGuardRange);
  Ref<Result> decode(Ref<BinaryBitmap> image, DecodeHints hints);

  BarcodeFormat getBarcodeFormat();
};

}
}

#endif
