#include <iostream>
using namespace std;

const int numCell = 4; // 보드판의 가로 세로 길이
int k = 0; // 누구 차례인지 체크하기 위한 변수
char current_user = 'X'; // 현재 유저의 돌을 저장하기 위한 변수
char board[numCell][numCell]{}; // 보드판을 나타내는 2차원 배열
int x, y = 0; // 사용자에게 xy좌표값을 입력받기 위한 변수

bool isValid(int x, int y);
bool checkWin(char c);
int main() {
	// 게임을 진행하는 데 필요한 변수 선언


	// 보드판 초기화
	for (int i = 0; i < numCell; i++) {
		for (int j = 0; j < numCell; j++) {
			board[i][j] = ' ';
		}
	}

	// 게임을 무한 반복
	while (true) {
		// 1. 누구 차례인지 출력
		// TODO 1.1: 3인용 게임으로 변경
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
		cout << k % 3 + 1 << "번 유저(" << current_user << ")의 차례입니다. -> ";

		// 2. 좌표 입력 받기
		cout << "(x, y) 좌표를 입력하세요: ";
		int x, y;
		cin >> x >> y;

		// 3. 입력받은 좌표의 유효성 체크
		// TODO FUNC 1: isValid 함수 생성 후 호출
		if (isValid(x, y)) {
			continue;
		}




		// 4. 입력받은 좌표에 현재 유저의 돌 놓기
		board[x][y] = current_user;

		// 5. 현재 보드 판 출력
		// TODO 1.2: numCell 숫자에 맞춘 보드판 출력
		// TODO 1.2: numCell 숫자에 맞춘 보드판 출력
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




		bool isWin = false; // 승리 여부
		// TODO FUNC2: 6.1부터 6.2까지 checkWin 함수 생성 후 호출
		// 6.1. 가로/세로 돌 체크하기
		if (checkWin(current_user)) {
			break;
		}



		// 6.2. 대각선을 체크하기
		// TODO 1.3: numCell에 맞춘 대각선 빙고 체크 코드로 확장
		// HINT: for 문


		// 승리자가 결정되었으면 해당 플레이어를 출력하고 게임을 종료한다.
		if (isWin == true) {
			cout << k % 2 + 1 << "번 유저(" << current_user << ")의 승리입니다!" << endl;
			break;
		}

		// 7. 모든 칸 다 찼는지 체크하기
		int checked = 0;
		for (int i = 0; i < numCell; i++) {
			for (int j = 0; j < numCell; j++) {
				if (board[i][j] == ' ') {
					checked++;
				}
			}
		}
		if (checked == 0) {
			cout << "모든 칸이 다 찼습니다.  종료합니다. " << endl;
			break;
		}

		k++;
	}

	return 0;
}

bool isValid(int a, int b) {
	//함수의 유효성 체크를 위해 만들었는데.. 유효성 체크가 안되고 "이미 돌이 차있다는 메세지만 자꾸 나옴".. 전역변수 선언이 안되어있었음

	if (a >= numCell || b >= numCell) {// 좌표 범위를 벗어날때
		cout << a << "," << b << ": x와 y둘중 하나가 칸을 벗어납니다. " << endl;
		return true;
	}
	if (board[a][b] != ' ') {// 좌표범위의 입력값이 중복될때
		cout << a << "," << b << ": 이미 돌이 차있습니다. " << endl;
		return true;
	}
	return false;
}

bool checkWin(char c) {
	// 왼쪽 위에서 오른쪽 아래 대각선 체크
	for (int i = 0; i < numCell - 1; i++) {
		if (board[i][i] != c || board[i][i] != board[i + 1][i + 1]) {
			break; // 대각선에 돌이 하나라도 다르면 종료
		}

		if (i == numCell - 2) {
			cout << "왼쪽 위에서 오른쪽 아래 대각선으로 모두 돌이 놓였습니다!" << endl;
			return true; // 대각선이 모두 같으면 승리 메시지 출력 후 true 반환
		}
	}

	// 오른쪽 위에서 왼쪽 아래 대각선 체크
	for (int i = 0; i < numCell - 1; i++) {
		if (board[i][numCell - i - 1] != c || board[i][numCell - i - 1] != board[i + 1][numCell - i - 2]) {
			break; // 대각선에 돌이 하나라도 다르면 종료
		}

		if (i == numCell - 2) {
			cout << "오른쪽 위에서 왼쪽 아래 대각선으로 모두 돌이 놓였습니다!" << endl;
			return true; // 대각선이 모두 같으면 승리 메시지 출력 후 true 반환
		}
	}

	// 세로에 모두 돌이 놓였는지 체크
	for (int i = 0; i < numCell; i++) {
		bool vertical_win = true;
		for (int j = 0; j < numCell - 1; j++) {
			if (board[j][i] != c || board[j][i] != board[j + 1][i]) {
				vertical_win = false;
				break;
			}
		}
		if (vertical_win) {
			cout << "세로에 모두 돌이 놓였습니다!!" << endl;
			return true;
		}
	}

	// 가로에 모두 돌이 놓였는지 체크
	for (int i = 0; i < numCell; i++) {
		bool horizontal_win = true;
		for (int j = 0; j < numCell - 1; j++) {
			if (board[i][j] != c || board[i][j] != board[i][j + 1]) {
				horizontal_win = false;
				break;
			}
		}
		if (horizontal_win) {
			cout << "가로에 모두 돌이 놓였습니다!!" << endl;
			return true;
		}
	}

	// 위의 모든 조건이 만족하지 않으면 false 반환
	return false;
}
