#include <iostream>
using namespace std;

void swap(int& a, int& b) {
	int tmp;
	tmp = a;
	a=b;
}

int main() {
	int num;

	cout << "수열의 길이를 입력하세요: ";
	cin >> num;

	cout << endl;

	long* p = new long[num];

	cout << "입력한 수열의 길이만큼의 정수를 입력하세요: ";
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