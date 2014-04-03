#include "Polynomial.h"
Polynomial::Polynomial(const std::vector<double> vec) {
	a = vec;
	pow = a.size()-1;
}
Polynomial::Polynomial(double c) {
	std::vector<double> vec(1);
	vec[0] = c;
	a = vec;
	pow = 0;
}
Polynomial::Polynomial(double c, int power) {
	std::vector<double> vec(power+1);
	vec[0] = c;
	a = vec;
	pow = power;
}
std::ostream& operator<<(std::ostream& os, const Polynomial& P) {
	if ( P.a.front() != 0 ) {
		os << P.a.front();
		if ( P.pow > 0 ) os << "*x";
		if ( P.pow > 1 ) os << "^" << P.pow;
	}
	for (int i = 1; i < P.pow-1; i++){
		if ( P.a[i] > 0 ) {
			os << " + ";
			os << P.a[i] << "*x^" << (P.pow - i);
		}
		else if ( P.a[i] < 0 ) {
			os << " - ";
			os << -P.a[i] << "*x^" << (P.pow - i);
		}
	}
	if (P.pow > 1 ){
		if ( P.a[P.pow-1] > 0 ) {
			os << " + ";
			os << P.a[P.pow-1] << "*x";
		}
		else if ( P.a[P.pow-1] < 0 ) {
			os << " - ";
			os << -P.a[P.pow-1] << "*x";
		}
	}
	if (P.pow > 0 ){
		if ( P.a.back() > 0 ) {
			os << " + ";
			os << P.a.back();
		}
		else if ( P.a.back() < 0 ) {
			os << " - ";
			os << -P.a.back();
		}
	}
	return os;
}
double Polynomial::operator () (double x){
	double value = a.front();
	for (int i = 1; i < pow+1; i++){
	value *= x;
	value += a[i];
	}
	return value;
}
Polynomial Polynomial::derivative(){
	std::vector<double> b(pow);
	for (int i = 0; i < pow; i++){
		b[i] = a[i]*(pow-i);
	}
	Polynomial P(b);
	return P;
}
Polynomial Polynomial::operator += (const Polynomial& P){
	std::vector<double> b(std::max(pow,P.pow)+1);
	if ( pow >= P.pow) {
		b = a;
		for ( int i = 0; i < P.pow + 1; i++){
			b[pow - i] += P.a[P.pow - i];
		}
	}
	else {
		b = P.a;
		for ( int i = 0; i < pow + 1; i++){
			b[P.pow - i] += a[pow - i];
		}
		pow = P.pow;
	}
	a = b;
	Polynomial Q(*this);
	return Q;
}
Polynomial operator + (const Polynomial& P1, const Polynomial& P2){
	Polynomial P = P1;
	P += P2;
	return P;
}
Polynomial Polynomial::operator - () const {
	std::vector<double> b(pow+1);
	for (int i = 0; i< pow + 1; i++) {
		b[i] = - a[i];
	}
	Polynomial Q(b);
	return Q;
}
Polynomial Polynomial::operator -= (const Polynomial& P){
	Polynomial Q(*this);
	Q = Q-P;
	a = Q.a;
	pow = Q.pow;
	return Q;
}
Polynomial operator - (const Polynomial& P1, const Polynomial& P2){
	Polynomial P = P1;
	P = P +  (-P2);
	return P;
}
Polynomial operator * (const Polynomial& P, const Polynomial& Q){
	int pow = P.pow+Q.pow;
	std::vector<double> a(pow+1);
	for (int i = 0; i<pow+1; i++) {
		for (int j = 0; j < std::max(P.pow,Q.pow)+1; j++) {
			if ( ( i-j < P.a.size() ) && ( j < Q.a.size() ) )
			a[i] += P.a[i-j]*Q.a[j];
		}
	}
	Polynomial R(a);
	return R;
}
Polynomial Polynomial::operator *= (const Polynomial& P){
	Polynomial Q(*this);
	Q = Q*P;
	a = Q.a;
	pow = Q.pow;
	return Q;
}
Polynomial operator / (const Polynomial& P, const Polynomial& Q) {
	if ( P.pow < Q.pow ) {
		Polynomial B(0);
		return B;
	}
	else {
		std::vector<double> b(P.pow-Q.pow+1);
		Polynomial P1 = P;
		for ( int i = 0; i < b.size(); i++ ) {
			b[i] = 1.0*P1.a[i]/Q.a[0];
			Polynomial C(b[i],P.pow-Q.pow-i);
			//std::cout << C << std::endl;
			P1 -= (Q*C);
			//std::cout << P1 << std::endl;
		}
		Polynomial B(b);
		return B;
	}
}
Polynomial operator % (const Polynomial& P, const Polynomial& Q) {
	Polynomial R = P - Q*(P/Q);
	return R;
}

