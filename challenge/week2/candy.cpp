#include<iostream>
#include<math.h>

using namespace std;

int main()
{
	int money = 0;
	int candy = 0;

	cout << "가지고 있는 돈은?";
	cin >> money;

	cout << "캔디의 가격은?";
	cin >> candy;

	cout <<"최대로 살 수 있는 캔디" << money / candy << endl;
	cout <<"캔디 구입후 남은 돈" << money % candy << endl;

		return 0;
	


}