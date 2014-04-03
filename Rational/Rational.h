#ifndef _Rational_h
#define _Rational_h
#include <iostream>
#include <cmath>
class Rational{
public:
	Rational(int m = 0, int n = 1); //tested
	Rational(double f, double e); //tested
	friend std::ostream& operator<<(std::ostream& os, const Rational& s);
	friend Rational operator + (const Rational& r1, const Rational& r2); //tested
	friend Rational operator - (const Rational& r1, const Rational& r2); //tested
	friend Rational operator * (const Rational& r1, const Rational& r2); //tested
	friend Rational operator / (const Rational& r1, const Rational& r2); //tested
	Rational operator += (const Rational& r); //tested
	Rational operator -= (const Rational& r); //tested
	Rational operator *= (const Rational& r); //tested
	Rational operator /= (const Rational& r); //tested
	Rational operator - () const; //tested
	Rational operator ++ (int); //tested
	Rational operator ++ (); //tested
	Rational operator -- (int); //tested
	Rational operator -- (); //tested
	Rational pow(int a) const; //tested
	void simplify(); //tested
	int euclid(int a,int b); //tested
	double to_double(); //tested
private:
	int numerator;
	int denominator;
};
#endif


