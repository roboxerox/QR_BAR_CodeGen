// -*- mode:c++; tab-width:2; indent-tabs-mode:nil; c-basic-offset:2 -*-
/*
 *  DecoderResult.cpp
 *  zqrdecode
 *
 */

#include <zqrdecode/common/DecoderResult.h>

using namespace std;
using namespace zqrdecode;

DecoderResult::DecoderResult(ArrayRef<char> rawBytes,
                             Ref<String> text,
                             ArrayRef< ArrayRef<char> >& byteSegments,
                             string const& ecLevel, string charSet) :
  rawBytes_(rawBytes),
  text_(text),
  byteSegments_(byteSegments),
  ecLevel_(ecLevel), charSet_(charSet) {}

DecoderResult::DecoderResult(ArrayRef<char> rawBytes,
                             Ref<String> text)
  : rawBytes_(rawBytes), text_(text),charSet_("") {}

ArrayRef<char> DecoderResult::getRawBytes() {
  return rawBytes_;
}

Ref<String> DecoderResult::getText() {
    return text_;
}

string DecoderResult::charSet()
{
    return charSet_;
}
