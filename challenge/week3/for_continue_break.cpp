#include<iostream>
using namespace std;

int main()
{
	int userInput; //userInput 값을 받아드림

	cout << "정수를 10번 입력하세요 (0을 입력하면 종료)";


	for (int i = 0; i < 10; i++) //초기값 i와 조건는 i가 10이하이고 증감값은 1임
	{
		cin >> userInput;
		if (userInput == 0) {
			break; // userInput 값이 0이면 if문 탈출
		}

		cout << "입력값: " << userInput << "횟수 :" << i << endl;


	}
	cout << "종료 되었습니다";

	return 0;
}