#include <iostream>
#include <string>
using namespace std;

int main() {
	int randomNum; // ����� �ϴ� 3�ڸ����� ���� ���� ����
	string firstNum; // ������ ù��° �ڸ���
	string secondNum; // ������ �ι�° �ڸ���
	string thirdNum; // ������ ����° �ڸ���


	while (1) {
		randomNum = rand() % 900 + 100; // ������ 3�ڸ��� ����
		string NewRand;

		NewRand = to_string(randomNum);



		bool same = false; // ��� ���� �ٸ� ��� true�� ���� ����

		// TODO 1: 3�ڸ� ������ �ڸ����� �����ϰ�, ��� ���� �ٸ��� üũ�ϴ� �ڵ��� �ۼ�
		//�����Ϸ��� ����ߴµ� randdomNum�� string�� ��ȯ�ϸ� ������ ������ ��
		firstNum = NewRand[0];
		secondNum = NewRand[1];
		thirdNum = NewRand[2];










		if (same == true) {
			break;
		}


		int turn = 0;
		while (1) {
			cout << turn + 1 << "��° �õ��Դϴ�. " << endl;

			int userNumber; // ����ڰ� �Է��� ���ڸ��� ���� ����
			string guessFirst; // ������ ������ ù��° �ڸ���
			string guessSecond; // ������ ������ �ι�° �ڸ���
			string guessThird; // ������ ������ ����° �ڸ���


			// ����ڿ��� ���ڸ� ���� �Է¹޴� �ڵ� ���
			while (1) {
				cout << "���ڸ� ���� �Է����ּ���: ";
				cin >> userNumber;

				bool same = false; // ��� ���� �ٸ� ��� true�� ���� ����
				// TODO 1: 3�ڸ� ������ �ڸ����� �����ϰ�, ��� ���� �ٸ��� üũ�ϴ� �ڵ��� �ۼ�


			//�������� string���� ��ȯ�� ������ �ڸ��� ����
				string Newuser = to_string(userNumber);
				guessFirst = Newuser[0];
				guessSecond = Newuser[1];
				guessThird = Newuser[2];

				if (guessFirst == guessSecond || guessSecond == guessThird || guessThird == guessFirst) {
					cout << "�Է��� ���ڿ� �ߺ��� ���ڰ� �ֽ��ϴ�" << endl;
					continue;
				}



				if (to_string(userNumber).length() != 3) {
					cout << "�Էµ� ���ڰ� 3�ڸ� ���� �ƴմϴ�. �ٽ� �Է��ϼ���." << endl;
					continue;
				}

				if (same == true) {
					break;
				}
			}


			int strike = 0; // ��Ʈ����ũ ������ �����ϴ� ����
			int ball = 0; // �� ������ �����ϴ� ����

			// TODO 2: ����� ������ ������ �ڸ����� ���ڸ� ���ϸ� ��Ʈ�� �ֱ� ���� �ڵ��� �ۼ�
			if (firstNum == guessFirst)
				strike++;
			if (secondNum == guessSecond)
				strike++;



			cout << userNumber << "�� ��� : " << strike << " ��Ʈ����ũ, " << ball << "�� �Դϴ�." << endl;

			if (strike == 3) {

				cout << "������ ������ϴ�. �����մϴ�.";
				break;
			}

			turn += 1;

		}
	}
	return 0;
}