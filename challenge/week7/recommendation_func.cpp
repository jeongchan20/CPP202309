#include <iostream>
using namespace std;

//함수에서도 사용하기위해서 전역변수 선언
const int NUM_USERS = 3;
const int NUM_ITEMS = 3;
//main함수뒤에 함수를 정의했으므로 함수원형 작성
void initializePreferences();
void findRecommendedItems();
int userPreferences[NUM_USERS][NUM_ITEMS];


int main() {
	//함수호출
	initializePreferences();
	findRecommendedItems();
	return 0;
}

//사용자에게 선호도를 입력받음(이중for문을 통해서!)
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

//사용자에게 입력받음 선호도를 바탕으로 추천하는 항목을 출력함(이중for문과 새로운 변수 maxPreferenceIndex를 통해서!)
void findRecommendedItems()
{
	for (int i = 0; i < NUM_USERS; ++i) {
		int maxPreferenceIndex = 0;
		for (int j = 1; j < NUM_ITEMS; ++j) {
			//이중 for문을 돌면서 최댓값을 체크하고 기존에 가지고있는 최댓값보다 크면 그 값으로 최대값 대체함!
			if (userPreferences[i][j] > userPreferences[i][maxPreferenceIndex]) {
				maxPreferenceIndex = j;
			}
		}

		//사용자에게 추천하는 항목 출력 	
		cout << "사용자" << (i + 1) << "에게 추천하는 항목: ";
		cout << (maxPreferenceIndex + 1) << endl;
	}
}