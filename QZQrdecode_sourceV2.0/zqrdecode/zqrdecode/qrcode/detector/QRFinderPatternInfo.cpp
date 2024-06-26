/*
 *  FinderPatternInfo.cpp
 *  zqrdecode
 *
 */

#include <zqrdecode/qrcode/detector/FinderPatternInfo.h>

namespace zqrdecode {
namespace qrcode {

FinderPatternInfo::FinderPatternInfo(std::vector<Ref<FinderPattern> > patternCenters) :
    bottomLeft_(patternCenters[0]), topLeft_(patternCenters[1]), topRight_(patternCenters[2]) {
}

Ref<FinderPattern> FinderPatternInfo::getBottomLeft() {
  return bottomLeft_;
}
Ref<FinderPattern> FinderPatternInfo::getTopLeft() {
  return topLeft_;
}
Ref<FinderPattern> FinderPatternInfo::getTopRight() {
  return topRight_;
}

}
}
