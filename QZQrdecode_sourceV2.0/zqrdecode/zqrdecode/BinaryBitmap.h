#ifndef __BINARYBITMAP_H__
#define __BINARYBITMAP_H__

/*
 *  BinaryBitmap.h
 *  zqrdecode
 *
 */

#include <zqrdecode/common/Counted.h>
#include <zqrdecode/common/BitMatrix.h>
#include <zqrdecode/common/BitArray.h>
#include <zqrdecode/Binarizer.h>

namespace zqrdecode {
	
	class BinaryBitmap : public Counted {
	private:
		Ref<Binarizer> binarizer_;
		
	public:
		BinaryBitmap(Ref<Binarizer> binarizer);
		virtual ~BinaryBitmap();
		
		Ref<BitArray> getBlackRow(int y, Ref<BitArray> row);
		Ref<BitMatrix> getBlackMatrix();
		
		Ref<LuminanceSource> getLuminanceSource() const;

		int getWidth() const;
		int getHeight() const;

		bool isRotateSupported() const;
		Ref<BinaryBitmap> rotateCounterClockwise();

		bool isCropSupported() const;
		Ref<BinaryBitmap> crop(int left, int top, int width, int height);

	};
	
}

#endif /* BINARYBITMAP_H_ */
