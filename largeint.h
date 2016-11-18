// largeint.h (Declaration of Class LargeInt)

#include <vector>
#include <iostream>
#include <string>


class LargeInt {
public:
	using inputtype = long long;

	LargeInt(inputtype);				// constructor
	std::string decimal() const;			// decimal representation
	bool operator<(const LargeInt &) const;		// comparison
	LargeInt operator+(const LargeInt &) const;	// addition
	const LargeInt & operator+=(const LargeInt &);	// addition
	const LargeInt & operator*=(const LargeInt&);
	LargeInt operator*(const LargeInt&) const;

private:
	std::vector<short> _v;				// store single digits, last digit in _v[0]
	static const std::string digits;
};
