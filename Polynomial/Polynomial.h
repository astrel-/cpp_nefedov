#ifndef _Polynomial_h
#define _Polynomial_h
#include <iostream>
#include <vector>
class Polynomial{
public:
	Polynomial(const std::vector<double> vec); //tested
	Polynomial(double c);
	Polynomial(double c, int power);
	friend std::ostream& operator<<(std::ostream& os, const Polynomial& P); //tested
	double operator () (double x); //tested
	Polynomial derivative (); //tested
	Polynomial operator += (const Polynomial& P); //tested
	friend Polynomial operator + (const Polynomial& P1, const Polynomial& P2); //tested
	friend Polynomial operator - (const Polynomial& P1, const Polynomial& P2); //tested
	friend Polynomial operator * (const Polynomial& P, const Polynomial& Q); //tested
	friend Polynomial operator / (const Polynomial& P, const Polynomial& Q); //tested
	friend Polynomial operator % (const Polynomial& P, const Polynomial& Q); //tested
	Polynomial operator - () const; //tested;
	Polynomial operator -= (const Polynomial& P); //tested
	Polynomial operator *= (const Polynomial& P); //tested
private:
	std::vector<double> a;
	int pow;
};
#endif
