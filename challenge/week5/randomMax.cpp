#include<iostream>
#include<stdlib.h>
using namespace std;

int main()
{
	const int numCell = 10; //numcCell ����� 10����
	int numlist[numCell][numCell]; //2���� ���� ����!


	for (int i = 0; i < numCell; i++) //�Է��� �ޱ����ؼ� ���� for������ ����
	{
		for (int j = 0; j < numCell; j++)  //�Է��� �ޱ����ؼ� ���� for������ ����
		{
			int elem = rand() % 1000;  //elem�� 0~999�� ������ ����
			numlist[i][j] = elem; //2���� �迭�� ���� 1ĭ�� elem�� ���� �����Ե�
			cout << i << "," << j << " : " << elem << endl;
		}
	}

	cout << endl;
	int max = 0;
	int maxI = 0;
	int maxJ = 0;

	for (int i = 0; i < numCell; i++) //����� ���� ���� for���� ���� ���� ����
	{
		int j = 0; //j�� 0���� ��������!!

		for (int value : numlist[i]) //for���� ����������� �� i�� ���� ���� �ͼ� ������ ���� �񱳽�Ŵ
		{

			if (value > max) //value�� max���� Ŭ���!
			{
				{
					max = value; //max���ٰ� value���� ������
					maxI = i; //maxI�� i�� ���Խ�Ŵ
					maxJ = j;

				}
				j++;
			}
		}

		cout << "���� ū ���� " << max << "�̰�,";
		cout << "i�� j�� ���� " << maxI << "," << maxJ << "�Դϴ�" << endl;
		cout << "���� ���: " << numlist[maxI][maxJ] << endl;

		return 0;
	}
}