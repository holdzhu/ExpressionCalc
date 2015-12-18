#ifndef ENDOPERATOR_H
#define ENDOPERATOR_H

#include "Operator.h"

class EndOperator : Operator
{
	public:
		int getPriorityValue();
		Operator::PriorityDirection getPriorityDirection();
		void deal(OperatorStack& os, PolynomialStack& ps);
		static Operator* getInstance();
	private:
		static Operator* instance;
};

#endif // ENDOPERATOR_H
