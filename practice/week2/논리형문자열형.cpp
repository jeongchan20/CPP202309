#include<iostream>
#include<string>
using namespace std;

int main()
{   //s1에 Good문자 저장 s2에는 bad문자 저장 
	string s1 = "Good";
	string s2 = "bad";

	//s1에 bool는 논리형 이므로 0,1만 반환함 참이면 1 거짓이면 0을 반환함
		bool b = (s1 == s2);
	cout << b << endl;

	s2 = "Good";
	b = (s1 == s2);
	cout << b << endl;
}