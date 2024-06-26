// -*- mode:c++; tab-width:2; indent-tabs-mode:nil; c-basic-offset:2 -*-
/*
 *  DataMatrixReader.cpp
 *  zqrdecode
 *
 */

#include <zqrdecode/datamatrix/DataMatrixReader.h>
#include <zqrdecode/datamatrix/detector/Detector.h>
#include <iostream>

namespace zqrdecode {
namespace datamatrix {

using namespace std;

DataMatrixReader::DataMatrixReader() :
    decoder_() {
}

Ref<Result> DataMatrixReader::decode(Ref<BinaryBitmap> image, DecodeHints hints) {
  (void)hints;
  Detector detector(image->getBlackMatrix());
  Ref<DetectorResult> detectorResult(detector.detect());
  ArrayRef< Ref<ResultPoint> > points(detectorResult->getPoints());


  Ref<DecoderResult> decoderResult(decoder_.decode(detectorResult->getBits()));

  Ref<Result> result(
    new Result(decoderResult->getText(), decoderResult->getRawBytes(), points, BarcodeFormat::DATA_MATRIX));

  return result;
}

DataMatrixReader::~DataMatrixReader() {
}

}
}
