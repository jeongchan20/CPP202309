#include <iostream>
using namespace std;

int main()
{
	int choice;

	cout << "1. 파일 저장" << endl;
	cout << "2. 저장 없이 닫기" << endl;
	cout << "3. 종료" << endl;
	// choice 사용자로 부터 입력받음
	cin >> choice;

	//choice가 1인경우 "파일 저장을 선택했습니다." 표시후 if문 탈출 아니라면 else if로 넘어감
	if (choice == 1)
		cout << "파일 저장을 선택했습니다." << endl;
	//choice가 2인경우 "파일 닫기를 선택했습니다." 표시후 if문 탈출 else if로 넘어감
	else if (choice == 2)
		cout << "파일 닫기를 선택했습니다." << endl;
	//choice가 3인경우 "프로그램을 종료합니다." 표시후 if문 탈출 else로 넘어감
	else if (choice == 3)
		cout << "프로그램을 종료합니다." << endl;
	//choice가 3인 아닌경우는 "잘못된 선택입니다." 표시하고 if문 탈출 
	else
		cout << "잘못된 선택입니다." << endl;

	return 0;
}
