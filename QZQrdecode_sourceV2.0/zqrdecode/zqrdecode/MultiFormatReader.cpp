// -*- mode:c++; tab-width:2; indent-tabs-mode:nil; c-basic-offset:2 -*-


#include <zqrdecode/ZQrdecode.h>
#include <zqrdecode/MultiFormatReader.h>
#include <zqrdecode/qrcode/QRCodeReader.h>
#include <zqrdecode/datamatrix/DataMatrixReader.h>
#include <zqrdecode/aztec/AztecReader.h>
#include <zqrdecode/pdf417/PDF417Reader.h>
#include <zqrdecode/oned/MultiFormatUPCEANReader.h>
#include <zqrdecode/oned/MultiFormatOneDReader.h>
#include <zqrdecode/ReaderException.h>

using zqrdecode::Ref;
using zqrdecode::Result;
using zqrdecode::MultiFormatReader;

// VC++
using zqrdecode::DecodeHints;
using zqrdecode::BinaryBitmap;

MultiFormatReader::MultiFormatReader() {}
  
Ref<Result> MultiFormatReader::decode(Ref<BinaryBitmap> image) {
  setHints(DecodeHints::DEFAULT_HINT);
  return decodeInternal(image);
}

Ref<Result> MultiFormatReader::decode(Ref<BinaryBitmap> image, DecodeHints hints) {
  setHints(hints);
  return decodeInternal(image);
}

Ref<Result> MultiFormatReader::decodeWithState(Ref<BinaryBitmap> image) {
  // Make sure to set up the default state so we don't crash
  if (readers_.size() == 0) {
    setHints(DecodeHints::DEFAULT_HINT);
  }
  return decodeInternal(image);
}

void MultiFormatReader::setHints(DecodeHints hints) {
  hints_ = hints;
  readers_.clear();
  bool tryHarder = hints.getTryHarder();

  bool addOneDReader = hints.containsFormat(BarcodeFormat::UPC_E) ||
    hints.containsFormat(BarcodeFormat::UPC_A) ||
    hints.containsFormat(BarcodeFormat::UPC_E) ||
    hints.containsFormat(BarcodeFormat::EAN_13) ||
    hints.containsFormat(BarcodeFormat::EAN_8) ||
    hints.containsFormat(BarcodeFormat::CODABAR) ||
    hints.containsFormat(BarcodeFormat::CODE_39) ||
    hints.containsFormat(BarcodeFormat::CODE_93) ||
    hints.containsFormat(BarcodeFormat::CODE_128) ||
    hints.containsFormat(BarcodeFormat::ITF) ||
    hints.containsFormat(BarcodeFormat::RSS_14) ||
    hints.containsFormat(BarcodeFormat::RSS_EXPANDED);
  if (addOneDReader && !tryHarder) {
    readers_.push_back(Ref<Reader>(new zqrdecode::oned::MultiFormatOneDReader(hints)));
  }
  if (hints.containsFormat(BarcodeFormat::QR_CODE)) {
    readers_.push_back(Ref<Reader>(new zqrdecode::qrcode::QRCodeReader()));
  }
  if (hints.containsFormat(BarcodeFormat::DATA_MATRIX)) {
    readers_.push_back(Ref<Reader>(new zqrdecode::datamatrix::DataMatrixReader()));
  }
  if (hints.containsFormat(BarcodeFormat::AZTEC)) {
    readers_.push_back(Ref<Reader>(new zqrdecode::aztec::AztecReader()));
  }
  if (hints.containsFormat(BarcodeFormat::PDF_417)) {
    readers_.push_back(Ref<Reader>(new zqrdecode::pdf417::PDF417Reader()));
  }
  /*
  if (hints.contains(BarcodeFormat.MAXICODE)) {
    readers.add(new MaxiCodeReader());
  }
  */
  if (addOneDReader && tryHarder) {
    readers_.push_back(Ref<Reader>(new zqrdecode::oned::MultiFormatOneDReader(hints)));
  }
  if (readers_.size() == 0) {
    if (!tryHarder) {
      readers_.push_back(Ref<Reader>(new zqrdecode::oned::MultiFormatOneDReader(hints)));
    }
    readers_.push_back(Ref<Reader>(new zqrdecode::qrcode::QRCodeReader()));
    readers_.push_back(Ref<Reader>(new zqrdecode::datamatrix::DataMatrixReader()));
    readers_.push_back(Ref<Reader>(new zqrdecode::aztec::AztecReader()));
    readers_.push_back(Ref<Reader>(new zqrdecode::pdf417::PDF417Reader()));
    // readers.add(new MaxiCodeReader());

    if (tryHarder) {
      readers_.push_back(Ref<Reader>(new zqrdecode::oned::MultiFormatOneDReader(hints)));
    }
  }
}

Ref<Result> MultiFormatReader::decodeInternal(Ref<BinaryBitmap> image) {
  for (unsigned int i = 0; i < readers_.size(); i++) {
    try {
      return readers_[i]->decode(image, hints_);
    } catch (ReaderException const& re) {
      (void)re;
      // continue
    }
  }
  throw ReaderException("No code detected");
}
  
MultiFormatReader::~MultiFormatReader() {}
