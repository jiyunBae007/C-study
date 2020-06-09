#include <iostream>
#include <string>
using namespace std;

class VendingMachine
{
private:
	string name; //음료 이름
	int price; //가격
	int total=0; //음료 합산 값
public:
	VendingMachine() {}; //생성자
	void purchase(double v1); //총 금액 출력, 지폐 입력, 거스름 돈 출력
	void menu(); //메뉴판
	void NewMenu();  // 새 메뉴판
	string getName(); //name return
	double getPrice(); //price return
	double getTotal(); //total return
	void setName(string n); //name 수정
	void setPrice(int p); //price 수정
	void setTotal(int t); //toral 수정
};

void VendingMachine::purchase(double v1) {
	int cash, change;
	cout << "총 금액: " << v1 << endl;
	cout << "지폐를 입력하세요: ";

	while (1)
	{
		cin >> cash;
		change = cash - v1;

		if (change < 0) // 입력한 금액이 총 금액보다 적은 경우
		{
			cout << "금액이 부족합니다. 다시 넣어주세요. ";
		}

		else if (change == 0) // 입력한 금액과 총 금액이 같은 경우
		{
			cout << "거스름돈이 없습니다. 안녕히 가세요." << endl;
			break;
		}

		else if (change > 0) // 입력한 금액이 총 금액보다 큰 경우
		{
			if (change % 100 == 0) // 거스름돈이 몇 십원 단위가 아닌 몇 백원 단위인 경우
			{
				cout << "500원 : " << change / 500 << "개" << endl;
				cout << "100원 : " << change % 500 / 100 << "개" << endl;
				cout << "안녕히가세요." << endl;
				break;
			}
			else // 거스름돈이 몇 십원으로 나온 경우
			{
				cout << "거스름돈은 500원과 100원만 가능합니다." << endl;
				cout << "500원 : " << change / 500 << "개" << endl;
				cout << "100원 : " << change % 500 / 100 << "개" << endl;
				cout << "안녕히가세요." << endl;
				break;
			}
		}
	}

}

void VendingMachine::menu()
{
	cout << "=== SWING 자판기 ===" << endl;
	cout << "1. 코카콜라 : 1500원" << endl;
	cout << "2. 제주감귤주스 : 1500원" << endl;
	cout << "3. 포카리스웨트 : 2000원" << endl;
	cout << "4. 준비중" << endl;
	cout << "5. 계산" << endl;

}

void VendingMachine::NewMenu()
{
	cout << "=====SWING 자판기=====" << endl;
	cout << "1.코카콜라: 1500원" << endl;
	cout << "2. 제주감귤주스: 1500원" << endl;
	cout << "3.포카리그웨트: 2000원" << endl;
	cout << "4." << name << ": " << price << "원" << endl;
	cout << "5.계산" << endl;
}


string VendingMachine::getName() {
	
	return name;
}

double VendingMachine::getPrice() {
	
	return price;
}

double VendingMachine::getTotal() {
	return total;
}

void VendingMachine::setName(string n) {
	name = n;
}

void VendingMachine::setPrice(int p) {
	price = p;
}

void VendingMachine::setTotal(int t) {
	total += t;
}

int main()
{
	VendingMachine vm; //객체 생성 vm
	VendingMachine* p = &vm;  //객체 vm 가르키는 포인터 변수 p 선언
	string new_name;
	double new_price;
	int num; //선택하는 번호
	int amount; //구매하는 음료수의 개수

	vm.menu();

	cout << "추가할 음료 이름을 입력해주세요: ";
	cin >> new_name;
	p->setName(new_name);  

	cout << "판매할 가격을 입력하세요: ";
	cin >> new_price;
	p->setPrice(new_price);  
	cout << endl;

	do 
	{
		vm.NewMenu();

		cout << "번호를 선택해주세요: ";
		cin >> num;

		switch (num) {
		case 1:
			cout << "구매할 수량을 입력해주세요: ";
			cin >> amount;
			cout << endl;
			p->setTotal(amount * 1500);  
			break;
		case 2:
			cout << "구매할 수량을 입력해주세요: ";
			cin >> amount;
			cout << endl;
			p->setTotal(amount * 1500);  
			break;
		case 3:
			cout << "구매할 수량을 입력해주세요: ";
			cin >> amount;
			cout << endl;
			p->setTotal(amount * 2000);  
			break;
		case 4:
			cout << "구매할 수량을 입력해주세요: ";
			cin >> amount;
			cout << endl;
			p->setTotal(amount * vm.getPrice());  
			break;
		}
	} while (num != 5);  // 5 선택 전까지 반복하기

	cout << endl << "계산 중입니다. 기다려주세요..." << endl;

	vm.purchase(vm.getTotal());
}