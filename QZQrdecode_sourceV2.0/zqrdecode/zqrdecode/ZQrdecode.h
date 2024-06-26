// -*- mode:c++; tab-width:2; indent-tabs-mode:nil; c-basic-offset:2 -*-
#ifndef __ZQRDECODE_H_
#define __ZQRDECODE_H_

#define ZQRDECODE_ARRAY_LEN(v) ((int)(sizeof(v)/sizeof(v[0])))
#define ZX_LOG_DIGITS(digits) \
    ((digits == 8) ? 3 : \
     ((digits == 16) ? 4 : \
      ((digits == 32) ? 5 : \
       ((digits == 64) ? 6 : \
        ((digits == 128) ? 7 : \
         (-1))))))

#ifndef ZQRDECODE_DEBUG
#define ZQRDECODE_DEBUG 0
#endif

namespace zqrdecode {
typedef char byte;
typedef bool boolean;
}

#include <limits>

#if defined(_WIN32) || defined(_WIN64)

#include <float.h>

namespace zqrdecode {
inline bool isnan_z(float v) {return _isnan(v) != 0;}
inline bool isnan_z(double v) {return _isnan(v) != 0;}
inline float nan() {return std::numeric_limits<float>::quiet_NaN();}
}

#else

//#include <cmath>

#include <math.h>


namespace zqrdecode {
inline bool isnan_z(float v) {
    return isnan(v);
}
inline bool isnan_z(double v) {
    return isnan(v);
}
inline float nan() {return std::numeric_limits<float>::quiet_NaN();}
}

#endif

#if ZQRDECODE_DEBUG

#include <iostream>
#include <string>

using std::cout;
using std::cerr;
using std::endl;
using std::flush;
using std::string;
using std::ostream;

#if ZQRDECODE_DEBUG_TIMER

#include <sys/time.h>

namespace zqrdecode {

class DebugTimer {
public:
  DebugTimer(char const* string_) : chars(string_) {
    gettimeofday(&start, 0);
  }

  DebugTimer(std::string const& string_) : chars(0), string(string_) {
    gettimeofday(&start, 0);
  }

  void mark(char const* string) {
    struct timeval end;
    gettimeofday(&end, 0);
    int diff =
      (end.tv_sec - start.tv_sec)*1000*1000+(end.tv_usec - start.tv_usec);
    
    cerr << diff << " " << string << '\n';
  }

  void mark(std::string string) {
    mark(string.c_str());
  }

  ~DebugTimer() {
    if (chars) {
      mark(chars);
    } else {
      mark(string.c_str());
    }
  }

private:
  char const* const chars;
  std::string string;
  struct timeval start;
};

}

#define ZQRDECODE_TIME(string) DebugTimer __timer__ (string)
#define ZQRDECODE_TIME_MARK(string) __timer__.mark(string)

#endif

#endif // ZQRDECODE_DEBUG

#ifndef ZQRDECODE_TIME
#define ZQRDECODE_TIME(string) (void)0
#endif
#ifndef ZQRDECODE_TIME_MARK
#define ZQRDECODE_TIME_MARK(string) (void)0
#endif

#endif
