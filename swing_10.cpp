#include <iostream>
#include <vector>
using namespace std;


class kiosk {
private:
	vector<string>burger = { "1. 새우버거 ","2. 불고기버거 ","3. 싸이버거 ","4. 딥치즈버거 " };
	vector<string>side = { "1. 치즈스틱 ","2. 감자튀김 ","3. 샐러드 ","4. 아이스크림 " };
	vector<string>drink = { "1. 사이다 ","2. 콜라 ","3. 환타 ","4. 오렌지주스 " };
public:
	kiosk() {

	};
	int order, n;
	void getburger();
	void getside();
	void getdrink();
	void select(int a);
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
		

		cout << "계속 선택하시겠습니까? (y or 끝내려면 아무키나 눌러주세요)" << endl;
		cin >> choice;

	} while (choice=='y');

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
		cout << burger[i];
	}
	cout << endl;
	cout << "주문할 버거의 번호와 수량을 입력해주세요" << endl << "ex>새우버거 2개: 1 2" << endl;
	cin >> order >> n;
	if (order < 0 || order>4) {
		do
		{
			cout << "존재하지 않는 메뉴를 선택하셨습니다" << endl << "다시 선택해 주십시오" << endl;
			cin >> order >> n;
		} while (order < 0 || order > 4);
	}
	cout << burger[order - 1] << " " << n << "개가 주문되었습니다" << endl;
}

void kiosk::getdrink() {
	for (int i = 0; i < 4; i++) {
		cout << drink[i];
	}
	cout << endl;
	cout << "주문할 음료의 번호와 수량을 입력해주세요" << endl << "ex>사이다 2개: 1 2" << endl;
	cin >> order >> n;
	if (order < 0 || order>4) {
		do
		{
			cout << "존재하지 않는 메뉴를 선택하셨습니다" << endl << "다시 선택해 주십시오" << endl;
			cin >> order >> n;
		} while (order < 0 || order > 4);
	}
	cout << drink[order - 1] << " " << n << "개가 주문되었습니다" << endl;
}

void kiosk::getside() {
	for (int i = 0; i < 4; i++) {
		cout << side[i];
	}
	cout << endl;
	cout << "주문할 사이드의 번호와 수량을 입력해주세요" << endl << "ex>치즈스틱 2개: 1 2" << endl;
	cin >> order >> n;
	if (order < 0 || order>4) {
		do
		{
			cout << "존재하지 않는 메뉴를 선택하셨습니다" << endl << "다시 선택해 주십시오" << endl;
			cin >> order >> n;
		} while (order < 0 || order > 4);
	}
	cout << side[order - 1] << " " << n << "개가 주문되었습니다" << endl;

}
