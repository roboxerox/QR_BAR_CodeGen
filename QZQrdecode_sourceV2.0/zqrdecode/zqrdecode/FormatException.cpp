// -*- mode:c++; tab-width:2; indent-tabs-mode:nil; c-basic-offset:2 -*-
/*
 *  FormatException.cpp
 *  zqrdecode
 *
 */

#include <zqrdecode/FormatException.h>

namespace zqrdecode {

FormatException::FormatException() {}

FormatException::FormatException(const char *msg) :
    ReaderException(msg) {
}

FormatException::~FormatException() throw() {
}

FormatException const&
FormatException::getFormatInstance() {
  static FormatException instance;
  return instance;
}

}
