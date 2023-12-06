#include "���.h"
#include<fstream>
using namespace std;

const int mapX = 5;
const int mapY = 5;
// 0�� �� ����, 1�� ������, 2�� ��, 3�� ����, 4�� ������
int map[mapY][mapX] = { {0, 1, 2, 0, 4},
                           {1, 0, 0, 2, 0},
                           {0, 0, 0, 0, 0},
                           {0, 2, 3, 0, 0},
                           {3, 0, 0, 0, 2} };

// Ŭ���� �������� ����
User Magician;
User Warrior;


// ����� ���� �Լ�
bool CheckXY(int user_x, int mapX, int user_y, int mapY);
void DisplayMap(int map[][mapX], int user_x1, int user_y1, int user_x2, int user_y2);
bool CheckGoal(int map[][mapX], int user_x, int user_y);
void CheckState(int map[][mapX], int user_x, int user_y, User& user);
bool CheckUser(User& user);
void MoveUser(const string& input, int& user_x, int& user_y, int mapX, int mapY, User& user);
void LoadMapFromFile(const std::string& filename, int map[][mapX]);


// ���� �Լ�
int main() {
    // Ŭ���������� ����� hp
    Magician.GetHP();
    Warrior.GetHP();

    const std::string mapFileName = "map.txt";
    LoadMapFromFile(mapFileName, map);


    // �� �÷��̾��� ��ġ�� ������ ����
    int magician_x = 0;  // ù ��° �÷��̾� ���� ��ȣ
    int magician_y = 0;  // ù ��° �÷��̾� ���� ��ȣ

    int warrior_x = 2;   // �� ��° �÷��̾� ���� ��ȣ
    int warrior_y = 0;   // �� ��° �÷��̾� ���� ��ȣ

    bool magician_turn = true;  // ����Ŀ�� ������ ���θ� ��Ÿ���� �÷���

    while (1) {  // ����ڿ��� ��� �Է¹ޱ� ���� ���� ����

        // �÷��̾��� ��
        if (magician_turn) {
            // ù ��° �÷��̾��� ��
            cout << "Magician �����Դϴ� - ���� HP:" << Magician.GetHP()
                << "  ��ɾ �Է��ϼ��� (��,��,��,��,����,����): ";
            string magician_input;
            cin >> magician_input;

            // �÷��̾� �̵� �� ���� üũ
            MoveUser(magician_input, magician_x, magician_y, mapX, mapY, Magician);
            CheckState(map, magician_x, magician_y, Magician);

            // ���� �÷��̾� ���� ���
            cout << "���� HP:" << Magician.GetHP() << " ";
            cout << "���� �� ĭ �ö󰩴ϴ�." << endl;
            DisplayMap(map, magician_x, magician_y, warrior_x, warrior_y);

            // �÷��̾� ���� üũ �� ���� ���� ���� Ȯ��
            if (!CheckUser(Magician)) {
                cout << "Magician�� HP�� 0 ���ϰ� �Ǿ����ϴ�. �����߽��ϴ�.";
                cout << "������ �����մϴ�.";
                break;
            }
        }
        else {
            // �� ��° �÷��̾��� ��
            cout << "Warrior �����Դϴ� - ���� HP:" << Warrior.GetHP()
                << "  ��ɾ �Է��ϼ��� (��,��,��,��,����,����): ";
            string warrior_input;
            cin >> warrior_input;

            // �÷��̾� �̵� �� ���� üũ
            MoveUser(warrior_input, warrior_x, warrior_y, mapX, mapY, Warrior);
            CheckState(map, warrior_x, warrior_y, Warrior);

            // ���� �÷��̾� ���� ���
            cout << "���� HP:" << Warrior.GetHP() << " ";
            cout << "���� �� ĭ �ö󰩴ϴ�." << endl;
            DisplayMap(map, magician_x, magician_y, warrior_x, warrior_y);

            // �÷��̾� ���� üũ �� ���� ���� ���� Ȯ��
            if (!CheckUser(Warrior)) {
                cout << "Warrior�� HP�� 0 ���ϰ� �Ǿ����ϴ�. �����߽��ϴ�.";
                cout << "������ �����մϴ�.";
                break;
            }
        }

        // �÷��̾��� ���� ����
        magician_turn = !magician_turn;

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
                cout << " M    |";  // �� �� 1ĭ ����
            }
            else if (i == user_y2 && j == user_x2) {
                cout << " W    |";  // �� �� 1ĭ ����
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
        if (user_y < mapY)
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
void CheckState(int map[][mapX], int user_x, int user_y, User& user) {
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
bool CheckUser(User& user) {
    if (user.GetHP() < 1) {
        return false;
    }
    else
        return true;
}
void MoveUser(const string& input, int& user_x, int& user_y, int mapX, int mapY, User& user) {
    int new_x = user_x;
    int new_y = user_y;

    if (input == "��") {
        new_y = user_y - 1;
    }
    else if (input == "��") {
        new_y = user_y + 1;
    }
    else if (input == "��") {
        new_x = user_x - 1;
    }
    else if (input == "��") {
        new_x = user_x + 1;
    }

    if (CheckXY(new_x, mapX, new_y, mapY)) {
        user_x = new_x;
        user_y = new_y;
        CheckState(map, user_x, user_y, user);
        cout << "���� HP:" << user.GetHP() << " " << input << "���� �̵��߽��ϴ�." << endl;

    }
    else {
        cout << "���� ������ϴ�. �ٽ� ���ư��ϴ�." << endl;

    }
}

void LoadMapFromFile(const string& filename, int map[][mapX]) {
    ifstream file(filename);

    try {
        if (!file.is_open()) {
            throw runtime_error("������ �� �� �����ϴ�.");
        }

        file.close();
    }
    catch (const exception& e) {
        cerr << "���� �߻�: " << e.what() << endl;
        exit(EXIT_FAILURE);
    }

}
