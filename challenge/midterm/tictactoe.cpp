#include <iostream>
using namespace std;

const int numCell = 4; // �������� ���� ���� ����
int k = 0; // ���� �������� üũ�ϱ� ���� ����
char current_user = 'X'; // ���� ������ ���� �����ϱ� ���� ����
char board[numCell][numCell]{}; // �������� ��Ÿ���� 2���� �迭
int x, y = 0; // ����ڿ��� xy��ǥ���� �Է¹ޱ� ���� ����

bool isValid(int x, int y);
bool checkWin(char c);
int main() {
	// ������ �����ϴ� �� �ʿ��� ���� ����


	// ������ �ʱ�ȭ
	for (int i = 0; i < numCell; i++) {
		for (int j = 0; j < numCell; j++) {
			board[i][j] = ' ';
		}
	}

	// ������ ���� �ݺ�
	while (true) {
		// 1. ���� �������� ���
		// TODO 1.1: 3�ο� �������� ����
		switch (k % 3) {
		case 0:
			current_user = 'X';
			break;
		case 1:
			current_user = 'O';
			break;
		case 2:
			current_user = 'H';
			break;


		}
		cout << k % 3 + 1 << "�� ����(" << current_user << ")�� �����Դϴ�. -> ";

		// 2. ��ǥ �Է� �ޱ�
		cout << "(x, y) ��ǥ�� �Է��ϼ���: ";
		int x, y;
		cin >> x >> y;

		// 3. �Է¹��� ��ǥ�� ��ȿ�� üũ
		// TODO FUNC 1: isValid �Լ� ���� �� ȣ��
		if (isValid(x, y)) {
			continue;
		}




		// 4. �Է¹��� ��ǥ�� ���� ������ �� ����
		board[x][y] = current_user;

		// 5. ���� ���� �� ���
		// TODO 1.2: numCell ���ڿ� ���� ������ ���
		// TODO 1.2: numCell ���ڿ� ���� ������ ���
		for (int i = 0; i < numCell; i++) {
			for (int j = 0; j < numCell; j++) {
				cout << board[i][j];
				if (j < numCell) {
					cout << "  |";
				}
			}
			cout << endl;
			if (i < numCell) {
				for (int j = 0; j < numCell; j++) {
					cout << "---l";
				}
				cout << endl;
			}
		}




		bool isWin = false; // �¸� ����
		// TODO FUNC2: 6.1���� 6.2���� checkWin �Լ� ���� �� ȣ��
		// 6.1. ����/���� �� üũ�ϱ�
		if (checkWin(current_user)) {
			break;
		}



		// 6.2. �밢���� üũ�ϱ�
		// TODO 1.3: numCell�� ���� �밢�� ���� üũ �ڵ�� Ȯ��
		// HINT: for ��


		// �¸��ڰ� �����Ǿ����� �ش� �÷��̾ ����ϰ� ������ �����Ѵ�.
		if (isWin == true) {
			cout << k % 2 + 1 << "�� ����(" << current_user << ")�� �¸��Դϴ�!" << endl;
			break;
		}

		// 7. ��� ĭ �� á���� üũ�ϱ�
		int checked = 0;
		for (int i = 0; i < numCell; i++) {
			for (int j = 0; j < numCell; j++) {
				if (board[i][j] == ' ') {
					checked++;
				}
			}
		}
		if (checked == 0) {
			cout << "��� ĭ�� �� á���ϴ�.  �����մϴ�. " << endl;
			break;
		}

		k++;
	}

	return 0;
}

bool isValid(int a, int b) {
	//�Լ��� ��ȿ�� üũ�� ���� ������µ�.. ��ȿ�� üũ�� �ȵǰ� "�̹� ���� ���ִٴ� �޼����� �ڲ� ����".. �������� ������ �ȵǾ��־���

	if (a >= numCell || b >= numCell) {// ��ǥ ������ �����
		cout << a << "," << b << ": x�� y���� �ϳ��� ĭ�� ����ϴ�. " << endl;
		return true;
	}
	if (board[a][b] != ' ') {// ��ǥ������ �Է°��� �ߺ��ɶ�
		cout << a << "," << b << ": �̹� ���� ���ֽ��ϴ�. " << endl;
		return true;
	}
	return false;
}

bool checkWin(char c) {
	// ���� ������ ������ �Ʒ� �밢�� üũ
	for (int i = 0; i < numCell - 1; i++) {
		if (board[i][i] != c || board[i][i] != board[i + 1][i + 1]) {
			break; // �밢���� ���� �ϳ��� �ٸ��� ����
		}

		if (i == numCell - 2) {
			cout << "���� ������ ������ �Ʒ� �밢������ ��� ���� �������ϴ�!" << endl;
			return true; // �밢���� ��� ������ �¸� �޽��� ��� �� true ��ȯ
		}
	}

	// ������ ������ ���� �Ʒ� �밢�� üũ
	for (int i = 0; i < numCell - 1; i++) {
		if (board[i][numCell - i - 1] != c || board[i][numCell - i - 1] != board[i + 1][numCell - i - 2]) {
			break; // �밢���� ���� �ϳ��� �ٸ��� ����
		}

		if (i == numCell - 2) {
			cout << "������ ������ ���� �Ʒ� �밢������ ��� ���� �������ϴ�!" << endl;
			return true; // �밢���� ��� ������ �¸� �޽��� ��� �� true ��ȯ
		}
	}

	// ���ο� ��� ���� �������� üũ
	for (int i = 0; i < numCell; i++) {
		bool vertical_win = true;
		for (int j = 0; j < numCell - 1; j++) {
			if (board[j][i] != c || board[j][i] != board[j + 1][i]) {
				vertical_win = false;
				break;
			}
		}
		if (vertical_win) {
			cout << "���ο� ��� ���� �������ϴ�!!" << endl;
			return true;
		}
	}

	// ���ο� ��� ���� �������� üũ
	for (int i = 0; i < numCell; i++) {
		bool horizontal_win = true;
		for (int j = 0; j < numCell - 1; j++) {
			if (board[i][j] != c || board[i][j] != board[i][j + 1]) {
				horizontal_win = false;
				break;
			}
		}
		if (horizontal_win) {
			cout << "���ο� ��� ���� �������ϴ�!!" << endl;
			return true;
		}
	}

	// ���� ��� ������ �������� ������ false ��ȯ
	return false;
}
