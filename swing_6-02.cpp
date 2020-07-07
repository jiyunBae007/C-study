#include <iostream>
#include<string>
using namespace std;

class PhoneBook
{
private:
    string number; // ��ȭ��ȣ
    string name; // �̸�
public:
    PhoneBook(); // ������
    void setPnum(string number); // ��ȭ��ȣ ����
    void setName(string name); // �̸� ����
    void addPhone(string name, string number); // �̸��� ��ȭ��ȣ ����
    string getPnum(); // ��ȭ��ȣ ��������
    string getName(); // �̸� ��������
    void editPnum(string number); // �߰�-��ȣ ����
};

class PhoneBookManager
{
private:
    PhoneBook* phoneB; // ��ü �迭 ������ ���� ����
    int size; // ��ü �迭�� ũ��
public:
    PhoneBookManager(int num); // ������ - PhoneBook���� ��ü �迭 ����
    void showAll(); // ��ȭ��ȣ�� ��� ����
    void searchPnum(); // ��ȭ��ȣ ã��
    void addPnum(); // ��ȭ��ȣ ��ü �߰� ����(�迭�� ���� ���� +1)
    void editPnum(); // ��ȭ��ȣ ����
};

int main()
{
    int num; // ��ȭ��ȣ ��
    int menu = 0; // �޴� ��ȣ �޴� ����

    cout << " --- SWING ��ȭ��ȣ�� ---" << endl;
    cout << "������ ��ȭ��ȣ�� ���� �Է����ּ��� >> ";
    cin >> num;
    PhoneBookManager manager(num);
    while (menu != 5)
    {
        cout << endl << " --- SWING ��ȭ��ȣ�� --- " << endl;
        cout << "1. ��ȭ��ȣ�� ����" << endl;
        cout << "2. ��ȭ��ȣ �˻�" << endl;
        cout << "3. ��ȭ��ȣ �߰��ϱ�" << endl;
        cout << "4. ��ȭ��ȣ �����ϱ�" << endl;
        cout << "5. ����" << endl;

        cout << "��ȣ�� �Է����ּ��� >> ";
        cin >> menu;

        switch (menu)
        {
        case 1: manager.showAll(); break;
        case 2: manager.searchPnum(); break;
        case 3: manager.addPnum(); break;
        case 4: manager.editPnum(); break;
        case 5: cout << endl << endl << "���α׷��� �����մϴ�." << endl; break;
        default: cout << endl << endl << "�߸� �Է��ϼ̽��ϴ�." << endl;
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
    this->number.replace(0, 13, number); // ���� ��ȭ��ȣ�� ���ι��� ��ȭ��ȣ�� �����ϱ�
}

PhoneBookManager::PhoneBookManager(int num)  //num��ŭ ��ȭ��ȣ�ο� ����� �����ϰ� �Ѵ�.
{
    int i;
    string name1, number1;   
    size = num;
    phoneB = new PhoneBook[size]; // size��ŭ ��ü �迭 ���� �����Ѵ�.

    for (i = 0; i < num; i++) // �̸��� ��ȭ��ȣ �Է�
    {
        cout << i + 1 << "��° ����� �̸��� �Է����ּ��� >> ";
        cin >> name1;
        phoneB[i].setName(name1);
        cout << i + 1 << "��° ����� ��ȭ��ȣ�� �Է����ּ��� >> ";
        cin >> number1;
        phoneB[i].setPnum(number1);
        cout << endl;
    }
}

void PhoneBookManager::showAll()       //��ü ����� �����ִ� �Լ�_for���� ����� �����
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
    cout << endl << endl << "������ ��ȣ�� �˻��ϰڽ��ϱ�? >> ";
    cin >> search;
    for (i = 0; i < size; i++)
    {
        if (search == phoneB[i].getName())
            n = i; // search�� ����ڰ� ã�� ����� �̸��� ���� ��쿡, �ε��� �� n�� ����
    }

    if (n < size) // n�� size���� ���� ���, ��ġ�ϴ� �̸� ���� �� �ش��ϴ� �ε��� ���� ��ȭ��ȣ ���
        cout << phoneB[n].getName() << "���� ��ȭ��ȣ : " << phoneB[n].getPnum() << endl;

    if (n == 100) // n���� �״���� ���, ��ġ�ϴ� �̸� ����
        cout << "����ó�� �������� �ʽ��ϴ�." << endl;
}

void PhoneBookManager::addPnum()
{
    string newName, newNumber;
    int i;

    cout << endl << endl << "�̸��� �Է����ּ��� >> ";
    cin >> newName;
    cout << "��ȭ��ȣ�� �Է����ּ��� >> ";
    cin >> newNumber;

    PhoneBook* tmp = new PhoneBook[size + 1]; // �ӽ� ��ü �迭 tmp ����

    for (i = 0; i < size; i++) // tmp �迭�� phoneB �迭 ����
        tmp[i] = phoneB[i];

    delete[] phoneB; // phoneB �迭 �޸� ��ȯ
    size++; // ������ 1�� ����

    phoneB = new PhoneBook[size]; // ����� '1'�� ������ ���·� �޸� �ٽ� �Ҵ�
    for (i = 0; i < size; i++) // phoneB �迭�� tmp �迭 ����
        phoneB[i] = tmp[i];

    phoneB[size - 1].addPhone(newName, newNumber); // ��ȭ��ȣ �߰�

    cout << "��ȭ��ȣ�� �߰��Ǿ����ϴ�." << endl;
}

void PhoneBookManager::editPnum()
{
    int i, m = 100;
    string editName, editNumber;
    cout << endl << endl << "������ ��ȣ�� �����ϰڽ��ϱ�? >> ";
    cin >> editName;
    for (i = 0; i < size; i++)
    {
        if (editName == phoneB[i].getName())
            m = i; // editName�� ��ġ�ϴ� �̸��� �ε��� �� m�� ����
    }

    if (m < size) // m�� size���� ���� ���, �ش��ϴ� �ε��� �� ������ ��ȭ��ȣ ���� ����
    {
        cout << "������ ��ȣ�� �Է����ּ��� >> ";
        cin >> editNumber;
        phoneB[m].editPnum(editNumber);
        cout << "��ȭ��ȣ�� ����Ǿ����ϴ�." << endl;
    }

    if (m == 100) // m���� �״�� 1000�� ���, ��ġ�ϴ� �̸� ����
        cout << "����ó�� �������� �ʽ��ϴ�." << endl;
}