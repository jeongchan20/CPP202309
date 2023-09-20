#include<iostream>
#include<time.h>
using namespace std;

int main() {

	srand(time(NULL)); //random 함수 관련 설정

	int answer = rand() % 100; //정답

	int tries = 0; //시도 횟수 저장하는 변수

	int guess; //사용자 입력 저장하기 위한 변수

	do {	//일단 실행을 함
		cout << "정답을 추측하여 보시오";

		cin >> guess; //추측값 입력받음
		tries++;

		if (answer > guess) //정답이 더 크다면  추측값이 낮다고 표시해줌
			cout << "제시한 정수가 낮습니다." << endl;
		if (answer <guess)	//정답이 더 낮다면  추측값이 높다고 표시해줌
			cout << "제시한 정수가 높습니다." << endl;

	} while (answer!= guess); //정답과 추측값이 다르지 않는게 거짓이면 탈출 즉 맞다면 탈출

	cout << "축하합니다. 시도 횟수 " << tries << endl;

	return 0;
}

			