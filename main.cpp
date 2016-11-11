#include <iostream>
#include "largeint.h"

int main(int argc, char *argv[])
{
	LargeInt a(atoi(argv[1]));
	LargeInt b(atoi(argv[2]));
	std::cout << (a*b).decimal() << std::endl;
	return 0;
}
