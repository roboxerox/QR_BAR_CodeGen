// -*- mode:c++; tab-width:2; indent-tabs-mode:nil; c-basic-offset:2 -*-
/*
 *  MultiFormatUPCEANReader.cpp
 *  zqrdecode
 */

#include <zqrdecode/ZQrdecode.h>
#include <zqrdecode/oned/MultiFormatUPCEANReader.h>
#include <zqrdecode/oned/EAN13Reader.h>
#include <zqrdecode/oned/EAN8Reader.h>
#include <zqrdecode/oned/UPCEReader.h>
#include <zqrdecode/oned/UPCAReader.h>
#include <zqrdecode/oned/OneDResultPoint.h>
#include <zqrdecode/common/Array.h>
#include <zqrdecode/ReaderException.h>
#include <zqrdecode/NotFoundException.h>
#include <math.h>

using zqrdecode::NotFoundException;
using zqrdecode::Ref;
using zqrdecode::Result;
using zqrdecode::oned::MultiFormatUPCEANReader;
    
// VC++
using zqrdecode::DecodeHints;
using zqrdecode::BitArray;

MultiFormatUPCEANReader::MultiFormatUPCEANReader(DecodeHints hints) : readers() {
  if (hints.containsFormat(BarcodeFormat::EAN_13)) {
    readers.push_back(Ref<UPCEANReader>(new EAN13Reader()));
  } else if (hints.containsFormat(BarcodeFormat::UPC_A)) {
    readers.push_back(Ref<UPCEANReader>(new UPCAReader()));
  }
  if (hints.containsFormat(BarcodeFormat::EAN_8)) {
    readers.push_back(Ref<UPCEANReader>(new EAN8Reader()));
  }
  if (hints.containsFormat(BarcodeFormat::UPC_E)) {
    readers.push_back(Ref<UPCEANReader>(new UPCEReader()));
  }
  if (readers.size() == 0) {
    readers.push_back(Ref<UPCEANReader>(new EAN13Reader()));
    // UPC-A is covered by EAN-13
    readers.push_back(Ref<UPCEANReader>(new EAN8Reader()));
    readers.push_back(Ref<UPCEANReader>(new UPCEReader()));
  }
}

#include <typeinfo>

Ref<Result> MultiFormatUPCEANReader::decodeRow(int rowNumber, Ref<BitArray> row) {
  // Compute this location once and reuse it on multiple implementations
  UPCEANReader::Range startGuardPattern = UPCEANReader::findStartGuardPattern(row);
  for (int i = 0, e = readers.size(); i < e; i++) {
    Ref<UPCEANReader> reader = readers[i];
    Ref<Result> result;
    try {
      result = reader->decodeRow(rowNumber, row, startGuardPattern);
    } catch (ReaderException const& ignored) {
      (void)ignored;
      continue;
    }

    // Special case: a 12-digit code encoded in UPC-A is identical
    // to a "0" followed by those 12 digits encoded as EAN-13. Each
    // will recognize such a code, UPC-A as a 12-digit string and
    // EAN-13 as a 13-digit string starting with "0".  Individually
    // these are correct and their readers will both read such a
    // code and correctly call it EAN-13, or UPC-A, respectively.
    //
    // In this case, if we've been looking for both types, we'd like
    // to call it a UPC-A code. But for efficiency we only run the
    // EAN-13 decoder to also read UPC-A. So we special case it
    // here, and convert an EAN-13 result to a UPC-A result if
    // appropriate.
    bool ean13MayBeUPCA =
      result->getBarcodeFormat() == BarcodeFormat::EAN_13 &&
      result->getText()->charAt(0) == '0';

    // Note: doesn't match Java which uses hints

    bool canReturnUPCA = true;

    if (ean13MayBeUPCA && canReturnUPCA) {
      // Transfer the metdata across
      Ref<Result> resultUPCA (new Result(result->getText()->substring(1),
                                         result->getRawBytes(),
                                         result->getResultPoints(),
                                         BarcodeFormat::UPC_A));
      // needs java metadata stuff
      return resultUPCA;
    }
    return result;
  }

  throw NotFoundException();
}
