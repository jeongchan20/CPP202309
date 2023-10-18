#include<iostream>
#include<string>
using namespace std;

int main() {
	string s1, s2;
	int count = 0;

	cout << "DNA1: ";
	cin >> s1;
	cout << "DNA2: ";
	cin >> s2;
	//길이가 다른지 비교
	if (s1.length() != s2.length())
		cout << "오류: 길이가 다름" << endl;

	//길이가 같고 for문을 통해 배열의 값이 다르면 1씩 추가시킴 
	else {
		for (int i = 0; i < s1.length(); i++) {
			if (s1[i] != s2[i])
				count += 1;
		}
	}
}
