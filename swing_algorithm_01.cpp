#include <iostream>
using namespace std;

void swap(int& a, int& b) {
	int tmp;
	tmp = a;
	a=b;
}

int main() {
	int num;

	cout << "������ ���̸� �Է��ϼ���: ";
	cin >> num;

	cout << endl;

	long* p = new long[num];

	cout << "�Է��� ������ ���̸�ŭ�� ������ �Է��ϼ���: ";
	for (int i = 0; i < num; i++) {
		cin >> p[i];
	}

	int min;
	for (int i = 0; i < num - 1; i++) {
		min = i;

		for (int j = i + 1; j < num; j++) {
			if (p[min] > p[j]) {
				min = j;
			}
		}
		swap(p[min], p[i]);
	}


	for (int i = 0; i < num; i++)
		cout << p[i] << " ";
}