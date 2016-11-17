//Catalan Reihe

#include <iostream>
#include "largeint.h"
#include <vector>

void Multi(int n,std::vector<LargeInt> resultmulti){
	int i=0;
	resultmulti1[0]=1;
	resultmulti1[1]=1;
	while (i<n){
	LargeInt sum(0);
		for (unsigned j=1;j<=n;++j){
			sum=sum+resultmulti[i]*resultmulti[i-j]
		}
		resultmulti1.push.back(sum);
		++i;
	}
}

int main(){
	int n;
	std::cout<< "Enter an LargeInteger: ";
	std::cin>> n;
	std::cout<< "The number is ";
	std::cout <<"\n";
	std::vector<LargeInt> resultmulti;
	Multi(5,resultmulti);
}
