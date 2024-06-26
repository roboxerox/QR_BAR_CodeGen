// -*- mode:c++; tab-width:2; indent-tabs-mode:nil; c-basic-offset:2 -*-

#ifndef __ILLEGAL_STATE_EXCEPTION_H__
#define __ILLEGAL_STATE_EXCEPTION_H__


#include <zqrdecode/ReaderException.h>

namespace zqrdecode {

class IllegalStateException : public ReaderException {
public:
  IllegalStateException() throw() {}
  IllegalStateException(const char *msg) throw() : ReaderException(msg) {}
  ~IllegalStateException() throw() {}
};

}

#endif // __ILLEGAL_STATE_EXCEPTION_H__
