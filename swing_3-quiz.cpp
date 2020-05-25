#include <iostream>
#include <string>
using namespace std;

int max(int x, int y) {         //큰 수를 찾는 함수 생성
	if (x > y) return x;
	else return y;
}

int min(int x, int y) {        //작은 수를 찾는 함수 생성
	if (x > y) return y;
	else return x;
}

int main() {
	int x, y;
	cout << "두 수를 입력해 주세요 (띄어쓰기로 구분)<< ";
	cin >> x >> y;
	cout << endl;

	cout << "큰 수 >>" << max(x, y) << endl;
	cout << "작은 수 >>" << min(x, y) << endl;
}
