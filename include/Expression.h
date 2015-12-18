#ifndef EXPRESSION_H
#define EXPRESSION_H

#include <iostream>
#include <vector>
#include <cmath>
#include "Polynomial.h"
#include "OperatorStack.h"
#include "PolynomialStack.h"
#include "EndOperator.h"
#include "OperatorStatus.h"
#include "PolynomialStatus.h"
#include "AdditionOperator.h"
#include "SubtractionOperator.h"
#include "MultiplicationOperator.h"
#include "DivisionOperator.h"
#include "ExponentiationOperator.h"
#include "LeftBracketOperator.h"
#include "RightBracketOperator.h"
#include "EndOperator.h"
#include "NegativeOperator.h"
#include "PositiveOperator.h"

class Expression
{
	public:
		Expression();
		friend std::istream& operator >> (std::istream& in, Expression& exp);
		friend std::ostream& operator << (std::ostream& out, Expression& exp);
		Expression& calculate();
	private:
		static const RationalNumber PI;
		static const RationalNumber E;
		std::string str;
		std::vector<Polynomial> mHistory;
};

#endif // EXPRESSION_H
