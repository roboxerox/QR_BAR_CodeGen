// -*- mode:c++; tab-width:2; indent-tabs-mode:nil; c-basic-offset:2 -*-
/*
 *  Mode.cpp
 *  zqrdecode
 *
 */

#include <zqrdecode/ZQrdecode.h>
#include <zqrdecode/qrcode/decoder/Mode.h>
#include <zqrdecode/common/Counted.h>
#include <zqrdecode/ReaderException.h>
#include <zqrdecode/qrcode/Version.h>
#include <sstream>

using zqrdecode::qrcode::Mode;
using std::ostringstream;

// VC++
using zqrdecode::qrcode::Version;

Mode Mode::TERMINATOR(0, 0, 0, 0x00, "TERMINATOR");
Mode Mode::NUMERIC(10, 12, 14, 0x01, "NUMERIC");
Mode Mode::ALPHANUMERIC(9, 11, 13, 0x02, "ALPHANUMERIC");
Mode Mode::STRUCTURED_APPEND(0, 0, 0, 0x03, "STRUCTURED_APPEND");
Mode Mode::BYTE(8, 16, 16, 0x04, "BYTE");
Mode Mode::ECI(0, 0, 0, 0x07, "ECI");
Mode Mode::KANJI(8, 10, 12, 0x08, "KANJI");
Mode Mode::FNC1_FIRST_POSITION(0, 0, 0, 0x05, "FNC1_FIRST_POSITION");
Mode Mode::FNC1_SECOND_POSITION(0, 0, 0, 0x09, "FNC1_SECOND_POSITION");
Mode Mode::HANZI(8, 10, 12, 0x0D, "HANZI");

Mode::Mode() :
    characterCountBitsForVersions0To9_(0),
    characterCountBitsForVersions10To26_(0),
    characterCountBitsForVersions27AndHigher_(0),
    bits_(0),
    name_("")
{}

Mode::Mode(int cbv0_9, int cbv10_26, int cbv27, int bits, char const* name) :
    characterCountBitsForVersions0To9_(cbv0_9), characterCountBitsForVersions10To26_(cbv10_26),
    characterCountBitsForVersions27AndHigher_(cbv27), bits_(bits), name_(name)
{
}

Mode::Mode(const zqrdecode::qrcode::Mode &mode)
{
    characterCountBitsForVersions0To9_ = mode.characterCountBitsForVersions0To9_;
    characterCountBitsForVersions10To26_ = mode.characterCountBitsForVersions10To26_;
    characterCountBitsForVersions27AndHigher_ = mode.characterCountBitsForVersions27AndHigher_;
    bits_ = mode.bits_;
    name_ = mode.name_;
}

Mode& Mode::forBits(int bits) {
    switch (bits) {
    case 0x0:
        return TERMINATOR;
    case 0x1:
        return NUMERIC;
    case 0x2:
        return ALPHANUMERIC;
    case 0x3:
        return STRUCTURED_APPEND;
    case 0x4:
        return BYTE;
    case 0x5:
        return FNC1_FIRST_POSITION;
    case 0x7:
        return ECI;
    case 0x8:
        return KANJI;
    case 0x9:
        return FNC1_SECOND_POSITION;
    case 0xD:
        // 0xD is defined in GBT 18284-2000, may not be supported in foreign country
        return HANZI;
    default:
        ostringstream s;
        s << "Illegal mode bits: " << bits;
        throw ReaderException(s.str().c_str());
    }
}

int Mode::getCharacterCountBits(const Version *version) const
{
    int number = version->getVersionNumber();
    if (number <= 9) {
        return characterCountBitsForVersions0To9_;
    } else if (number <= 26) {
        return characterCountBitsForVersions10To26_;
    } else {
        return characterCountBitsForVersions27AndHigher_;
    }
}

bool Mode::operator==(const Mode& other)
{
    return ( characterCountBitsForVersions0To9_ == other.characterCountBitsForVersions0To9_
            && characterCountBitsForVersions10To26_ == other.characterCountBitsForVersions10To26_
            && characterCountBitsForVersions27AndHigher_ == other.characterCountBitsForVersions27AndHigher_
            && name_ == other.name_
            && bits_ == other.bits_ );
}
