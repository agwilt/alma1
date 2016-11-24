//Catalan Reihe

#include <iostream>
#include "largeint.h"

int main(int argc, char *argv[]) {
	/*
	if (argc<3) return 1;
	LargeInt a(std::stoi(argv[1]));
	LargeInt b(std::stoi(argv[2]));
	std::cout << (a*b).decimal() << std::endl;;
	*/
	if (argc<2) return 1;
	int n = std::stoi(argv[1]);

	std::vector<LargeInt> C;
	C.push_back(LargeInt(1)); // 0
	C.push_back(LargeInt(1)); // 1
	//std::cout << "0: 1\n1: 1\n";

	LargeInt sum(0);

	for (int i=1; i<n; ++i) {
		sum = 0;
		for (int k=0; k<=i; ++k) {
			sum  += C[k] * C[i-k];
		}
		C.push_back(sum);
		//std::cout << i+1 << ": " << sum.decimal() << std::endl;
	}
	std::cout << C[n].decimal() << std::endl;
	return 0;
}
