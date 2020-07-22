#include <iostream>
using namespace std;


void hanoi(int n, char A, char C, char B) {
	if (n == 1)
		cout << A << " 에서" << B << "로 이동" << endl;
	else
	{
		hanoi(n - 1, A, B, C);
		cout << A << " 에서" << B << "로 이동" << endl;

		hanoi(n - 1, C, A, B);

	}
}

int main() {
	int num;

SEVEN:
	cout << "원판의 개수를 입력하세요 >> ";
	cin >> num;

	int p = pow(2, num)-1; // 원판의 개수가 num일 때 총 이동의 횟수는 2^num-1이다.

	if (1 <= num && num <= 20)
	{
		cout << "총 이동 횟수는 :" << p << endl;
		hanoi(num, 'A', 'C', 'B');
		goto EXIT;
	}
	else
	{
		cout << "num은 1이상 20이하만 가능합니다" << endl;
		goto SEVEN;
	}

EXIT:
	return 0;
}

	



