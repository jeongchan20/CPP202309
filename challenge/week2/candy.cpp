#include<iostream>
#include<math.h>

using namespace std;

int main()
{
	int money = 0;
	int candy = 0;

	cout << "������ �ִ� ����?";
	cin >> money;

	cout << "ĵ���� ������?";
	cin >> candy;

	cout <<"�ִ�� �� �� �ִ� ĵ��" << money / candy << endl;
	cout <<"ĵ�� ������ ���� ��" << money % candy << endl;

		return 0;
	


}