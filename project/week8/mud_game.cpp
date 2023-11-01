#include <iostream>
#include <string>
using namespace std;

const int mapX = 5;
const int mapY = 5;
int hp = 20;

// ����� ���� �Լ�
bool checkXY(int user_x, int mapX, int user_y, int mapY);
void displayMap(int map[][mapX], int user_x, int user_y);
bool checkGoal(int map[][mapX], int user_x, int user_y);
int MoveMinus(int&x);
void checkState(int map[][mapX], int user_x, int user_y);

// ����  �Լ�
int main() {
	// 0�� �� ����, 1�� ������, 2�� ��, 3�� ����, 4�� ������
	int map[mapY][mapX] = { {0, 1, 2, 0, 4},
					{1, 0, 0, 2, 0},
					{0, 0, 0, 0, 0},
					{0, 2, 3, 0, 0},
					{3, 0, 0, 0, 2} };


	// ������ ��ġ�� ������ ����
	int user_x = 0; // ���� ��ȣ
	int user_y = 0; // ���� ��ȣ
	

	// ���� ���� 
	while (1) { // ����ڿ��� ��� �Է¹ޱ� ���� ���� ����

		// ������� �Է��� ������ ����
		string user_input = "";
		int k = 0;

		cout << "���� HP:"<<hp<<"  ��ɾ �Է��ϼ��� (��,��,��,��,����,����): ";
		cin >> user_input;

		if (user_input == "��") {
			// ���� �� ĭ �ö󰡱�
			user_y -= 1;
			bool inMap = checkXY(user_x, mapX, user_y, mapY);
			if (inMap == false) {
				cout << "���� ������ϴ�. �ٽ� ���ư��ϴ�." << endl;
				user_y += 1;
			}
			else {
			// ���� ���� ���� �����Ƿ� ���� moveminus�Լ��� -1�� ������ 
				checkState(map, user_x, user_y);
				cout << "���� HP:"<<MoveMinus(hp);
				cout << " ���� �� ĭ �ö󰩴ϴ�." << endl;
				displayMap(map, user_x, user_y);
				//ü���� 0�ϰ�� ���� 
				if (hp <= 0)
				{
					cout << "HP�� 0 ���ϰ� �Ǿ����ϴ�. �����߽��ϴ�.";
					cout << "������ �����մϴ�.";
					break;
				}
			
			}
			
			
		}
		else if (user_input == "��") {
			// TODO: �Ʒ��� �� ĭ ��������
			user_y += 1;
			bool inMap = checkXY(user_x, mapX, user_y, mapY);
			if (inMap == false) {
				cout << "���� ������ϴ�. �ٽ� ���ư��ϴ�." << endl;
				user_y -= 1;
			}
			else {
				checkState(map, user_x, user_y);
				cout << "���� HP:" << MoveMinus(hp);
				cout << " ���� �� ĭ �������ϴ�." << endl;
				displayMap(map, user_x, user_y);
				//ü���� 0�ϰ�� ���� 
				if (hp <= 0)
				{
					cout << "HP�� 0 ���ϰ� �Ǿ����ϴ�. �����߽��ϴ�.";
					cout << "������ �����մϴ�.";
					break;
				}
			}
		}
		else if (user_input == "��") {
			// TODO: �������� �̵��ϱ�
			user_x -= 1;
			bool inMap = checkXY(user_x, mapX, user_y, mapY);

			if (inMap == false) {
				cout << "���� ������ϴ�. �ٽ� ���ư��ϴ�." << endl;
				user_x += 1;
			}
			else {
				//// ���� ���� ���� �����Ƿ� ���� moveminus�Լ��� -1�� ������ 
				checkState(map, user_x, user_y);
				cout << "���� HP:" << MoveMinus(hp);
				cout << "�������� �̵��մϴ�." << endl;
				displayMap(map, user_x, user_y);
				//ü���� 0�ϰ�� ���� 
				if (hp <= 0)
				{
					cout << "HP�� 0 ���ϰ� �Ǿ����ϴ�. �����߽��ϴ�.";
					cout << "������ �����մϴ�.";
					break;
				}
			}
		}
		else if (user_input == "��") {
			// TODO: ���������� �̵��ϱ�
			user_x += 1;
			bool inMap = checkXY(user_x, mapX, user_y, mapY);
			if (inMap == false) {
				cout << "���� ������ϴ�. �ٽ� ���ư��ϴ�." << endl;
				user_x -= 1;
			}
			else {
				// ���� ���� ���� �����Ƿ� ���� moveminus�Լ��� -1�� ������ 
				checkState(map, user_x, user_y);
				cout << "���� HP:" << MoveMinus(hp);
				cout << "���������� �̵��մϴ�." << endl;
				displayMap(map, user_x, user_y);
				//ü���� 0�ϰ�� ���� 
				if (hp <= 0)
				{
					cout << "HP�� 0 ���ϰ� �Ǿ����ϴ�. �����߽��ϴ�.";
					cout << "������ �����մϴ�.";
					break;
				}
			}
		}
		else if (user_input == "����") {
			// TODO: ���� �����ֱ� �Լ� ȣ��
			displayMap(map, user_x, user_y);
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
		bool finish = checkGoal(map, user_x, user_y);
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
void displayMap(int map[][mapX], int user_x, int user_y) {
	//��κ��� Y��ǥ�� �����ϴ� ������ �⺻������  Y��ǥ�� ��κ����� �ν��ϱ⶧���̴�!
	for (int i = 0; i < mapY; i++) {
		for (int j = 0; j < mapX; j++) {
			if (i == user_y && j == user_x) {
				cout << " USER |"; // �� �� 1ĭ ����
			}
			else {
				int posState = map[i][j];
				switch (posState) {
				case 0:
					cout << "      |"; // 6ĭ ����
					break;
				case 1:
					cout << "������|";
					break;
				case 2:
					cout << "  ��  |"; // �� �� 2ĭ ����
					break;
				case 3:
					cout << " ���� |"; // �� �� 1ĭ ����
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
bool checkXY(int user_x, int mapX, int user_y, int mapY) {
	bool checkFlag = false;
	if (user_x >= 0 && user_x < mapX && user_y >= 0 && user_y < mapY) {
		checkFlag = true;
	}
	return checkFlag;
}

// ������ ��ġ�� ���������� üũ�ϴ� �Լ�
bool checkGoal(int map[][mapX], int user_x, int user_y) {
	// ������ �����ϸ�
	if (map[user_y][user_x] == 4) {
		return true;
	}
	return false;
}

//���� �̵��ø���  hp ���ҽ�Ű�� �Լ� 
int MoveMinus(int&x) {
	if (true)
		x-= 1;
	return x;
}

//������ � ���������� ���� ��ȯ���� ���ϴ� �Լ� 
void checkState(int map[][mapX], int user_x, int user_y) {

	switch (map[user_y][user_x]) {
	case 1:
		cout << "�������� �ֽ��ϴ�" << endl;
		break;
	case 2:
		cout << "���� �ֽ��ϴ�. HP�� 2 �پ��ϴ�." << endl;
		hp -= 2;
		break;
	case 3:
		cout << "������ �ֽ��ϴ�. HP�� 2 �þ�ϴ�." << endl;

		hp += 2;
		break;
	}
}


