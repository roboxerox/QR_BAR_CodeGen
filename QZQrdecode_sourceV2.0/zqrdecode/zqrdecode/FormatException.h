#ifndef __FORMAT_EXCEPTION_H__
#define __FORMAT_EXCEPTION_H__

/*
 *  FormatException.h
 *  zqrdecode
 *
 */

#include <zqrdecode/ReaderException.h>

namespace zqrdecode {

class FormatException : public ReaderException {
public:
  FormatException();
  FormatException(const char *msg);
  ~FormatException() throw();

  static FormatException const& getFormatInstance();
};

}
#endif // __FORMAT_EXCEPTION_H__
