

#include "EAN13Reader.h"
#include <zqrdecode/NotFoundException.h>

using std::vector;
using zqrdecode::Ref;
using zqrdecode::BitArray;
using zqrdecode::oned::EAN13Reader;

namespace {
  const int FIRST_DIGIT_ENCODINGS[10] = {
    0x00, 0x0B, 0x0D, 0xE, 0x13, 0x19, 0x1C, 0x15, 0x16, 0x1A
  };
}

EAN13Reader::EAN13Reader() : decodeMiddleCounters(4, 0) { }

int EAN13Reader::decodeMiddle(Ref<BitArray> row,
                              Range const& startRange,
                              std::string& resultString) {
  vector<int>& counters (decodeMiddleCounters);
  counters.clear();
  counters.resize(4);
  int end = row->getSize();
  int rowOffset = startRange[1];

  int lgPatternFound = 0;

  for (int x = 0; x < 6 && rowOffset < end; x++) {
    int bestMatch = decodeDigit(row, counters, rowOffset, L_AND_G_PATTERNS);
    resultString.append(1, (char) ('0' + bestMatch % 10));
    for (int i = 0, end = counters.size(); i <end; i++) {
      rowOffset += counters[i];
    }
    if (bestMatch >= 10) {
      lgPatternFound |= 1 << (5 - x);
    }
  }
  
  determineFirstDigit(resultString, lgPatternFound);
  
  Range middleRange = findGuardPattern(row, rowOffset, true, MIDDLE_PATTERN) ;
  rowOffset = middleRange[1];

  for (int x = 0; x < 6 && rowOffset < end; x++) {
    int bestMatch =
      decodeDigit(row, counters, rowOffset, L_PATTERNS);
    resultString.append(1, (char) ('0' + bestMatch));
    for (int i = 0, end = counters.size(); i < end; i++) {
      rowOffset += counters[i];
    }
  }
  return rowOffset;
}

void EAN13Reader::determineFirstDigit(std::string& resultString, int lgPatternFound) {
  // std::cerr << "K " << resultString << " " << lgPatternFound << " " <<FIRST_DIGIT_ENCODINGS << std::endl;
  for (int d = 0; d < 10; d++) {
    if (lgPatternFound == FIRST_DIGIT_ENCODINGS[d]) {
      resultString.insert((size_t)0, (size_t)1, (char) ('0' + d));
      return;
    }
  }
  throw NotFoundException();
}

zqrdecode::BarcodeFormat EAN13Reader::getBarcodeFormat(){
  return BarcodeFormat::EAN_13;
}
