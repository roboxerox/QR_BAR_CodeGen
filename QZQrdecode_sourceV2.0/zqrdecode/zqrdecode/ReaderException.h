// -*- mode:c++; tab-width:2; indent-tabs-mode:nil; c-basic-offset:2 -*-
#ifndef __READER_EXCEPTION_H__
#define __READER_EXCEPTION_H__

/*
 *  ReaderException.h
 *  zqrdecode
 *
 */

#include <zqrdecode/Exception.h>

namespace zqrdecode {

class ReaderException : public Exception {
 public:
  ReaderException() throw() {}
  ReaderException(char const* msg) throw() : Exception(msg) {}
  ~ReaderException() throw() {}
};

}

#endif // __READER_EXCEPTION_H__
