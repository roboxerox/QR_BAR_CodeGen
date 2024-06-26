// -*- mode:c++; tab-width:2; indent-tabs-mode:nil; c-basic-offset:2 -*-
#ifndef __HYBRIDBINARIZER_H__
#define __HYBRIDBINARIZER_H__
/*
 *  HybridBinarizer.h
 *  zqrdecode
 *
 */

#include <vector>
#include <zqrdecode/Binarizer.h>
#include <zqrdecode/common/GlobalHistogramBinarizer.h>
#include <zqrdecode/common/BitArray.h>
#include <zqrdecode/common/BitMatrix.h>

namespace zqrdecode {
	
	class HybridBinarizer : public GlobalHistogramBinarizer {
	 private:
    Ref<BitMatrix> matrix_;
	  Ref<BitArray> cached_row_;

	public:
		HybridBinarizer(Ref<LuminanceSource> source);
		virtual ~HybridBinarizer();
		
		virtual Ref<BitMatrix> getBlackMatrix();
		Ref<Binarizer> createBinarizer(Ref<LuminanceSource> source);
  private:
    // We'll be using one-D arrays because C++ can't dynamically allocate 2D
    // arrays
    ArrayRef<int> calculateBlackPoints(ArrayRef<char> luminances,
                                       int subWidth,
                                       int subHeight,
                                       int width,
                                       int height);
    void calculateThresholdForBlock(ArrayRef<char> luminances,
                                    int subWidth,
                                    int subHeight,
                                    int width,
                                    int height,
                                    ArrayRef<int> blackPoints,
                                    Ref<BitMatrix> const& matrix);
    void thresholdBlock(ArrayRef<char>luminances,
                        int xoffset,
                        int yoffset,
                        int threshold,
                        int stride,
                        Ref<BitMatrix> const& matrix);
	};

}

#endif
