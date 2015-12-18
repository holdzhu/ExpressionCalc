#include "RationalNumber.h"

const int RationalNumber::intLimit = std::numeric_limits<int>::max();

RationalNumber::RationalNumber(long long numerator, long long denominator) : numerator(numerator), denominator(denominator)
{
	if (denominator == 0)
	{
		throw std::domain_error("Denominator cannot be zero!");
	}
	fraction = true;
	reduce();
}

RationalNumber::RationalNumber(long double realNumber) : realNumber(realNumber)
{
	fraction = false;
}

RationalNumber RationalNumber::operator + (const RationalNumber& B) const
{
	if (!isFraction() || !B.isFraction())
	{
		return RationalNumber(getRealNumber() + B.getRealNumber());
	}
	return RationalNumber(numerator * B.denominator + denominator * B.numerator, denominator * B.denominator);
}

RationalNumber RationalNumber::operator - (const RationalNumber& B) const
{
	if (!isFraction() || !B.isFraction())
	{
		return RationalNumber(getRealNumber() - B.getRealNumber());
	}
	return RationalNumber(numerator * B.denominator - denominator * B.numerator, denominator * B.denominator);
}

RationalNumber RationalNumber::operator * (const RationalNumber& B) const
{
	if (!isFraction() || !B.isFraction())
	{
		return RationalNumber(getRealNumber() * B.getRealNumber());
	}
	return RationalNumber(numerator * B.numerator, denominator * B.denominator);
}

RationalNumber RationalNumber::operator / (const RationalNumber& B) const
{
	if (!isFraction() || !B.isFraction())
	{
		return RationalNumber(getRealNumber() / B.getRealNumber());
	}
	if (B.numerator == 0)
	{
		throw std::domain_error("Division by zero!");
	}
	return RationalNumber(numerator * B.denominator, denominator * B.numerator);
}

RationalNumber RationalNumber::operator ^ (const RationalNumber& B) const
{
	if (!isFraction() || !B.isInteger())
	{
		return RationalNumber(powl(getRealNumber(), B.getRealNumber()));
	}
	RationalNumber S(1, 1);
	RationalNumber A = *this;
	long long n = B.numerator;
	if (n < 0)
	{
		A = RationalNumber(1, 1) / A;
		n = -n;
	}
	while (n)
	{
		if (n & 1)
		{
			S = S * A;
		}
		A = A * A;
		n >>= 1;
	}
	return S;
}

std::ostream& operator << (std::ostream& out, RationalNumber rn)
{
	if (!rn.fraction)
	{
		out << (double)rn.getRealNumber();
	}
	else
	{
		out << rn.numerator;
		if (rn.denominator != 1)
		{
			out << '/' << rn.denominator;
		}
	}
	return out;
}

bool RationalNumber::isZero() const
{
	return (fraction && numerator == 0) || (!fraction && std::abs(realNumber) < eps);
}

bool RationalNumber::isInteger() const
{
	return fraction && denominator == 1;
}

bool RationalNumber::isNonnegativeInteger() const
{
	return fraction && denominator == 1 && numerator >= 0;
}

bool RationalNumber::isFraction() const
{
	return fraction;
}

bool RationalNumber::isPositive() const
{
	return (fraction && numerator > 0) || (!fraction && realNumber > 0);
}

bool RationalNumber::isUnit() const
{
	return fraction && std::abs(numerator) == 1;
}

long long RationalNumber::getNumerator() const
{
	return numerator;
}

long double RationalNumber::getRealNumber() const
{
	return realNumber;
}

void RationalNumber::reduce()
{
	if (!fraction)
	{
		return;
	}
	long long gcd = std::__gcd(numerator, denominator);
	numerator /= gcd;
	denominator /= gcd;
	if (denominator < 0)
	{
		numerator = -numerator;
		denominator = -denominator;
	}
	if (std::abs(numerator) > intLimit || std::abs(denominator) > intLimit)
	{
		fraction = false;
	}
	realNumber = (long double)numerator / denominator;
}
