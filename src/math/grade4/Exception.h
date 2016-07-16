/*
 * Exception.h
 *
 *  Created on: Oct 14, 2013
 *      Author: paul
 */

#ifndef EXCEPTION_H_
#define EXCEPTION_H_

#include <exception> // std::exception
#include <string> // std::string

namespace math {
namespace grade4 {

class Exception : public std::exception
{

public:
	/**
	 * Construct a new price exception with the provided message.
	 * @param message - short description of the error message.
	 */
	Exception (const std::string& message);

	virtual ~Exception() throw();

	/**
	 * Retreive the error message associated with this exception
	 * @return error message.
	 */
//	const char* what() const;
	virtual const char* what()const throw();

private:
	/** Exception message. */
	std::string message_;
};

} /* namespace grade4 */
} /* namespace math */
#endif /* EXCEPTION_H_ */
