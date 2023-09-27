#include<iostream>
#include<time.h>
using namespace std;

int main() {

	int i;
	int ans; //정답 입력!
	int corretct = 0; //정답 갯수 체크 

	cout << "산수 문제를 자동으로 출제합니다 ." << endl;

	while (corretct < 5) {
		int firstNum = rand() % 100; //0~99까지의 정수 값
		int secondNum = rand() % 100; //0~99까지의 정수 값

			cout << firstNum << "+" << secondNum << "="; //화면에 문제 출력
			cin >> ans; //사용자로부터 입력 받음 답을
	

			if (ans == firstNum + secondNum) //사용자의 값과 답이 일치하면 맞았습니다를 출력후 correctct에 1증감
			{
				cout << "맞았습니다 ." << endl;
				corretct++;
			}
			else
			{

				cout << "틀렷습니다" << endl;//사용자의 값과 답이 일치하면 맞았습니다를 출력후 correctct에 1증감
				
			}

		}
			
	}