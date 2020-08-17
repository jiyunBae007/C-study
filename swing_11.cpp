#include <iostream>
#include <vector>
#include<fstream>
using namespace std;


class kiosk {
private:
	vector<string>burger = { "새우버거 ","불고기버거 ","싸이버거 ","딥치즈버거 " };
	vector<int>bprice = { 4300,4500,4700,4900 };
	vector<string>side = { "치즈스틱 ","감자튀김 ","샐러드 ","아이스크림 " };
	vector<int>sprice = { 1500,1000,1500,700 };
	vector<string>drink = { "사이다 ","콜라 ","환타 ","오렌지주스 " };
	int dprice = 1000;
	vector<string>total = { "총 주문 메뉴" };
	ofstream writeFile;

public:
	kiosk() { };
	int border, sorder, dorder;
	int b, s, d;
	int cnt = 0;
	void getburger();
	void getside();
	void getdrink();
	void select(int a);
	void price();
	void receipt();
	~kiosk() {

	};
};

int main() {

	kiosk kiki;

	int num;
	int n = 0;
	char choice;

	do {
		cout << "========메뉴 분류========" << endl;
		cout << "1. 햄버거\n2. 사이드\n3. 음료" << endl;
		cout << "=========================" << endl;

		cout << endl;

		cout << "몇번을 선택하시겠습니까? " << endl;
		cin >> num;


		kiki.select(num);


		cout << "계속 선택하시겠습니까? (y/n)" << endl;
		cin >> choice;

	} while (choice == 'y');

	kiki.price();

	cout << "영수증이 출력되었습니다." << endl;

	kiki.receipt();

}

void kiosk::select(int a) {
	switch (a)
	{
	case 1:
		getburger();
		break;
	case 3:
		getdrink();
		break;
	case 2:
		getside();
		break;
	default:
		cout << "존재하지 않는 분류를 선택하셨습니다." << endl << "다시 선택해 주십시오" << endl;
		break;
	}
}

void kiosk::getburger() {
	for (int i = 0; i < 4; i++) {
		cout << i + 1 << "." << burger[i] << "(" << bprice[i] << ")" << endl;
	}
	cout << endl;
	cout << "주문할 버거의 번호와 수량을 입력해주세요" << endl << "ex>새우버거 2개: 1 2" << endl;
	cin >> border >> b;
	if (border < 0 || border>4) {
		do
		{
			cout << "존재하지 않는 메뉴를 선택하셨습니다" << endl << "다시 선택해 주십시오" << endl;
			cin >> border >> b;
		} while (border < 0 || border > 4);
	}
	cout << burger[border - 1] << " " << b << "개가 주문되었습니다" << endl;
}

void kiosk::getdrink() {
	for (int i = 0; i < 4; i++) {
		cout << i + 1 << "." << drink[i] << "(" << dprice << ")" << endl;
	}
	cout << endl;
	cout << "주문할 음료의 번호와 수량을 입력해주세요" << endl << "ex>사이다 2개: 1 2" << endl;
	cin >> dorder >> d;
	if (dorder < 0 || dorder>4) {
		do
		{
			cout << "존재하지 않는 메뉴를 선택하셨습니다" << endl << "다시 선택해 주십시오" << endl;
			cin >> dorder >> d;
		} while (dorder < 0 || dorder > 4);
	}
	cout << drink[dorder - 1] << " " << d << "개가 주문되었습니다" << endl;
}

void kiosk::getside() {
	for (int i = 0; i < 4; i++) {
		cout << i + 1 << "." << side[i] << "(" << sprice[i] << ")" << endl;
	}
	cout << endl;
	cout << "주문할 사이드의 번호와 수량을 입력해주세요" << endl << "ex>치즈스틱 2개: 1 2" << endl;
	cin >> sorder >> s;
	if (sorder < 0 || sorder>4) {
		do
		{
			cout << "존재하지 않는 메뉴를 선택하셨습니다" << endl << "다시 선택해 주십시오" << endl;
			cin >> sorder >> s;
		} while (sorder < 0 || sorder > 4);
	}
	cout << side[sorder - 1] << " " << s << "개가 주문되었습니다" << endl;

}

void kiosk::price() {
	//+버거의 총 가격
	cnt = cnt + (b * bprice[border-1]);
	//+사이드 메뉴의 총 가격
	cnt = cnt + (s * sprice[sorder-1]);
	//+음료수의 총 가격
	cnt = cnt + (d * dprice);
}


void kiosk::receipt() {
	writeFile.open("receipt.txt");

	writeFile << "======= 영수증 =======" << endl;
	writeFile << burger[border - 1] << " " << b << "개" << endl;
	writeFile << side[sorder - 1] << " " << s << "개" << endl;
	writeFile << drink[dorder - 1] << " " << d << "개" << endl;

	writeFile << "=========================" << endl;

	writeFile << "총 가격: " << cnt << endl;
	writeFile << "감사합니다!";

	writeFile.close();
}