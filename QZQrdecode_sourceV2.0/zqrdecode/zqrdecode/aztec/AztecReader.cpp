// -*- mode:c++; tab-width:2; indent-tabs-mode:nil; c-basic-offset:2 -*-
/*
 *  AztecReader.cpp
 *  zqrdecode
 *
 */

#include <zqrdecode/aztec/AztecReader.h>
#include <zqrdecode/aztec/detector/Detector.h>
#include <zqrdecode/common/DecoderResult.h>
#include <iostream>

using zqrdecode::Ref;
using zqrdecode::ArrayRef;
using zqrdecode::Result;
using zqrdecode::aztec::AztecReader;

// VC++
using zqrdecode::BinaryBitmap;
using zqrdecode::DecodeHints;
        
AztecReader::AztecReader() : decoder_() {
  // nothing
}
        
Ref<Result> AztecReader::decode(Ref<zqrdecode::BinaryBitmap> image) {
  Detector detector(image->getBlackMatrix());
            
  Ref<AztecDetectorResult> detectorResult(detector.detect());
            
  ArrayRef< Ref<ResultPoint> > points(detectorResult->getPoints());
            
  Ref<DecoderResult> decoderResult(decoder_.decode(detectorResult));
            
  Ref<Result> result(new Result(decoderResult->getText(),
                                decoderResult->getRawBytes(),
                                points,
                                BarcodeFormat::AZTEC));
            
  return result;
}
        
Ref<Result> AztecReader::decode(Ref<BinaryBitmap> image, DecodeHints) {
  //cout << "decoding with hints not supported for aztec" << "\n" << flush;
  return this->decode(image);
}
        
AztecReader::~AztecReader() {
  // nothing
}
        
zqrdecode::aztec::Decoder& AztecReader::getDecoder() {
  return decoder_;
}
