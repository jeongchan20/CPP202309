#include <iostream>
using namespace std;

const int NUM_USERS = 3;
const int NUM_ITEMS = 3;
void initializePreferences();
void findRecommendedItems();
int userPreferences[NUM_USERS][NUM_ITEMS];


int main() {

	initializePreferences();
	findRecommendedItems();
	return 0;
}

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

void findRecommendedItems()
{
	for (int i = 0; i < NUM_USERS; ++i) {
		int maxPreferenceIndex = 0;
		for (int j = 1; j < NUM_ITEMS; ++j) {
			if (userPreferences[i][j] > userPreferences[i][maxPreferenceIndex]) {
				maxPreferenceIndex = j;
			}
		}

		//����ڿ��� ��õ�ϴ� �׸� ��� 	
		cout << "�����" << (i + 1) << "���� ��õ�ϴ� �׸�: ";
		cout << (maxPreferenceIndex + 1) << endl;
	}
}