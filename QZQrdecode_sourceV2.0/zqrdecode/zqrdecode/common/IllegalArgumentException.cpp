/*
 *  IllegalArgumentException.cpp
 *  zqrdecode
 *
 */

#include <zqrdecode/common/IllegalArgumentException.h>

using zqrdecode::IllegalArgumentException;

IllegalArgumentException::IllegalArgumentException() : Exception() {}
IllegalArgumentException::IllegalArgumentException(const char *msg) : Exception(msg) {}
IllegalArgumentException::~IllegalArgumentException() throw() {}
