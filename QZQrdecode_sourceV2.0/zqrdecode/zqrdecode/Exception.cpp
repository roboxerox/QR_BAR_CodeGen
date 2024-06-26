// -*- mode:c++; tab-width:2; indent-tabs-mode:nil; c-basic-offset:2 -*-
/*
 *  Exception.cpp
 *  zqrdecode
 *
 */

#include <zqrdecode/ZQrdecode.h>
#include <zqrdecode/Exception.h>
#include <string.h>

using zqrdecode::Exception;

void Exception::deleteMessage() {
  delete [] message;
}

char const* Exception::copy(char const* msg) {
  char* message = 0;
  if (msg) {
    int l = strlen(msg)+1;
    if (l) {
      message = new char[l];
      strcpy(message, msg);
    }
  }
  return message;
}
