#include <iostream>
using namespace std;

int main()
{
	// a,b,c,smallgest ���� ����
	int a, b, c, smallgest;

	cout << "3���� ������ �Է��Ͻÿ� ";

	// a,b,c ����ڿ��� �Է¹���
	cin >> a >> b >> c;

	// a�� b���� �۰� a�� c���� ������ smallgest�� a �� ����
	if (a < b && a < c)
		smallgest = a;
	// b�� a���� �۰� b�� c���� ������ smallgest�� b �� ����
	else if (b < a && b < c)
		smallgest = b;
	// ������ ��� smallgest�� c �� ����
	else
		smallgest = c;

	// ���Ե� smallgest �� ǥ��
	cout << "���� ���� ������ " << smallgest << endl;

	return 0;
}