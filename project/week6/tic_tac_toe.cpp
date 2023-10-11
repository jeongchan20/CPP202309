#include<iostream>
#include<string>
using namespace std;

int main()
{
	const int numCell = 3;
	//board �迭�� �ʱ�ȭ 
	char board[numCell][numCell]{};
	int x, y;

	//���ڿ� �̹Ƿ� �������� ' '�� �ʱ�ȭ ��Ŵ!
	for (x = 0; x < numCell; x++) {
		for (y = 0; y < numCell; y++) {
			board[x][y] = ' ';
		}
	}

	// ¦�� Ȧ���� ���� �������� �Ǵ���
	int k = 0;
	char currentUser = 'X';
	while (true)
	{
		switch (k % 2)
		{
		case 0:
			cout << k % 2 + 1 << "�� ����(X)�� �����Դϴ� -> ";
			currentUser = 'X';
			break;
		case 1:
			cout << k % 2 + 1 << "�� ����(O)�� �����Դϴ� -> ";
			currentUser = 'O';
			break;
		}

		//��ǥ �Է��� ���� 
		cout << "(x,y)��ǥ�� �Է��ϼ���: ";
		cin >> x >> y;


		//�Է¹��� ��ǥ�� �̹� ���� ���ִ°��̰ų� ������ ��� ��� �����޼��� ǥ�� 
		if (x >= numCell || y >= numCell)
		{
			cout << x << ", " << y << ": ";
			cout << "x�� y�� �ϳ��� ĭ�� ����ϴ�." << endl;
			continue;
		}

		if (board[x][y] != ' ')
		{
			cout << x << ", " << y << ": �̹� ���� ���ֽ��ϴ�" << endl;
			continue;
		}
		//�Է¹��� ��ǥ�� ���� �� ���� 
		board[x][y] = currentUser;

		//������ ǥ�ý�Ŵ
		for (int i = 0; i < numCell; i++)
		{
			cout << "---l---l---" << endl;
			for (int j = 0; j < numCell; j++)
			{
				cout << board[i][j];
				if (j == numCell - 1) {
					break;
				}
				cout << "  l";
			}
			cout << endl;
		}
		cout << "---l---l---" << endl;
		k++;

		//�����ǿ� ��ĭ�� ������ Ȯ��
		int checked = 0;
		for (int i = 0; i < numCell; i++)
		{
			for (int j = 0; j < numCell; j++) {
				if (board[i][j] == ' ') {
					checked++;
				}
			}
		}
		//checked�� 0�̶�� ��ĭ�� ���ٴ� �ǹ��̹Ƿ� ���α׷� ���� 
		if (checked == 0)
		{
			cout << "��� ĭ�� �� á���ϴ�. �����մϴ�" << endl;
			break;
		}


		bool isWin = false;

		//���η� �̱�� ��� 
		for (int i = 0; i < numCell; i++) {
			if (board[i][0] == currentUser && board[i][1] == currentUser && board[i][2] == currentUser)
			{
				cout << "���ο� ��� ���� �������ϴ�!: ";
				isWin = true;
			}
			//���� �̱�� ��� 
			if (board[0][i] == currentUser && board[1][i] == currentUser && board[2][i] == currentUser)
			{
				cout << "���ο� ��� ���� �������ϴ�!: ";
				isWin = true;
			}
		}
		//�밢���� ������ �̱�� ��� 
		if (board[0][0] == currentUser && board[1][1] == currentUser && board[2][2] == currentUser) {
			cout << "���� ������ ������ �Ʒ� �밢������ ��� ���� �������ϴ�! :";
			isWin = true;
		}

		if (board[0][2] == currentUser && board[1][1] == currentUser && board[2][0] == currentUser) {
			cout << "������ ������ ���� �Ʒ� �밢������ ��� ���� �������ϴ�! :";
			isWin = true;
		}
		// isWin�� �⺻������ false������ �� ���� ���ǿ� ������ true�ǹǷ� if���� �������Ѽ� �����Ŵ
		if (isWin == true) {
			cout << k % 2 + 1 << "�� ����(" << currentUser << ")�� �¸��Դϴ�!" << endl;
			cout << "�����մϴ�" << endl;
			break;
		}


	}
	return 0;
}