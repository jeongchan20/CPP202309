#include<iostream>
using namespace std;

int main()
{
	int userInput; //userInput ����

	cout << "������ 10�� �Է��ϼ��� (0�� �Է��ϸ� ����):";

	for (int i = 0; i < 10; i++) //i�� 0~9���� ����ȿ� �ִ� ���� �ݺ�
	{
		cin >> userInput;
		if (userInput == 0) //userInput�� 0�̶�� for���� break�� ���Ͽ� Ż��~
		{
			break;

			cout << "�Է°�: " << userInput << " Ƚ�� :" << i << endl; //cout�� ����� userInput�� �Է°�������..
		}
		cout << "���� �Ǿ����ϴ�";

		return 0;
	}
}