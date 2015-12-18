#include "LeftBracketOperator.h"

Operator* LeftBracketOperator::instance = nullptr;

int LeftBracketOperator::getPriorityValue()
{
	return 1;
}

Operator::PriorityDirection LeftBracketOperator::getPriorityDirection()
{
	return Operator::LEFT;
}

void LeftBracketOperator::deal(OperatorStack& os, PolynomialStack& ps)
{
	os.push(this);
}

void LeftBracketOperator::calculate(PolynomialStack& ps)
{
	throw std::invalid_argument("Invalid expression!");
}

Operator* LeftBracketOperator::getInstance()
{
	if (!instance)
	{
		instance = new LeftBracketOperator();
	}
	return instance;
}
