#ifndef OPERATOR_H
#define OPERATOR_H

#include "OperatorStack.h"
#include "PolynomialStack.h"

class Operator
{
	public:
		enum PriorityDirection
		{
			LEFT,
			RIGHT
		};
		virtual ~Operator();
		virtual int getPriorityValue();
		virtual PriorityDirection getPriorityDirection();
		virtual void deal(OperatorStack& os, PolynomialStack& ps);
		virtual void calculate(PolynomialStack& ps);
	protected:
		Operator();
};

#endif // OPERATOR_H
