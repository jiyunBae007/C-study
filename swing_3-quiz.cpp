#include <iostream>
#include <string>
using namespace std;

int max(int x, int y) {
	if (x > y) return x;
	else return y;
}

int min(int x, int y) {
	if (x > y) return y;
	else return x;
}

int main() {
	int x, y;
	cout << "�� ���� �Է��� �ּ��� (����� ����)<< ";
	cin >> x >> y;
	cout << endl;

	cout << "ū �� >>" << max(x, y) << endl;
	cout << "���� �� >>" << min(x, y) << endl;
}