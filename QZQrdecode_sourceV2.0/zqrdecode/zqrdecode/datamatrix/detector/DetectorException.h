/*
 * DetectorException.h
 *
 *  Created on: Aug 26, 2011
 *      Author: luiz
 */

#ifndef DETECTOREXCEPTION_H_
#define DETECTOREXCEPTION_H_

#include <zqrdecode/Exception.h>

namespace zqrdecode {
namespace datamatrix {

class DetectorException : public Exception {
  public:
    DetectorException(const char *msg);
    virtual ~DetectorException() throw();
};
} /* namespace nexxera */
} /* namespace zqrdecode */
#endif /* DETECTOREXCEPTION_H_ */
