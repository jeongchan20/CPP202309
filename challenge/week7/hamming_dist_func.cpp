#include<iostream>
#include<string>
using namespace std;

string toLowerStr(string str);
string UpperStr(string str);
int calcHammingDist(string s1, string s2);

int main() {
	string s1, s2;
	cin >> s1;
	cin >> s2;
	
	cout<<calcHammingDist(s1,s2);

}

string toLowerStr(string str) {
	for (auto& c : str) {
		c = tolower(c);
	
	}
	return str;
}

string UpperStr(string str) {
	for (auto& c : str) {
		c = toupper(c);

	}
	return str;
}

int calcHammingDist(string s1, string s2) {
	s1 = toLowerStr(s1);
	s2 = toLowerStr(s2);

	int count = 0;
	for (int i = 0; i < s1.length(); i++) {
		if (s1[i] != s2[i])
			count += 1;

	}
	return count;
}