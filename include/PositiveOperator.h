#ifndef POSITIVEOPERATOR_H
#define POSITIVEOPERATOR_H

#include "Operator.h"

class PositiveOperator : Operator
{
	public:
		int getPriorityValue();
		PriorityDirection getPriorityDirection();
		void deal(OperatorStack& os, PolynomialStack& ps);
		static Operator* getInstance();
	private:
		static Operator* instance;
};

#endif // POSITIVEOPERATOR_H
