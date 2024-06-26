#ifndef __FINDER_PATTERN_INFO_H__
#define __FINDER_PATTERN_INFO_H__

/*
 *  FinderPatternInfo.h
 *  zqrdecode
 *
 */

#include <zqrdecode/qrcode/detector/FinderPattern.h>
#include <zqrdecode/common/Counted.h>
#include <zqrdecode/common/Array.h>
#include <vector>

namespace zqrdecode {
namespace qrcode {

class FinderPatternInfo : public Counted {
private:
  Ref<FinderPattern> bottomLeft_;
  Ref<FinderPattern> topLeft_;
  Ref<FinderPattern> topRight_;

public:
  FinderPatternInfo(std::vector<Ref<FinderPattern> > patternCenters);

  Ref<FinderPattern> getBottomLeft();
  Ref<FinderPattern> getTopLeft();
  Ref<FinderPattern> getTopRight();
};
}
}

#endif // __FINDER_PATTERN_INFO_H__
