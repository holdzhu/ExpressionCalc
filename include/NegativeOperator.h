#ifndef NEGATIVEOPERATOR_H
#define NEGATIVEOPERATOR_H

#include "Operator.h"

class NegativeOperator : Operator
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

#endif // NEGATIVEOPERATOR_H
