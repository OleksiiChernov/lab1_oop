
#include "rational_number.hpp"

#include <stdexcept>


RationalNumber::RationalNumber(int _numerator, int _denominator)
{
	m_numerator = _numerator;

	if (_denominator == 0)
		throw std::logic_error("Zero denominator");
	else if (_denominator < 0)
	{
		m_numerator = -m_numerator;
		m_denominator = -_denominator;
	}
	else
		m_denominator = _denominator;
	Simplify();
}




inline void RationalNumber::Simplify()
{
	int a = (m_numerator < 0) ? -m_numerator : m_numerator;
	int b = m_denominator;

	int c;
	while (a != 0)
	{
		c = a;
		a = b % a;
		b = c;
	}

	m_numerator /= b;
	m_denominator /= b;
}


int NOD(int _numerator, int _denominator)
{
		if (_denominator == 0)
			return _numerator;
		if (_numerator % _denominator == 0)
			return 1;
		return NOD(_denominator, _numerator % _denominator);
}



RationalNumber operator+(const RationalNumber & num1, const RationalNumber & num2)
{
	int _numerator1 = num1.getNumerator();
	int _denominator1 = num1.getDenominator();
	int _numerator2 = num2.getNumerator();
	int _denominator2 = num2.getDenominator();
	int nod = NOD(_denominator1, _denominator2);
	
	int num , den;
	if (_denominator1 < _denominator2)
	{
		den = _denominator1 * _denominator2;
		num = (_numerator1 * _denominator2) + (_numerator2 * _denominator1);

	}
	else if (_denominator1 == _denominator2)
	{
		num = _numerator1 + _numerator2;
		den = _denominator1;
	}
	else
	{
		num = _numerator2 + ((nod / _denominator2) * _numerator1);
		den = ((nod/_denominator1) * _denominator1);
	}

	RationalNumber x(num, den);
	return(x);
}


RationalNumber RationalNumber::operator+=(RationalNumber & num)
{
	int _numerator = num.getNumerator();
	int _denominator = num.getDenominator();
	int nod = NOD(_denominator, m_denominator);

	if (_denominator > m_denominator)
	{
		m_numerator = (m_numerator * _denominator) + (_numerator * m_denominator);
		m_denominator = (m_denominator * _denominator);
	}
	else if (_denominator == m_denominator)
		m_numerator = m_numerator + _numerator;
	else
	{
		m_numerator = m_numerator + (nod * _numerator);
		m_denominator = ((nod/m_denominator) * _denominator);
	}
	Simplify();
	return(*this);
}


RationalNumber operator-(const RationalNumber & num1, const RationalNumber & num2)
{
	int _numerator1 = num1.getNumerator();
	int _denominator1 = num1.getDenominator();
	int _numerator2 = num2.getNumerator();
	int _denominator2 = num2.getDenominator();
	int nod = NOD(_denominator1, _denominator2);

	int num, den;
	if (_denominator1 < _denominator2)
	{
		den = _denominator1 * _denominator2;
		num = (_numerator1 * _denominator2) - (_numerator2 * _denominator1);
	}
	else if (_denominator1 == _denominator2)
	{
		num = _numerator1 - _numerator2;
		den = _denominator1;
	}
	else
	{
		num = _numerator2 - ((nod/_denominator2) * _numerator1);
		den = ((nod/_denominator1) * _denominator1);
	}
	RationalNumber x(num, den);
	return(x);
}


RationalNumber RationalNumber::operator-=(RationalNumber & num)
{
	int _numerator = num.getNumerator();
	int _denominator = num.getDenominator();
	int nod = NOD(_denominator, m_denominator);

	if (_denominator > m_denominator)
	{
		m_numerator = (m_numerator * _denominator) - (_numerator * m_denominator);
		m_denominator = (m_denominator * _denominator);
	}
	else if (_denominator == m_denominator)
		m_numerator = m_numerator - _numerator;
	else
	{
		m_numerator = m_numerator - ((nod/_denominator) * _numerator);
		m_denominator = ((nod/m_denominator) * _denominator);
	}
	Simplify();
	return(*this);
}


RationalNumber operator*(const RationalNumber & num1, const RationalNumber & num2)
{
	int num, den;

	num = num1.getNumerator() * num2.getNumerator();
	den = num1.getDenominator() * num2.getDenominator();

	RationalNumber x(num, den);

	return(x);
}


RationalNumber RationalNumber::operator*=(RationalNumber & num)
{
	int _numerator = num.getNumerator();
	int _denominator = num.getDenominator();

	m_numerator = m_numerator * _numerator;
	m_denominator = m_denominator * _denominator;

	Simplify();
	return(*this);
}


RationalNumber operator/(const RationalNumber & num1, const RationalNumber & num2)
{
	int num, den;

	num = num1.getNumerator() * num2.getDenominator();
	den = num1.getDenominator() * num2.getNumerator();

	RationalNumber x(num, den);

	return(x);
}


RationalNumber RationalNumber::operator/=(RationalNumber & num)
{
	int _numerator = num.getNumerator();
	int _denominator = num.getDenominator();

	m_numerator = m_numerator * _denominator;
	m_denominator = m_denominator * _numerator;

	Simplify();
	return(*this);
}


bool RationalNumber::operator == (RationalNumber & num) const
{
	return (m_numerator == num.m_numerator) && (m_denominator == num.m_denominator);
}


bool RationalNumber::operator != (RationalNumber & num) const
{
	return ! (*this == num);
}


bool RationalNumber::operator < (RationalNumber & num) const
{
	return(m_numerator < num.m_numerator && (m_denominator < num.m_denominator || m_denominator == num.m_denominator));
}


bool RationalNumber::operator <= (RationalNumber & num) const
{
	return((m_numerator < num.m_numerator || m_numerator == num.m_numerator) && 
		(m_denominator < num.m_denominator || m_denominator == num.m_denominator));
}


bool RationalNumber::operator > (RationalNumber & num) const
{
	return(m_numerator > num.m_numerator && (m_denominator > num.m_denominator || m_denominator == num.m_denominator));
}


bool RationalNumber::operator >= (RationalNumber & num) const
{
	return((m_numerator > num.m_numerator || m_numerator == num.m_numerator) && 
		(m_denominator > num.m_denominator || m_denominator == num.m_denominator));
}


std::ostream & operator << (std::ostream & stream, RationalNumber & num)
{
	stream << num.getNumerator() << "/" << num.getDenominator();
	return stream;
}