#include <iostream>
using namespace std;

class ATM
{
private:
	string name; // ������ �̸�
	int pw = 0; // ���� ��й�ȣ
	int check = 0; // ���� ��й�ȣ Ȯ�� �� ����� ����
	int money = 0; // ���� �ܾ�

public:
	ATM(); // ������
	void deposit(); // �Ա�
	void withdraw(); // ����
	void send(string receiver, int sendMon); // ��ü-����
	void receive(int receiveMon); // ��ü-����
	int getMoney(); // �� �ִ��� ���
	string getName(); // �̸� �ҷ�����
	void setName(); // ������ �̸� �Է�
	void setPw(); // ���� ��й�ȣ �Է�
	void setMoney(); // ������ �ܾ� �Է�
	void pwCheck1(); // ��й�ȣ ��Ȯ��
	void pwCheck2();
};

int main()
{
	int num; // ���࿡ ������ �ο� ��
	int i, n, k = 0, m = 0;
	string Name = "ME"; // ������ ����� �̸�
	string receiver = "YOU"; //�޴� ��� �̸�
	int number; // �޴� ��ȣ �����ϴ� ����
	int sendMoney; // ���� �ݾ�

	cout << "���࿡ ������ �ο��� �Է����ּ��� > ";
	cin >> num;
	ATM* account = new ATM[num]; // num��ŭ ��ü �迭 ���� ����

	for (i = 0; i < num; i++)  //for���� ���� num�� �ش��ϴ� ���ڸ�ŭ ������ ����
	{
		cout << endl << i + 1 << "��° �մ�" << endl << endl;
		cout << "������ �����ֽʽÿ� >> ";
		(account + i)->setName();
		cout << "��й�ȣ�� �Է����ּ��� >> ";
		(account + i)->setPw();
		cout << "�� �� �� �Է����ּ��� >> ";
		(account + i)->pwCheck1();
		cout << "�Ա��� �ݾ��� �Է����ּ��� >> ";
		(account + i)->setMoney();
		cout << endl;
	}

	while (1)
	{
		while (1)
		{
			cout << endl << " --- SWING ATM ---" << endl;
			cout << "������ �Է����ּ��� (������ x�� �Է����ּ���) >> ";
			cin >> Name;

			if (Name == "x") // x �Է��ϸ� while�� ��������
				break;

			k = 100; // k�� �ʱ�ȭ
			for (n = 0; n < num; n++)
			{
				if (Name == (account + n)->getName())
					k = n;
				// Name�� �������� �̸��� ���Ͽ� ���� �� �ش� �ε��� ���� k�� ����
			}

			// k���� �״�� 100�̸� �������� �ʴ´ٴ� ���� ����ϰ� ��
			// x �Է��� �� �Ʒ� ���� �Բ� ��µ��� �ʵ��� Name != "x" ���� �߰�
			if (k == 100 && Name != "x")
				cout << "�������� �ʴ� �������Դϴ�." << endl;
			else
				break; // �����ϴ� ������ �̸� �Է� �� ��ȣ ���� â���� �Ѿ
		}

		if (Name == "x") // �� while������ �������� ��, ����ڰ� 'x' �Է��ϸ� while�� ���������� ���α׷� ����
			break;

		number = 0;

		while (number != 5)
		{
			cout << endl << " --- SWING ATM " << (account + k)->getName() << "�� ---" << endl;
			cout << "1. �Ա�" << endl;
			cout << "2. ����" << endl;
			cout << "3. ��ü" << endl;
			cout << "4. �ܾ� Ȯ��" << endl;
			cout << "5. ����" << endl << endl;
			cout << "��ȣ�� �������ּ��� >> ";
			cin >> number;

			switch (number)
			{
			case 1:
			{
				cout << "�Ա��� �ݾ��� �Է����ּ��� >> ";
				(account + k)->deposit();
				cout << endl << "���� " << (account + k)->getName() << "���� �ܾ��� " << (account + k)->getMoney() << "�� �Դϴ�." << endl;
				break;
			}
			case 2:
			{
				cout << "�󸶸� �����Ͻðڽ��ϱ�? >> ";
				(account + k)->withdraw();
				cout << "��й�ȣ�� �Է����ּ��� >> ";
				(account + k)->pwCheck2();
				cout << endl << "���� " << (account + k)->getName() << "���� �ܾ��� " << (account + k)->getMoney() << "�� �Դϴ�." << endl;
				break;
			}
			case 3:
			{
				cout << "�������� �����ڽ��ϱ�? >> ";
				cin >> receiver;

				m = 100; // m�� �ʱ�ȭ(:�ʱ�ȭ ���ϸ� ���Ե� ����� �ƴ� ����� �̸��� �Է��ϸ� ������ �ԷµǾ��� �ε��� ���� �����ȴ�.)

				for (n = 0; n < num; n++)
				{
					if (receiver == (account + n)->getName())
						m = n;
					// Name��  �̸��� ���Ͽ� ���� �� �ش� �ε��� ���� m�� ����
				}

				if (m == 100) // �ʱ� m�� �״���� �� �����ְ� �������� X
					break;

				cout << "�󸶸� �����ڽ��ϱ�? >> ";
				cin >> sendMoney;
				(account + k)->send((account + m)->getName(), sendMoney);
				cout << "��й�ȣ�� �Է����ּ��� >> ";
				(account + k)->pwCheck2();
				cout << endl << (account + m)->getName() << "�Բ� " << sendMoney << "���� ���½��ϴ�." << endl;
				(account + m)->receive(sendMoney);
				cout << endl << "���� " << (account + k)->getName() << "���� �ܾ��� " << (account + k)->getMoney() << "�� �Դϴ�." << endl;
				break;
			}
			case 4:
				cout << (account + k)->getName() << "���� ���� �ܾ��� " << (account + k)->getMoney() << "�� �Դϴ�." << endl; break;
			case 5: break;
			}
		}
	}

	cout << "ATM�� �����մϴ�." << endl;

	return 0;
}

ATM::ATM()
{};

void ATM::deposit()
{
	int plus;
	cin >> plus;
	money += plus;
}

void ATM::withdraw()
{
	int minus;
	cin >> minus;
	money -= minus;
}

void ATM::send(string receiver, int sendMon)
{
	money -= sendMon;
}

void ATM::receive(int receiveMon)
{
	money += receiveMon;
}

int ATM::getMoney()
{
	return money;
}

string ATM::getName()
{
	return name;
}

void ATM::setName()
{
	cin >> name;
}

void ATM::setPw()
{
	cin >> pw;
}

void ATM::setMoney()
{
	cin >> money;
}

void ATM::pwCheck1()
{
	cin >> check;

	if (check != pw)
	{
		while (check != pw) // �Էµ� ��й�ȣ�� pw�� �ٸ� �� ��� �ݺ�
		{
			cout << "��й�ȣ�� ���� �ٸ��ϴ�." << endl << endl;
			cout << "��й�ȣ�� �Է����ּ��� >> ";
			cin >> check;
		}
	}
}

void ATM::pwCheck2()
{
	cin >> check;

	if (check != pw)
	{
		while (check != pw) // �Էµ� ��й�ȣ�� pw�� �ٸ� �� ��� �ݺ�
		{
			cout << "��й�ȣ�� Ʋ�Ƚ��ϴ�." << endl;
			cout << "��й�ȣ�� �Է����ּ��� >> ";
			cin >> check;
		}
	}
}
