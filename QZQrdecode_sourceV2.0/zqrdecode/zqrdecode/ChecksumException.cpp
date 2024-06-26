// -*- mode:c++; tab-width:2; indent-tabs-mode:nil; c-basic-offset:2 -*-
/*
 *  ChecksumException.cpp
 *  zqrdecode
 *
 */

#include <zqrdecode/ChecksumException.h>

using zqrdecode::ChecksumException;

ChecksumException::ChecksumException() throw() {}
ChecksumException::ChecksumException(const char *msg) throw() : ReaderException(msg) {}
ChecksumException::~ChecksumException() throw() {}
