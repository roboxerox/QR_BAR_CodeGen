#ifndef __ERROR_CORRECTION_LEVEL_H__
#define __ERROR_CORRECTION_LEVEL_H__

/*
 *  ErrorCorrectionLevel.h
 *  zqrdecode
 *
 */

#include <zqrdecode/ReaderException.h>
#include <zqrdecode/common/Counted.h>

namespace zqrdecode {
namespace qrcode {

class ErrorCorrectionLevel : public Counted {
private:
  int ordinal_;
  int bits_;
  std::string name_;
  ErrorCorrectionLevel(int inOrdinal, int bits, char const* name);
  static ErrorCorrectionLevel *FOR_BITS[];
  static int N_LEVELS;
public:
  static ErrorCorrectionLevel L;
  static ErrorCorrectionLevel M;
  static ErrorCorrectionLevel Q;
  static ErrorCorrectionLevel H;

  ErrorCorrectionLevel(const ErrorCorrectionLevel& other);

  int ordinal() const;
  int bits() const;
  std::string const& name() const;
  operator std::string const& () const;

  static ErrorCorrectionLevel& forBits(int bits);
};
}
}

#endif // __ERROR_CORRECTION_LEVEL_H__
