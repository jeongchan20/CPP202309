#include<iostream>
#include<string>
using namespace std;

int main()
{
	//name을 string 문자열로 정의함
	string name;

	//이름을 표시할수있게 사용자화면에 나타냄
	cout << "이름을 입력하시오: ";
		cin >> name;
		//이름을 입력받을수있게함
	cout << name << "을 환영합니다." << endl;
	return 0;

}
