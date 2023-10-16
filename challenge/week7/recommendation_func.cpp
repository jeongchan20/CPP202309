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
		cout << "사용자 " << (i + 1) << "의 선호도를 입력하세요(";
		cout << NUM_ITEMS << "개의 항목에 대해 ):";
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

		//사용자에게 추천하는 항목 출력 	
		cout << "사용자" << (i + 1) << "에게 추천하는 항목: ";
		cout << (maxPreferenceIndex + 1) << endl;
	}
}