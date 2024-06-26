// -*- mode:c++; tab-width:2; indent-tabs-mode:nil; c-basic-offset:2 -*-
#ifndef __GLOBALHISTOGRAMBINARIZER_H__
#define __GLOBALHISTOGRAMBINARIZER_H__
/*
 *  GlobalHistogramBinarizer.h
 *  zqrdecode
 *
 */

#include <zqrdecode/Binarizer.h>
#include <zqrdecode/common/BitArray.h>
#include <zqrdecode/common/BitMatrix.h>
#include <zqrdecode/common/Array.h>

namespace zqrdecode {
	
class GlobalHistogramBinarizer : public Binarizer {
private:
  ArrayRef<char> luminances;
  ArrayRef<int> buckets;
public:
  GlobalHistogramBinarizer(Ref<LuminanceSource> source);
  virtual ~GlobalHistogramBinarizer();
		
  virtual Ref<BitArray> getBlackRow(int y, Ref<BitArray> row);
  virtual Ref<BitMatrix> getBlackMatrix();
  static int estimateBlackPoint(ArrayRef<int> const& buckets);
  Ref<Binarizer> createBinarizer(Ref<LuminanceSource> source);
private:
  void initArrays(int luminanceSize);
};

}
	
#endif /* GLOBALHISTOGRAMBINARIZER_H_ */
