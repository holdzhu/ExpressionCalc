#ifndef ADDITIONOPERATOR_H
#define ADDITIONOPERATOR_H

#include "ArithmeticOperator.h"

class AdditionOperator : ArithmeticOperator
{
	public:
		int getPriorityValue();
		void calculate(PolynomialStack& ps);
		static Operator* getInstance();
	private:
		static Operator* instance;
};

#endif // ADDITIONOPERATOR_H
