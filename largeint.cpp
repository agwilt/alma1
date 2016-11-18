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
	} else { //y._v.size() > x._v.size()
		if (y._v.size() % 2 != 0) {
			y._v.insert(y._v.end(), 0);
		}
		while (y._v.size() > x._v.size()) {
			x._v.insert(x._v.end(), 0);
		}
	}
	LargeInt x1(*this);
	int i=(x._v.size())/(2);
	int end=x._v.size();
	x1._v.clear();
	while(i<end){
		x1._v.push_back(x._v[i]);
		i++;
	}
	std::cout << "x1: " << x1.decimal() << std::endl;
	
	LargeInt y1(*this);
	i=(y._v.size()) / (2);
	end=y._v.size();
	y1._v.clear();
	while (i < end) {
		y1._v.push_back(y._v[i]);
		i++;
	}
	std::cout << "y1: " << y1.decimal() << std::endl;
	LargeInt x2(*this);
	i=0;
	end=(x._v.size()) / (2);
	x2._v.clear();
	while (i < end) {
		x2._v.push_back(x._v[i]);
		i++;
	}
	std::cout << "x2: " << x2.decimal() << std::endl;
	LargeInt y2(*this);
	i=0;
	end=(y._v.size()) / (2);
	y2._v.clear();
	while (i < end) {
		y2._v.push_back(y._v[i]);
		i++;
	}
	std::cout << "y2: " << y2.decimal() << std::endl;
	
	int j;
	int e10n = x._v.size();
	int e10n2= (x._v.size()/2)+(x._v.size()%2);
	LargeInt Multi1=x1*y1;	
	std::cout << "Multi1: " << Multi1.decimal() << std::endl;		//should add everything up again .. from Karatsuba somehow
	LargeInt Multi2=x2*y2;
	std::cout << "Multi2: " << Multi2.decimal() << std::endl;	
	LargeInt Multi3= (x1*y2)+(y1*x2);
	for (j=0;j<e10n;++j){
		Multi1._v.insert(Multi1._v.begin(), 0);
	}
	for(j=0;j<e10n2;++j){
		Multi3._v.insert(Multi3._v.begin(), 0);
	}	
	*this=Multi1+Multi3+Multi2;

    return *this;
  
}


