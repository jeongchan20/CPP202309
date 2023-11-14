#include "user.h"
using namespace std;

const int mapX = 5;
const int mapY = 5;
//클래스 전역변수 선언
User my_user;


// 사용자 정의 함수
bool CheckXY(int user_x, int mapX, int user_y, int mapY);
void DisplayMap(int map[][mapX], int user_x, int user_y);
bool CheckGoal(int map[][mapX], int user_x, int user_y);
void CheckState(int map[][mapX], int user_x, int user_y);
bool CheckUser(User user);

// 메인  함수
int main() {
	//클래스에서의 선언된 hp
	 my_user.GetHP();
	// 0은 빈 공간, 1은 아이템, 2는 적, 3은 포션, 4는 목적지
	int map[mapY][mapX] = { {0, 1, 2, 0, 4},
						   {1, 0, 0, 2, 0},
						   {0, 0, 0, 0, 0},
						   {0, 2, 3, 0, 0},
						   {3, 0, 0, 0, 2} };

	// 유저의 위치를 저장할 변수
	int user_x = 0;  // 가로 번호
	int user_y = 0;  // 세로 번호

	// 게임 시작
	while (1) {  // 사용자에게 계속 입력받기 위해 무한 루프

		// 사용자의 입력을 저장할 변수
		string user_input = "";
		int k = 0;

		cout << "현재 HP:" << my_user.GetHP()
			<< "  명령어를 입력하세요 (상,하,좌,우,지도,종료): ";
		cin >> user_input;

		if (user_input == "상") {
			// 위로 한 칸 올라가기
			user_y -= 1;
			bool in_map = CheckXY(user_x, mapX, user_y, mapY);
			if (in_map == false) {
				cout << "맵을 벗어났습니다. 다시 돌아갑니다." << endl;
				user_y += 1;
			}
			else {
				// 맵이 벗어 나지 않으므로 실행 moveminus함수로 -1를 시켜줌
				CheckState(map, user_x, user_y);
				my_user.DecreaseHP(1);
				cout << "현재 HP:" << my_user.GetHP();
				cout << " 위로 한 칸 올라갑니다." << endl;
				DisplayMap(map, user_x, user_y);
				// 체력이 0일경우 종료
				if (not(CheckUser(my_user))) {
					cout << "HP가 0 이하가 되었습니다. 실패했습니다.";
					cout << "게임을 종료합니다.";
					break;
				}
			}

		}
		else if (user_input == "하") {
			// TODO: 아래로 한 칸 내려가기
			user_y += 1;
			bool in_map = CheckXY(user_x, mapX, user_y, mapY);
			if (in_map == false) {
				cout << "맵을 벗어났습니다. 다시 돌아갑니다." << endl;
				user_y -= 1;
			}
			else {
				CheckState(map, user_x, user_y);
				my_user.DecreaseHP(1);
					cout << "현재 HP:" << my_user.GetHP();
				cout << " 위로 한 칸 내려갑니다." << endl;
				DisplayMap(map, user_x, user_y);
				// 체력이 0일경우 종료
				if (not(CheckUser(my_user))) {
					cout << "HP가 0 이하가 되었습니다. 실패했습니다.";
					cout << "게임을 종료합니다.";
					break;
				}
			}
		}
		else if (user_input == "좌") {
			// TODO: 왼쪽으로 이동하기
			user_x -= 1;
			bool in_map = CheckXY(user_x, mapX, user_y, mapY);

			if (in_map == false) {
				cout << "맵을 벗어났습니다. 다시 돌아갑니다." << endl;
				user_x += 1;
			}
			else {
				
				CheckState(map, user_x, user_y);
				my_user.DecreaseHP(1);
				cout << "현재 HP:" << my_user.GetHP();
				cout << "왼쪽으로 이동합니다." << endl;
				DisplayMap(map, user_x, user_y);
				// 체력이 0일경우 종료
				if (not(CheckUser(my_user))) {
					cout << "HP가 0 이하가 되었습니다. 실패했습니다.";
					cout << "게임을 종료합니다.";
					break;
				}
			}
		}
		else if (user_input == "우") {
			// TODO: 오른쪽으로 이동하기
			user_x += 1;
			bool in_map = CheckXY(user_x, mapX, user_y, mapY);
			if (in_map == false) {
				cout << "맵을 벗어났습니다. 다시 돌아갑니다." << endl;
				user_x -= 1;
			}
			else {
				// 맵이 벗어 나지 않으므로 실행 moveminus함수로 -1를 시켜줌
				CheckState(map, user_x, user_y);
				my_user.DecreaseHP(1);
				cout << "현재 HP:" << my_user.GetHP();
				cout << "오른쪽으로 이동합니다." << endl;
				DisplayMap(map, user_x, user_y);
				// 체력이 0일경우 종료
				if (not(CheckUser(my_user))) {
					cout << "HP가 0 이하가 되었습니다. 실패했습니다.";
					cout << "게임을 종료합니다.";
					break;
				}
			}
		}
		else if (user_input == "지도") {
			// TODO: 지도 보여주기 함수 호출
			DisplayMap(map, user_x, user_y);
		}
		else if (user_input == "종료") {
			cout << "종료합니다.";
			break;
		}
		else {
			cout << "잘못된 입력입니다." << endl;
			continue;
		}

		// 목적지에 도달했는지 체크
		bool finish = CheckGoal(map, user_x, user_y);
		if (finish == true) {
			cout << "목적지에 도착했습니다! 축하합니다!" << endl;
			cout << "게임을 종료합니다." << endl;
			break;
		}
	}
	return 0;
}

