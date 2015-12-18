#ifndef LEFTBRACKETOPERATOR_H
#define LEFTBRACKETOPERATOR_H

#include "Operator.h"

class LeftBracketOperator : Operator
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

#endif // LEFTBRACKETOPERATOR_H
