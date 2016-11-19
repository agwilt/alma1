//Catalan Reihe

#include <iostream>
#include "largeint.h"
#include <vector>

/*void Multi(int n,std::vector<LargeInt> resultmulti){
	int i=0;
	int j;
	resultmulti[0]=1;
	resultmulti[1]=1;
	while (i<n){
	LargeInt sum(0);
		for (j=1;j<=n;++j){
			sum=sum+resultmulti[i]*resultmulti[i-j];
		}
		resultmulti.push_back(sum);
		++i;
	}
}*/

int main(){
	 LargeInt a = LargeInt(11);
	 LargeInt b = LargeInt(20);
	 LargeInt produkt = a * b;
	 std::cout << produkt.decimal();

	/*int n;
	std::cout<< "Enter an LargeInteger: ";
	std::cin>> n;
	std::cout<< "The number is ";
	std::cout <<"\n";
	std::vector<LargeInt> resultmulti;
	Multi(5,resultmulti);
	*/
	return 0;
}
