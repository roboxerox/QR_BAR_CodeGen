#ifndef __MULTI_DETECTOR_H__
#define __MULTI_DETECTOR_H__


#include <zqrdecode/qrcode/detector/Detector.h>
#include <zqrdecode/common/DetectorResult.h>
#include <zqrdecode/DecodeHints.h>

namespace zqrdecode {
namespace multi {

class MultiDetector : public zqrdecode::qrcode::Detector {
  public:
    MultiDetector(Ref<BitMatrix> image);
    virtual ~MultiDetector();
    virtual std::vector<Ref<DetectorResult> > detectMulti(DecodeHints hints);
};

}
}

#endif // __MULTI_DETECTOR_H__
