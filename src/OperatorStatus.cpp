#include "OperatorStatus.h"

Status* OperatorStatus::mStatus = nullptr;

void OperatorStatus::dealPolynomial(Status*& status, OperatorStack& os, PolynomialStack& ps, Polynomial rn)
{
	ps.push(rn);
	status = PolynomialStatus::getInstance();
}

void OperatorStatus::dealOperator(Status*& status, OperatorStack& os, PolynomialStack& ps, Operator* op)
{
	throw std::invalid_argument("Invalid expression!");
}

void OperatorStatus::dealAmbiguous(Status*& status, OperatorStack& os, PolynomialStack& ps, Operator* op1, Operator* op2)
{
	op2->deal(os, ps);
}

void OperatorStatus::dealLeftBracket(Status*& status, OperatorStack& os, PolynomialStack& ps)
{
	LeftBracketOperator::getInstance()->deal(os, ps);
}

void OperatorStatus::dealRightBracket(Status*& status, OperatorStack& os, PolynomialStack& ps)
{
	throw std::invalid_argument("Invalid expression!");
}

Status* OperatorStatus::getInstance()
{
	if (!mStatus)
	{
		mStatus = new OperatorStatus();
	}
	return mStatus;
}
