#include<iostream>
#include<string>
using namespace std;

int main()
{
	const int numCell = 3;
	//board 배열을 초기화 
	char board[numCell][numCell]{};
	int x, y;

	//문자열 이므로 보드판을 ' '로 초기화 시킴!
	for (x = 0; x < numCell; x++) {
		for (y = 0; y < numCell; y++) {
			board[x][y] = ' ';
		}
	}

	// 짝수 홀수로 누구 차례인지 판단함
	int k = 0;
	char currentUser = 'X';
	while (true)
	{
		switch (k % 2)
		{
		case 0:
			cout << k % 2 + 1 << "번 유저(X)의 차례입니다 -> ";
			currentUser = 'X';
			break;
		case 1:
			cout << k % 2 + 1 << "번 유저(O)의 차례입니다 -> ";
			currentUser = 'O';
			break;
		}

		//좌표 입력을 받음 
		cout << "(x,y)좌표를 입력하세요: ";
		cin >> x >> y;


		//입력받은 좌표가 이미 돌이 차있는곳이거나 범위를 벗어날 경우 오류메세지 표시 
		if (x >= numCell || y >= numCell)
		{
			cout << x << ", " << y << ": ";
			cout << "x와 y중 하나가 칸을 벗어납니다." << endl;
			continue;
		}

		if (board[x][y] != ' ')
		{
			cout << x << ", " << y << ": 이미 돌이 차있습니다" << endl;
			continue;
		}
		//입력받은 좌표에 유저 돌 놓기 
		board[x][y] = currentUser;

		//게임판 표시시킴
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

		//보드판에 빈칸이 없는지 확인
		int checked = 0;
		for (int i = 0; i < numCell; i++)
		{
			for (int j = 0; j < numCell; j++) {
				if (board[i][j] == ' ') {
					checked++;
				}
			}
		}
		//checked가 0이라면 빈칸이 없다는 의미이므로 프로그램 종료 
		if (checked == 0)
		{
			cout << "모든 칸이 다 찼습니다. 종료합니다" << endl;
			break;
		}


		bool isWin = false;

		//가로로 이기는 경우 
		for (int i = 0; i < numCell; i++) {
			if (board[i][0] == currentUser && board[i][1] == currentUser && board[i][2] == currentUser)
			{
				cout << "가로에 모두 돌이 놓였습니다!: ";
				isWin = true;
			}
			//세로 이기는 경우 
			if (board[0][i] == currentUser && board[1][i] == currentUser && board[2][i] == currentUser)
			{
				cout << "세로에 모두 돌이 놓였습니다!: ";
				isWin = true;
			}
		}
		//대각선이 꽉차서 이기는 경우 
		if (board[0][0] == currentUser && board[1][1] == currentUser && board[2][2] == currentUser) {
			cout << "왼쪽 위에서 오른쪽 아래 대각선으로 모두 돌이 놓였습니다! :";
			isWin = true;
		}

		if (board[0][2] == currentUser && board[1][1] == currentUser && board[2][0] == currentUser) {
			cout << "오른쪽 위에서 왼쪽 아래 대각선으로 모두 돌이 놓였습니다! :";
			isWin = true;
		}
		// isWin는 기본적으로 false이지만 각 게임 조건에 맞으면 true되므로 if문을 만족시켜서 종료시킴
		if (isWin == true) {
			cout << k % 2 + 1 << "번 유저(" << currentUser << ")의 승리입니다!" << endl;
			cout << "종료합니다" << endl;
			break;
		}


	}
	return 0;
}