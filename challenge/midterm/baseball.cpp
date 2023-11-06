#include <iostream>
#include <string>
using namespace std;

int main() {

    int randomNum; // 맞춰야 하는 3자리수의 숫자 저장 변수
    string firstNum; // 정답의 첫번째 자리수
    string secondNum; // 정답의 두번째 자리수
    string thirdNum; // 정답의 세번째 자리수

    // 컴퓨터가 생성한 3자리 랜덤 숫자 생성
    while (1) {
        randomNum = rand() % 900 + 100; // 랜덤한 3자리수 생성
        string NewRand = to_string(randomNum);

        // 3자리 숫자의 자릿수 추출
        firstNum = NewRand[0];
        secondNum = NewRand[1];
        thirdNum = NewRand[2];

        // 모든 수가 다른지 확인
        if (firstNum != secondNum && secondNum != thirdNum && firstNum != thirdNum) {
            break;
        }
    }

    int turn = 0;
    while (1) {
        cout << turn + 1 << "번째 시도입니다." << endl;

        int userNumber; // 사용자가 입력한 세자리수 저장 변수
        string guessFirst; // 추측한 숫자의 첫번째 자리수
        string guessSecond; // 추측한 숫자의 두번째 자리수
        string guessThird; // 추측한 숫자의 세번째 자리수

        // 사용자에게 세자리 수를 입력받음
        while (1) {
            cout << "세자리 수를 입력해주세요: ";
            cin >> userNumber;
            string Newuser = to_string(userNumber);

            // 유저수의 자릿수 추출
            guessFirst = Newuser[0];
            guessSecond = Newuser[1];
            guessThird = Newuser[2];

            if (guessFirst == guessSecond || guessSecond == guessThird || guessThird == guessFirst) {
                cout << "입력한 숫자에 중복된 숫자가 있습니다." << endl;
            }
            else if (Newuser.length() != 3) {
                cout << "입력된 숫자가 3자리 수가 아닙니다. 다시 입력하세요." << endl;
            }
            else {
                break;
            }
        }

        int strike = 0; // 스트라이크 갯수를 저장하는 변수
        int ball = 0; // 볼 갯수를 저장하는 변수

        // 정답과 추측한 숫자의 자릿수와 숫자를 비교하여 스트라이크와 볼 계산
        if (firstNum == guessFirst)
            strike++;
        if (secondNum == guessSecond)
            strike++;
        if (thirdNum == guessThird)
            strike++;

        if (firstNum == guessSecond || firstNum == guessThird)
            ball++;
        if (secondNum == guessFirst || secondNum == guessThird)
            ball++;
        if (thirdNum == guessFirst || thirdNum == guessSecond)
            ball++;

        cout << userNumber << "의 결과 : " << strike << " 스트라이크, " << ball << " 볼 입니다." << endl;

        if (strike == 3) {
            cout << "정답을 맞췄습니다. 축하합니다." << endl;
            break;
        }

        turn += 1;
    }

    return 0;
}
