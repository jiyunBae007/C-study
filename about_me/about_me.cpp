#include <iostream>
#include <string>
using namespace std;
int main()
{
	string name;
	cout << "�̸��� �Է��ϼ���.: ";
	getline(cin, name);

	string birth;
	cout << "������ �Է��ϼ���.: ";
	getline(cin, birth);

	string age;
	cout << "���̸� �Է�������.: ";
	getline(cin, age);

	string major;
	cout << "�Ҽ��а��� �Է��ϼ���.: ";
	getline(cin, major);
	
	cout << "<ȸ�� ����>" << '\n';
	cout << "�̸�: " << name<<'\n';
	cout << "����: " << birth << '\n';
	cout << "����: " << age << '\n';
	cout << "�Ҽ��а�: " << major<<'\n';

}