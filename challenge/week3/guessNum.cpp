#include<iostream>
#include<time.h>
using namespace std;

int main() {

	srand(time(NULL)); //random �Լ� ���� ����

	int answer = rand() % 100; //����

	int tries = 0; //�õ� Ƚ�� �����ϴ� ����

	int guess; //����� �Է� �����ϱ� ���� ����

	do {	//�ϴ� ������ ��
		cout << "������ �����Ͽ� ���ÿ�";

		cin >> guess; //������ �Է¹���
		tries++;

		if (answer > guess) //������ �� ũ�ٸ�  �������� ���ٰ� ǥ������
			cout << "������ ������ �����ϴ�." << endl;
		if (answer <guess)	//������ �� ���ٸ�  �������� ���ٰ� ǥ������
			cout << "������ ������ �����ϴ�." << endl;

	} while (answer!= guess); //����� �������� �ٸ��� �ʴ°� �����̸� Ż�� �� �´ٸ� Ż��

	cout << "�����մϴ�. �õ� Ƚ�� " << tries << endl;

	return 0;
}

			