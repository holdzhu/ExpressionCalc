#include "MultiplicationOperator.h"

Operator* MultiplicationOperator::instance = nullptr;

int MultiplicationOperator::getPriorityValue()
{
	return 3;
}

void MultiplicationOperator::calculate(PolynomialStack& ps)
{
	Polynomial B = ps.top();
	ps.pop();
	Polynomial A = ps.top();
	ps.pop();
	ps.push(A * B);
}

Operator* MultiplicationOperator::getInstance()
{
	if (!instance)
	{
		instance = new MultiplicationOperator();
	}
	return instance;
}
