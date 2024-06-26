#ifndef __DECODER_RESULT_H__
#define __DECODER_RESULT_H__

/*
 *  DecoderResult.h
 *  zqrdecode
 *
 */

#include <zqrdecode/common/Counted.h>
#include <zqrdecode/common/Array.h>
#include <string>
#include <zqrdecode/common/Str.h>

namespace zqrdecode {

class DecoderResult : public Counted {
private:
  ArrayRef<char> rawBytes_;
  Ref<String> text_;
  ArrayRef< ArrayRef<char> > byteSegments_;
  std::string ecLevel_;
  std::string charSet_;

public:
  DecoderResult(ArrayRef<char> rawBytes,
                Ref<String> text,
                ArrayRef< ArrayRef<char> >& byteSegments,
                std::string const& ecLevel,
                std::string charSet = "");

  DecoderResult(ArrayRef<char> rawBytes, Ref<String> text);

  ArrayRef<char> getRawBytes();
  Ref<String> getText();
  std::string charSet();
};

}

#endif // __DECODER_RESULT_H__
