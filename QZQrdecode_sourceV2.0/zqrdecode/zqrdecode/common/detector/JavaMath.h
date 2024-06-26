// -*- mode:c++; tab-width:2; indent-tabs-mode:nil; c-basic-offset:2 -*-
#ifndef __ZQRDECODE_COMMON_DETECTOR_MATH_H__
#define __ZQRDECODE_COMMON_DETECTOR_MATH_H__


#include <cmath>

namespace zqrdecode {
namespace common {
namespace detector {

class Math {
 private:
  Math();
  ~Math();
 public:

  // Java standard Math.round
  static inline int round(float a) {
    return (int)std::floor(a +0.5f);
  }

};

}
}
}

#endif
