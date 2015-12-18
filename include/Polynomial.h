#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <vector>
#include "RationalNumber.h"

class Polynomial
{
	public:
		Polynomial(bool x = false);
		Polynomial(RationalNumber rn, int times = 0);
		Polynomial operator + (const Polynomial& B) const;
		Polynomial operator - (const Polynomial& B) const;
		Polynomial operator * (const Polynomial& B) const;
		Polynomial operator / (const Polynomial& B) const;
		Polynomial operator ^ (const Polynomial& B) const;
		friend std::ostream& operator << (std::ostream& out, Polynomial poly);
	private:
		std::vector<RationalNumber> array;
		void autoResize();
		int size() const;
};

#endif // POLYNOMIAL_H
