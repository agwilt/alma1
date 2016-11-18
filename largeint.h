// largeint.h (Declaration of Class LargeInt)

#include <vector>
#include <iostream>
#include <string>

inline int max(int a, int b) { return (a>b)?a:b; }

class LargeInt {
public:
	using inputtype = long long;

	LargeInt(inputtype);				// constructor
	std::string decimal() const;			// decimal representation
	bool operator<(const LargeInt &) const;		// comparison
	bool operator>(const LargeInt &) const;		// other comparison
	LargeInt operator+(const LargeInt &) const;	// addition
	const LargeInt & operator+=(const LargeInt &);	// addition
	const LargeInt & operator-=(const LargeInt &);	// subtraction
	const LargeInt & operator*=(const LargeInt&);	// multiplication
	LargeInt operator*(const LargeInt&) const;	// multiplication
	LargeInt operator+(const LargeInt &) const;	// addition
	LargeInt operator-(const LargeInt &) const;	// subtraction
	LargeInt timesten(int n); 			// multiplied by 10**n
	
private:
	std::vector<short> _v;				// store single digits, last digit in _v[0]
	static const std::string digits;
};
