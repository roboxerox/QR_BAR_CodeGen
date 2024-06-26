// -*- mode:c++; tab-width:2; indent-tabs-mode:nil; c-basic-offset:2 -*-
#ifndef __STR_H__
#define __STR_H__

/*
 *  Str.h
 *  zqrdecode
 *
 */

#include <string>
#include <iostream>
#include <zqrdecode/common/Counted.h>

namespace zqrdecode {

class String;
std::ostream& operator << (std::ostream& out, String const& s);

class String : public Counted {
private:
  std::string text_;
public:
  explicit String(const std::string &text);
  explicit String(int);
  char charAt(int) const;
  Ref<String> substring(int) const;
  const std::string& getText() const;
  int size() const;
  void append(std::string const& tail);
  void append(char c);
  int length() const;
  friend std::ostream& zqrdecode::operator << (std::ostream& out, String const& s);
};

}

#endif // __COMMON__STRING_H__
