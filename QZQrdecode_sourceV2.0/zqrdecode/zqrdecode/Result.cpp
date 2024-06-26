// -*- mode:c++; tab-width:2; indent-tabs-mode:nil; c-basic-offset:2 -*-
/*
 *  Result.cpp
 *  zqrdecode
 *
 */

#include <zqrdecode/Result.h>

using zqrdecode::Result;
using zqrdecode::Ref;
using zqrdecode::ArrayRef;
using zqrdecode::String;
using zqrdecode::ResultPoint;

// VC++
using zqrdecode::BarcodeFormat;

Result::Result(Ref<String> text,
               ArrayRef<char> rawBytes,
               ArrayRef< Ref<ResultPoint> > resultPoints,
               BarcodeFormat format, std::string charSet) :
  text_(text), rawBytes_(rawBytes), resultPoints_(resultPoints), format_(format), charSet_(charSet) {
}

Result::~Result() {
}

Ref<String> Result::getText() {
  return text_;
}

ArrayRef<char> Result::getRawBytes() {
  return rawBytes_;
}

ArrayRef< Ref<ResultPoint> > const& Result::getResultPoints() const {
  return resultPoints_;
}

ArrayRef< Ref<ResultPoint> >& Result::getResultPoints() {
  return resultPoints_;
}

zqrdecode::BarcodeFormat Result::getBarcodeFormat() const {
    return format_;
}

std::string Result::getCharSet() const
{
    return charSet_;
}
