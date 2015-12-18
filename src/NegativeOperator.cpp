#include "NegativeOperator.h"

Operator* NegativeOperator::instance = nullptr;

int NegativeOperator::getPriorityValue()
{
	return 4;
}

Operator::PriorityDirection NegativeOperator::getPriorityDirection()
{
	return Operator::RIGHT;
}

void NegativeOperator::deal(OperatorStack& os, PolynomialStack& ps)
{
	os.push(this);
}

void NegativeOperator::calculate(PolynomialStack& ps)
{
	Polynomial A = ps.top();
	ps.pop();
	A = A * Polynomial(RationalNumber(-1LL));
	ps.push(A);
}

Operator* NegativeOperator::getInstance()
{
	if (!instance)
	{
		instance = new NegativeOperator();
	}
	return instance;
}
