#include<iostream>
#include<math.h>

using namespace std;

int main()
{
	//돈과 캔디 변수 선언 및 초기화
	int money = 0;
	int candy = 0;

	//사용자로 부터 가지고있는 돈과 캔디 가격 입력받음
	cout << "가지고 있는 돈은?";
	cin >> money;

	cout << "캔디의 가격은?";
	cin >> candy;

	//최대로 살수있는 캔디 수와 남은 돈을 출력시킴
	cout <<"최대로 살 수 있는 캔디" << money / candy << endl;
	cout <<"캔디 구입후 남은 돈" << money % candy << endl;

		return 0;
	


}