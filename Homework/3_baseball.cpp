#include <iostream>
#include <string>
using namespace std;

int main() {
	int randomNum; // 맞춰야 하는 3자리수의 숫자 저장 변수
	string firstNum; // 정답의 첫번째 자리수
	string secondNum; // 정답의 두번째 자리수
	string thirdNum; // 정답의 세번째 자리수


	while (1) {
		randomNum = rand() % 900 + 100; // 랜덤한 3자리수 생성
		string NewRand;

		NewRand = to_string(randomNum);



		bool same = false; // 모든 수가 다를 경우 true를 갖는 변수

		// TODO 1: 3자리 숫자의 자릿수를 추출하고, 모든 수가 다른지 체크하는 코드블록 작성
		//추출하려고 노력했는데 randdomNum을 string로 변환하면 컴파일 오류가 남
		firstNum = NewRand[0];
		secondNum = NewRand[1];
		thirdNum = NewRand[2];










		if (same == true) {
			break;
		}


		int turn = 0;
		while (1) {
			cout << turn + 1 << "번째 시도입니다. " << endl;

			int userNumber; // 사용자가 입력한 세자리수 저장 변수
			string guessFirst; // 추측한 숫자의 첫번째 자리수
			string guessSecond; // 추측한 숫자의 두번째 자리수
			string guessThird; // 추측한 숫자의 세번째 자리수


			// 사용자에게 세자리 수를 입력받는 코드 블록
			while (1) {
				cout << "세자리 수를 입력해주세요: ";
				cin >> userNumber;

				bool same = false; // 모든 수가 다를 경우 true를 갖는 변수
				// TODO 1: 3자리 숫자의 자릿수를 추출하고, 모든 수가 다른지 체크하는 코드블록 작성


			//유저수를 string으로 변환후 각각의 자릿수 추출
				string Newuser = to_string(userNumber);
				guessFirst = Newuser[0];
				guessSecond = Newuser[1];
				guessThird = Newuser[2];

				if (guessFirst == guessSecond || guessSecond == guessThird || guessThird == guessFirst) {
					cout << "입력한 숫자에 중복된 숫자가 있습니다" << endl;
					continue;
				}



				if (to_string(userNumber).length() != 3) {
					cout << "입력된 숫자가 3자리 수가 아닙니다. 다시 입력하세요." << endl;
					continue;
				}

				if (same == true) {
					break;
				}
			}


			int strike = 0; // 스트라이크 갯수를 저장하는 변수
			int ball = 0; // 볼 갯수를 저장하는 변수

			// TODO 2: 정답과 추측한 숫자의 자릿수와 숫자를 비교하며 힌트를 주기 위한 코드블록 작성
			if (firstNum == guessFirst)
				strike++;
			if (secondNum == guessSecond)
				strike++;



			cout << userNumber << "의 결과 : " << strike << " 스트라이크, " << ball << "볼 입니다." << endl;

			if (strike == 3) {

				cout << "정답을 맞췄습니다. 축하합니다.";
				break;
			}

			turn += 1;

		}
	}
	return 0;
}