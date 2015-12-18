#include "ExponentiationOperator.h"

Operator* ExponentiationOperator::instance = nullptr;

int ExponentiationOperator::getPriorityValue()
{
	return 4;
}

Operator::PriorityDirection ExponentiationOperator::getPriorityDirection()
{
	return Operator::RIGHT;
}

void ExponentiationOperator::calculate(PolynomialStack& ps)
{
	Polynomial B = ps.top();
	ps.pop();
	Polynomial A = ps.top();
	ps.pop();
	ps.push(A ^ B);
}

Operator* ExponentiationOperator::getInstance()
{
	if (!instance)
	{
		instance = new ExponentiationOperator();
	}
	return instance;
}
