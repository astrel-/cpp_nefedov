#include "Rational.h"
using namespace std;
int main() {
	Rational N(0,1);
	Rational M(1,2);
	N.simplify();
	for (int i = 0; i<10;i++){
		N= N+M;
		cout << "Number = " << (N) << endl;
		M/=2;
	}
	cout << "Number = " << (N) << endl;
	const Rational P(1,2);
	P.pow(10);
	cout << "Number2 = " << (1-P.pow(10)) << endl;
	
}