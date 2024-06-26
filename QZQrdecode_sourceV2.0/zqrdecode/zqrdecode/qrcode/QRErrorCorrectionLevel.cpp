// -*- mode:c++; tab-width:2; indent-tabs-mode:nil; c-basic-offset:2 -*-
/*
 *  ErrorCorrectionLevel.cpp
 *  zqrdecode
 *
 */

#include <zqrdecode/qrcode/ErrorCorrectionLevel.h>

using std::string;

namespace zqrdecode {
namespace qrcode {

ErrorCorrectionLevel::ErrorCorrectionLevel(int inOrdinal,
                                           int bits,
                                           char const* name) :
    ordinal_(inOrdinal), bits_(bits), name_(name)
{}

ErrorCorrectionLevel::ErrorCorrectionLevel(const ErrorCorrectionLevel &other) :
    ordinal_(other.ordinal()), bits_(other.bits()), name_(other.name())
{}

int ErrorCorrectionLevel::ordinal() const {
  return ordinal_;
}

int ErrorCorrectionLevel::bits() const {
  return bits_;
}

string const& ErrorCorrectionLevel::name() const {
  return name_;
}

ErrorCorrectionLevel::operator string const& () const {
  return name_;
}

ErrorCorrectionLevel& ErrorCorrectionLevel::forBits(int bits) {
  if (bits < 0 || bits >= N_LEVELS) {
    throw ReaderException("Ellegal error correction level bits");
  }
  return *FOR_BITS[bits];
}

  ErrorCorrectionLevel ErrorCorrectionLevel::L(0, 0x01, "L");
  ErrorCorrectionLevel ErrorCorrectionLevel::M(1, 0x00, "M");
  ErrorCorrectionLevel ErrorCorrectionLevel::Q(2, 0x03, "Q");
  ErrorCorrectionLevel ErrorCorrectionLevel::H(3, 0x02, "H");
ErrorCorrectionLevel *ErrorCorrectionLevel::FOR_BITS[] = { &M, &L, &H, &Q };
int ErrorCorrectionLevel::N_LEVELS = 4;

}
}
