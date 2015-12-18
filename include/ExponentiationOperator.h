#ifndef EXPONENTIATIONOPERATOR_H
#define EXPONENTIATIONOPERATOR_H

#include "ArithmeticOperator.h"

class ExponentiationOperator : ArithmeticOperator
{
	public:
		int getPriorityValue();
		Operator::PriorityDirection getPriorityDirection();
		void calculate(PolynomialStack& ps);
		static Operator* getInstance();
	private:
		static Operator* instance;
};

#endif // EXPONENTIATIONOPERATOR_H
