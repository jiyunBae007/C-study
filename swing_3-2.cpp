#include <iostream>

using namespace std;

void swap(int *x, int *y) {         //swap �Լ� ���� �Է� ������ �ݴ�� �� ���� ����ϱ� ���ؼ��� ù ��° ���� ������ �� �ϳ��� ���� temp�� �ʿ��ϴ�.
	int temp;

	temp = *x;
	*x = *y;
	*y = temp;

}

int main() {
	int x, y;
	cout << "first number >> ";     // �� �� x, y�� ����ڷκ��� �Է� ����
	cin >> x;
	cout << "second number >> ";
	cin >> y;

	cout << "swap �� >>" << x<< " "<< y << endl;
	swap(x, y);                           //swap �Լ��� ȣ����
	cout << "swap �� >>" << x << " "<< y << endl;
}