#include <iostream>
using namespace std;


int main() {
	const int NUM_USERS = 3;
	const int NUM_ITEMS = 3;
	int userPreferences[NUM_USERS][NUM_ITEMS];

	//사용자와 항목 간의 선호도를 입력 받아 2차원 배월 초기화 
	for (int i = 0; i < NUM_USERS; ++i) {
		cout << "사용자 " << (i + 1) << "의 선호도를 입력하세요(";
		cout << NUM_ITEMS << "개의 항목에 대해 ):";
		for (int j = 0; j < NUM_ITEMS; j++) {
			cin >> userPreferences[i][j];
		}
	}
	//각 사용자에 대한 추천항목을 2중 for과 if문을 사용해서 활용함
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
	return 0;
}