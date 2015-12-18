#ifndef SUBTRACTIONOPERATOR_H
#define SUBTRACTIONOPERATOR_H

#include "ArithmeticOperator.h"

class SubtractionOperator : ArithmeticOperator
{
	public:
		int getPriorityValue();
		void calculate(PolynomialStack& ps);
		static Operator* getInstance();
	private:
		static Operator* instance;
};

#endif // SUBTRACTIONOPERATOR_H
