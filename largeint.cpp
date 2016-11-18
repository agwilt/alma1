// largeint.cpp (Implementation of Class LargeInt)

#include "largeint.h"

const std::string LargeInt::digits = "0123456789";

LargeInt::LargeInt(inputtype i)   // constructor, calls constructor of vector
{
	do {
		v.push_back(i % 10);
		i /= 10;
	} while (i > 0);
}


std::string LargeInt::decimal() const   // returns decimal representation
{
	std::string s("");
	for (auto i : _v) {	   // range for statement: i runs over all
		s = digits[i] + s;	// elements of _v
	}
	return s;
}


bool LargeInt::operator<(const LargeInt & arg) const   // checks if < arg
{
	if (_v.size() == arg._v.size()) {
		auto it2 = arg._v.rbegin();
	for (auto it1 = _v.rbegin(); it1 != _v.rend(); ++it1, ++it2) {
		if (*it1 < *it2) return true;
		if (*it1 > *it2) return false;
	}
		return false;
	}
	return _v.size() < arg._v.size();
}


LargeInt LargeInt::operator+(const LargeInt & arg) const  // addition
{
	LargeInt result(*this);
	result += arg;
	return result;
}


const LargeInt & LargeInt::operator+=(const LargeInt & arg)   // addition
{
	if (arg._v.size() > _v.size()) {
		_v.resize(arg._v.size(), 0);
	}
	auto it1 = _v.begin();
	for (auto it2 = arg._v.begin(); it2 != arg._v.end(); ++it2, ++it1) {
		*it1 += *it2;
	}
	short carry = 0;
	for (auto & i : _v) {
		i += carry;
		carry = i / 10;
		i %= 10;
	}
	if (carry != 0) _v.push_back(carry);
	return *this;
}
