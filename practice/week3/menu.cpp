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
	// 케이스를 나눠서 그에따라 출력값이 변화됨 
	switch (choice) {
		// 1번이 맞다면 스위치문 을 탈출
	case 1:
		cout << "파일 저장을 선택했습니다." << endl;
		break;
		// 2번이 맞다면 스위치문 을 탈출
	case 2:
		cout << "파일 닫기를 선택했습니다." << endl;
		break;
		// 3번이 맞다면 스위치문 을 탈출
	case 3:
		cout << "프로그램을 종료합니다." << endl;
		break;
		//마지막은 케이스가 없으므로 default값 출력후 스위치문 탈출 
	default:
		cout << "잘못된 선택입니다." << endl;
		break;
	}

	return 0;

}


