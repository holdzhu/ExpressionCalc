#include "Operator.h"

Operator::Operator()
{

}

Operator::~Operator()
{

}

int Operator::getPriorityValue()
{
	return 0;
}

Operator::PriorityDirection Operator::getPriorityDirection()
{
	return Operator::LEFT;
}

void Operator::deal(OperatorStack& os, PolynomialStack& ps)
{

}

void Operator::calculate(PolynomialStack& ps)
{

}
