#include <iostream>
#include "largeint.h"

int main(int argc, char *argv[])
{
	if (argc<3) return 3;
	LargeInt a(atoi(argv[1]));
	LargeInt b(atoi(argv[2]));
	std::cout << (a*b).decimal() << std::endl;
	return 0;
}
