#include <iostream>

int main(int argc, char *argv[])
{
	if (argc<3) {
		std::cerr << argv[0] << ": Error: a or b not specified.\n";
		return 1;
	}

	int a = atoi(argv[1]);
	int b = atoi(argv[2]);

	if (b<4 or a<4) {
		std::cerr << "Please make sure a and b are at least 4.\n";
		return 1;
	}

	if (b < a) {
		std::cerr << "Seriously?\n";
		return 1;
	}

	int *primes = new int[b];
	int p_length = 0;

	// Fill prime array
	bool *is_prime = new bool[b];
	for (int i=0; i<b; ++i) is_prime[i] = true;
	for (int i=2; i<b; ++i) {
		if (is_prime[i]) {
			primes[p_length] = i;
			p_length++;
			for (int j=i; j<=(b/i); j++) is_prime[j*i]=false;
		}
	}

	int min;
	int sums_temp, sums = b; // definitely bigger than everything
	if (a%2) { //if a odd
		a++;
	}

	// now count for all even ints between a and b
	for (int c=a; c<=b; c+=2) {
		sums_temp = 0;
		for (int i=0; primes[i]<=(c/2); i++) {
			if (sums_temp >= sums) break;
			if (is_prime[c-primes[i]]) {
				sums_temp++;
			}
		}
		if (sums_temp < sums) {
			sums = sums_temp;
			min = c;
		}
	}

	std::cout << "Even number between " << a << " and " << b << " with the least prime sums:\n";
	std::cout << min << " has " << sums << ":\n";
	for (int i=0; primes[i]<=(min/2); ++i) {
		int p = primes[i];
		if (is_prime[min-p]) {
			std::cout << p << " + " << min-p << "\n";
		}
	}
}
