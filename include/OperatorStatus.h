#ifndef OPERATORSTATUS_H
#define OPERATORSTATUS_H

#include "Status.h"
#include "PolynomialStatus.h"
#include "LeftBracketOperator.h"

class OperatorStatus : Status
{
	public:
		void dealPolynomial(Status*& status, OperatorStack& os, PolynomialStack& ps, Polynomial rn);
		void dealOperator(Status*& status, OperatorStack& os, PolynomialStack& ps, Operator* op);
		void dealAmbiguous(Status*& status, OperatorStack& os, PolynomialStack& ps, Operator* op1, Operator* op2);
		void dealLeftBracket(Status*& status, OperatorStack& os, PolynomialStack& ps);
		void dealRightBracket(Status*& status, OperatorStack& os, PolynomialStack& ps);
		static Status* getInstance();
	private:
		static Status* mStatus;
};

#endif // OPERATORSTATUS_H
