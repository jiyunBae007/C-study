#include <iostream>
#include <string>
using namespace std;
#include "PhoneBook.h"

int main() {
	Address Iaddress;
	Iaddress.addPhone();

	int x;
	while (1) {
		cout << "\n1. �ֽ� ��� ��ȭ��ȣ ��ȸ\n2. �ֽ� ��� ��ȭ��ȣ ����\n3. ����\n";
		cin >> x;
		if (x == 1) {
			cout << Iaddress.getName() << "::" << Iaddress.getPnum() << "\n";
			cout << endl;

		}
		if (x == 2) {
			Iaddress.editPhone();
		}
		if (x == 3) {
			break;
		}
	}
}