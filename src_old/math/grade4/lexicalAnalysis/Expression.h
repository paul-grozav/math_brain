/*
 * Expression.h
 *
 * Created on: Oct 8, 2013
 * Begun by: Tancredi-Paul Grozav <paul@grozav.info>
 * License: Private property of Tancredi-Paul Grozav <paul@grozav.info>. All rights reserved.
 */

#ifndef EXPRESSION_H_
#define EXPRESSION_H_

#include <string> // std::string
#include <list> // std::list

namespace math {
namespace grade4 {
namespace lexicalAnalysis {

/**
 * Evaluates an expression. You give it a std::string and it creates instances of NaturalNumbers or whatever that expression contains
 * @author Tancredi-Paul Grozav <paul@grozav.info>
 */
class Expression {
public:
	/**
	 * Tokenize the given std::string. And fills the std::list<Token> member
	 * @param expression The expression to parse (tokenize)
	 * @author Tancredi-Paul Grozav <paul@grozav.info>
	 */
	Expression(const std::string& expression);
	/**
	 * Destroy the current Expression instance
	 * @author Tancredi-Paul Grozav <paul@grozav.info>
	 */
	virtual ~Expression();
protected:
	/**
	 * List of tokens/expresions
	 * @author Tancredi-Paul Grozav <paul@grozav.info>
	 */
	std::list<Expression> tokens_;
};

} /* namespace lexicalAnalysis */
} /* namespace grade1 */
} /* namespace math */
#endif /* EXPRESSION_H_ */
