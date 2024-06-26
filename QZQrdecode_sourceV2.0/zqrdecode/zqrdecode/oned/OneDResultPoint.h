#ifndef __ONED_RESULT_POINT_H__
#define __ONED_RESULT_POINT_H__
/*
 *  OneDResultPoint.h
 *  zqrdecode
 *
 */
#include <zqrdecode/ResultPoint.h>
#include <cmath>

namespace zqrdecode {
	namespace oned {
		
		class OneDResultPoint : public ResultPoint {
			
		public:
			OneDResultPoint(float posX, float posY);
		};
	}
}

#endif
