#include<iostream>
#include<time.h>
using namespace std;

int main() {

	int i;
	int ans; //���� �Է�!
	int corretct = 0; //���� ���� üũ 

	cout << "��� ������ �ڵ����� �����մϴ� ." << endl;

	while (corretct < 5) {
		int firstNum = rand() % 100; //0~99������ ���� ��
		int secondNum = rand() % 100; //0~99������ ���� ��

			cout << firstNum << "+" << secondNum << "="; //ȭ�鿡 ���� ���
			cin >> ans; //����ڷκ��� �Է� ���� ����
	

			if (ans == firstNum + secondNum) //������� ���� ���� ��ġ�ϸ� �¾ҽ��ϴٸ� ����� correctct�� 1����
			{
				cout << "�¾ҽ��ϴ� ." << endl;
				corretct++;
			}
			else
			{

				cout << "Ʋ�ǽ��ϴ�" << endl;//������� ���� ���� ��ġ�ϸ� �¾ҽ��ϴٸ� ����� correctct�� 1����
				
			}

		}
			
	}