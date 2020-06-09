#include <iostream>
#include <string>
using namespace std;
#include "PhoneBook.h"

int main() {
	Address Iaddress;
	Iaddress.addPhone();

	int x;
	while (1) {
		cout << "\n1. 최신 등록 전화번호 조회\n2. 최신 등록 전화번호 수정\n3. 종료\n";
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