// -*- mode:c++; tab-width:2; indent-tabs-mode:nil; c-basic-offset:2 -*-
/*
 *  FinderPattern.cpp
 *  zqrdecode
 *
 */

#include <zqrdecode/qrcode/detector/FinderPattern.h>

using std::abs;
using zqrdecode::Ref;
using zqrdecode::qrcode::FinderPattern;

FinderPattern::FinderPattern(float posX, float posY, float estimatedModuleSize)
    : ResultPoint(posX,posY), estimatedModuleSize_(estimatedModuleSize), count_(1) {}
		
FinderPattern::FinderPattern(float posX, float posY, float estimatedModuleSize, int count)
    : ResultPoint(posX,posY), estimatedModuleSize_(estimatedModuleSize), count_(count) {}
		
int FinderPattern::getCount() const {
  return count_;
}
		
float FinderPattern::getEstimatedModuleSize() const {
  return estimatedModuleSize_;
}
		
void FinderPattern::incrementCount() {
  count_++;
  // cerr << "ic " << getX() << " " << getY() << " " << count_ << endl;
}
		
/*
  bool FinderPattern::aboutEquals(float moduleSize, float i, float j) const {
  return abs(i - posY_) <= moduleSize && abs(j - posX_) <= moduleSize && (abs(moduleSize - estimatedModuleSize_)
  <= 1.0f || abs(moduleSize - estimatedModuleSize_) / estimatedModuleSize_ <= 0.1f);
  }
*/
bool FinderPattern::aboutEquals(float moduleSize, float i, float j) const {
  if (abs(i - getY()) <= moduleSize && abs(j - getX()) <= moduleSize) {
    float moduleSizeDiff = abs(moduleSize - estimatedModuleSize_);
    return moduleSizeDiff <= 1.0f || moduleSizeDiff <= estimatedModuleSize_;
  }
  return false;
}
		
Ref<FinderPattern> FinderPattern::combineEstimate(float i, float j, float newModuleSize) const {
  // fprintf(stderr, "ce %f %f %f\n", i, j, newModuleSize);

  int combinedCount = count_ + 1;
  float combinedX = (count_ * getX() + j) / combinedCount;
  float combinedY = (count_ * getY() + i) / combinedCount;
  float combinedModuleSize = (count_ * getEstimatedModuleSize() + newModuleSize) / combinedCount;
  return Ref<FinderPattern>(new FinderPattern(combinedX, combinedY, combinedModuleSize, combinedCount));
}
