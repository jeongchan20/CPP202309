#include<iostream>
using namespace std;

int main()
{
	int userInput; //userInput 정의

	cout << "정수를 10번 입력하세요 (0을 입력하면 종료):";

	for (int i = 0; i < 10; i++) //i가 0~9까지 문장안에 있는 내용 반복
	{
		cin >> userInput;
		if (userInput == 0) //userInput이 0이라면 for문을 break에 의하여 탈출~
		{
			break;

			cout << "입력값: " << userInput << " 횟수 :" << i << endl; //cout을 출력함 userInput의 입력값에따라서..
		}
		cout << "종료 되었습니다";

		return 0;
	}
}