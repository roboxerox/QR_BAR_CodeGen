// -*- mode:c++; tab-width:2; indent-tabs-mode:nil; c-basic-offset:2 -*-
/*
 *  String.cpp
 *  zqrdecode
 */

#include <zqrdecode/common/Str.h>

using std::string;
using zqrdecode::String;
using zqrdecode::Ref;

String::String(const std::string &text) :
  text_(text) {
}

String::String(int capacity) {
  text_.reserve(capacity);
}

const std::string& String::getText() const {
  return text_;
}

char String::charAt(int i) const { return text_[i]; }

int String::size() const { return text_.size(); }

int String::length() const { return text_.size(); }

Ref<String> String::substring(int i) const {
  return Ref<String>(new String(text_.substr(i)));
}

void String::append(const std::string &tail) {
  text_.append(tail);
}

void String::append(char c) {
  text_.append(1,c);
}

std::ostream& zqrdecode::operator << (std::ostream& out, String const& s) {
  out << s.text_;
  return out;
}
