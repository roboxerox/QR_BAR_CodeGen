// -*- mode:c++; tab-width:2; indent-tabs-mode:nil; c-basic-offset:2 -*-

#ifndef __ALIGNMENT_PATTERN_H__
#define __ALIGNMENT_PATTERN_H__

/*
 *  AlignmentPattern.h
 *  zqrdecode
 *
 */

#include <zqrdecode/ResultPoint.h>
#include <cmath>

namespace zqrdecode {
	namespace qrcode {
		
		class AlignmentPattern : public ResultPoint {
		private:
			float estimatedModuleSize_;
			
		public:
			AlignmentPattern(float posX, float posY, float estimatedModuleSize);
			bool aboutEquals(float moduleSize, float i, float j) const;
      Ref<AlignmentPattern> combineEstimate(float i, float j,
                                            float newModuleSize) const;
		};
		
	}
}

#endif // __ALIGNMENT_PATTERN_H__
