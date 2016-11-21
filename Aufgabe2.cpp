//Catalan Reihe

#include <iostream>
#include "largeint.h"
#include <vector>

void Multi(int n,std::vector<LargeInt> resultmulti){
	int i=0;
	int j;
	resultmulti[0]=1;
	resultmulti[1]=1;
	while (i<n){
	LargeInt sum(0);
		for (j=1;j<=n;++j){
			sum=sum+resultmulti[i]*resultmulti[i-j-1];
		}
		resultmulti.push_back(sum);
		++i;
	}
}

int main(){
	 /*LargeInt a = LargeInt(1127143430);
	 LargeInt b = LargeInt(2044534531);
	 LargeInt produkt = a * b;
	 std::cout << produkt.decimal();*/

	int n;
	std::cout<< "Enter an Integer: ";
	std::cin>> n;
	std::vector<LargeInt> resultmulti;
	Multi(n,resultmulti);
	std::cout<< "The number is ";
	std::cout <<"\n";
	std::cout << resultmulti[resultmulti.size()-1].decimal();
	
	
	return 0;
}
