// -*- mode:c++; tab-width:2; indent-tabs-mode:nil; c-basic-offset:2 -*-
/*
 *  QRCodeReader.cpp
 *  zqrdecode
 *
 */

#include <zqrdecode/qrcode/QRCodeReader.h>
#include <zqrdecode/qrcode/detector/Detector.h>

#include <iostream>

namespace zqrdecode {
	namespace qrcode {
		
		using namespace std;
		
		QRCodeReader::QRCodeReader() :decoder_() {
		}
        //TODO : see if any of the other files in the qrcode tree need tryHarder
		Ref<Result> QRCodeReader::decode(Ref<BinaryBitmap> image, DecodeHints hints) {
			Detector detector(image->getBlackMatrix());
			Ref<DetectorResult> detectorResult(detector.detect(hints));
			ArrayRef< Ref<ResultPoint> > points (detectorResult->getPoints());
			Ref<DecoderResult> decoderResult(decoder_.decode(detectorResult->getBits()));
			Ref<Result> result(
                               new Result(decoderResult->getText(), decoderResult->getRawBytes(), points, BarcodeFormat::QR_CODE, decoderResult->charSet()));
			return result;
		}
		
		QRCodeReader::~QRCodeReader() {
		}
		
    Decoder& QRCodeReader::getDecoder() {
        return decoder_;
    }
	}
}
