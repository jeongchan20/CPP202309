#include<iostream>
#include<stdlib.h>
using namespace std;

int main()
{
	const int numCell = 10; //numcCell ����� 10����
	int numlist[numCell][numCell]; //2���� ���� ����!


	for (int i = 0; i < numCell; i++)  //�Է��� �ޱ����ؼ� ���� for������ ����
	{
		for (int j = 0; j < numCell; j++)  //�Է��� �ޱ����ؼ� ���� for������ ����
		{
			int elem = rand() % 1000; //elem�� 0~999�� ������ ����
			numlist[i][j] =elem; //2���� �迭�� ���� 1ĭ�� elem�� ���� �����Ե�
			cout << i << "," << j << " : " << elem << endl;
		}
	}

	cout << endl;
	int max;
	int maxI;
	int maxJ;

	for (int i = 0; i < numCell; i++) //����� ���� ���� for���� ���� ���� ����
	{
		for (int j = 0; j < numCell; j++) //����� ���� ���� for���� ���� ���� ����
		{
			int value = numlist[i][j]; //vlaue����[i][j]�� ����
			if (value > max) //value�� max�� ũ�ٸ� vlaue�� max������ ��ü!�ϰ� i��j�� maxI maxJ�� �� ���Ե�
			{
				max = value;
				maxI = i;
				maxJ = j;

			}
		}
	}

	cout << "���� ū ���� " << max << "�̰�,";
	cout << "i�� j�� ���� " << maxI << "," << maxJ << "�Դϴ�" << endl;
	cout << "���� ���: " << numlist[maxI][maxJ] << endl;

	return 0;
}