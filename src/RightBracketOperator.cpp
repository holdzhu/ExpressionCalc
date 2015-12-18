#include "RightBracketOperator.h"

Operator* RightBracketOperator::instance = nullptr;

int RightBracketOperator::getPriorityValue()
{
	return 1;
}

Operator::PriorityDirection RightBracketOperator::getPriorityDirection()
{
	return Operator::LEFT;
}

void RightBracketOperator::deal(OperatorStack& os, PolynomialStack& ps)
{
	while (os.top()->getPriorityValue() > getPriorityValue())
	{
		Operator *O = os.top();
		os.pop();
		O->calculate(ps);
	}
	os.pop();
}

void RightBracketOperator::calculate(PolynomialStack& ps)
{
	throw std::invalid_argument("Invalid expression!");
}

Operator* RightBracketOperator::getInstance()
{
	if (!instance)
	{
		instance = new RightBracketOperator();
	}
	return instance;
}
