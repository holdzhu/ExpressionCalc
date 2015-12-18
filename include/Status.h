#ifndef STATUS_H
#define STATUS_H

#include "Status.h"
#include "OperatorStack.h"
#include "PolynomialStack.h"

class Status
{
	public:
		virtual void dealPolynomial(Status*& status, OperatorStack& os, PolynomialStack& ps, Polynomial rn) = 0;
		virtual void dealOperator(Status*& status, OperatorStack& os, PolynomialStack& ps, Operator* op) = 0;
		virtual void dealAmbiguous(Status*& status, OperatorStack& os, PolynomialStack& ps, Operator* op1, Operator* op2) = 0;
		virtual void dealLeftBracket(Status*& status, OperatorStack& os, PolynomialStack& ps) = 0;
		virtual void dealRightBracket(Status*& status, OperatorStack& os, PolynomialStack& ps) = 0;
};

#endif // STATUS_H
