// -*- mode:c++; tab-width:2; indent-tabs-mode:nil; c-basic-offset:2 -*-
/*
 *  UPCAReader.cpp
 *  zqrdecode
 *
 */

#include "UPCAReader.h"
#include <zqrdecode/ReaderException.h>

using zqrdecode::oned::UPCAReader;
using zqrdecode::Ref;
using zqrdecode::Result;

// VC++
using zqrdecode::BitArray;
using zqrdecode::BinaryBitmap;
using zqrdecode::DecodeHints;

UPCAReader::UPCAReader() : ean13Reader() {}

Ref<Result> UPCAReader::decodeRow(int rowNumber, Ref<BitArray> row) {
  return maybeReturnResult(ean13Reader.decodeRow(rowNumber, row));
}

Ref<Result> UPCAReader::decodeRow(int rowNumber,
                                  Ref<BitArray> row,
                                  Range const& startGuardRange) {
  return maybeReturnResult(ean13Reader.decodeRow(rowNumber, row, startGuardRange));
}

Ref<Result> UPCAReader::decode(Ref<BinaryBitmap> image, DecodeHints hints) {
  return maybeReturnResult(ean13Reader.decode(image, hints));
}

int UPCAReader::decodeMiddle(Ref<BitArray> row,
                             Range const& startRange,
                             std::string& resultString) {
  return ean13Reader.decodeMiddle(row, startRange, resultString);
}

Ref<Result> UPCAReader::maybeReturnResult(Ref<Result> result) {
  if (result.empty()) {
    return result;
  }
  const std::string& text = (result->getText())->getText();
  if (text[0] == '0') {
    Ref<String> resultString(new String(text.substr(1)));
    Ref<Result> res(new Result(resultString, result->getRawBytes(), result->getResultPoints(),
                               BarcodeFormat::UPC_A));
    return res;
  }
  return Ref<Result>();
}

zqrdecode::BarcodeFormat UPCAReader::getBarcodeFormat(){
  return BarcodeFormat::UPC_A;
}
