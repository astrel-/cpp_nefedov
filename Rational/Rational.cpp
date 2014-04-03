#include "Rational.h"
Rational::Rational(int m, int n){
	if (n>0) {
		numerator = m;
		denominator = n;
	}
	else {
		numerator = -m;
		denominator = -n;
	}
}
Rational::Rational(double f, double e){
	std::string str(std::to_string(f));
	int pos = str.find('.');
	char str1[pos];
	str.copy(str1, pos, 0);
	int p[3];
	int q[3];
	int a;
	double x[2];
	q[0] = 0;
	q[1] = 1;
	p[0] = 1;
	p[1] = atoi(str1);
	x[0] = f-p[1];
	std::cout << p[1] << std::endl;
	while ( std::abs((1.0*p[1]/q[1])-f) > e ){
		std::string str(std::to_string(1.0/x[0]));
		pos = str.find('.');
		char str1[pos];
		str.copy(str1, pos, 0);
		a = atoi(str1);
		x[1] = 1.0/x[0] - a;
		x[0] = x[1];
		q[2] = a*q[1] + q[0];
		p[2] = a*p[1] + p[0];
		p[0] = p[1];
		q[0] = q[1];
		p[1] = p[2];
		q[1] = q[2];
		std::cout << "p = " << p[2] << "\tq = " << q[2] << std::endl;
	}
	numerator = p[1];
	denominator = q[1];
}
Rational operator + (const Rational& r1, const Rational& r2){
	Rational r;
	r.numerator = r1.numerator*r2.denominator+r1.denominator*r2.numerator;
	r.denominator = r1.denominator*r2.denominator;
	r.simplify();
	return r;
}
Rational operator - (const Rational& r1, const Rational& r2){
	Rational r = -r2;
	return r1+r;
}
Rational operator * (const Rational& r1 , const Rational& r2){
	Rational r;
	r.numerator = r1.numerator*r2.numerator;
	r.denominator = r1.denominator*r2.denominator;
	r.simplify();
	return r;
}
Rational operator / (const Rational& r1 , const Rational& r2){
	Rational r;
	r.numerator = r1.numerator*r2.denominator;
	r.denominator = r1.denominator*r2.numerator;
	r.simplify();
	return r;
}
Rational Rational::operator += (const Rational& r){
	*this = *this + r;
	return *this;
}
Rational Rational::operator -= (const Rational& r){
	*this = *this - r;
	return *this;
}
Rational Rational::operator *= (const Rational& r){
	*this = *this * r;
	return *this;
}
Rational Rational::operator /= (const Rational& r){
	*this = *this / r;
	return *this;
}
Rational Rational::operator - () const{
	return Rational(-numerator,denominator);
}
Rational Rational::operator ++ (int) {
	Rational r(*this);
	++(*this);
	return r;
}
Rational Rational::operator ++ (){
	Rational r(*this);
	numerator += denominator;
	return r;
}
Rational Rational::operator -- (int){
	Rational r(*this);
	--(*this);
	return r;
}
Rational Rational::operator -- (){
	Rational r(*this);
	numerator -= denominator;
	return r;
}
std::ostream& operator<<(std::ostream& os, const Rational& r) {
	os << r.numerator << "/" << r.denominator;
	return os;
}
Rational Rational::pow(int a) const{
	Rational r(*this);
	if (a>0){
		Rational r1 = r;
		for (int i=1;i<a;i++){
			r1 = r1*r;
		}
		return r1;
	}
	else if (a<0){
		Rational r1 = r;
		for (int i=1;i<-a;i++){
			r1 = r1*r;
		}
		return 1/r1;
	}
	else return Rational(1);
}
void Rational::simplify(){
	int a = abs(numerator);
	int b = denominator;
	int c;
	if ( a>b ) c = euclid(a,b);
	else c = euclid (b,a);
	if ( c>1 ) {
		numerator /= c;
		denominator /= c;
	}
}
int Rational::euclid(int a, int b){
	int c;
	if ( b==0 ) return(1);
	while (a%b!=0){
		c = a%b;
		a = b;
		b = c;
	}
	return b;
}
double Rational::to_double(){
	return (1.0*numerator/denominator);
}