#include<iostream>
#include<string>
using namespace std;

int main()
{   //s1�� Good���� ���� s2���� bad���� ���� 
	string s1 = "Good";
	string s2 = "bad";

	//s1�� bool�� ���� �̹Ƿ� 0,1�� ��ȯ�� ���̸� 1 �����̸� 0�� ��ȯ��
		bool b = (s1 == s2);
	cout << b << endl;

	s2 = "Good";
	b = (s1 == s2);
	cout << b << endl;
}