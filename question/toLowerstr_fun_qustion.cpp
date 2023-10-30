#include<iostream>
#include<string>
using namespace std;
string toLowerStr(string str);
int main() {
	string s1, s2;
	int count = 0;
	while (1)
	{
	cout << "DNA1: ";
	cin >> s1;
	cout << "DNA2: ";
	cin >> s2;

	



		if (s1.length() != s2.length()) {


			cout << "오류: 길이가 다름" << endl;
			continue;
		}
		else {
			for (int i = 0; i < s1.length(); i++) {
				if (s1[i] != s2[i])
					count += 1;
			}
			cout << "해밍 거리는 " << count << endl;
			break;

		}
		
	}

	cout<<toLowerStr(s1);
	return 0;
}

//범위기반 for대신 그냥 for문으로 사용을했는데 컴파일 오류가 납니다
//1.왜 참조를 하면 오류가 나는지 궁금합니다
//2.실습 해답에서는 새로운변수 newStr를 사용했는데 사용한이유가 궁금합니다.. 바로 return str값을 하면 안되나요?
string toLowerStr(string&str) {
	for (int i = 0; i < str.length(); i++) {
		str[i] = tolower(str[i]);
		return str;
	}
}
