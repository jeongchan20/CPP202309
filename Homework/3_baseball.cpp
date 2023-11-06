#include <iostream>
#include <string>
using namespace std;

int main() {

    int randomNum; // ����� �ϴ� 3�ڸ����� ���� ���� ����
    string firstNum; // ������ ù��° �ڸ���
    string secondNum; // ������ �ι�° �ڸ���
    string thirdNum; // ������ ����° �ڸ���

    // ��ǻ�Ͱ� ������ 3�ڸ� ���� ���� ����
    while (1) {
        randomNum = rand() % 900 + 100; // ������ 3�ڸ��� ����
        string NewRand = to_string(randomNum);

        // 3�ڸ� ������ �ڸ��� ����
        firstNum = NewRand[0];
        secondNum = NewRand[1];
        thirdNum = NewRand[2];

        // ��� ���� �ٸ��� Ȯ��
        if (firstNum != secondNum && secondNum != thirdNum && firstNum != thirdNum) {
            break;
        }
    }

    int turn = 0;
    while (1) {
        cout << turn + 1 << "��° �õ��Դϴ�." << endl;

        int userNumber; // ����ڰ� �Է��� ���ڸ��� ���� ����
        string guessFirst; // ������ ������ ù��° �ڸ���
        string guessSecond; // ������ ������ �ι�° �ڸ���
        string guessThird; // ������ ������ ����° �ڸ���

        // ����ڿ��� ���ڸ� ���� �Է¹���
        while (1) {
            cout << "���ڸ� ���� �Է����ּ���: ";
            cin >> userNumber;
            string Newuser = to_string(userNumber);

            // �������� �ڸ��� ����
            guessFirst = Newuser[0];
            guessSecond = Newuser[1];
            guessThird = Newuser[2];

            if (guessFirst == guessSecond || guessSecond == guessThird || guessThird == guessFirst) {
                cout << "�Է��� ���ڿ� �ߺ��� ���ڰ� �ֽ��ϴ�." << endl;
            }
            else if (Newuser.length() != 3) {
                cout << "�Էµ� ���ڰ� 3�ڸ� ���� �ƴմϴ�. �ٽ� �Է��ϼ���." << endl;
            }
            else {
                break;
            }
        }

        int strike = 0; // ��Ʈ����ũ ������ �����ϴ� ����
        int ball = 0; // �� ������ �����ϴ� ����

        // ����� ������ ������ �ڸ����� ���ڸ� ���Ͽ� ��Ʈ����ũ�� �� ���
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

        cout << userNumber << "�� ��� : " << strike << " ��Ʈ����ũ, " << ball << " �� �Դϴ�." << endl;

        if (strike == 3) {
            cout << "������ ������ϴ�. �����մϴ�." << endl;
            break;
        }

        turn += 1;
    }

    return 0;
}
