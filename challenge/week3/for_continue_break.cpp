#include<iostream>
using namespace std;

int main()
{
	int userInput; //userInput ���� �޾Ƶ帲

	cout << "������ 10�� �Է��ϼ��� (0�� �Է��ϸ� ����)";


	for (int i = 0; i < 10; i++) //�ʱⰪ i�� ���Ǵ� i�� 10�����̰� �������� 1��
	{
		cin >> userInput;
		if (userInput == 0) {
			break; // userInput ���� 0�̸� if�� Ż��
		}

		cout << "�Է°�: " << userInput << "Ƚ�� :" << i << endl;


	}
	cout << "���� �Ǿ����ϴ�";

	return 0;
}