#include "Expression.h"

const RationalNumber Expression::PI = RationalNumber(acosl(-1));
const RationalNumber Expression::E = RationalNumber(expl(1));

Expression::Expression()
{
}

std::istream& operator >> (std::istream& in, Expression& exp)
{
	std::cout << " In[" << exp.mHistory.size() << "] = ";
	return getline(in, exp.str);
}

std::ostream& operator << (std::ostream& out, Expression& exp)
{
	return out << "Out[" << exp.mHistory.size() - 1 << "] = " << exp.mHistory.back();
}

Expression& Expression::calculate()
{
	OperatorStack os;
	PolynomialStack ps;
	os.push(EndOperator::getInstance());
	Status* status = OperatorStatus::getInstance();
	try
	{
		for (std::string::iterator it = str.begin(); it != str.end(); ++it)
		{
			if (*it == ' ')
			{
				continue;
			}
			if (*it == '$')
			{
				unsigned int id = 0;
				++it;
				if (!isdigit(*it))
				{
					id = mHistory.size() - 1u;
				}
				else
				{
					while (it != str.end())
					{
						if (isdigit(*it))
						{
							id *= 10;
							id += *it - '0';
						}
						else
						{
							break;
						}
						++it;
					}
				}
				--it;
				if (id >= mHistory.size())
				{
					throw std::out_of_range("Out of range!");
				}
				status->dealPolynomial(status, os, ps, mHistory[id]);
			}
			else if (isdigit(*it) || *it == '.')
			{
				RationalNumber rn;
				long long denominator = 1;
				bool hasDot = false;
				while (it != str.end())
				{
					if (isdigit(*it))
					{
						if (hasDot)
						{
							denominator *= 10;
							rn = rn + RationalNumber(*it - '0', denominator);
						}
						else
						{
							rn = rn * RationalNumber(10LL);
							rn = rn + RationalNumber(static_cast<long long>(*it - '0'));
						}
					}
					else if (*it == '.' && !hasDot)
					{
						hasDot = true;
					}
					else
					{
						break;
					}
					++it;
				}
				--it;
				status->dealPolynomial(status, os, ps, Polynomial(rn));
			}
			else if (*it == 'x')
			{
				status->dealPolynomial(status, os, ps, Polynomial(true));
			}
			else if (*it == 'p' && it + 1 != str.end() && *(it + 1) == 'i')
			{
				it++;
				status->dealPolynomial(status, os, ps, Polynomial(PI));
			}
			else if (*it == 'e')
			{
				status->dealPolynomial(status, os, ps, Polynomial(E));
			}
			else
			{
				if (*it == '+' || *it == '-')
				{
					if (*it == '+')
					{
						status->dealAmbiguous(status, os, ps, AdditionOperator::getInstance(), PositiveOperator::getInstance());
					}
					else
					{
						status->dealAmbiguous(status, os, ps, SubtractionOperator::getInstance(), NegativeOperator::getInstance());
					}
				}
				else if (*it == '(')
				{
					status->dealLeftBracket(status, os, ps);
				}
				else if (*it == ')')
				{
					status->dealRightBracket(status, os, ps);
				}
				else
				{
					Operator *O;
					if (*it == '^')
					{
						O = ExponentiationOperator::getInstance();
					}
					else if (*it == '*')
					{
						if (it + 1 != str.end() && *(it + 1) == '*')
						{
							O = ExponentiationOperator::getInstance();
							it++;
						}
						else
						{
							O = MultiplicationOperator::getInstance();
						}
					}
					else if (*it == '/')
					{
						O = DivisionOperator::getInstance();
					}
					else
					{
						throw std::invalid_argument("Invalid expression!");
					}
					status->dealOperator(status, os, ps, O);
				}
			}
		}
		status->dealOperator(status, os, ps, EndOperator::getInstance());
		Polynomial ans = ps.top();
		ps.pop();
		if (!os.empty() || !ps.empty())
		{
			throw std::invalid_argument("Invalid expression!");
		}
		mHistory.push_back(ans);
		return *this;
	}
	catch (std::bad_alloc&)
	{
		throw;
	}
	catch (std::domain_error&)
	{
		throw;
	}
	catch (std::invalid_argument&)
	{
		throw;
	}
	catch (std::length_error&)
	{
		throw;
	}
	catch (std::exception&)
	{
		throw std::invalid_argument("Invalid expression!");
	}
}
