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
	cout << "-------SWING ��ȭ��ȣ��---------\n";
	cout << "�̸��� �Է��� �ּ���: ";
	cin >> name;
	cout << "\n��ȭ��ȣ�� �Է��� �ּ���: ";
	cin >> Pnumber;

}

void Address::editPhone() {
	string In_name;
	string In_number;

	cout << "�̸��� �Է��� �ּ���: ";
	cin >> In_name;

	if (In_name != name) {
		do {
			cout << "����ó�� �������� �ʽ��ϴ�. �ٽ� �Է����ּ���. >>";
			cin >> In_name;


		} while (In_name != name);

		cout << "������ ��ȭ��ȣ�� �Է����ּ��� >>";
		cin >> In_number;
		Pnumber = In_number;
		cout << endl;
	}
	else
	{
		cout << "������ ��ȭ��ȣ�� �Է����ּ��� >>";
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