// -*- mode:c++; tab-width:2; indent-tabs-mode:nil; c-basic-offset:2 -*-
#ifndef __EXCEPTION_H__
#define __EXCEPTION_H__

/*
 *  Exception.h
 *  zqrdecode
 *
 */

#include <string>
#include <exception>

namespace zqrdecode {

class Exception : public std::exception {
private:
  char const* const message;

public:
  Exception() throw() : message(0) {}
  Exception(const char* msg) throw() : message(copy(msg)) {}
  Exception(Exception const& that) throw() : std::exception(that), message(copy(that.message)) {}
  ~Exception() throw() {
    if(message) {
      deleteMessage();
    }
  }
  char const* what() const throw() {return message ? message : "";}

private:
  static char const* copy(char const*);
  void deleteMessage();
};

}

#endif // __EXCEPTION_H__
