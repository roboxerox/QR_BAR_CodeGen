// -*- mode:c++; tab-width:2; indent-tabs-mode:nil; c-basic-offset:2 -*-
/*
 *  Binarizer.cpp
 *  zqrdecode
 *
 */

#include <zqrdecode/Binarizer.h>

namespace zqrdecode {
	
	Binarizer::Binarizer(Ref<LuminanceSource> source) : source_(source) {
  }
	
	Binarizer::~Binarizer() {
	}
	
	Ref<LuminanceSource> Binarizer::getLuminanceSource() const {
		return source_;
	}

  int Binarizer::getWidth() const {
    return source_->getWidth();
  }
	
  int Binarizer::getHeight() const {
    return source_->getHeight();
  }
	
}
