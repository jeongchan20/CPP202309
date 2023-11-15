#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int maxPeople = 0;
	vector<int>Age;
	vector<string>Name;
	cout << "총 고객의 수를 입력하라: ";
	//cin >> maxPeople;
	cin >> maxPeople;
	

	for (int i = 0; i < maxPeople; i++) // for문을 활용하여 배열에 값을 집어넣음
	{	//cout << "총 고객의 수를 입력하라: "

		cout << "사람 " << i + 1 << "의 " << "이름 : ";
		string name;
		cin >> name;
		Name.push_back(name);
		cout << "사람 " << i + 1 << "의 " << "나이 : ";
		int age;
		cin >> age;
		Age.push_back(age);
		

	}

	int ageThreshold;  // 특정나이를 선언
	cout << "특정 나이 이상인 사람을 찾으려면 나이를 입력하세요: ";
	cin >> ageThreshold; // 특정나이를 찾기위하여 입력받음

	cout << ageThreshold << "세 이상인 고객들:\n";
	int detectedPeople = 0;  // 특정나이 이상인 사람의 명수

	for (int i = 0; i < maxPeople; i++) //for문을 이용하여 detectedPeole를  찾음
	{
		if (Age[i] > ageThreshold) // ages의 나이가 클경우 
		{
			{
				cout << Name[i] << " (" << Age[i] << "세)\n";  // ages의 나이가 클경우 나이와 이름을 출력시킴
				detectedPeople++; // ages의 나이가 더 크므로 명수 1명추가!
			}
		}

		if (detectedPeople == 0) // 조건에 맞는사람이 0명이므로 고객이 없다고 출력!
		{
			cout << ageThreshold << "이상의 나이를 가진 고객이 없습니다";
		}
		return 0;
	}

}