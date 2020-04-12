#include <iostream>
using namespace std;
int main()
{
	int num1,num2;
	cout << "First number>>";
	cin >> num1;
	cout << "Second number>>";
	cin >> num2;

	cout << "계산 결과"<<'\n';
	cout << num1 << "+" << num2 << "=" << (num1 + num2) << '\n';
	cout << num1 << "-" << num2 << "=" << (num1 - num2) << '\n';
	cout << num1 << "*" << num2 << "=" << (num1 * num2) << '\n';

	double num1_2, num2_2;
	num1_2 = num1;
	num2_2 = num2;
	cout << num1 << "/" << num2 << "=" << (num1_2 / num2_2) << '\n';

}