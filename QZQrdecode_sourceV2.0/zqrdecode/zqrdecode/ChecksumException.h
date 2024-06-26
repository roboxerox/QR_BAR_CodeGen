// -*- mode:c++; tab-width:2; indent-tabs-mode:nil; c-basic-offset:2 -*-

#ifndef __CHECKSUM_EXCEPTION_H__
#define __NOT_FOUND_EXCEPTION_H__


#include <zqrdecode/ReaderException.h>

namespace zqrdecode {
  class ChecksumException : public ReaderException {
    typedef ReaderException Base;
  public:
    ChecksumException() throw();
    ChecksumException(const char *msg) throw();
    ~ChecksumException() throw();
  };
}

#endif // __CHECKSUM_EXCEPTION_H__
