#include "EndOperator.h"

Operator* EndOperator::instance = nullptr;

int EndOperator::getPriorityValue()
{
	return 0;
}

Operator::PriorityDirection EndOperator::getPriorityDirection()
{
	return Operator::LEFT;
}

void EndOperator::deal(OperatorStack& os, PolynomialStack& ps)
{
	while (os.top()->getPriorityValue() > getPriorityValue())
	{
		Operator *O = os.top();
		os.pop();
		O->calculate(ps);
	}
	os.pop();
}

Operator* EndOperator::getInstance()
{
	if (!instance)
	{
		instance = new EndOperator();
	}
	return instance;
}
