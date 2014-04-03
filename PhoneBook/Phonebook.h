#ifndef _Phonebook_h
#define _Phonebook_h
#include<iostream>
#include<map>
#include<string>
typedef std::map<std::string, std::string> Book;
class Phonebook{
public:
	Phonebook();
	void add(std::string name, std::string number); //tested
	void erase(std::string name); //tested
	void print(); //tested
	void find(std::string name); //tested
private:
	Book phone;
};
#endif


