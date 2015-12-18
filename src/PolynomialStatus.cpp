#include "PolynomialStatus.h"

Status* PolynomialStatus::mStatus = nullptr;

void PolynomialStatus::dealPolynomial(Status*& status, OperatorStack& os, PolynomialStack& ps, Polynomial rn)
{
	MultiplicationOperator::getInstance()->deal(os, ps);
	ps.push(rn);
}

void PolynomialStatus::dealOperator(Status*& status, OperatorStack& os, PolynomialStack& ps, Operator* op)
{
	op->deal(os, ps);
	status = OperatorStatus::getInstance();
}

void PolynomialStatus::dealAmbiguous(Status*& status, OperatorStack& os, PolynomialStack& ps, Operator* op1, Operator* op2)
{
	op1->deal(os, ps);
	status = OperatorStatus::getInstance();
}

void PolynomialStatus::dealLeftBracket(Status*& status, OperatorStack& os, PolynomialStack& ps)
{
	MultiplicationOperator::getInstance()->deal(os, ps);
	LeftBracketOperator::getInstance()->deal(os, ps);
	status = OperatorStatus::getInstance();
}

void PolynomialStatus::dealRightBracket(Status*& status, OperatorStack& os, PolynomialStack& ps)
{
	RightBracketOperator::getInstance()->deal(os, ps);
}

Status* PolynomialStatus::getInstance()
{
	if (!mStatus)
	{
		mStatus = new PolynomialStatus();
	}
	return mStatus;
}

