#ifndef __FORMAT_INFORMATION_H__
#define __FORMAT_INFORMATION_H__

/*
 *  FormatInformation.h
 *  zqrdecode
 *
 */

#include <zqrdecode/qrcode/ErrorCorrectionLevel.h>
#include <zqrdecode/common/Counted.h>
#include <iostream>

namespace zqrdecode {
namespace qrcode {

class FormatInformation : public Counted {
private:
  static int FORMAT_INFO_MASK_QR;
  static int FORMAT_INFO_DECODE_LOOKUP[][2];
  static int N_FORMAT_INFO_DECODE_LOOKUPS;
  static int BITS_SET_IN_HALF_BYTE[];

  ErrorCorrectionLevel &errorCorrectionLevel_;
  char dataMask_;

  FormatInformation(int formatInfo);

public:
  static int numBitsDiffering(int a, int b);
  static Ref<FormatInformation> decodeFormatInformation(int maskedFormatInfo1, int maskedFormatInfo2);
  static Ref<FormatInformation> doDecodeFormatInformation(int maskedFormatInfo1, int maskedFormatInfo2);
  ErrorCorrectionLevel &getErrorCorrectionLevel();
  char getDataMask();
  friend bool operator==(const FormatInformation &a, const FormatInformation &b);
  friend std::ostream& operator<<(std::ostream& out, const FormatInformation& fi);
};
}
}

#endif // __FORMAT_INFORMATION_H__
