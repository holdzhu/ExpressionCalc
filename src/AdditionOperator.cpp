#include "AdditionOperator.h"

Operator* AdditionOperator::instance = nullptr;

int AdditionOperator::getPriorityValue()
{
	return 2;
}

void AdditionOperator::calculate(PolynomialStack& ps)
{
	Polynomial B = ps.top();
	ps.pop();
	Polynomial A = ps.top();
	ps.pop();
	ps.push(A + B);
}

Operator* AdditionOperator::getInstance()
{
	if (!instance)
	{
		instance = new AdditionOperator();
	}
	return instance;
}
