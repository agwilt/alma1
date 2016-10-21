#include <iostream>

int main(int argc, char *argv[])
{
	// Exit with an error message if not enough arguments received.
	if (argc<3) {
		std::cerr << argv[0] << ": Error: a or b not specified.\n";
		return 1;
	}

	// Then get a and b from argv (TODO: Safer method)
	int a = atoi(argv[1]);
	int b = atoi(argv[2]);

	// Error if a or b are under 4
	if (b<4 or a<4) {
		std::cerr << "Please make sure a and b are at least 4.\n";
		return 1;
	}

	/* Tell the user he's an idiot if he input stupid numbers.
	 * Technically, it should only accept b>a, but it's useful to find the
	 * number of prime sums a single number has.
	 */
	if (b < a) {
		std::cerr << "Seriously?\n";
		return 1;
	}

	// Initialize array to store my list of primes, along with its length
	int *primes = new int[b];
	int p_length = 0;

	// Start sieving for primes
	// is_prime is very useful later on to check if a number is prime
	bool *is_prime = new bool[b];
	// Initialize is_prime as true everywhere
	for (int i=0; i<b; ++i) is_prime[i] = true;
	for (int i=2; i<b; ++i) {
		if (is_prime[i]) {
			primes[p_length] = i;
			p_length++;
			for (int j=i; j<=(b/i); j++) is_prime[j*i]=false;
		}
	}

	// min: number between a and b with the smallest number of prime sums
	// sums: the (current) smallest number of sums
	// sums_temp: number of sums for the current c
	int min;
	int sums_temp, sums = b; // definitely bigger than everything

	// If a is odd, increment it
	if (a%2) a++;

	// Now count sums for all even ints between a and b
	for (int c=a; c<=b; c+=2) {
		sums_temp = 0;
		// Go through all primes <= c/2 and check if c-prime is prime.
		for (int i=0; primes[i]<=(c/2); i++) {
			// Stop if c already has as many sums as the minimum
			if (sums_temp >= sums) break;
			// If a prime sum was found, increment counter
			if (is_prime[c-primes[i]]) sums_temp++;
		}
		// Update sums and min if a "better" c was found
		if (sums_temp < sums) {
			sums = sums_temp;
			min = c;
		}
	}

	// Loop to output min, sums, and all of min's sums.
	std::cout << "Even number between " << a << " and " << b << " with the least prime sums:\n";
	std::cout << min << " has " << sums << ":\n";

	for (int i=0; primes[i]<=(min/2); ++i) {
		int p = primes[i];
		if (is_prime[min-p]) std::cout << p << " + " << min-p << "\n";
	}
}
