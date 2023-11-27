#include "user.h"
using namespace std;

const int mapX = 5;
const int mapY = 5;
// 클래스 전역변수 선언
User Magician;
User Warrior;

// 사용자 정의 함수
bool CheckXY(int user_x, int mapX, int user_y, int mapY);
void DisplayMap(int map[][mapX], int user_x1, int user_y1, int user_x2, int user_y2);
bool CheckGoal(int map[][mapX], int user_x, int user_y);
void CheckState(int map[][mapX], int user_x, int user_y, User& user);
bool CheckUser(User& user);
bool CheckUser(User&Magician);
bool CheckUser(User&Warrior);


// 메인 함수
int main() {
    // 클래스에서의 선언된 hp
    Magician.GetHP();
    Warrior.GetHP();

    // 0은 빈 공간, 1은 아이템, 2는 적, 3은 포션, 4는 목적지
    int map[mapY][mapX] = { {0, 1, 2, 0, 4},
                           {1, 0, 0, 2, 0},
                           {0, 0, 0, 0, 0},
                           {0, 2, 3, 0, 0},
                           {3, 0, 0, 0, 2} };

    // 두 플레이어의 위치를 저장할 변수
    int magician_x = 0;  // 첫 번째 플레이어 가로 번호
    int magician_y = 0;  // 첫 번째 플레이어 세로 번호

    int warrior_x = 2;   // 두 번째 플레이어 가로 번호
    int warrior_y = 0;   // 두 번째 플레이어 세로 번호

    // 게임 시작
    while (1) {  // 사용자에게 계속 입력받기 위해 무한 루프

        // 첫 번째 플레이어의 턴
        cout << "첫 번째 플레이어 - 현재 HP:" << Magician.GetHP()
            << "  명령어를 입력하세요 (상,하,좌,우,지도,종료): ";
        string magician_input;
        cin >> magician_input;

        if (magician_input == "상") {
            // 위로 한 칸 올라가기
            magician_y -= 1;
            bool in_map = CheckXY(magician_x, mapX, magician_y, mapY);
            if (in_map == false) {
                cout << "맵을 벗어났습니다. 다시 돌아갑니다." << endl;
                magician_y += 1;
            }
            else {
                CheckState(map, magician_x, magician_y, Magician);
                cout << "현재 HP:" << Magician.GetHP();
                cout << " 위로 한 칸 올라갑니다." << endl;
                DisplayMap(map, magician_x, magician_y, warrior_x, warrior_y);
                if (!CheckUser(Magician)) {
                    cout << "HP가 0 이하가 되었습니다. 실패했습니다.";
                    cout << "게임을 종료합니다.";
                    break;
                }
            }
        }
        // TODO: 나머지 입력에 대한 처리

        // 두 번째 플레이어의 턴
        cout << "두 번째 플레이어 - 현재 HP:" << Warrior.GetHP()
            << "  명령어를 입력하세요 (상,하,좌,우,지도,종료): ";
        string warrior_input;
        cin >> warrior_input;

        if (warrior_input == "상") {
            // 위로 한 칸 올라가기
            warrior_y -= 1;
            bool in_map = CheckXY(warrior_x, mapX, warrior_y, mapY);
            if (in_map == false) {
                cout << "맵을 벗어났습니다. 다시 돌아갑니다." << endl;
                warrior_y += 1;
            }
            else {
                CheckState(map, warrior_x, warrior_y, Warrior);
                cout << "현재 HP:" << Warrior.GetHP();
                cout << " 위로 한 칸 올라갑니다." << endl;
                DisplayMap(map, magician_x, magician_y, warrior_x, warrior_y);
                if (!CheckUser(Warrior)) {
                    cout << "HP가 0 이하가 되었습니다. 실패했습니다.";
                    cout << "게임을 종료합니다.";
                    break;
                }
            }
        }
        // TODO: 나머지 입력에 대한 처리

        // 목적지에 도달했는지 체크
        bool finish = CheckGoal(map, magician_x, magician_y) || CheckGoal(map, warrior_x, warrior_y);
        if (finish) {
            cout << "목적지에 도착했습니다! 축하합니다!" << endl;
            cout << "게임을 종료합니다." << endl;
            break;
        }
    }
    return 0;
}

void DisplayMap(int map[][mapX], int user_x1, int user_y1, int user_x2, int user_y2) {
    // 행부분을 Y좌표로 설정하는 이유는 기본적으로  Y좌표를 행부분으로
    // 인식하기 때문이다!
    for (int i = 0; i < mapY; i++) {
        for (int j = 0; j < mapX; j++) {
            if (i == user_y1 && j == user_x1) {
                cout << " USER1 |";  // 양 옆 1칸 공백
            }
            else if (i == user_y2 && j == user_x2) {
                cout << " USER2 |";  // 양 옆 1칸 공백
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
void CheckState(int map[][mapX], int user_x, int user_y,User& user) {
	switch (map[user_y][user_x]) {
	case 1:
		cout << "아이템이 있습니다" << endl;
		break;
	case 2:
		cout << "적이 있습니다. HP가 2 줄어듭니다." << endl;
		user.DecreaseHP(2);
		break;
	case 3:
		cout << "포션이 있습니다. HP가 2 늘어납니다." << endl;

		user.IncreaseHP(2);
		break;
	}
}
//hp체크 함수
bool CheckUser(User&user) {
	if (user.GetHP() < 1) {
		return false;
	}
	else
		return true;
}

bool CheckUser(User& Magician) {
    if (Magician.GetHP() < 1) {
        return false;
    }
    else
        return true;
}
bool CheckUser(User& Warrior) {
    if (Warrior.GetHP() < 1) {
        return false;
    }
    else
        return true;
}