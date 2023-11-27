#include "user.h"
using namespace std;

const int mapX = 5;
const int mapY = 5;
// Ŭ���� �������� ����
User Magician;
User Warrior;

// ����� ���� �Լ�
bool CheckXY(int user_x, int mapX, int user_y, int mapY);
void DisplayMap(int map[][mapX], int user_x1, int user_y1, int user_x2, int user_y2);
bool CheckGoal(int map[][mapX], int user_x, int user_y);
void CheckState(int map[][mapX], int user_x, int user_y, User& user);
bool CheckUser(User& user);
bool CheckUser(User&Magician);
bool CheckUser(User&Warrior);


// ���� �Լ�
int main() {
    // Ŭ���������� ����� hp
    Magician.GetHP();
    Warrior.GetHP();

    // 0�� �� ����, 1�� ������, 2�� ��, 3�� ����, 4�� ������
    int map[mapY][mapX] = { {0, 1, 2, 0, 4},
                           {1, 0, 0, 2, 0},
                           {0, 0, 0, 0, 0},
                           {0, 2, 3, 0, 0},
                           {3, 0, 0, 0, 2} };

    // �� �÷��̾��� ��ġ�� ������ ����
    int magician_x = 0;  // ù ��° �÷��̾� ���� ��ȣ
    int magician_y = 0;  // ù ��° �÷��̾� ���� ��ȣ

    int warrior_x = 2;   // �� ��° �÷��̾� ���� ��ȣ
    int warrior_y = 0;   // �� ��° �÷��̾� ���� ��ȣ

    // ���� ����
    while (1) {  // ����ڿ��� ��� �Է¹ޱ� ���� ���� ����

        // ù ��° �÷��̾��� ��
        cout << "ù ��° �÷��̾� - ���� HP:" << Magician.GetHP()
            << "  ��ɾ �Է��ϼ��� (��,��,��,��,����,����): ";
        string magician_input;
        cin >> magician_input;

        if (magician_input == "��") {
            // ���� �� ĭ �ö󰡱�
            magician_y -= 1;
            bool in_map = CheckXY(magician_x, mapX, magician_y, mapY);
            if (in_map == false) {
                cout << "���� ������ϴ�. �ٽ� ���ư��ϴ�." << endl;
                magician_y += 1;
            }
            else {
                CheckState(map, magician_x, magician_y, Magician);
                cout << "���� HP:" << Magician.GetHP();
                cout << " ���� �� ĭ �ö󰩴ϴ�." << endl;
                DisplayMap(map, magician_x, magician_y, warrior_x, warrior_y);
                if (!CheckUser(Magician)) {
                    cout << "HP�� 0 ���ϰ� �Ǿ����ϴ�. �����߽��ϴ�.";
                    cout << "������ �����մϴ�.";
                    break;
                }
            }
        }
        // TODO: ������ �Է¿� ���� ó��

        // �� ��° �÷��̾��� ��
        cout << "�� ��° �÷��̾� - ���� HP:" << Warrior.GetHP()
            << "  ��ɾ �Է��ϼ��� (��,��,��,��,����,����): ";
        string warrior_input;
        cin >> warrior_input;

        if (warrior_input == "��") {
            // ���� �� ĭ �ö󰡱�
            warrior_y -= 1;
            bool in_map = CheckXY(warrior_x, mapX, warrior_y, mapY);
            if (in_map == false) {
                cout << "���� ������ϴ�. �ٽ� ���ư��ϴ�." << endl;
                warrior_y += 1;
            }
            else {
                CheckState(map, warrior_x, warrior_y, Warrior);
                cout << "���� HP:" << Warrior.GetHP();
                cout << " ���� �� ĭ �ö󰩴ϴ�." << endl;
                DisplayMap(map, magician_x, magician_y, warrior_x, warrior_y);
                if (!CheckUser(Warrior)) {
                    cout << "HP�� 0 ���ϰ� �Ǿ����ϴ�. �����߽��ϴ�.";
                    cout << "������ �����մϴ�.";
                    break;
                }
            }
        }
        // TODO: ������ �Է¿� ���� ó��

        // �������� �����ߴ��� üũ
        bool finish = CheckGoal(map, magician_x, magician_y) || CheckGoal(map, warrior_x, warrior_y);
        if (finish) {
            cout << "�������� �����߽��ϴ�! �����մϴ�!" << endl;
            cout << "������ �����մϴ�." << endl;
            break;
        }
    }
    return 0;
}

void DisplayMap(int map[][mapX], int user_x1, int user_y1, int user_x2, int user_y2) {
    // ��κ��� Y��ǥ�� �����ϴ� ������ �⺻������  Y��ǥ�� ��κ�����
    // �ν��ϱ� �����̴�!
    for (int i = 0; i < mapY; i++) {
        for (int j = 0; j < mapX; j++) {
            if (i == user_y1 && j == user_x1) {
                cout << " USER1 |";  // �� �� 1ĭ ����
            }
            else if (i == user_y2 && j == user_x2) {
                cout << " USER2 |";  // �� �� 1ĭ ����
            }
            else {
                int pos_state = map[i][j];
                switch (pos_state) {
                case 0:
                    cout << "      |";  // 6ĭ ����
                    break;
                case 1:
                    cout << "������|";
                    break;
                case 2:
                    cout << "  ��  |";  // �� �� 2ĭ ����
                    break;
                case 3:
                    cout << " ���� |";  // �� �� 1ĭ ����
                    break;
                case 4:
                    cout << "������|";
                    break;
                }
            }
        }
        cout << endl;
        cout << " -------------------------------- " << endl;
    }
}

// �̵��Ϸ��� ���� ��ȿ�� ��ǥ���� üũ�ϴ� �Լ�
bool CheckXY(int user_x, int mapX, int user_y, int mapY) {
	bool check_flag = false;
	if (user_x >= 0 && user_x < mapX && user_y >= 0) {
		if(user_y < mapY)
		check_flag = true;
	}
	return check_flag;
}

// ������ ��ġ�� ���������� üũ�ϴ� �Լ�
bool CheckGoal(int map[][mapX], int user_x, int user_y) {
	// ������ �����ϸ�
	if (map[user_y][user_x] == 4) {
		return true;
	}
	return false;
}



// ������ � ���������� ���� ��ȯ���� ���ϴ� �Լ�
void CheckState(int map[][mapX], int user_x, int user_y,User& user) {
	switch (map[user_y][user_x]) {
	case 1:
		cout << "�������� �ֽ��ϴ�" << endl;
		break;
	case 2:
		cout << "���� �ֽ��ϴ�. HP�� 2 �پ��ϴ�." << endl;
		user.DecreaseHP(2);
		break;
	case 3:
		cout << "������ �ֽ��ϴ�. HP�� 2 �þ�ϴ�." << endl;

		user.IncreaseHP(2);
		break;
	}
}
//hpüũ �Լ�
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