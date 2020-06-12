#ifndef PHONEBOOK_H
#define PHONEBOOK_H

class PhoneBook
{
private:
	string name;
	string pnum;

public:
	void addPhone();
	void editPhone();
	string getPnum();
	string getName();
	void putName(); // 변수 name을 private으로 지정해서 main 함수에서 접근할 수 없기 때문에
					// 이름을 입력받는 함수 하나를 더 만들었습니다.
};

#endif
