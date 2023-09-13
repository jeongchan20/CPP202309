#include<iostream>
#include<string>
using namespace std;

int main()
{
	string s1 = "사과";
	string s2;
	// s2=s1+" " +10 + "개"는 10은 상수이므로 문자열과 결합할수가 없음;

	s2 = s1 + " " + to_string(10) + "개";
		cout << s2 << endl;
}