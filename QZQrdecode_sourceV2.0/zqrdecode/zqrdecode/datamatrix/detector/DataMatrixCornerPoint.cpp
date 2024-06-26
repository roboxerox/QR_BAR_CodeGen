/*
 *  CornerPoint.cpp
 *  zqrdecode
 *
 */

#include <zqrdecode/datamatrix/detector/CornerPoint.h>


namespace zqrdecode {
	namespace datamatrix {
		
		using namespace std;
		
		CornerPoint::CornerPoint(float posX, float posY) :
		  ResultPoint(posX,posY), counter_(0) {
		}
		
		int CornerPoint::getCount() const {
			return counter_;
		}
				
		void CornerPoint::incrementCount() {
			counter_++;
		}
		
		bool CornerPoint::equals(Ref<CornerPoint> other) const {
			return posX_ == other->getX() && posY_ == other->getY();
		}
		
	}
}
