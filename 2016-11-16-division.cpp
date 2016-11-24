#include <iostream>

typedef union {
	double number;
	long data;
} fp_hack;

int main()
{
	fp_hack zaehler, nenner;
	double inverse;
	std::cout << "Zähler: ";
	std::cin >> zaehler.number;
	std::cout << "Nenner: ";
	std::cin >> nenner.number;

	if (nenner.number<0) {
		nenner.number *= -1;
		zaehler.number *= -1;
	}

	// Bit magic
	long diff = (nenner.data - (1022l<<52)) & 0xfff0000000000000;
	zaehler.data -= diff;
	nenner.data -= diff;

	// Magic starting values from Wikipedia
	inverse = 2.823529411764706 - 1.8823529411764706 * nenner.number;
	// One or two Newton method iterations
	for (int i=0; i<4; ++i)
		inverse += inverse*(1-(nenner.number*inverse));

	printf("%.15g\n", zaehler.number*inverse);
}
