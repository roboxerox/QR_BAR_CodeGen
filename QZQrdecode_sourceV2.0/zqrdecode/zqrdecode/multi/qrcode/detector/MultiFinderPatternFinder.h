#ifndef __MULTI_FINDER_PATTERN_FINDER_H__
#define __MULTI_FINDER_PATTERN_FINDER_H__



#include <zqrdecode/qrcode/detector/FinderPattern.h>
#include <zqrdecode/qrcode/detector/FinderPatternFinder.h>
#include <zqrdecode/qrcode/detector/FinderPatternInfo.h>

namespace zqrdecode {
namespace multi {

class MultiFinderPatternFinder : zqrdecode::qrcode::FinderPatternFinder {
  private:
    std::vector<std::vector<Ref<zqrdecode::qrcode::FinderPattern> > > selectBestPatterns();

    static const float MAX_MODULE_COUNT_PER_EDGE;
    static const float MIN_MODULE_COUNT_PER_EDGE;
    static const float DIFF_MODSIZE_CUTOFF_PERCENT;
    static const float DIFF_MODSIZE_CUTOFF;

  public:
    MultiFinderPatternFinder(Ref<BitMatrix> image, Ref<ResultPointCallback> resultPointCallback);
    virtual ~MultiFinderPatternFinder();
    virtual std::vector<Ref<zqrdecode::qrcode::FinderPatternInfo> > findMulti(DecodeHints const& hints);


};

}
}

#endif // __MULTI_FINDER_PATTERN_FINDER_H__
