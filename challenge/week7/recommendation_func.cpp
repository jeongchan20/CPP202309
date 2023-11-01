#include <iostream>
using namespace std;

//�Լ������� ����ϱ����ؼ� �������� ����
const int NUM_USERS = 3;
const int NUM_ITEMS = 3;
//main�Լ��ڿ� �Լ��� ���������Ƿ� �Լ����� �ۼ�
void initializePreferences();
void findRecommendedItems();
int userPreferences[NUM_USERS][NUM_ITEMS];


int main() {
	//�Լ�ȣ��
	initializePreferences();
	findRecommendedItems();
	return 0;
}

//����ڿ��� ��ȣ���� �Է¹���(����for���� ���ؼ�!)
void initializePreferences()
{
	for (int i = 0; i < NUM_USERS; ++i) {
		cout << "����� " << (i + 1) << "�� ��ȣ���� �Է��ϼ���(";
		cout << NUM_ITEMS << "���� �׸� ���� ):";
		for (int j = 0; j < NUM_ITEMS; j++) {
			cin >> userPreferences[i][j];
		}
	}
	return;
}

//����ڿ��� �Է¹��� ��ȣ���� �������� ��õ�ϴ� �׸��� �����(����for���� ���ο� ���� maxPreferenceIndex�� ���ؼ�!)
void findRecommendedItems()
{
	for (int i = 0; i < NUM_USERS; ++i) {
		int maxPreferenceIndex = 0;
		for (int j = 1; j < NUM_ITEMS; ++j) {
			//���� for���� ���鼭 �ִ��� üũ�ϰ� ������ �������ִ� �ִ񰪺��� ũ�� �� ������ �ִ밪 ��ü��!
			if (userPreferences[i][j] > userPreferences[i][maxPreferenceIndex]) {
				maxPreferenceIndex = j;
			}
		}

		//����ڿ��� ��õ�ϴ� �׸� ��� 	
		cout << "�����" << (i + 1) << "���� ��õ�ϴ� �׸�: ";
		cout << (maxPreferenceIndex + 1) << endl;
	}
}