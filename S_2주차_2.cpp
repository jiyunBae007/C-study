#include <iostream>
#include <string>
using namespace std;

int main()
{

	int num;
	cout << "-----------별 찍기 시스템-------------\n";
	cout << "만들고 싶은 모양을 선택해주세요. \n";
	cout << "1. 직각삼각형 \n2. 정삼각형 \n3. 나비 \n4. 나가기 \n";
	cin >> num;

	int x;
	switch (num) {
	case 1: 
	{
		cout << "직각삼각형을 선택하셨습니다.\n";
		cout << "행의 개수를 선택해주세요.\n";
		cin >> x;
		int i, k;
		for (i = 0; i < x; i++) {                   // 직각삼각형을 오른쪽부터 시작하기 위해 for문 안에 두개의 for문을 사용했다.
			for (k = 0; k <= x - i - 1; k++)        // 맨 오른쪽부터 별이 하나씩 찍히기 위해서는 커서가 왼쪽부터 시작하기 때문에 정해진 갯수의 별을 찍기 전에 공백이 필요하다. 이 부분의 코딩은 그 공백과 별을 찍는 부분이다.
				cout << " ";
			for (int j = 0; j < i + 1; j++)
				cout << '*';

			cout << endl;
		}
		cout << "\n";
		for (i = x; i >= 1; i--) {                 //이 부분은 별의 개수가 줄어드는 부분이다. 그렇기에 감소하는 식을 썼다.
			for (k = i; k >= 1; k--)
				cout << '*';

			cout << endl;
		}
	break;
	}
	case 2:
	{	cout << "정삼각형을 선택하셨습니다.\n";
	cout << "행의 개수를 선택해주세요.\n";
	cin >> x;

	for (int i = 0; i < x; i++) {              // 정삼각형의 모양으로 별이 찍힐 때 마지막 칸의 별의 개수는 (사용자가 입력한 행의 개수인)x*2-1 으로 나타난다. 따라서 공백은 칸이 내려갈수록 x-1부터 0까지 점점 줄어들어야하고 별의 개수는 i*2+1로 점점 늘어나야한다.
		for (int k = x - 1; k > i; k--)
			cout << " ";
		for (int j = 0; j < 2 * i + 1; j++)
			cout << '*';

		cout << endl;

	}
	break;
	}
	case 3:
	{cout << "나비를 선택하셨습니다.\n";
	cout << "홀수를 입력해주세요:";
	cin >> x;

	while (x % 2 == 0) {                 //홀수를 입력할 때까지 홀수를 입력하라는 안내문이 나오는 것을 while문을 통해 반복하게 함
		cout << "홀수를 입력해주세요:";
		cin >> x;
	}


	int t;
	int j;
	int mid = x / 2; // 중간값(반전)

// i 변수는 무조건 행 반복(0~x)
	for (t = 0; t < x; t++)
	{
		if (t < mid + 1)                    // 중간값까지는 별표를 증가
		{
			for (j = 0; j < t + 1; j++)
				cout << "*";

			// 공백 추가(공백 감소)
			for (j = 0; j < mid - t; j++)

				cout << " ";


			cout << " "; // 정가운데 구분공백

			// 공백 추가(공백 감소)
			for (j = 0; j < mid - t; j++)

				cout << " ";

			// 열 반복(별표 증가)
			for (j = 0; j < (t + 1); j++)
				cout << "*";

		}
		else                                // 중간값 이후로는 별표를 감소
		{
			for (j = 0; j < x - t; j++)

				cout << "*";

			// 공백 추가(공백 증가)
			for (j = 0; j < (t - mid); j++) // (행수 - 중간값)만큼 공백 추가

				cout << " ";


			cout << " "; // 정가운데 구분공백

			// 공백 추가(공백 증가)
			for (j = 0; j < (t - mid); j++)

				cout << " ";

			// 열 반복(별표 감소)
			for (j = 0; j < x - t; j++)

				cout << "*";

		}

		cout << endl; // 줄바꿈
	}
	break;
	}

	case 4:
	{	cout << "나가기를 선택하셨습니다.\n";
	cout << "감사합니다\n";
	break;
	}


	}
}