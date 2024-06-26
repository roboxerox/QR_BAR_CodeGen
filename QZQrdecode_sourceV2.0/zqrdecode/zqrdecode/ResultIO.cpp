// -*- mode:c++; tab-width:2; indent-tabs-mode:nil; c-basic-offset:2 -*-
/*
 *  ResultIO.cpp
 *  zqrdecode
 *
 */

#include <zqrdecode/Result.h>

using zqrdecode::Result;
using std::ostream;

ostream& zqrdecode::operator<<(ostream &out, Result& result) {
  if (result.text_ != 0) {
    out << result.text_->getText();
  } else {
    out << "[" << result.rawBytes_->size() << " bytes]";
  }
  return out;
}
