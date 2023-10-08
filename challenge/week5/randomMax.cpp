#include<iostream>
#include<stdlib.h>
using namespace std;

int main()
{
	const int numCell = 10; //numcCell 상수로 10선언
	int numlist[numCell][numCell]; //2차원 상자 생성!


	for (int i = 0; i < numCell; i++) //입력을 받기위해서 행을 for문으로 돌림
	{
		for (int j = 0; j < numCell; j++)  //입력을 받기위해서 열을 for문으로 돌림
		{
			int elem = rand() % 1000;  //elem에 0~999에 변수를 넣음
			numlist[i][j] = elem; //2차원 배열에 각각 1칸씩 elem를 값을 가지게됨
			cout << i << "," << j << " : " << elem << endl;
		}
	}

	cout << endl;
	int max = 0;
	int maxI = 0;
	int maxJ = 0;

	for (int i = 0; i < numCell; i++) //출력을 위해 이중 for문을 만듬 행을 돌림
	{
		int j = 0; //j를 0으로 직접설정!!

		for (int value : numlist[i]) //for문을 변위기반으로 함 i줄 행을 끌고 와서 일일히 열을 비교시킴
		{

			if (value > max) //value가 max보다 클경우!
			{
				{
					max = value; //max에다가 value값을 대입함
					maxI = i; //maxI에 i를 대입시킴
					maxJ = j;

				}
				j++;
			}
		}

		cout << "가장 큰 값은 " << max << "이고,";
		cout << "i와 j는 각각 " << maxI << "," << maxJ << "입니다" << endl;
		cout << "검증 결과: " << numlist[maxI][maxJ] << endl;

		return 0;
	}
}