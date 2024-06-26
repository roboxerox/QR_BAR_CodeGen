// -*- mode:c++; tab-width:2; indent-tabs-mode:nil; c-basic-offset:2 -*-

#ifndef __DECODED_BIT_STREAM_PARSER_H__
#define __DECODED_BIT_STREAM_PARSER_H__

/*
 *  DecodedBitStreamParser.h
 *  zqrdecode
 *
 */

#include <string>
#include <sstream>
#include <map>
#include <zqrdecode/qrcode/decoder/Mode.h>
#include <zqrdecode/common/BitSource.h>
#include <zqrdecode/common/Counted.h>
#include <zqrdecode/common/Array.h>
#include <zqrdecode/common/DecoderResult.h>
#include <zqrdecode/common/CharacterSetECI.h>
#include <zqrdecode/DecodeHints.h>

namespace zqrdecode {
namespace qrcode {

class DecodedBitStreamParser {
public:
  typedef std::map<DecodeHintType, std::string> Hashtable;

private:
  static char const ALPHANUMERIC_CHARS[];
  static char toAlphaNumericChar(size_t value);

  static void decodeHanziSegment(Ref<BitSource> bits, std::string &result, int count);
  static void decodeKanjiSegment(Ref<BitSource> bits, std::string &result, int count);
  static void decodeByteSegment(Ref<BitSource> bits, std::string &result, int count);
  static std::string decodeByteSegment(Ref<BitSource> bits_,
                                std::string& result,
                                int count,
                                zqrdecode::common::CharacterSetECI* currentCharacterSetECI,
                                ArrayRef< ArrayRef<char> >& byteSegments,
                                Hashtable const& hints);
  static void decodeAlphanumericSegment(Ref<BitSource> bits, std::string &result, int count, bool fc1InEffect);
  static void decodeNumericSegment(Ref<BitSource> bits, std::string &result, int count);

  static void append(std::string &ost, const char *bufIn, size_t nIn, const char *src);
  static void append(std::string &ost, std::string const& in, const char *src);

public:
  static Ref<DecoderResult> decode(ArrayRef<char> bytes,
                                   Version *version,
                                   ErrorCorrectionLevel const& ecLevel,
                                   Hashtable const& hints);
};

}
}

#endif // __DECODED_BIT_STREAM_PARSER_H__
