//Catalan Reihe

#include <iostream>
#include "largeint.h"

int main(int argc, char *argv[]) {
	/*
	if (argc<3) return 1;
	LargeInt a(atoi(argv[1]));
	LargeInt b(atoi(argv[2]));
	std::cout << (a*b).decimal() << std::endl;;
	*/
	if (argc<2) return 1;
	int n = atoi(argv[1]);

	std::vector<LargeInt> C;
	C.push_back(LargeInt(1));
	C.push_back(LargeInt(1));

	LargeInt sum(0);

	for (int i=1; i<=n; ++i) {

		sum = LargeInt(0);
		for (int k=0; k<=i; ++k) {
			sum  += C[k] * C[i-k];
		}
		C.push_back(sum);
	}
	std::cout << C[n].decimal() << std::endl;
	return 0;
}
