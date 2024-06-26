

#include <zqrdecode/multi/qrcode/QRCodeMultiReader.h>
#include <zqrdecode/ReaderException.h>
#include <zqrdecode/multi/qrcode/detector/MultiDetector.h>
#include <zqrdecode/BarcodeFormat.h>

namespace zqrdecode {
namespace multi {
QRCodeMultiReader::QRCodeMultiReader(){}

QRCodeMultiReader::~QRCodeMultiReader(){}

std::vector<Ref<Result> > QRCodeMultiReader::decodeMultiple(Ref<BinaryBitmap> image, 
  DecodeHints hints)
{
  std::vector<Ref<Result> > results;
  MultiDetector detector(image->getBlackMatrix());

  std::vector<Ref<DetectorResult> > detectorResult =  detector.detectMulti(hints);
  for (unsigned int i = 0; i < detectorResult.size(); i++) {
    try {
      Ref<DecoderResult> decoderResult = getDecoder().decode(detectorResult[i]->getBits());
      ArrayRef< Ref<ResultPoint> > points = detectorResult[i]->getPoints();
      Ref<Result> result = Ref<Result>(new Result(decoderResult->getText(),
      decoderResult->getRawBytes(), 
      points, BarcodeFormat::QR_CODE));
      // result->putMetadata(ResultMetadataType.BYTE_SEGMENTS, decoderResult->getByteSegments());
      // result->putMetadata(ResultMetadataType.ERROR_CORRECTION_LEVEL, decoderResult->getECLevel().toString());
      results.push_back(result);
    } catch (ReaderException const& re) {
      (void)re;
      // ignore and continue 
    }
  }
  if (results.empty()){
    throw ReaderException("No code detected");
  }
  return results;
}

} // End zqrdecode::multi namespace
} // End zqrdecode namespace
