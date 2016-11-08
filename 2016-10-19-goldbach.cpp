#include <iostream>

/*
 * 2016-10-19-golbach.cpp
 * (Andreas and Jean-Luc)
 *
 * Takes two numbers a and b, (with a>2 and b>=a) and returns the even number c
 * (with a<=c<=b) that has the least sums of two primes (e.g. 68=7+61=31+37).
 *
 * Arguments:
 * ./2016-10-19-golbach a [b] (if no b supplied, b is set to a)
 * or
 * ./2016-10-19-golbach (gets a and b from stdin)
 */

void primes_list(int *primes, bool *is_prime, int b)
{
	int p_length = 0;

	for (int i=0; i<b; ++i) is_prime[i] = true;
	// Start sieving for primes.
	// Initialize is_prime as true everywhere
	for (int i=2; i<b; ++i) {
		if (is_prime[i]) {
			primes[p_length] = i;
			++p_length;
			// Set multiples of i to false
			for (int j=i; j<(b/i); ++j) is_prime[i*j]=false;
		}
	}
}

void output_sums(int *primes, bool *is_prime, int c)
{
	for (int *p = primes; *p <= (c/2); ++p) {
		if (is_prime[c-*p])
			std::cout << c << " = " << *p << " + " << c-*p << "\n";
	}
}

void error(const char *string)
{
	std::cerr << string;
	exit(1);
}

int main(int argc, char *argv[])
{
	int user_a, a, b;

	// argc==1: stdin, argc==2: b=a=argv[1], argc>2: b,a from argv
	if (argc==1) {
		std::cout << "Enter a: ";
		std::cin >> a;
		if (std::cin.fail()) error("Error: Bad input.\n");
		std::cout << "Enter b: ";
		std::cin >> b;
		if (std::cin.fail()) error("Error: Bad input.\n");
	} else {
		a = atoi(argv[1]);
		// If only one argument was supplied, set b=a
		if (argc>=3) b = atoi(argv[2]);
		else b = a;
	}

	// Error if a or b aren't over 2
	if (a<=2)
		error("Please make sure a is over 2.\n");

	// Change to b<=a for stricter error checking
	if ((argc==2) && (a%2))
		error("Even numbers only, please.\n");
	if ((argc!=2) && (b <= a))
		error("Oh dear. It would seem that b isn't greater than a ....\n");

	// If a is odd, increment it
	user_a = a; //nice output
	if (a%2) ++a;

	/*
	 * Setup done, proceed to find some primes
	 */

	// Declare list of primes and bool array is_prime
	int *primes = new int[b];
	bool *is_prime = new bool[b];
	// Populate primes and is_prime.
	primes_list(primes, is_prime, b);

	/*
	 * Primes found, now count sums
	 */

	/* min: number between a and b with the smallest number of prime sums
	 * sums: the (current) smallest number of sums
	 * sums_temp: number of sums for the current c
	 */
	int min=0; // Initialize to suppress stupid compiler warnings
	int sums_temp, sums = b; // definitely bigger than everything

	// Now count sums for all even ints between a and b
	for (int c=a; c<=b; c+=2) {
		sums_temp = 0;
		// Go through all primes <= c/2 and check if c-prime is prime.
		for (int *p = primes; *p <= (c/2); ++p) {
			// Stop if c already has as many sums as the minimum
			if (sums_temp >= sums) break;
			// If a prime sum was found, increment counter
			if (is_prime[c-*p]) ++sums_temp;
		}
		// Update sums and min if a "better" c was found
		if (sums_temp < sums) {
			sums = sums_temp;
			min = c;
		}
	}

	// Output min, sums, and all of min's sums.
	output_sums(primes, is_prime, min);

	if (argc==2) //only one number supplied
		std::cout << "Total: " << sums << " prime sums.\n";
	else
		std::cout << "Even number between " << user_a << " and " << b
		<< " with the least prime sums:\t" << min << " has "
		<< sums << " sum" << ((sums>1)?"s":"") << ".\n";
}
