#include <iostream>
#include<string>
using namespace std;

class PhoneBook
{
private:
    string number; // 전화번호
    string name; // 이름
public:
    PhoneBook(); // 생성자
    void setPnum(string number); // 전화번호 저장
    void setName(string name); // 이름 저장
    void addPhone(string name, string number); // 이름과 전화번호 저장
    string getPnum(); // 전화번호 가져오기
    string getName(); // 이름 가져오기
    void editPnum(string number); // 추가-번호 수정
};

class PhoneBookManager
{
private:
    PhoneBook* phoneB; // 객체 배열 생성을 위한 선언
    int size; // 객체 배열의 크기
public:
    PhoneBookManager(int num); // 생성자 - PhoneBook으로 객체 배열 생성
    void showAll(); // 전화번호부 목록 보기
    void searchPnum(); // 전화번호 찾기
    void addPnum(); // 전화번호 객체 추가 생성(배열의 원소 개수 +1)
    void editPnum(); // 전화번호 수정
};

int main()
{
    int num; // 전화번호 수
    int menu = 0; // 메뉴 번호 받는 변수

    cout << " --- SWING 전화번호부 ---" << endl;
    cout << "저장할 전화번호의 수를 입력해주세요 >> ";
    cin >> num;
    PhoneBookManager manager(num);
    while (menu != 5)
    {
        cout << endl << " --- SWING 전화번호부 --- " << endl;
        cout << "1. 전화번호부 보기" << endl;
        cout << "2. 전화번호 검색" << endl;
        cout << "3. 전화번호 추가하기" << endl;
        cout << "4. 전화번호 수정하기" << endl;
        cout << "5. 종료" << endl;

        cout << "번호를 입력해주세요 >> ";
        cin >> menu;

        switch (menu)
        {
        case 1: manager.showAll(); break;
        case 2: manager.searchPnum(); break;
        case 3: manager.addPnum(); break;
        case 4: manager.editPnum(); break;
        case 5: cout << endl << endl << "프로그램을 종료합니다." << endl; break;
        default: cout << endl << endl << "잘못 입력하셨습니다." << endl;
        }
    }
}

PhoneBook::PhoneBook()
{}

void PhoneBook::setPnum(string number)
{
    this->number = number;
}

void PhoneBook::setName(string name)
{
    this->name = name;
}

void PhoneBook::addPhone(string name, string number)
{
    this->number = number;
    this->name = name;
}

string PhoneBook::getPnum()
{

    return number;
}

string PhoneBook::getName()
{
    return name;
}

void PhoneBook::editPnum(string number)
{
    this->number.replace(0, 13, number); // 기존 전화번호를 새로받은 전화번호로 수정하기
}

PhoneBookManager::PhoneBookManager(int num)  //num만큼 전화번호부에 사람을 저장하게 한다.
{
    int i;
    string name1, number1;   
    size = num;
    phoneB = new PhoneBook[size]; // size만큼 객체 배열 동적 생성한다.

    for (i = 0; i < num; i++) // 이름과 전화번호 입력
    {
        cout << i + 1 << "번째 사람의 이름을 입력해주세요 >> ";
        cin >> name1;
        phoneB[i].setName(name1);
        cout << i + 1 << "번째 사람의 전화번호를 입력해주세요 >> ";
        cin >> number1;
        phoneB[i].setPnum(number1);
        cout << endl;
    }
}

void PhoneBookManager::showAll()       //전체 목록을 보여주는 함수_for문을 사용해 출력함
{
    cout << endl << endl;
    int i;
    for (i = 0; i < size; i++)
    {
        cout << i + 1 << ". " << phoneB[i].getName();
        cout << "::" << phoneB[i].getPnum() << endl;
    }
}

void PhoneBookManager::searchPnum()
{
    int i, n = 100;
    string search;
    cout << endl << endl << "누구의 번호를 검색하겠습니까? >> ";
    cin >> search;
    for (i = 0; i < size; i++)
    {
        if (search == phoneB[i].getName())
            n = i; // search와 사용자가 찾는 사람의 이름이 같을 경우에, 인덱스 값 n에 대입
    }

    if (n < size) // n이 size보다 작은 경우, 일치하는 이름 있을 때 해당하는 인덱스 값의 전화번호 출력
        cout << phoneB[n].getName() << "님의 전화번호 : " << phoneB[n].getPnum() << endl;

    if (n == 100) // n값이 그대로인 경우, 일치하는 이름 없음
        cout << "연락처가 존재하지 않습니다." << endl;
}

void PhoneBookManager::addPnum()
{
    string newName, newNumber;
    int i;

    cout << endl << endl << "이름을 입력해주세요 >> ";
    cin >> newName;
    cout << "전화번호를 입력해주세요 >> ";
    cin >> newNumber;

    PhoneBook* tmp = new PhoneBook[size + 1]; // 임시 객체 배열 tmp 생성

    for (i = 0; i < size; i++) // tmp 배열에 phoneB 배열 복사
        tmp[i] = phoneB[i];

    delete[] phoneB; // phoneB 배열 메모리 반환
    size++; // 사이즈 1씩 증가

    phoneB = new PhoneBook[size]; // 사이즈가 '1'이 증가된 상태로 메모리 다시 할당
    for (i = 0; i < size; i++) // phoneB 배열에 tmp 배열 복사
        phoneB[i] = tmp[i];

    phoneB[size - 1].addPhone(newName, newNumber); // 전화번호 추가

    cout << "전화번호가 추가되었습니다." << endl;
}

void PhoneBookManager::editPnum()
{
    int i, m = 100;
    string editName, editNumber;
    cout << endl << endl << "누구의 번호를 수정하겠습니까? >> ";
    cin >> editName;
    for (i = 0; i < size; i++)
    {
        if (editName == phoneB[i].getName())
            m = i; // editName과 일치하는 이름의 인덱스 값 m에 대입
    }

    if (m < size) // m이 size보다 작은 경우, 해당하는 인덱스 값 있으면 전화번호 변경 진행
    {
        cout << "변경할 번호를 입력해주세요 >> ";
        cin >> editNumber;
        phoneB[m].editPnum(editNumber);
        cout << "전화번호가 변경되었습니다." << endl;
    }

    if (m == 100) // m값이 그대로 1000인 경우, 일치하는 이름 없음
        cout << "연락처가 존재하지 않습니다." << endl;
}