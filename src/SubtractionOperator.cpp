#include "SubtractionOperator.h"

Operator* SubtractionOperator::instance = nullptr;

int SubtractionOperator::getPriorityValue()
{
	return 2;
}

void SubtractionOperator::calculate(PolynomialStack& ps)
{
	Polynomial B = ps.top();
	ps.pop();
	Polynomial A = ps.top();
	ps.pop();
	ps.push(A - B);
}

Operator* SubtractionOperator::getInstance()
{
	if (!instance)
	{
		instance = new SubtractionOperator();
	}
	return instance;
}
