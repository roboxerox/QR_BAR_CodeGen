// -*- mode:c++; tab-width:2; indent-tabs-mode:nil; c-basic-offset:2 -*-
#ifndef __FINDER_PATTERN_H__
#define __FINDER_PATTERN_H__

/*
 *  FinderPattern.h
 *  zqrdecode
 *
 */

#include <zqrdecode/ResultPoint.h>
#include <cmath>

namespace zqrdecode {
	namespace qrcode {
		
		class FinderPattern : public ResultPoint {
		private:
			float estimatedModuleSize_;
			int count_;
			
			FinderPattern(float posX, float posY, float estimatedModuleSize, int count);

		public:
			FinderPattern(float posX, float posY, float estimatedModuleSize);
			int getCount() const;
			float getEstimatedModuleSize() const;
			void incrementCount();
			bool aboutEquals(float moduleSize, float i, float j) const;
			Ref<FinderPattern> combineEstimate(float i, float j, float newModuleSize) const;
		};
	}
}

#endif // __FINDER_PATTERN_H__
