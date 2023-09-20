#include<iostream>
using namespace std;

int main() {

	int vowel = 0; // 변수 초기화
	int consonant = 0;// 변수 초기화

	cout << "영문자를 입력하고 ctrl+z를 치세요" << endl;

	char ch;
	

	while (cin >> ch) // while 조건이 ch를 입력할떄 까지임
	{
		switch (ch) 
		{
		case 'a': case'e':case'i':case'o': case'u': // 모음인 케이스만 분류함
			vowel++; //vowel를 1추가시킴
			break;

		default: //모음을 제외한 나머지는 자음이므로 디폴트값으로 consonant를 1증감 시킴
			consonant++;
		}
	}
	cout << "모음: " << vowel << endl; // 모음 갯수 출력
	cout << "자음: " << consonant << endl;  // 자음 갯수 출력
	return 0;

}