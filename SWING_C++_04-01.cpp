#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class Random {                  //Random 클래스 생성
public:                          //멤버에 대한 접근을 public으로 해서 모든 클래스 접근을 가능하게 했다.
    Random();                     //멤버 함수 생성
    int next();                  
    int nextInRange(int x, int y);
};
Random::Random() {                   //Random 클래스에 정의된 멤버 함수 Random()을 구현
    srand((unsigned)time(0));        //srand로 난수를 생성하게 함. 이때 unsigned를 사용해 양수인 난수를 생성하게함
}
int Random::next() {              //Random 클래스에 정의된 멤버 함수 next()를 구현
    return rand();                // rand() 함수를 return하게 함. 즉 난수를 리턴값으로 함
}
int Random::nextInRange(int x, int y) {   //Random 클래스에 정의된 멤버 함수 nextInRange()를 구현
    return rand() % (y - x + 1) + x;      //리턴 값으로  (y-x+1)+x로 rand()를 나눈 값을 반환한다.
}
int main() {                            //메인 함수 부분
    Random r;                            //객체 r 생성
    cout << "-- 0에서 " << RAND_MAX << "까지의 랜덤 정수 10 개--" << endl;     //문구를 출력하게 함.
    for (int i = 0; i < 10; ++i) {                                               //for 문이 10번 돌면서 10개의 정수를 출력하게 함.
        int n = r.next(); // 0에서 RAND_MAX(32767) 사이의 랜덤한 정수
        cout << n << ' ';
    }
    cout << endl << endl << "-- 2에서 " << "4 까지의 랜덤 정수 10 개 --" << endl;    //문구를 출력하게 함.
    for (int i = 0; i < 10; ++i) {                                                //for 문을 10번 돌면서 10개의 정수를 출력하게 함.
        int n = r.nextInRange(2, 4); //2에서 4 사이의 랜덤한 정수
        cout << n << ' ';
    }
    cout << endl;
}