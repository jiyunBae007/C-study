#include <iostream>
#define SIZE 5

using namespace std;

void sort(int arry[SIZE]) {                    //sort �Լ� ����
	int temp;                                      
	for (int i = 0; i < SIZE - 1; i++) {       //�迭 arry�� �Էµ� ���� ������ 5���̹Ƿ� i�� 0���� SIZE-1�� 4���� for���� �ݺ��ϰ� ��
		for (int j = i + 1; j < SIZE; j++) {   
			if (arry[i] > arry[j]) {            // ���� 2������ swap�Լ��� ���� ���� �迭���� �տ� �ִ� ���� �ڿ� �ִ� ������ �۴ٸ� �� �� ���� ��ġ�� �ٲٰ� ��
				temp = arry[j];
				arry[j] = arry[i];
				arry[i] = temp;
			}
		}
	}
}


void print(int arry[SIZE]) {        // print �Լ� ����
	for (int i = 0; i < 5; i++)     // for ���� ����Ͽ� �迭 arry�� �����
		cout << arry[i] << " ";
}

int main() {
	int a, b, c, d, e;
	int i = 0;
	int arry[5];

	cout << "���� �ټ����� �Է����ּ��� (����� ����) >> ";   //����ڷκ��� 5���� ���� �Է¹޴´�.
	cin >> a >> b >> c >> d >> e;
	arry[0] = a;    //�Է¹��� 5���� ���� �迭�� �Է��Ѵ�.
	arry[1] = b;
	arry[2] = c;
	arry[3] = d;
	arry[4] = e;

	cout << "< ���� �� >" << endl;

	print(arry);

	cout << endl;

	sort(arry);

	cout << "< ���� �� >" << endl;

	print(arry);

}