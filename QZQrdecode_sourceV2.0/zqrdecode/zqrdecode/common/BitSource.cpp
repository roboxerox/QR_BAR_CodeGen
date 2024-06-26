// -*- mode:c++; tab-width:2; indent-tabs-mode:nil; c-basic-offset:2 -*-
/*
 *  BitSource.cpp
 *  zqrdecode
 *
 */

#include <zqrdecode/common/BitSource.h>
#include <sstream>
#include <zqrdecode/common/IllegalArgumentException.h>

namespace zqrdecode {

int BitSource::readBits(int numBits) {
  if (numBits < 0 || numBits > 32 || numBits > available()) {
    std::ostringstream oss;
    oss << numBits;
    throw IllegalArgumentException(oss.str().c_str());
  }

  int result = 0;

  // First, read remainder from current byte
  if (bitOffset_ > 0) {
    int bitsLeft = 8 - bitOffset_;
    int toRead = numBits < bitsLeft ? numBits : bitsLeft;
    int bitsToNotRead = bitsLeft - toRead;
    int mask = (0xFF >> (8 - toRead)) << bitsToNotRead;
    result = (bytes_[byteOffset_] & mask) >> bitsToNotRead;
    numBits -= toRead;
    bitOffset_ += toRead;
    if (bitOffset_ == 8) {
      bitOffset_ = 0;
      byteOffset_++;
    }
  }

  // Next read whole bytes
  if (numBits > 0) {
    while (numBits >= 8) {
      result = (result << 8) | (bytes_[byteOffset_] & 0xFF);
      byteOffset_++;
      numBits -= 8;
    }


    // Finally read a partial byte
    if (numBits > 0) {
      int bitsToNotRead = 8 - numBits;
      int mask = (0xFF >> bitsToNotRead) << bitsToNotRead;
      result = (result << numBits) | ((bytes_[byteOffset_] & mask) >> bitsToNotRead);
      bitOffset_ += numBits;
    }
  }

  return result;
}

int BitSource::available() {
  return 8 * (bytes_->size() - byteOffset_) - bitOffset_;
}
}
