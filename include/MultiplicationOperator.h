#ifndef MULTIPLICATIONOPERATOR_H
#define MULTIPLICATIONOPERATOR_H

#include "ArithmeticOperator.h"

class MultiplicationOperator : ArithmeticOperator
{
	public:
		int getPriorityValue();
		void calculate(PolynomialStack& ps);
		static Operator* getInstance();
	private:
		static Operator* instance;
};

#endif // MULTIPLICATIONOPERATOR_H
