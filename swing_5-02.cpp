#include <iostream>
#include <string>
using namespace std;

class VendingMachine
{
private:
	string name; //���� �̸�
	int price; //����
	int total=0; //���� �ջ� ��
public:
	VendingMachine() {}; //������
	void purchase(double v1); //�� �ݾ� ���, ���� �Է�, �Ž��� �� ���
	void menu(); //�޴���
	void NewMenu();  // �� �޴���
	string getName(); //name return
	double getPrice(); //price return
	double getTotal(); //total return
	void setName(string n); //name ����
	void setPrice(int p); //price ����
	void setTotal(int t); //toral ����
};

void VendingMachine::purchase(double v1) {
	int cash, change;
	cout << "�� �ݾ�: " << v1 << endl;
	cout << "���� �Է��ϼ���: ";

	while (1)
	{
		cin >> cash;
		change = cash - v1;

		if (change < 0) // �Է��� �ݾ��� �� �ݾ׺��� ���� ���
		{
			cout << "�ݾ��� �����մϴ�. �ٽ� �־��ּ���. ";
		}

		else if (change == 0) // �Է��� �ݾװ� �� �ݾ��� ���� ���
		{
			cout << "�Ž������� �����ϴ�. �ȳ��� ������." << endl;
			break;
		}

		else if (change > 0) // �Է��� �ݾ��� �� �ݾ׺��� ū ���
		{
			if (change % 100 == 0) // �Ž������� �� �ʿ� ������ �ƴ� �� ��� ������ ���
			{
				cout << "500�� : " << change / 500 << "��" << endl;
				cout << "100�� : " << change % 500 / 100 << "��" << endl;
				cout << "�ȳ���������." << endl;
				break;
			}
			else // �Ž������� �� �ʿ����� ���� ���
			{
				cout << "�Ž������� 500���� 100���� �����մϴ�." << endl;
				cout << "500�� : " << change / 500 << "��" << endl;
				cout << "100�� : " << change % 500 / 100 << "��" << endl;
				cout << "�ȳ���������." << endl;
				break;
			}
		}
	}

}

void VendingMachine::menu()
{
	cout << "=== SWING ���Ǳ� ===" << endl;
	cout << "1. ��ī�ݶ� : 1500��" << endl;
	cout << "2. ���ְ����ֽ� : 1500��" << endl;
	cout << "3. ��ī������Ʈ : 2000��" << endl;
	cout << "4. �غ���" << endl;
	cout << "5. ���" << endl;

}

void VendingMachine::NewMenu()
{
	cout << "=====SWING ���Ǳ�=====" << endl;
	cout << "1.��ī�ݶ�: 1500��" << endl;
	cout << "2. ���ְ����ֽ�: 1500��" << endl;
	cout << "3.��ī���׿�Ʈ: 2000��" << endl;
	cout << "4." << name << ": " << price << "��" << endl;
	cout << "5.���" << endl;
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
	VendingMachine vm; //��ü ���� vm
	VendingMachine* p = &vm;  //��ü vm ����Ű�� ������ ���� p ����
	string new_name;
	double new_price;
	int num; //�����ϴ� ��ȣ
	int amount; //�����ϴ� ������� ����

	vm.menu();

	cout << "�߰��� ���� �̸��� �Է����ּ���: ";
	cin >> new_name;
	p->setName(new_name);  

	cout << "�Ǹ��� ������ �Է��ϼ���: ";
	cin >> new_price;
	p->setPrice(new_price);  
	cout << endl;

	do 
	{
		vm.NewMenu();

		cout << "��ȣ�� �������ּ���: ";
		cin >> num;

		switch (num) {
		case 1:
			cout << "������ ������ �Է����ּ���: ";
			cin >> amount;
			cout << endl;
			p->setTotal(amount * 1500);  
			break;
		case 2:
			cout << "������ ������ �Է����ּ���: ";
			cin >> amount;
			cout << endl;
			p->setTotal(amount * 1500);  
			break;
		case 3:
			cout << "������ ������ �Է����ּ���: ";
			cin >> amount;
			cout << endl;
			p->setTotal(amount * 2000);  
			break;
		case 4:
			cout << "������ ������ �Է����ּ���: ";
			cin >> amount;
			cout << endl;
			p->setTotal(amount * vm.getPrice());  
			break;
		}
	} while (num != 5);  // 5 ���� ������ �ݺ��ϱ�

	cout << endl << "��� ���Դϴ�. ��ٷ��ּ���..." << endl;

	vm.purchase(vm.getTotal());
}