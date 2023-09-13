#include<iostream>
//상수를 정의함.. 변수와 달리 상수는 고정된값으로 프로그램이 빌드가됨
#define PI 3.14159265359 
using namespace std;

int main()
{
	int income = 1000;
	//TAX_rate를 상수로 고정시킴
	const double TAX_RATE = 0.25;
	//income을 재정의 함
	income = income - TAX_RATE * income;

	double x = 100;
	x = x * PI;
	//x를 출력시킴
	cout << x << endl;
	return 0;


}