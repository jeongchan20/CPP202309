#include "user.h"
using namespace std;

const int mapX = 5;
const int mapY = 5;
//Ŭ���� �������� ����
User my_user;


// ����� ���� �Լ�
bool CheckXY(int user_x, int mapX, int user_y, int mapY);
void DisplayMap(int map[][mapX], int user_x, int user_y);
bool CheckGoal(int map[][mapX], int user_x, int user_y);
void CheckState(int map[][mapX], int user_x, int user_y);
bool CheckUser(User user);

// ����  �Լ�
int main() {
	//Ŭ���������� ����� hp
	 my_user.GetHP();
	// 0�� �� ����, 1�� ������, 2�� ��, 3�� ����, 4�� ������
	int map[mapY][mapX] = { {0, 1, 2, 0, 4},
						   {1, 0, 0, 2, 0},
						   {0, 0, 0, 0, 0},
						   {0, 2, 3, 0, 0},
						   {3, 0, 0, 0, 2} };

	// ������ ��ġ�� ������ ����
	int user_x = 0;  // ���� ��ȣ
	int user_y = 0;  // ���� ��ȣ

	// ���� ����
	while (1) {  // ����ڿ��� ��� �Է¹ޱ� ���� ���� ����

		// ������� �Է��� ������ ����
		string user_input = "";
		int k = 0;

		cout << "���� HP:" << my_user.GetHP()
			<< "  ��ɾ �Է��ϼ��� (��,��,��,��,����,����): ";
		cin >> user_input;

		if (user_input == "��") {
			// ���� �� ĭ �ö󰡱�
			user_y -= 1;
			bool in_map = CheckXY(user_x, mapX, user_y, mapY);
			if (in_map == false) {
				cout << "���� ������ϴ�. �ٽ� ���ư��ϴ�." << endl;
				user_y += 1;
			}
			else {
				// ���� ���� ���� �����Ƿ� ���� moveminus�Լ��� -1�� ������
				CheckState(map, user_x, user_y);
				my_user.DecreaseHP(1);
				cout << "���� HP:" << my_user.GetHP();
				cout << " ���� �� ĭ �ö󰩴ϴ�." << endl;
				DisplayMap(map, user_x, user_y);
				// ü���� 0�ϰ�� ����
				if (not(CheckUser(my_user))) {
					cout << "HP�� 0 ���ϰ� �Ǿ����ϴ�. �����߽��ϴ�.";
					cout << "������ �����մϴ�.";
					break;
				}
			}

		}
		else if (user_input == "��") {
			// TODO: �Ʒ��� �� ĭ ��������
			user_y += 1;
			bool in_map = CheckXY(user_x, mapX, user_y, mapY);
			if (in_map == false) {
				cout << "���� ������ϴ�. �ٽ� ���ư��ϴ�." << endl;
				user_y -= 1;
			}
			else {
				CheckState(map, user_x, user_y);
				my_user.DecreaseHP(1);
					cout << "���� HP:" << my_user.GetHP();
				cout << " ���� �� ĭ �������ϴ�." << endl;
				DisplayMap(map, user_x, user_y);
				// ü���� 0�ϰ�� ����
				if (not(CheckUser(my_user))) {
					cout << "HP�� 0 ���ϰ� �Ǿ����ϴ�. �����߽��ϴ�.";
					cout << "������ �����մϴ�.";
					break;
				}
			}
		}
		else if (user_input == "��") {
			// TODO: �������� �̵��ϱ�
			user_x -= 1;
			bool in_map = CheckXY(user_x, mapX, user_y, mapY);

			if (in_map == false) {
				cout << "���� ������ϴ�. �ٽ� ���ư��ϴ�." << endl;
				user_x += 1;
			}
			else {
				
				CheckState(map, user_x, user_y);
				my_user.DecreaseHP(1);
				cout << "���� HP:" << my_user.GetHP();
				cout << "�������� �̵��մϴ�." << endl;
				DisplayMap(map, user_x, user_y);
				// ü���� 0�ϰ�� ����
				if (not(CheckUser(my_user))) {
					cout << "HP�� 0 ���ϰ� �Ǿ����ϴ�. �����߽��ϴ�.";
					cout << "������ �����մϴ�.";
					break;
				}
			}
		}
		else if (user_input == "��") {
			// TODO: ���������� �̵��ϱ�
			user_x += 1;
			bool in_map = CheckXY(user_x, mapX, user_y, mapY);
			if (in_map == false) {
				cout << "���� ������ϴ�. �ٽ� ���ư��ϴ�." << endl;
				user_x -= 1;
			}
			else {
				// ���� ���� ���� �����Ƿ� ���� moveminus�Լ��� -1�� ������
				CheckState(map, user_x, user_y);
				my_user.DecreaseHP(1);
				cout << "���� HP:" << my_user.GetHP();
				cout << "���������� �̵��մϴ�." << endl;
				DisplayMap(map, user_x, user_y);
				// ü���� 0�ϰ�� ����
				if (not(CheckUser(my_user))) {
					cout << "HP�� 0 ���ϰ� �Ǿ����ϴ�. �����߽��ϴ�.";
					cout << "������ �����մϴ�.";
					break;
				}
			}
		}
		else if (user_input == "����") {
			// TODO: ���� �����ֱ� �Լ� ȣ��
			DisplayMap(map, user_x, user_y);
		}
		else if (user_input == "����") {
			cout << "�����մϴ�.";
			break;
		}
		else {
			cout << "�߸��� �Է��Դϴ�." << endl;
			continue;
		}

		// �������� �����ߴ��� üũ
		bool finish = CheckGoal(map, user_x, user_y);
		if (finish == true) {
			cout << "�������� �����߽��ϴ�! �����մϴ�!" << endl;
			cout << "������ �����մϴ�." << endl;
			break;
		}
	}
	return 0;
}

// ������ ����� ��ġ ����ϴ� �Լ�\
//�迭�� ũ�⸦ �����Ҷ� ���κи� ��� �ν�����! ������ �Ѵ� �����������!
void DisplayMap(int map[][mapX], int user_x, int user_y) {
	// ��κ��� Y��ǥ�� �����ϴ� ������ �⺻������  Y��ǥ�� ��κ�����
	// �ν��ϱ⶧���̴�!
	for (int i = 0; i < mapY; i++) {
		for (int j = 0; j < mapX; j++) {
			if (i == user_y && j == user_x) {
				cout << " USER |";  // �� �� 1ĭ ����
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
void CheckState(int map[][mapX], int user_x, int user_y) {
	switch (map[user_y][user_x]) {
	case 1:
		cout << "�������� �ֽ��ϴ�" << endl;
		break;
	case 2:
		cout << "���� �ֽ��ϴ�. HP�� 2 �پ��ϴ�." << endl;
		my_user.DecreaseHP(2);
		break;
	case 3:
		cout << "������ �ֽ��ϴ�. HP�� 2 �þ�ϴ�." << endl;

		my_user.IncreaseHP(2);
		break;
	}
}
//hpüũ �Լ�
bool CheckUser(User user) {
	if (user.GetHP() < 1) {
		return false;
	}
	else
		return true;
}