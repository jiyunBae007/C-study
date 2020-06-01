#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class Random {                  //Random Ŭ���� ����
public:                          //����� ���� ������ public���� �ؼ� ��� Ŭ���� ������ �����ϰ� �ߴ�.
    Random();                     //��� �Լ� ����
    int next();                  
    int nextInRange(int x, int y);
};
Random::Random() {                   //Random Ŭ������ ���ǵ� ��� �Լ� Random()�� ����
    srand((unsigned)time(0));        //srand�� ������ �����ϰ� ��. �̶� unsigned�� ����� ����� ������ �����ϰ���
}
int Random::next() {              //Random Ŭ������ ���ǵ� ��� �Լ� next()�� ����
    return rand();                // rand() �Լ��� return�ϰ� ��. �� ������ ���ϰ����� ��
}
int Random::nextInRange(int x, int y) {   //Random Ŭ������ ���ǵ� ��� �Լ� nextInRange()�� ����
    return rand() % (y - x + 1) + x;      //���� ������  (y-x+1)+x�� rand()�� ���� ���� ��ȯ�Ѵ�.
}
int main() {                            //���� �Լ� �κ�
    Random r;                            //��ü r ����
    cout << "-- 0���� " << RAND_MAX << "������ ���� ���� 10 ��--" << endl;     //������ ����ϰ� ��.
    for (int i = 0; i < 10; ++i) {                                               //for ���� 10�� ���鼭 10���� ������ ����ϰ� ��.
        int n = r.next(); // 0���� RAND_MAX(32767) ������ ������ ����
        cout << n << ' ';
    }
    cout << endl << endl << "-- 2���� " << "4 ������ ���� ���� 10 �� --" << endl;    //������ ����ϰ� ��.
    for (int i = 0; i < 10; ++i) {                                                //for ���� 10�� ���鼭 10���� ������ ����ϰ� ��.
        int n = r.nextInRange(2, 4); //2���� 4 ������ ������ ����
        cout << n << ' ';
    }
    cout << endl;
}