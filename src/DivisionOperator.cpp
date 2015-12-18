#include "DivisionOperator.h"

Operator* DivisionOperator::instance = nullptr;

int DivisionOperator::getPriorityValue()
{
	return 3;
}

void DivisionOperator::calculate(PolynomialStack& ps)
{
	Polynomial B = ps.top();
	ps.pop();
	Polynomial A = ps.top();
	ps.pop();
	ps.push(A / B);
}

Operator* DivisionOperator::getInstance()
{
	if (!instance)
	{
		instance = new DivisionOperator();
	}
	return instance;
}
