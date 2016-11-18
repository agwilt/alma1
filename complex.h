#include <string>

class Complex
{
	public:
		Complex(double, double);

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

		double real() const;
		double imag() const;
		double abs() const;

	private:
		double Re, Im;
};
