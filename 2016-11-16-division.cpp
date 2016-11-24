#include <iostream>

// To store a double in .number and mess with it using .data
typedef union {
	double number;
	long data;
} fp_hack;

int main()
{
	fp_hack zaehler, nenner;
	double inverse;

	// Get input from user. We're supposed to take ints, but that's just stupid.
	std::cout << "Zähler: ";
	std::cin >> zaehler.number;
	std::cout << "Nenner: ";
	std::cin >> nenner.number;

	// Make sure the denominator is positive
	if (nenner.number<0) {
		nenner.number *= -1;
		zaehler.number *= -1;
	}

	// Bit magic. 0xc020000000000000 = K_2(1022l<<52)
	// Diff is the exponent differenc to subtract from zaehler and nenner, so
	// that nenner's exponent is -1
	long diff = (nenner.data + 0xc020000000000000) & 0xfff0000000000000;
	zaehler.data -= diff;
	nenner.data -= diff;

	// Magic starting values from Wikipedia
	inverse = 2.823529411764706 - 1.8823529411764706 * nenner.number;
	// One or two Newton method iterations
	for (int i=0; i<4; ++i)
		inverse += inverse*(1-(nenner.number*inverse));

	// Output using printf (to specify the number of digits to print)
	printf("%.15g\n", zaehler.number*inverse);
}
