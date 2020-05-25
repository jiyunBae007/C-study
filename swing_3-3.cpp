#include <iostream>
#define SIZE 5

using namespace std;

void sort(int arry[SIZE]) {                    //sort 함수 생성
	int temp;                                      
	for (int i = 0; i < SIZE - 1; i++) {       //배열 arry에 입력된 수의 개수가 5개이므로 i가 0부터 SIZE-1인 4까지 for문을 반복하게 함
		for (int j = i + 1; j < SIZE; j++) {   
			if (arry[i] > arry[j]) {            // 과제 2에서의 swap함수와 같이 만약 배열에서 앞에 있는 수가 뒤에 있는 수보다 작다면 이 두 수의 위치를 바꾸게 함
				temp = arry[j];
				arry[j] = arry[i];
				arry[i] = temp;
			}
		}
	}
}


void print(int arry[SIZE]) {        // print 함수 생성
	for (int i = 0; i < 5; i++)     // for 문을 사용하여 배열 arry를 출력함
		cout << arry[i] << " ";
}

int main() {
	int a, b, c, d, e;
	int i = 0;
	int arry[5];

	cout << "숫자 다섯개를 입력해주세요 (띄어쓰기로 구분) >> ";   //사용자로부터 5개의 수를 입력받는다.
	cin >> a >> b >> c >> d >> e;
	arry[0] = a;    //입력받은 5개의 수를 배열에 입력한다.
	arry[1] = b;
	arry[2] = c;
	arry[3] = d;
	arry[4] = e;

	cout << "< 정렬 전 >" << endl;

	print(arry);

	cout << endl;

	sort(arry);

	cout << "< 정렬 후 >" << endl;

	print(arry);

}