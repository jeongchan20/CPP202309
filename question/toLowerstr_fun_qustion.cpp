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


			cout << "����: ���̰� �ٸ�" << endl;
			continue;
		}
		else {
			for (int i = 0; i < s1.length(); i++) {
				if (s1[i] != s2[i])
					count += 1;
			}
			cout << "�ع� �Ÿ��� " << count << endl;
			break;

		}
		
	}

	cout<<toLowerStr(s1);
	return 0;
}

//������� for��� �׳� for������ ������ߴµ� ������ ������ ���ϴ�
//1.�� ������ �ϸ� ������ ������ �ñ��մϴ�
//2.�ǽ� �ش信���� ���ο�� newStr�� ����ߴµ� ����������� �ñ��մϴ�.. �ٷ� return str���� �ϸ� �ȵǳ���?
string toLowerStr(string&str) {
	for (int i = 0; i < str.length(); i++) {
		str[i] = tolower(str[i]);
		return str;
	}
}
