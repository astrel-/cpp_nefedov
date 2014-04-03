#include "Phonebook.h"
Phonebook::Phonebook() {
	phone["Yura"] = "985";
	phone["Anna"] = "462";
}
void Phonebook::add(std::string name, std::string number) {
	Book::iterator iter = phone.find(name);
	if ( iter != phone.end() ) {
		std::cout << "You have a contact " << iter->first << " with number " << iter->second << std::endl << "Do you want to rewrite with new number " << number << "?(y/n)" << std::endl;
		std::string answer;
		std::cin >> answer;
		if ( answer == "y" ) {
			this->erase(name);
			phone.insert(std::make_pair(name, number));
		}
	}
	else {
		phone.insert(std::make_pair(name, number));
	}
}
void Phonebook::find(std::string name) {
	Book::iterator iter = phone.find(name);
	if ( iter != phone.end() ) {
		std::cout << iter->first << ":\t" << iter->second <<std::endl;
	}
	else {
		std::cout << "There is no " << name << " in your phone book" << std::endl;
	}
}
void Phonebook::erase(std::string name) {
	Book::iterator iter = phone.find(name);
	if ( iter != phone.end() ) {
		phone.erase(iter);
	}
	else {
		std::cout << "There is no " << name << " in your phone book" << std::endl;
	}
}
void Phonebook::print() {
	for (Book::iterator iter = phone.begin();
		 iter != phone.end(); iter++) {
		std::cout << iter->first << ":\t" << iter->second <<std::endl;
	}
}