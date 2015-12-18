#ifndef RATIONALNUMBER_H
#define RATIONALNUMBER_H

#include <iostream>
#include <algorithm>
#include <limits>
#include <stdexcept>
#include <cmath>

class RationalNumber
{
	public:
		explicit RationalNumber(long long numerator = 0, long long denominator = 1);
		explicit RationalNumber(long double realNumber);
		RationalNumber operator + (const RationalNumber& B) const;
		RationalNumber operator - (const RationalNumber& B) const;
		RationalNumber operator * (const RationalNumber& B) const;
		RationalNumber operator / (const RationalNumber& B) const;
		RationalNumber operator ^ (const RationalNumber& B) const;
		friend std::ostream& operator << (std::ostream& out, RationalNumber rn);
		bool isNonnegativeInteger() const;
		long long getNumerator() const;
		bool isPositive() const;
		bool isInteger() const;
		bool isZero() const;
		bool isUnit() const;
	private:
		static const int intLimit;
		static constexpr long double eps = 1e-15;
		long long numerator;
		long long denominator;
		bool fraction;
		long double realNumber;
		void reduce();
		long double getRealNumber() const;
		bool isFraction() const;
};

#endif // RATIONALNUMBER_H
