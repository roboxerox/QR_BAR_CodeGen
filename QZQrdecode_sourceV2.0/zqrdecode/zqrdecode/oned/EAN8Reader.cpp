

#include "EAN8Reader.h"
#include <zqrdecode/ReaderException.h>

using std::vector;
using zqrdecode::oned::EAN8Reader;

// VC++
using zqrdecode::Ref;
using zqrdecode::BitArray;

EAN8Reader::EAN8Reader() : decodeMiddleCounters(4, 0) {}

int EAN8Reader::decodeMiddle(Ref<BitArray> row,
                             Range const& startRange,
                             std::string& result){
  vector<int>& counters (decodeMiddleCounters);
  counters[0] = 0;
  counters[1] = 0;
  counters[2] = 0;
  counters[3] = 0;

  int end = row->getSize();
  int rowOffset = startRange[1];

  for (int x = 0; x < 4 && rowOffset < end; x++) {
    int bestMatch = decodeDigit(row, counters, rowOffset, L_PATTERNS);
    result.append(1, (char) ('0' + bestMatch));
    for (int i = 0, end = counters.size(); i < end; i++) {
      rowOffset += counters[i];
    }
  }

  Range middleRange =
    findGuardPattern(row, rowOffset, true, MIDDLE_PATTERN);
  rowOffset = middleRange[1];
  for (int x = 0; x < 4 && rowOffset < end; x++) {
    int bestMatch = decodeDigit(row, counters, rowOffset, L_PATTERNS);
    result.append(1, (char) ('0' + bestMatch));
    for (int i = 0, end = counters.size(); i < end; i++) {
      rowOffset += counters[i];
    }
  }
  return rowOffset;
}

zqrdecode::BarcodeFormat EAN8Reader::getBarcodeFormat(){
  return BarcodeFormat::EAN_8;
}
