#include "ArithmeticOperator.h"

Operator::PriorityDirection ArithmeticOperator::getPriorityDirection()
{
	return Operator::LEFT;
}

void ArithmeticOperator::deal(OperatorStack& os, PolynomialStack& ps)
{
	Operator *O = os.top();
	if (getPriorityValue() < O->getPriorityValue() || (getPriorityValue() == O->getPriorityValue() && getPriorityDirection() == LEFT))
	{
		while (!os.empty() && os.top()->getPriorityValue() >= getPriorityValue())
		{
			Operator *O = os.top();
			os.pop();
			O->calculate(ps);
		}
	}
	os.push(this);
}
