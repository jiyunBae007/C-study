#include<iostream>
#include<string>
using namespace std;

string str_day[] = { "SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT" };
int month_day[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };



// 날짜이름
string solution(int month, int day)
{
    int sum = 0;

    for (int i = 1; i < month; i++)
    {
        sum += month_day[i - 1];
    }

    sum += day - 1;

    int answer_day = (5 + sum) % 7;   // 2016.1.1 = 금

    return str_day[answer_day];
}
int main()
{
    int a = 0;
    int b = 0;

    cout << "월과 요일을 입력하세요: ";
    cin >> a;
    cin >> b;

    cout << solution(a,b);
    return 0;
}

