#include<iostream>
using namespace std;

int main() {

	int vowel = 0; // ���� �ʱ�ȭ
	int consonant = 0;// ���� �ʱ�ȭ

	cout << "�����ڸ� �Է��ϰ� ctrl+z�� ġ����" << endl;

	char ch;
	

	while (cin >> ch) // while ������ ch�� �Է��ҋ� ������
	{
		switch (ch) 
		{
		case 'a': case'e':case'i':case'o': case'u': // ������ ���̽��� �з���
			vowel++; //vowel�� 1�߰���Ŵ
			break;

		default: //������ ������ �������� �����̹Ƿ� ����Ʈ������ consonant�� 1���� ��Ŵ
			consonant++;
		}
	}
	cout << "����: " << vowel << endl; // ���� ���� ���
	cout << "����: " << consonant << endl;  // ���� ���� ���
	return 0;

}