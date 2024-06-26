

#include <zqrdecode/multi/qrcode/detector/MultiDetector.h>
#include <zqrdecode/multi/qrcode/detector/MultiFinderPatternFinder.h>
#include <zqrdecode/ReaderException.h>

namespace zqrdecode {
namespace multi {
using namespace zqrdecode::qrcode;

MultiDetector::MultiDetector(Ref<BitMatrix> image) : Detector(image) {}

MultiDetector::~MultiDetector(){}

std::vector<Ref<DetectorResult> > MultiDetector::detectMulti(DecodeHints hints){
  Ref<BitMatrix> image = getImage();
  MultiFinderPatternFinder finder = MultiFinderPatternFinder(image, hints.getResultPointCallback());
  std::vector<Ref<FinderPatternInfo> > info = finder.findMulti(hints);
  std::vector<Ref<DetectorResult> > result;
  for(unsigned int i = 0; i < info.size(); i++){
    try{
      result.push_back(processFinderPatternInfo(info[i]));
    } catch (ReaderException const& e){
      (void)e;
      // ignore
    }
  }

  return result;
}

} // End zqrdecode::multi namespace
} // End zqrdecode namespace
