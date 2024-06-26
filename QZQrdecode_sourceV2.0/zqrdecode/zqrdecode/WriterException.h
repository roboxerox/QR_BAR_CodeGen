#ifndef WRITEREXCEPTION_H
#define WRITEREXCEPTION_H

#include <zqrdecode/Exception.h>

namespace zqrdecode {

class WriterException : public Exception {
 public:
  WriterException() throw() {}
  WriterException(char const* msg) throw() : Exception(msg) {}
  ~WriterException() throw() {}
};

}

#endif // WRITEREXCEPTION_H
