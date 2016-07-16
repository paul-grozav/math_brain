/*
 * Exception.cpp
 *
 *  Created on: Oct 14, 2013
 *      Author: paul
 */

#include "Exception.h"

namespace math {
namespace grade4 {

Exception::Exception (const std::string& message)
{
	message_ = message;
}

Exception::~Exception() throw()
{
}

const char* Exception::what() const throw()
{
	return message_.c_str();
}

} /* namespace grade4 */
} /* namespace math */
