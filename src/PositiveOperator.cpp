#include "PositiveOperator.h"

Operator* PositiveOperator::instance = nullptr;

int PositiveOperator::getPriorityValue()
{
	return 4;
}

Operator::PriorityDirection PositiveOperator::getPriorityDirection()
{
	return Operator::RIGHT;
}

void PositiveOperator::deal(OperatorStack& os, PolynomialStack& ps)
{
	os.push(this);
}

Operator* PositiveOperator::getInstance()
{
	if (!instance)
	{
		instance = new PositiveOperator();
	}
	return instance;
}
