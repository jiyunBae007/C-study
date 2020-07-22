#include <iostream>
using namespace std;


void hanoi(int n, char A, char C, char B) {
	if (n == 1)
		cout << A << " ����" << B << "�� �̵�" << endl;
	else
	{
		hanoi(n - 1, A, B, C);
		cout << A << " ����" << B << "�� �̵�" << endl;

		hanoi(n - 1, C, A, B);

	}
}

int main() {
	int num;

SEVEN:
	cout << "������ ������ �Է��ϼ��� >> ";
	cin >> num;

	int p = pow(2, num)-1; // ������ ������ num�� �� �� �̵��� Ƚ���� 2^num-1�̴�.

	if (1 <= num && num <= 20)
	{
		cout << "�� �̵� Ƚ���� :" << p << endl;
		hanoi(num, 'A', 'C', 'B');
		goto EXIT;
	}
	else
	{
		cout << "num�� 1�̻� 20���ϸ� �����մϴ�" << endl;
		goto SEVEN;
	}

EXIT:
	return 0;
}

	



