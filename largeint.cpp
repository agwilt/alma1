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


std::string LargeInt::decimal() const   // returns decimal representation
{
    std::string s("");
    for (auto i : _v) {       // range for statement: i runs over all
        s = digits[i] + s;    // elements of _v
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

LargeInt LargeInt::operator*(const LargeInt& arg) const  // multiplication
{
	LargeInt result(*this);
	result *= arg;
	return result;
}

const LargeInt & LargeInt::operator*=(const LargeInt & arg) //multiplication
{
	if (arg._v.size()< 2 && _v.size()<2){					//Termination condition
		int minimulti;

		minimulti=_v[0]*arg._v[0];
		_v.clear();
		_v.push_back(minimulti%10);
		_v.push_back(minimulti/10);	
		return *this;
	}		

	LargeInt x(*this);
	x._v = _v;
	LargeInt y(*this);
	y._v = arg._v;

	if (x._v.size() >= y._v.size()) {
		if (x._v.size() % 2 != 0) {
			x._v.insert(x._v.end(), 0);
		}
		while (x._v.size() > y._v.size()) {
			y._v.insert(y._v.end(), 0);

		}
	}
	else { 
		if (y._v.size() % 2 != 0) {
			y._v.insert(y._v.end(), 0);
		}
		while (y._v.size() > x._v.size()) {
			x._v.insert(x._v.end(), 0);
		}
	}
	
	LargeInt x1(*this);
	unsigned i;
	
	for(i=0;i<x._v.size()/2;++i){						//gives the parts value of respective parts of the argument
		x1._v.push_back(x._v[i+(_v.size()/2)]);	
	}
	LargeInt y1(*this);

	for(i=0;i<y._v.size()/2;++i){
		y1._v.push_back(y._v[i+_v.size()/2]);		
	}
	
	LargeInt x2(*this);
	for(i=0;i<x._v.size()/2;++i){						//gives the parts value of respective parts of the argument
		x2._v.push_back(x._v[i]);		
	}
	LargeInt y2(*this);
	for(i=0;i<y._v.size()/2;++i){
		y2._v.push_back(y._v[i]);	
	}
	int j;
	int e10n = x._v.size();
	int e10n2= (x._v.size()/2)+(x._v.size()%2);
	LargeInt Multi1=x1*y1;							//should add everything up again  from Karatsuba somehow
	LargeInt Multi2=x2*y2;
	LargeInt Multi3=(x1*y2)+(x2*y1)	;
	for (j=0;j<e10n;++j){
		Multi1._v.push_back(0);
	}
	for(j=0;j<e10n2;++j){
		Multi3._v.push_back(0);
	}

	*this=Multi1+Multi3+Multi2;

    return *this;
}
