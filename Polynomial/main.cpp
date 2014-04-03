#include "Polynomial.h"
#include "math.h"
using namespace std;
int main() {
	vector<double> a(4);
	vector<double> b(2);
	a[0] = -2;
	a[1] = -1;
	a[3] = 6;
	b[0] = 1;
	b[1] = 2;
	Polynomial P(a);
	Polynomial Q(b);
	vector<double> c(3);
	c[0] = 1;
	c[1] = 3;
	c[2] = 1;
	vector<double> d(2);
	d[0] = 1;
	d[1] = 1;
	Polynomial C(c);
	Polynomial D(d);
	//cout << "Div "<< C%D << endl;
	vector<double> ln(6);
	ln[0] = 1.0/5;
	for (int i = 1; i < 5; i++) {
		ln[i] = -ln[i-1]*(6-i)/(5-i);
	}
	Polynomial Ln(ln);
	//cout << Ln << endl;
	vector<double> sinc(7);
	sinc[0] = -1.0/5040;
	sinc[2] = 1.0/120;
	sinc[4] = -1.0/6;
	sinc[6] = 1;
	Polynomial Sinc(sinc);
	cout << "Taylor series give " << Ln(0.05) << "\t" << "Actual computing = " << log(1.05) <<endl;
	cout << "Taylor series give " << Sinc(0.05) << "\t" << "Actual computing = " << sin(0.05)/0.05<< endl;
	cout << "+ (Taylor) " << (Ln+Sinc)(0.05) << "\t" << "Computed = " << log(1.05)+sin(0.05)/0.05 << endl;
	cout << "- (Taylor) " << (Ln-Sinc)(0.05) << "\t" << "Computed = " << log(1.05)-sin(0.05)/0.05 << endl;
	cout << "* (Taylor) " << (Ln*Sinc)(0.05) << "\t" << "Computed = " << log(1.05)*sin(0.05)/0.05 << endl;
	cout << "Derivative Ln (Taylor) " << (Ln.derivative())(0.05) << "\t" << "Computed = " << 1/(1.05) << endl;
	cout << "Derivative sinc (Taylor) " << (Sinc.derivative())(0.05) << "\t" << "Computed = " << (0.05*cos(0.05)-sin(0.05))/(0.05*0.05) << endl;
	

}