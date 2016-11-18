#include "complex.h"
#include <cmath>
#include <iostream>
#include <string>

Complex::Complex(double real, double imag)
{
	Re = real;
	Im = imag;
}

std::string Complex::repr() const
{
	std::string s("");
	s += std::to_string(Re) + (Im<0)?"":"+" + std::to_string(Im) + "*i";
	return s;
}

const Complex & Complex::operator+=(const Complex &c)
{
	Re += c.real();
	Im += c.imag();
	return *this;
}

const Complex & Complex::operator-=(const Complex &c)
{
	Re -= c.real();
	Im -= c.imag();
	return *this;
}

const Complex & Complex::operator*=(const Complex &c)
{
	double real = Re*c.real() - Im*c.imag();
	double imag = Re*c.imag() + Im*c.real();
	Re = real;
	Im = imag;
	return *this;
}

const Complex & Complex::operator/=(const Complex &c)
{
	double factor = c.real()*c.real() + c.imag()*c.imag();
	double real = c.real()*Re + Im*c.imag();
	double imag = Im*c.real() - Re*c.imag();
	Re = real/factor;
	Im = imag/factor;
	return *this;
}

Complex Complex::operator+(const Complex &c) const
{
	return Complex(Re+c.real(), Im+c.imag());
}

Complex Complex::operator-(const Complex &c) const
{
	return Complex(Re-c.real(), Im-c.imag());
}

Complex Complex::operator*(const Complex &c) const
{
	return Complex((Re*c.real() - Im*c.imag()),(Re*c.imag() + Im*c.real()));
}

Complex Complex::operator/(const Complex &c) const
{
	double factor = c.real()*c.real() + c.imag()*c.imag();
	return Complex((c.real()*Re + Im*c.imag())/factor, (Im*c.real() - Re*c.imag())/factor);
}

Complex Complex::operator!() const
{
	return Complex(Re, -Im);
}

Complex Complex::inverse() const
{
	double factor = Re*Re + Im*Im;
	return Complex(Re/factor, -Im/factor);
}

double Complex::real() const
{
	return Re;
}

double Complex::imag() const
{
	return Im;
}

double Complex::abs() const
{
	return std::sqrt(Im*Im + Re*Re);
}
