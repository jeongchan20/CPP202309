#include<iostream>
#include<string>
using namespace std;

int main()
{
	const int STUDENT = 5; //상수선언
	const int SUBJECT = 3;//상수선언

	int scores[STUDENT][SUBJECT]; //2차원배열 scores 선언

	string studentNames[STUDENT] = { "영수","영희","철수","미미","쥬쥬" }; //STUDENT배열에 이름 대입
	string subjectNames[SUBJECT] = { "수학","영어","CPP"};//SUBJECT배열에 과목 대입

	for (int i = 0; i < STUDENT; i++)
	{
		cout << studentNames[i] << "의 성적을 하나씩 입력하세요." << endl; //사람이름 i번쨰이름을 출력
		for (int j = 0; j < SUBJECT; j++)
		{
			cout << subjectNames[j] << ":"; //교과목 입력을 출력시킴
			cin >> scores[i][j]; // 교과목,사람배열의 배열에다가 점수를 입력시킴
		}
	}

	for (int i = 0; i < STUDENT; i++)
	{
		cout << studentNames[i] << "의 평균 점수는";
		double sum = 0;
		double average = 0;

		for (int j = 0; j < SUBJECT; j++) { //sum변수에다 scores에 값이 넣어둔것을 더해줌.. for문이 끝나기 전에
			sum += scores[i][j];
		}
		average = sum / SUBJECT;
		cout << average << "입니다" << endl;
	}
	return 0;
}
