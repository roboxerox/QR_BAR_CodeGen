/*
 * DetectorException.cpp
 *
 *  Created on: Aug 26, 2011
 *      Author: luiz
 */

#include "DetectorException.h"

namespace zqrdecode {
namespace datamatrix {

DetectorException::DetectorException(const char *msg) :
    Exception(msg) {

}

DetectorException::~DetectorException() throw () {
  // TODO Auto-generated destructor stub
}

}
} /* namespace zqrdecode */
