#ifndef _RATIONAL_NUMBER_HPP_
#define _RATIONAL_NUMBER_HPP_

#include <iostream>

class RationalNumber
{
private:
	int m_numerator, m_denominator;
	void Simplify();

public:

	RationalNumber(int _numerator, int _denominator);

	int getNumerator() const;
	int getDenominator() const;
	
	
	RationalNumber operator+= (RationalNumber & num);
	RationalNumber operator-= (RationalNumber & num);
	RationalNumber operator*= (RationalNumber & num);
	RationalNumber operator/=(RationalNumber & num);

	bool operator == (RationalNumber & num) const;
	bool operator != (RationalNumber & num) const;
	bool operator < (RationalNumber & num) const;
	bool operator <= (RationalNumber & num) const;
	bool operator > (RationalNumber & num) const;
	bool operator >= (RationalNumber & num) const;

	operator double () 
	{ 
		return m_numerator / (double) m_denominator; 
	}

};

int NOD(int _numerator, int _denominator);

RationalNumber operator+ (const RationalNumber & num1, const RationalNumber & num2);
RationalNumber operator* (const RationalNumber & num1, const RationalNumber & num2);
RationalNumber operator- (const RationalNumber & num1, const RationalNumber & num2);
RationalNumber operator/ (const RationalNumber & num1, const RationalNumber & num2);

inline int RationalNumber::getNumerator() const
{
	return m_numerator;
}

inline int RationalNumber::getDenominator() const
{
	return m_denominator;
}

std::ostream & operator << (std::ostream & o, RationalNumber & num);

#endif //  _RATIONAL_NUMBER_HPP_