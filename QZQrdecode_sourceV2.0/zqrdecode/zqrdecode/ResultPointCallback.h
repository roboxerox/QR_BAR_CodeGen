#ifndef __RESULT_POINT_CALLBACK_H__
#define __RESULT_POINT_CALLBACK_H__

/*
 *  ResultPointCallback.h
 *  zqrdecode
 *
 */

#include <zqrdecode/common/Counted.h>

namespace zqrdecode {

class ResultPoint;

class ResultPointCallback : public Counted {
protected:
  ResultPointCallback() {}
public:
  virtual void foundPossibleResultPoint(ResultPoint const& point) = 0;
  virtual ~ResultPointCallback();
};

}

#endif // __RESULT_POINT_CALLBACK_H__
