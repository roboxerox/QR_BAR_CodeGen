#ifndef BINARIZER_H_
#define BINARIZER_H_

/*
 *  Binarizer.h
 *  zqrdecode
 *
 */

#include <zqrdecode/LuminanceSource.h>
#include <zqrdecode/common/BitArray.h>
#include <zqrdecode/common/BitMatrix.h>
#include <zqrdecode/common/Counted.h>

namespace zqrdecode {

class Binarizer : public Counted {
 private:
  Ref<LuminanceSource> source_;

 public:
  Binarizer(Ref<LuminanceSource> source);
  virtual ~Binarizer();

  virtual Ref<BitArray> getBlackRow(int y, Ref<BitArray> row) = 0;
  virtual Ref<BitMatrix> getBlackMatrix() = 0;

  Ref<LuminanceSource> getLuminanceSource() const ;
  virtual Ref<Binarizer> createBinarizer(Ref<LuminanceSource> source) = 0;

  int getWidth() const;
  int getHeight() const;

};

}
#endif /* BINARIZER_H_ */
