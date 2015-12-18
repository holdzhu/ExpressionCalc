#ifndef ARITHMETICOPERATOR_H
#define ARITHMETICOPERATOR_H

#include "Operator.h"

class ArithmeticOperator : protected Operator
{
	public:
		PriorityDirection getPriorityDirection();
		void deal(OperatorStack& os, PolynomialStack& ps);
};

#endif // ARITHMETICOPERATOR_H
