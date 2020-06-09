#include <iostream>
#include <string>

using namespace std;

#include "PhoneBook.h"

class Address {
private:
	string name;
	string Pnumber;
public:
	void addPhone();
	void editPhone();
	string getPnum();
	string getName();

};

void Address::addPhone() {
	cout << "-------SWING 전화번호부---------\n";
	cout << "이름을 입력해 주세요: ";
	cin >> name;
	cout << "\n전화번호를 입력해 주세요: ";
	cin >> Pnumber;

}

void Address::editPhone() {
	string In_name;
	string In_number;

	cout << "이름을 입력해 주세요: ";
	cin >> In_name;

	if (In_name != name) {
		do {
			cout << "연락처가 존재하지 않습니다. 다시 입력해주세요. >>";
			cin >> In_name;


		} while (In_name != name);

		cout << "변경할 전화번호를 입력해주세요 >>";
		cin >> In_number;
		Pnumber = In_number;
		cout << endl;
	}
	else
	{
		cout << "변경할 전화번호를 입력해주세요 >>";
		cin >> In_number;
		Pnumber = In_number;
		cout << endl;
	}

}

string Address::getPnum() {
	return Pnumber;
}

string Address::getName() {
	return name;
}