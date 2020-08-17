#include <iostream>
#include <vector>
#include<fstream>
using namespace std;


class kiosk {
private:
	vector<string>burger = { "������� ","�Ұ����� ","���̹��� ","��ġ����� " };
	vector<int>bprice = { 4300,4500,4700,4900 };
	vector<string>side = { "ġ�ƽ ","����Ƣ�� ","������ ","���̽�ũ�� " };
	vector<int>sprice = { 1500,1000,1500,700 };
	vector<string>drink = { "���̴� ","�ݶ� ","ȯŸ ","�������ֽ� " };
	int dprice = 1000;
	vector<string>total = { "�� �ֹ� �޴�" };
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
		cout << "========�޴� �з�========" << endl;
		cout << "1. �ܹ���\n2. ���̵�\n3. ����" << endl;
		cout << "=========================" << endl;

		cout << endl;

		cout << "����� �����Ͻðڽ��ϱ�? " << endl;
		cin >> num;


		kiki.select(num);


		cout << "��� �����Ͻðڽ��ϱ�? (y/n)" << endl;
		cin >> choice;

	} while (choice == 'y');

	kiki.price();

	cout << "�������� ��µǾ����ϴ�." << endl;

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
		cout << "�������� �ʴ� �з��� �����ϼ̽��ϴ�." << endl << "�ٽ� ������ �ֽʽÿ�" << endl;
		break;
	}
}

void kiosk::getburger() {
	for (int i = 0; i < 4; i++) {
		cout << i + 1 << "." << burger[i] << "(" << bprice[i] << ")" << endl;
	}
	cout << endl;
	cout << "�ֹ��� ������ ��ȣ�� ������ �Է����ּ���" << endl << "ex>������� 2��: 1 2" << endl;
	cin >> border >> b;
	if (border < 0 || border>4) {
		do
		{
			cout << "�������� �ʴ� �޴��� �����ϼ̽��ϴ�" << endl << "�ٽ� ������ �ֽʽÿ�" << endl;
			cin >> border >> b;
		} while (border < 0 || border > 4);
	}
	cout << burger[border - 1] << " " << b << "���� �ֹ��Ǿ����ϴ�" << endl;
}

void kiosk::getdrink() {
	for (int i = 0; i < 4; i++) {
		cout << i + 1 << "." << drink[i] << "(" << dprice << ")" << endl;
	}
	cout << endl;
	cout << "�ֹ��� ������ ��ȣ�� ������ �Է����ּ���" << endl << "ex>���̴� 2��: 1 2" << endl;
	cin >> dorder >> d;
	if (dorder < 0 || dorder>4) {
		do
		{
			cout << "�������� �ʴ� �޴��� �����ϼ̽��ϴ�" << endl << "�ٽ� ������ �ֽʽÿ�" << endl;
			cin >> dorder >> d;
		} while (dorder < 0 || dorder > 4);
	}
	cout << drink[dorder - 1] << " " << d << "���� �ֹ��Ǿ����ϴ�" << endl;
}

void kiosk::getside() {
	for (int i = 0; i < 4; i++) {
		cout << i + 1 << "." << side[i] << "(" << sprice[i] << ")" << endl;
	}
	cout << endl;
	cout << "�ֹ��� ���̵��� ��ȣ�� ������ �Է����ּ���" << endl << "ex>ġ�ƽ 2��: 1 2" << endl;
	cin >> sorder >> s;
	if (sorder < 0 || sorder>4) {
		do
		{
			cout << "�������� �ʴ� �޴��� �����ϼ̽��ϴ�" << endl << "�ٽ� ������ �ֽʽÿ�" << endl;
			cin >> sorder >> s;
		} while (sorder < 0 || sorder > 4);
	}
	cout << side[sorder - 1] << " " << s << "���� �ֹ��Ǿ����ϴ�" << endl;

}

void kiosk::price() {
	//+������ �� ����
	cnt = cnt + (b * bprice[border-1]);
	//+���̵� �޴��� �� ����
	cnt = cnt + (s * sprice[sorder-1]);
	//+������� �� ����
	cnt = cnt + (d * dprice);
}


void kiosk::receipt() {
	writeFile.open("receipt.txt");

	writeFile << "======= ������ =======" << endl;
	writeFile << burger[border - 1] << " " << b << "��" << endl;
	writeFile << side[sorder - 1] << " " << s << "��" << endl;
	writeFile << drink[dorder - 1] << " " << d << "��" << endl;

	writeFile << "=========================" << endl;

	writeFile << "�� ����: " << cnt << endl;
	writeFile << "�����մϴ�!";

	writeFile.close();
}