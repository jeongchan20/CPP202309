#include <iostream>
using namespace std;

int main()
{
	// a,b,c,largest 변수 선언
	int a, b, c, largest;

	cout << "3개의 정수를 입력하시오 ";

	// a,b,c 사용자에게 입력받음
	cin >> a >> b >> c;

	// a가 b보다 크고 a가 c보다 크면 largest에 a 값 대입
	if (a > b && a > c)
		largest = a;
	// b가 a보다 크고 b가 c보다 크면 largest에 b 값 대입
	else if (b > a && b > c)
		largest =b;
	// 나머지 경우 largest에 c 값 대입
	else
		largest =c;
	// 대입된 largest 값 표시
	cout << "가장 큰 정수는 " << largest << endl;

	return 0;
}