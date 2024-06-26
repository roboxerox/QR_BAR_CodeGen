#ifndef __RESULT_H__
#define __RESULT_H__

/*
 *  Result.h
 *  zqrdecode
 *
 */

#include <string>
#include <zqrdecode/common/Array.h>
#include <zqrdecode/common/Counted.h>
#include <zqrdecode/common/Str.h>
#include <zqrdecode/ResultPoint.h>
#include <zqrdecode/BarcodeFormat.h>

namespace zqrdecode {

class Result : public Counted {
private:
  Ref<String> text_;
  ArrayRef<char> rawBytes_;
  ArrayRef< Ref<ResultPoint> > resultPoints_;
  BarcodeFormat format_;
  std::string charSet_;

public:
  Result(Ref<String> text,
         ArrayRef<char> rawBytes,
         ArrayRef< Ref<ResultPoint> > resultPoints,
         BarcodeFormat format, std::string charSet = "");
  ~Result();
  Ref<String> getText();
  ArrayRef<char> getRawBytes();
  ArrayRef< Ref<ResultPoint> > const& getResultPoints() const;
  ArrayRef< Ref<ResultPoint> >& getResultPoints();
  BarcodeFormat getBarcodeFormat() const;
  std::string getCharSet() const;

  friend std::ostream& operator<<(std::ostream &out, Result& result);
};

}
#endif // __RESULT_H__
