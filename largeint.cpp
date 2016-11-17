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
    if (carry != 0) _v.push_back(carry);
    return *this;
}

LargeInt LargeInt::operator*(const LargeInt & arg) const  // multiplication
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

	if (x._v.size()< y._v.size()){							//set them into same size
		if(v.size%2==1){									//also make them even with addition of 0
			x._v.insert=0;				
		}
		while (x._v.size()< y._v.size()){
			arg._v.insert=0;		
		}
	}
	if (x._v.size()> y._v.size()){
		if(y._v.size%2==1){
			y._v.insert=0;				
		}
		while (y.arg._v.size()> y._v.size()){
			y._v.insert=0;		
		}
	}
	

	LargeInt x1(_v.size()/2);
	LargeInt y1(arg._v.size()/2);
	LargeInt x2(_v.size()/2);
	LargeInt y2(arg._v.size()/2);

	
	for(i=0;i<_v.size()/2;++i){							//gives the parts value of respective parts of the argument
		_x1.push_back=_x[i+_v.size()/2];		
	}
	for(i=0;i<arg._v.size()/2;++i){
		_y1.push_back=_y[i+_v.size()/2];		
	}
	for(i=0;i<_v.size()/2;++i){							//gives the parts value of respective parts of the argument
		_x2.push_back=_x[i];		
	}
	for(i=0;i<arg._v.size()/2;++i){
		_y2.push_back=_y[i];		
	}
	
	int 10n = x._v.size();
	int 10n2= (x._v.size()/2)+(x._v.size()%2);
	LargeInt Multi1=x1*y1;								//should add everything up again  from Karatsuba somehow
	LargeInt Multi2=x2*y2;
	LargeInt Multi3=(x1*y2)+(x2*y1)	
	for (i=0;i<10n;++i){
		Multi1.push_back=0;
	}
	for(i=0;i<10n2;++i){
		Multi3.push_back=0;
	}

	*this=Multi1+Multi3+Multi2;

    return *this;
}
