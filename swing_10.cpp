#include <iostream>
#include <vector>
using namespace std;


class kiosk {
private:
	vector<string>burger = { "1. ������� ","2. �Ұ����� ","3. ���̹��� ","4. ��ġ����� " };
	vector<string>side = { "1. ġ�ƽ ","2. ����Ƣ�� ","3. ������ ","4. ���̽�ũ�� " };
	vector<string>drink = { "1. ���̴� ","2. �ݶ� ","3. ȯŸ ","4. �������ֽ� " };
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
		cout << "========�޴� �з�========" << endl;
		cout << "1. �ܹ���\n2. ���̵�\n3. ����" << endl;
		cout << "=========================" << endl;

		cout << endl;

		cout << "����� �����Ͻðڽ��ϱ�? " << endl;
		cin >> num;

		
		kiki.select(num);
		

		cout << "��� �����Ͻðڽ��ϱ�? (y or �������� �ƹ�Ű�� �����ּ���)" << endl;
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
		cout << "�������� �ʴ� �з��� �����ϼ̽��ϴ�." << endl << "�ٽ� ������ �ֽʽÿ�" << endl;
		break;
	}
}

void kiosk::getburger() {
	for (int i = 0; i < 4; i++) {
		cout << burger[i];
	}
	cout << endl;
	cout << "�ֹ��� ������ ��ȣ�� ������ �Է����ּ���" << endl << "ex>������� 2��: 1 2" << endl;
	cin >> order >> n;
	if (order < 0 || order>4) {
		do
		{
			cout << "�������� �ʴ� �޴��� �����ϼ̽��ϴ�" << endl << "�ٽ� ������ �ֽʽÿ�" << endl;
			cin >> order >> n;
		} while (order < 0 || order > 4);
	}
	cout << burger[order - 1] << " " << n << "���� �ֹ��Ǿ����ϴ�" << endl;
}

void kiosk::getdrink() {
	for (int i = 0; i < 4; i++) {
		cout << drink[i];
	}
	cout << endl;
	cout << "�ֹ��� ������ ��ȣ�� ������ �Է����ּ���" << endl << "ex>���̴� 2��: 1 2" << endl;
	cin >> order >> n;
	if (order < 0 || order>4) {
		do
		{
			cout << "�������� �ʴ� �޴��� �����ϼ̽��ϴ�" << endl << "�ٽ� ������ �ֽʽÿ�" << endl;
			cin >> order >> n;
		} while (order < 0 || order > 4);
	}
	cout << drink[order - 1] << " " << n << "���� �ֹ��Ǿ����ϴ�" << endl;
}

void kiosk::getside() {
	for (int i = 0; i < 4; i++) {
		cout << side[i];
	}
	cout << endl;
	cout << "�ֹ��� ���̵��� ��ȣ�� ������ �Է����ּ���" << endl << "ex>ġ�ƽ 2��: 1 2" << endl;
	cin >> order >> n;
	if (order < 0 || order>4) {
		do
		{
			cout << "�������� �ʴ� �޴��� �����ϼ̽��ϴ�" << endl << "�ٽ� ������ �ֽʽÿ�" << endl;
			cin >> order >> n;
		} while (order < 0 || order > 4);
	}
	cout << side[order - 1] << " " << n << "���� �ֹ��Ǿ����ϴ�" << endl;

}
