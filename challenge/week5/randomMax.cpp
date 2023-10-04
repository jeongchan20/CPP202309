#include<iostream>
#include<stdlib.h>
using namespace std;

int main()
{
	const int numCell = 10; //numcCell 상수로 10선언
	int numlist[numCell][numCell]; //2차원 상자 생성!


	for (int i = 0; i < numCell; i++)  //입력을 받기위해서 행을 for문으로 돌림
	{
		for (int j = 0; j < numCell; j++)  //입력을 받기위해서 열을 for문으로 돌림
		{
			int elem = rand() % 1000; //elem에 0~999에 변수를 넣음
			numlist[i][j] =elem; //2차원 배열에 각각 1칸씩 elem를 값을 가지게됨
			cout << i << "," << j << " : " << elem << endl;
		}
	}

	cout << endl;
	int max;
	int maxI;
	int maxJ;

	for (int i = 0; i < numCell; i++) //출력을 위해 이중 for문을 만듬 행을 돌림
	{
		for (int j = 0; j < numCell; j++) //출력을 위해 이중 for문을 만듬 열을 돌림
		{
			int value = numlist[i][j]; //vlaue값을[i][j]로 선언
			if (value > max) //value가 max가 크다면 vlaue를 max값으로 교체!하고 i와j도 maxI maxJ로 로 대입됨
			{
				max = value;
				maxI = i;
				maxJ = j;

			}
		}
	}

	cout << "가장 큰 값은 " << max << "이고,";
	cout << "i와 j는 각각 " << maxI << "," << maxJ << "입니다" << endl;
	cout << "검증 결과: " << numlist[maxI][maxJ] << endl;

	return 0;
}