// 지도와 사용자 위치 출력하는 함수\
//배열의 크기를 정의할때 열부분만 적어도 인식을함! 원래는 둘다 적어야하지만!
void DisplayMap(int map[][mapX], int user_x, int user_y) {
	// 행부분을 Y좌표로 설정하는 이유는 기본적으로  Y좌표를 행부분으로
	// 인식하기때문이다!
	for (int i = 0; i < mapY; i++) {
		for (int j = 0; j < mapX; j++) {
			if (i == user_y && j == user_x) {
				cout << " USER |";  // 양 옆 1칸 공백
			}
			else {
				int pos_state = map[i][j];
				switch (pos_state) {
				case 0:
					cout << "      |";  // 6칸 공백
					break;
				case 1:
					cout << "아이템|";
					break;
				case 2:
					cout << "  적  |";  // 양 옆 2칸 공백
					break;
				case 3:
					cout << " 포션 |";  // 양 옆 1칸 공백
					break;
				case 4:
					cout << "목적지|";
					break;
				}
			}
		}
		cout << endl;
		cout << " -------------------------------- " << endl;
	}
}

// 이동하려는 곳이 유효한 좌표인지 체크하는 함수
bool CheckXY(int user_x, int mapX, int user_y, int mapY) {
	bool check_flag = false;
	if (user_x >= 0 && user_x < mapX && user_y >= 0) {
		if(user_y < mapY)
		check_flag = true;
	}
	return check_flag;
}

// 유저의 위치가 목적지인지 체크하는 함수
bool CheckGoal(int map[][mapX], int user_x, int user_y) {
	// 목적지 도착하면
	if (map[user_y][user_x] == 4) {
		return true;
	}
	return false;
}



// 유저가 어떤 상태인지에 따라 반환값을 정하는 함수
void CheckState(int map[][mapX], int user_x, int user_y) {
	switch (map[user_y][user_x]) {
	case 1:
		cout << "아이템이 있습니다" << endl;
		break;
	case 2:
		cout << "적이 있습니다. HP가 2 줄어듭니다." << endl;
		my_user.DecreaseHP(2);
		break;
	case 3:
		cout << "포션이 있습니다. HP가 2 늘어납니다." << endl;

		my_user.IncreaseHP(2);
		break;
	}
}
//hp체크 함수
bool CheckUser(User user) {
	if (user.GetHP() < 1) {
		return false;
	}
	else
		return true;
}