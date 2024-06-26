#ifndef __CORNER_FINDER_H__
#define __CORNER_FINDER_H__

/*
 *  CornerPoint.h
 *  zqrdecode
 *
 */

#include <zqrdecode/ResultPoint.h>
#include <cmath>

namespace zqrdecode {
	namespace datamatrix {
			
		class CornerPoint : public ResultPoint {
		private:
			int counter_;
			
		public:
			CornerPoint(float posX, float posY);
			int getCount() const;
			void incrementCount();
			bool equals(Ref<CornerPoint> other) const;
		};
	}
}

#endif // __CORNER_FINDER_H__
