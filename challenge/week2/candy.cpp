#include<iostream>
#include<math.h>

using namespace std;

int main()
{
	//���� ĵ�� ���� ���� �� �ʱ�ȭ
	int money = 0;
	int candy = 0;

	//����ڷ� ���� �������ִ� ���� ĵ�� ���� �Է¹���
	cout << "������ �ִ� ����?";
	cin >> money;

	cout << "ĵ���� ������?";
	cin >> candy;

	//�ִ�� ����ִ� ĵ�� ���� ���� ���� ��½�Ŵ
	cout <<"�ִ�� �� �� �ִ� ĵ��" << money / candy << endl;
	cout <<"ĵ�� ������ ���� ��" << money % candy << endl;

		return 0;
	


}