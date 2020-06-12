#ifndef PHONEBOOK_H
#define PHONEBOOK_H
#include <string>
using namespace std;

class PhoneBook
{
private:
	string name;
	string Pnumber;

public:
	void addPhone();
	void editPhone();
	string getPnum();
	string getName();

};

#endif
