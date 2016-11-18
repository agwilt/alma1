// largeint.cpp (Implementation of Class LargeInt)

#include "largeint.h"
#include <iostream>

const std::string LargeInt::digits = "0123456789";


LargeInt::LargeInt(inputtype i)   // constructor, calls constructor of vector
{
	do {
		_v.push_back(i % 10);
		i /= 10;
	} while (i > 0);
}

LargeInt::LargeInt(std::vector<short> vector)
{
	_v = vector;
}


std::string LargeInt::decimal() const   // returns decimal representation
{
	std::string s("");
	for (auto i : _v) {	   // range for statement: i runs over all
		s = digits[i] + s;	// elements of _v
	}
	return s;
}


bool LargeInt::operator>(const LargeInt & arg) const   // checks if > arg
{
	if (_v.size() == arg._v.size()) {
		auto it2 = arg._v.rbegin();
		for (auto it1 = _v.rbegin(); it1 != _v.rend(); ++it1, ++it2) {
			if (*it1 > *it2) return true;
			if (*it1 < *it2) return false;
		}
		return false;
	}
	return _v.size() > arg._v.size();
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

LargeInt LargeInt::operator-(const LargeInt & arg) const  // subtraction
{
	LargeInt result(*this);
	result -= arg;
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

const LargeInt & LargeInt::operator-=(const LargeInt & arg) // subtraction
{
	if (arg > *this) {
		throw std::invalid_argument( "arg larger than this" );
	}
	auto it1 = _v.begin();
	for (auto it2 = arg._v.begin(); it2 != arg._v.end(); ++it2, ++it1) {
		*it1 -= *it2;
	}
	short carry = 0;
	for (auto & i : _v) {
		i -= carry;
		carry = (i<0)?1:0;
		i += carry*10;
	}
	while (_v.back() == 0 && _v.size() > 1) _v.pop_back();
	return *this;
}

LargeInt LargeInt::timesten(int n)
{
	while (n --> 0)
		_v.insert(_v.begin(), 0);
	return *this;
}

LargeInt LargeInt::operator*(const LargeInt & arg) const // multiplication
{
	if (_v.size() == 1 && arg._v.size() == 1) {
		inputtype value = _v[0]*arg._v[0];
		std::cout << "Short option!\n";
		return LargeInt(value);
	}
	int n = max(_v.size(), arg._v.size())/2;
	std::vector<short> this_1_v(_v.begin(), _v.begin()+n);
	std::vector<short> this_2_v(_v.begin()+n, _v.end());
	std::vector<short> arg_1_v(_v.begin(), _v.begin()+n);
	std::vector<short> arg_2_v(_v.begin()+n, _v.end());
	LargeInt this_1(this_1_v);
	LargeInt this_2(this_2_v);
	LargeInt arg_1(arg_1_v);
	LargeInt arg_2(arg_2_v);
	LargeInt p = this_1*arg_1;
	LargeInt q = this_2*arg_2;
	LargeInt r = (this_1+this_2)*(arg_1+arg_2);
	return p.timesten(2*n) + (r-p-q).timesten(n) +q;
}
