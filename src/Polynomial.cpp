#include "Polynomial.h"

Polynomial::Polynomial(bool x)
{
	if (x)
	{
		array.resize(2);
		array[1] = RationalNumber(1LL);
	}
}

Polynomial::Polynomial(RationalNumber rn, int times)
{
	array.resize(times + 1);
	array[times] = rn;
}

Polynomial Polynomial::operator + (const Polynomial& B) const
{
	Polynomial poly;
	poly.array.resize(std::max(size(), B.size()));
	for (int i = 0; i < std::max(size(), B.size()); ++i)
	{
		if (i < size() && i < B.size())
		{
			poly.array[i] = array[i] + B.array[i];
		}
		else if (i < size())
		{
			poly.array[i] = array[i];
		}
		else
		{
			poly.array[i] = B.array[i];
		}
	}
	poly.autoResize();
	return poly;
}

Polynomial Polynomial::operator - (const Polynomial& B) const
{
	Polynomial poly;
	poly.array.resize(std::max(size(), B.size()));
	for (int i = 0; i < std::max(size(), B.size()); ++i)
	{
		if (i < size() && i < B.size())
		{
			poly.array[i] = array[i] - B.array[i];
		}
		else if (i < size())
		{
			poly.array[i] = array[i];
		}
		else
		{
			poly.array[i] = B.array[i] * RationalNumber(-1LL);
		}
	}
	poly.autoResize();
	return poly;
}

Polynomial Polynomial::operator * (const Polynomial& B) const
{
	Polynomial poly;
	poly.array.resize(std::max(size() + B.size() - 1, 0));
	for (int i = 0; i < size(); ++i)
	{
		for (int j = 0; j < B.size(); ++j)
		{
			poly.array[i + j] = poly.array[i + j] + array[i] * B.array[j];
		}
	}
	poly.autoResize();
	return poly;
}

Polynomial Polynomial::operator / (const Polynomial& B) const
{
	if (B.size() == 0)
	{
		throw std::domain_error("Division by zero!");
	}
	if (this->size() == 0)
	{
		return Polynomial();
	}
	if (size() < B.size())
	{
		throw std::domain_error("Division by polynomial!");
	}
	Polynomial A = *this;
	Polynomial poly;
	poly.array.resize(size() - B.size() + 1);
	for (int i = size() - B.size(); i >= 0; --i)
	{
		poly.array[i] = A.array[i + B.size() - 1] / B.array[B.size() - 1];
		A = A - B * Polynomial(poly.array[i], i);
	}
	A.autoResize();
	if (A.size() != 0 && this->size() > 1)
	{
		throw std::domain_error("Division by polynomial!");
	}
	poly.autoResize();
	return poly;
}

Polynomial Polynomial::operator ^ (const Polynomial& B) const
{
	Polynomial S(RationalNumber(1LL));
	if (B.size() == 0)
	{
		return S;
	}
	if (B.size() > 1 || (this->size() > 1 && !B.array[0].isNonnegativeInteger()))
	{
		throw std::invalid_argument("Invalid exponent!");
	}
	if (!B.array[0].isNonnegativeInteger())
	{
		return Polynomial(this->array[0] ^ B.array[0]);
	}
	Polynomial A = *this;
	long long n = B.array[0].getNumerator();
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

std::ostream& operator << (std::ostream& out, Polynomial poly)
{
	bool first = true;
	for (int i = poly.size() - 1; i >= 0; --i)
	{
		if (!poly.array[i].isZero())
		{
			if (poly.array[i].isPositive() > 0)
			{
				if (!first)
				{
					out << '+';
				}
				if (!(poly.array[i].isUnit() && poly.array[i].isInteger() && i > 0))
				{
					out << poly.array[i];
				}
			}
			else
			{
				if (!(poly.array[i].isUnit() && poly.array[i].isInteger() && i > 0))
				{
					out << poly.array[i];
				}
				else
				{
					out << '-';
				}
			}
			if (i >= 2)
			{
				out << "x^" << i;
			}
			else if (i == 1)
			{
				out << 'x';
			}
			first = false;
		}
	}
	if (first)
	{
		out << '0';
	}
	return out;
}

int Polynomial::size() const
{
	return array.size();
}

void Polynomial::autoResize()
{
	for (int i = size() - 1; i >= -1; --i)
	{
		if (i == -1 || !array[i].isZero())
		{
			array.resize(i + 1);
			break;
		}
	}
}
