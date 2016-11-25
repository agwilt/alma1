#include <cmath>
#include <iostream>
#include <string>

template <class T>
class Complex
{
	public:
		Complex(T, T);

		std::string repr() const;

		const Complex & operator+=(const Complex &);
		const Complex & operator-=(const Complex &);
		const Complex & operator*=(const Complex &);
		const Complex & operator/=(const Complex &);

		Complex operator+(const Complex &) const;
		Complex operator-(const Complex &) const;
		Complex operator*(const Complex &) const;
		Complex operator/(const Complex &) const;

		Complex operator!() const;

		Complex inverse() const;

		T real() const;
		T imag() const;
		T abs() const;

	private:
		T Re, Im;
};

template <class T>
Complex<T>::Complex(T real, T imag)
{
	Re = real;
	Im = imag;
}

template <class T>
std::string Complex<T>::repr() const
{
	std::string s("");
	s += std::to_string(Re) + ((Im<0)?"":"+") + std::to_string(Im) + "*i";
	return s;
}

template <class T>
const Complex<T> & Complex<T>::operator+=(const Complex &c)
{
	Re += c.real();
	Im += c.imag();
	return *this;
}

template <class T>
const Complex<T> & Complex<T>::operator-=(const Complex &c)
{
	Re -= c.real();
	Im -= c.imag();
	return *this;
}

template <class T>
const Complex<T> & Complex<T>::operator*=(const Complex &c)
{
	T real = Re*c.real() - Im*c.imag();
	T imag = Re*c.imag() + Im*c.real();
	Re = real;
	Im = imag;
	return *this;
}

template <class T>
const Complex<T> & Complex<T>::operator/=(const Complex &c)
{
	T factor = c.real()*c.real() + c.imag()*c.imag();
	T real = c.real()*Re + Im*c.imag();
	T imag = Im*c.real() - Re*c.imag();
	Re = real/factor;
	Im = imag/factor;
	return *this;
}

template <class T>
Complex<T> Complex<T>::operator+(const Complex &c) const
{
	return Complex<T>(Re+c.real(), Im+c.imag());
}

template <class T>
Complex<T> Complex<T>::operator-(const Complex &c) const
{
	return Complex<T>(Re-c.real(), Im-c.imag());
}

template <class T>
Complex<T> Complex<T>::operator*(const Complex &c) const
{
	return Complex<T>((Re*c.real() - Im*c.imag()),(Re*c.imag() + Im*c.real()));
}

template <class T>
Complex<T> Complex<T>::operator/(const Complex &c) const
{
	T factor = c.real()*c.real() + c.imag()*c.imag();
	return Complex<T>((c.real()*Re + Im*c.imag())/factor, (Im*c.real() - Re*c.imag())/factor);
}

template <class T>
Complex<T> Complex<T>::operator!() const
{
	return Complex<T>(Re, -Im);
}

template <class T>
Complex<T> Complex<T>::inverse() const
{
	T factor = Re*Re + Im*Im;
	return Complex<T>(Re/factor, -Im/factor);
}

template <class T>
T Complex<T>::real() const
{
	return Re;
}

template <class T>
T Complex<T>::imag() const
{
	return Im;
}

template <class T>
T Complex<T>::abs() const
{
	return std::sqrt(Im*Im + Re*Re);
}
