#ifndef DIVISIONOPERATOR_H
#define DIVISIONOPERATOR_H

#include "ArithmeticOperator.h"

class DivisionOperator : ArithmeticOperator
{
	public:
		int getPriorityValue();
		void calculate(PolynomialStack& ps);
		static Operator* getInstance();
	private:
		static Operator* instance;
};

#endif // DIVISIONOPERATOR_H
