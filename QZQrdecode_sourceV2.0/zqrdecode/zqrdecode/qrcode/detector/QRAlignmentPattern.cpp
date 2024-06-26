// -*- mode:c++; tab-width:2; indent-tabs-mode:nil; c-basic-offset:2 -*-
/*
 *  AlignmentPattern.cpp
 *  zqrdecode
 *
 */

#include <zqrdecode/qrcode/detector/AlignmentPattern.h>

using std::abs;
using zqrdecode::Ref;
using zqrdecode::qrcode::AlignmentPattern;

AlignmentPattern::AlignmentPattern(float posX, float posY, float estimatedModuleSize) :
    ResultPoint(posX,posY), estimatedModuleSize_(estimatedModuleSize) {
}

bool AlignmentPattern::aboutEquals(float moduleSize, float i, float j) const {
  if (abs(i - getY()) <= moduleSize && abs(j - getX()) <= moduleSize) {
    float moduleSizeDiff = abs(moduleSize - estimatedModuleSize_);
    return moduleSizeDiff <= 1.0f || moduleSizeDiff <= estimatedModuleSize_;
  }
  return false;
}

Ref<AlignmentPattern> AlignmentPattern::combineEstimate(float i, float j, float newModuleSize) const {
  float combinedX = (getX() + j) / 2.0f;
  float combinedY = (getY() + i) / 2.0f;
  float combinedModuleSize = (estimatedModuleSize_ + newModuleSize) / 2.0f;
  Ref<AlignmentPattern> result
      (new AlignmentPattern(combinedX, combinedY, combinedModuleSize));
  return result;
}
