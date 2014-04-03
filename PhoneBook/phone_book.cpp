#include <iostream>
#include<map>
#include "string.h"
using namespace std;

int main() {
	typedef map<std::string,std::string> Phonebook;
	Phonebook phone;
	phone["1"] = "0.2";
	phone["2"] = "0.3";
	phone.insert(make_pair("6","3.4"));
	cout << phone["6"] << endl;
	return 0;
}
