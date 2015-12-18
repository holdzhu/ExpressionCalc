#ifndef RIGHTBRACKETOPERATOR_H
#define RIGHTBRACKETOPERATOR_H

#include "Operator.h"

class RightBracketOperator : Operator
{
	public:
		int getPriorityValue();
		PriorityDirection getPriorityDirection();
		void deal(OperatorStack& os, PolynomialStack& ps);
		void calculate(PolynomialStack& ps);
		static Operator* getInstance();
	private:
		static Operator* instance;
};

#endif // RIGHTBRACKETOPERATOR_H
