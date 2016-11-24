#include <cmath>
#include <iostream>

double inverse_newton(double n)
{
	double x = 2.823529411764706 - 1.8823529411764706 * n;
	for (int i=0; i<4; ++i)
		x += x*(1-(n*x));
	return x;
}

double divide(double zaehler, double nenner)
{
	while (nenner>1) {
		zaehler/=2;
		nenner/=2;
	}

	double inverse = inverse_newton(nenner);

	return zaehler * inverse;
}

int main()
{
	double zaehler, nenner;

	std::cout << "Zähler: ";
	std::cin >> zaehler;
	std::cout << "Nenner: ";
	std::cin >> nenner;
	printf("\n%g/%g = %.15g\n", zaehler, nenner, divide(zaehler, nenner));

	return 0;
}
