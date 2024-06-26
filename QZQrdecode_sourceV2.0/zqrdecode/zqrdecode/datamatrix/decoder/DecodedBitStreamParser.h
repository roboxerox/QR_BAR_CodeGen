#ifndef __DECODED_BIT_STREAM_PARSER_DM_H__
#define __DECODED_BIT_STREAM_PARSER_DM_H__

/*
 *  DecodedBitStreamParser.h
 *  zqrdecode
 *
 */

#include <string>
#include <sstream>
#include <zqrdecode/common/Array.h>
#include <zqrdecode/common/BitSource.h>
#include <zqrdecode/common/Counted.h>
#include <zqrdecode/common/DecoderResult.h>


namespace zqrdecode {
namespace datamatrix {

class DecodedBitStreamParser {
private:
  static const int PAD_ENCODE = 0;  // Not really an encoding
  static const int ASCII_ENCODE = 1;
  static const int C40_ENCODE = 2;
  static const int TEXT_ENCODE = 3;
  static const int ANSIX12_ENCODE = 4;
  static const int EDIFACT_ENCODE = 5;
  static const int BASE256_ENCODE = 6;
    
  /**
   * See ISO 16022:2006, Annex C Table C.1
   * The C40 Basic Character Set (*'s used for placeholders for the shift values)
   */
  static const char C40_BASIC_SET_CHARS[];
  
  static const char C40_SHIFT2_SET_CHARS[];  
  /**
   * See ISO 16022:2006, Annex C Table C.2
   * The Text Basic Character Set (*'s used for placeholders for the shift values)
   */
  static const char TEXT_BASIC_SET_CHARS[];
  
  static const char TEXT_SHIFT3_SET_CHARS[];  
  /**
   * See ISO 16022:2006, 5.2.3 and Annex C, Table C.2
   */
  int decodeAsciiSegment(Ref<BitSource> bits, std::ostringstream &result, std::ostringstream &resultTrailer);
  /**
   * See ISO 16022:2006, 5.2.5 and Annex C, Table C.1
   */
  void decodeC40Segment(Ref<BitSource> bits, std::ostringstream &result);
  /**
   * See ISO 16022:2006, 5.2.6 and Annex C, Table C.2
   */
  void decodeTextSegment(Ref<BitSource> bits, std::ostringstream &result);
  /**
   * See ISO 16022:2006, 5.2.7
   */
  void decodeAnsiX12Segment(Ref<BitSource> bits, std::ostringstream &result);
  /**
   * See ISO 16022:2006, 5.2.8 and Annex C Table C.3
   */
  void decodeEdifactSegment(Ref<BitSource> bits, std::ostringstream &result);
  /**
   * See ISO 16022:2006, 5.2.9 and Annex B, B.2
   */
  void decodeBase256Segment(Ref<BitSource> bits, std::ostringstream &result, std::vector<char> byteSegments);

  void parseTwoBytes(int firstByte, int secondByte, int* result);
  /**
   * See ISO 16022:2006, Annex B, B.2
   */
  char unrandomize255State(int randomizedBase256Codeword,
                           int base256CodewordPosition) {
    int pseudoRandomNumber = ((149 * base256CodewordPosition) % 255) + 1;
    int tempVariable = randomizedBase256Codeword - pseudoRandomNumber;
    return (char) (tempVariable >= 0 ? tempVariable : (tempVariable + 256));
  };
  void append(std::ostream &ost, const char *bufIn, size_t nIn, const char *src);

public:
  DecodedBitStreamParser() { };
  Ref<DecoderResult> decode(ArrayRef<char> bytes);
};

}
}

#endif // __DECODED_BIT_STREAM_PARSER_DM_H__
