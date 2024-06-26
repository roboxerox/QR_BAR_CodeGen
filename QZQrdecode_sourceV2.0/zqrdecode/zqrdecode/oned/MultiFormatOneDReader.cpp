

#include <zqrdecode/ZQrdecode.h>
#include <zqrdecode/oned/MultiFormatOneDReader.h>
#include <zqrdecode/oned/MultiFormatUPCEANReader.h>
#include <zqrdecode/oned/Code39Reader.h>
#include <zqrdecode/oned/Code128Reader.h>
#include <zqrdecode/oned/Code93Reader.h>
#include <zqrdecode/oned/CodaBarReader.h>
#include <zqrdecode/oned/ITFReader.h>
#include <zqrdecode/ReaderException.h>
#include <zqrdecode/NotFoundException.h>

using zqrdecode::Ref;
using zqrdecode::Result;
using zqrdecode::oned::MultiFormatOneDReader;

// VC++
using zqrdecode::DecodeHints;
using zqrdecode::BitArray;

MultiFormatOneDReader::MultiFormatOneDReader(DecodeHints hints) : readers() {
  if (hints.containsFormat(BarcodeFormat::EAN_13) ||
      hints.containsFormat(BarcodeFormat::EAN_8) ||
      hints.containsFormat(BarcodeFormat::UPC_A) ||
      hints.containsFormat(BarcodeFormat::UPC_E)) {
    readers.push_back(Ref<OneDReader>(new MultiFormatUPCEANReader(hints)));
  }
  if (hints.containsFormat(BarcodeFormat::CODE_39)) {
    readers.push_back(Ref<OneDReader>(new Code39Reader()));
  }
  if (hints.containsFormat(BarcodeFormat::CODE_93)) {
    readers.push_back(Ref<OneDReader>(new Code93Reader()));
  }
  if (hints.containsFormat(BarcodeFormat::CODE_128)) {
    readers.push_back(Ref<OneDReader>(new Code128Reader()));
  }
  if (hints.containsFormat(BarcodeFormat::ITF)) {
    readers.push_back(Ref<OneDReader>(new ITFReader()));
  }
  if (hints.containsFormat(BarcodeFormat::CODABAR)) {
    readers.push_back(Ref<OneDReader>(new CodaBarReader()));
  }
/*
  if (hints.containsFormat(BarcodeFormat::RSS_14)) {
    readers.push_back(Ref<OneDReader>(new RSS14Reader()));
  }
*/
/*
  if (hints.containsFormat(BarcodeFormat::RSS_EXPANDED)) {
    readers.push_back(Ref<OneDReader>(new RSS14ExpandedReader()));
  }
*/
  if (readers.size() == 0) {
    readers.push_back(Ref<OneDReader>(new MultiFormatUPCEANReader(hints)));
    readers.push_back(Ref<OneDReader>(new Code39Reader()));
    readers.push_back(Ref<OneDReader>(new CodaBarReader()));
    readers.push_back(Ref<OneDReader>(new Code93Reader()));
    readers.push_back(Ref<OneDReader>(new Code128Reader()));
    readers.push_back(Ref<OneDReader>(new ITFReader()));
    // readers.push_back(Ref<OneDReader>(new RSS14Reader()));
    // readers.push_back(Ref<OneDReader>(new RSS14ExpandedReader()));
  }
}

#include <typeinfo>

Ref<Result> MultiFormatOneDReader::decodeRow(int rowNumber, Ref<BitArray> row) {
  int size = readers.size();
  for (int i = 0; i < size; i++) {
    OneDReader* reader = readers[i];
    try {
      Ref<Result> result = reader->decodeRow(rowNumber, row);
      return result;
    } catch (ReaderException const& re) {
      (void)re;
      // continue
    }
  }
  throw NotFoundException();
}
