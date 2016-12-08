#include <iostream>
#include <iomanip>

// To store a double in .number and mess with it using .data
typedef union {
	double number;
	unsigned long data;
} fp_hack;

int main()
{
	fp_hack zaehler, nenner;
	double inverse;

	// Get input from user. We're supposed to take ints, but that's just stupid.
	std::cout << "Zähler: ";
	std::flush(std::cout);
	if (! (std::cin >> zaehler.number)) return 1;
	std::cout << "Nenner: ";
	std::flush(std::cout);
	if (! (std::cin >> nenner.number)) return 1;

	// Check for 0
	if (nenner.number == 0) {
		std::cerr << "Don't be an idiot.\n";
		return 1;
	}

	// Bit magic spell is broken if zaehler=0
	if (zaehler.number == 0) {
		std::cout << 0 << std::endl;
		return 0;
	}

	// Make sure the denominator is positive
	if (nenner.number<0) {
		nenner.number *= -1;
		zaehler.number *= -1;
	}

	// Diff is the exponent differenc to subtract from zaehler and nenner, so
	// that nenner's exponent is -1
	unsigned long diff = (nenner.data - (1022lu<<52)) & 0xfff0000000000000;
	zaehler.data -= diff;
	nenner.data -= diff;

	// Magic starting values from Wikipedia
	inverse = 2.823529411764706 - 1.8823529411764706 * nenner.number;
	// One or two Newton method iterations
	for (int i=0; i<4; ++i)
		inverse *= 2-(nenner.number*inverse);

	// Output with 15 digits
	std::cout << std::setprecision(15) << zaehler.number*inverse << std::endl;
}
