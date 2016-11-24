// largeint.cpp (Implementation of Class LargeInt)

#include "largeint.h"

const std::string LargeInt::digits = "0123456789";

LargeInt::LargeInt(inputtype i)   // constructor, calls constructor of vector
{
	do {
		_v.push_back(i % 10);
		i /= 10;
	} while (i > 0);
}

const LargeInt & LargeInt::strip_trailing()
{
	while (_v.size() > 1 && _v.back() == 0) {
		_v.pop_back();
	}
	return *this;
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
	if (carry != 0){
		_v.push_back(carry);
	}
	return *this;
}

LargeInt LargeInt::operator-(const LargeInt & arg) const  // subtraction
{
	LargeInt result(*this);
	result -= arg;
	return result;
}

const LargeInt & LargeInt::operator-=(const LargeInt & arg) // subtraction
{
	if (arg > *this) {
		throw std::invalid_argument("arg larger than this");
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
	LargeInt ans(*this);
	//while (n --> 0)
		ans._v.insert(ans._v.begin(), n, 0);
	return ans;
}

LargeInt LargeInt::operator*(const LargeInt & arg) const // multiplication
{
	if ((_v.size() == 1 && _v[0]==0) || (arg._v.size() == 1 && arg._v[0]==0))
		return LargeInt(0);
	if (_v.size() == 1 && arg._v.size() == 1)
		return LargeInt(_v[0]*arg._v[0]);

	int l = max(_v.size(), arg._v.size());
	int n = l/2;

	LargeInt this_significant(*this);
	LargeInt this_insig(*this);
	LargeInt arg_significant(arg);
	LargeInt arg_insig(arg);

	// Pad all numbers with 0s
	while (this_significant._v.size() < arg._v.size()) {
		this_significant._v.push_back(0);
		this_insig._v.push_back(0);
	}
	while (arg_significant._v.size() < _v.size()) {
		arg_significant._v.push_back(0);
		arg_insig._v.push_back(0);
	}

	// "Split" the two vectors
	for (int i=0; i<(l-n); ++i) {
		this_insig._v.pop_back();
		arg_insig._v.pop_back();
	}
	for (int i=0; i<n; ++i) {
		this_significant._v.erase(this_significant._v.begin());
		arg_significant._v.erase(arg_significant._v.begin());
	}

	// Strip trailing 0s
	this_significant.strip_trailing();
	this_insig.strip_trailing();
	arg_significant.strip_trailing();
	arg_insig.strip_trailing();

	LargeInt p = this_significant*arg_significant;
	LargeInt q = this_insig*arg_insig;
	LargeInt r = (this_significant+this_insig)*(arg_significant+arg_insig);
	return (p.timesten(2*n) + (r-p-q).timesten(n) + q).strip_trailing();
}
