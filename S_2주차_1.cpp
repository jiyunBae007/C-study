#include <iostream>
#include <string>
using namespace std;

int main()
{
	int number[5];                           //입력 받을 숫자의 배열 생성
	cout << "숫자를 입력해주세요: ";         //숫자 5개 입력 받기
	cin >> number[0];
	cout << "숫자를 입력해주세요: ";
	cin >> number[1];
	cout << "숫자를 입력해주세요: ";
	cin >> number[2];
	cout << "숫자를 입력해주세요: ";
	cin >> number[3];
	cout << "숫자를 입력해주세요: ";
	cin >> number[4];
	
	cout << "------------ 결과---------------\n";
	
	int i;                                      //반복문 제어 변수 생성
	int count1=0;                              //짝수가 몇 개인지 세는 변수 생성
	int count2=0;                              //홀수가 몇 개인지 세는 변수 생성
	
	cout << "홀수: ";                          
	for (i = 0; i < 5; i++) {                  // 숫자가 모두 5개이므로 5개의 숫자를 홀/짝으로 나누기 위해 i의 조건을 5 이하로 잡음(인덱스는 0~4)
		if (number[i] % 2 == 0) {              //2로 나누었을 때 나머지가 0이면 짝수
			count1++;                          //짝수로 판별이 난 숫자의 개수가 늘어날수록 count1이 0에서 하나씩 더해진다. 
			continue;                          //숫자가 짝수로 판별이 나면 그 다음 문자으로 넘어가지 않고 for문의 처음으로 돌아가서 홀수로 판별이 난 숫자만 출력이 된다.
		}
		else {
			count2++;
			cout << number[i] << " ";
		}
	}


	cout << "\n홀수는 총 " << count2 << "개 입니다.\n";

	cout << "짝수: ";                         //짝수도 홀수를 출력한 방법으로 똑같이 for문을 돌면서 짝수로 판별이 나면 출력하게 함
	for (i = 0; i < 5; i++) {
		if (number[i] % 2 == 0) {
			
			cout << number[i] << " ";
		}
	}
	cout << "\n짝수는 총" << count1 << "개 입니다.\n";
	


}
