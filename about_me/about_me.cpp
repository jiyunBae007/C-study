#include <iostream>
#include <string>
using namespace std;
int main()
{
	string name;
	cout << "이름을 입력하세요.: ";
	getline(cin, name);

	string birth;
	cout << "생일을 입력하세요.: ";
	getline(cin, birth);

	string age;
	cout << "나이를 입려가세요.: ";
	getline(cin, age);

	string major;
	cout << "소속학과를 입력하세요.: ";
	getline(cin, major);
	
	cout << "<회원 정보>" << '\n';
	cout << "이름: " << name<<'\n';
	cout << "생일: " << birth << '\n';
	cout << "나이: " << age << '\n';
	cout << "소속학과: " << major<<'\n';

}