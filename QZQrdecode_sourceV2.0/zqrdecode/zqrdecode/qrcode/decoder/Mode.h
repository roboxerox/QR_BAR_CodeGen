// -*- mode:c++; tab-width:2; indent-tabs-mode:nil; c-basic-offset:2 -*-
#ifndef __MODE_H__
#define __MODE_H__

/*
 *  Mode.h
 *  zqrdecode
 *
 */

#include <zqrdecode/common/Counted.h>
#include <zqrdecode/qrcode/Version.h>
#include <zqrdecode/common/Counted.h>

namespace zqrdecode {
namespace qrcode {

class Mode : public Counted
{
private:
  int characterCountBitsForVersions0To9_;
  int characterCountBitsForVersions10To26_;
  int characterCountBitsForVersions27AndHigher_;
  int bits_;
  std::string name_;

  Mode(int cbv0_9, int cbv10_26, int cbv27, int bits, char const* name);

public:
  Mode(const Mode& mode);
  Mode();

  static Mode TERMINATOR;
  static Mode NUMERIC;
  static Mode ALPHANUMERIC;
  static Mode STRUCTURED_APPEND;
  static Mode BYTE;
  static Mode ECI;
  static Mode KANJI;
  static Mode FNC1_FIRST_POSITION;
  static Mode FNC1_SECOND_POSITION;
  static Mode HANZI;

  static Mode& forBits(int bits);
  int getCharacterCountBits(const Version *version) const;
  int getBits() const { return bits_; }

  bool operator==(const Mode& other);

  std::string getName() const { return name_; }
};
}
}

#endif // __MODE_H__
