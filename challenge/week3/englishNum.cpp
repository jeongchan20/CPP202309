#include <iostream>
using namespace std;

int main()
{
	int number;
	cout << "숫자를 입력하시오";
	
	//number를 입력받음
	cin >> number;

	//number가 0이면 zero를 표시하고 if문 탈출
	if (number == 0)
		cout << "zero\n";
	//number가 1이면 one를 표시하고 if문 탈출
	else if (number == 1)
		cout << "one\n";
	//number가 1이 아니면 many를 표시하고 if문 탈출
	else
		cout << "many\n";

	return 0;
}
