#include <iostream>

using namespace std;

void swap(int *x, int *y) {         //swap 함수 생성 입력 순서와 반대로 두 수를 출력하기 위해서는 첫 번째 수를 저장할 또 하나의 변수 temp가 필요하다.
	int temp;

	temp = *x;
	*x = *y;
	*y = temp;

}

int main() {
	int x, y;
	cout << "first number >> ";     // 두 수 x, y를 사용자로부터 입력 받음
	cin >> x;
	cout << "second number >> ";
	cin >> y;

	cout << "swap 전 >>" << x<< " "<< y << endl;
	swap(x, y);                           //swap 함수를 호출함
	cout << "swap 후 >>" << x << " "<< y << endl;
}