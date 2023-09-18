#include <iostream>
using namespace std;

int main()
{
	// a,b,c,smallgest 변수 선언
	int a, b, c, smallgest;

	cout << "3개의 정수를 입력하시오 ";

	// a,b,c 사용자에게 입력받음
	cin >> a >> b >> c;

	// a가 b보다 작고 a가 c보다 작으면 smallgest에 a 값 대입
	if (a < b && a < c)
		smallgest = a;
	// b가 a보다 작고 b가 c보다 작으면 smallgest에 b 값 대입
	else if (b < a && b < c)
		smallgest = b;
	// 나머지 경우 smallgest에 c 값 대입
	else
		smallgest = c;

	// 대입된 smallgest 값 표시
	cout << "가장 작은 정수는 " << smallgest << endl;

	return 0;
}