#include <iostream>
using namespace std;

int main()
{
	// a,b,c,largest ���� ����
	int a, b, c, largest;

	cout << "3���� ������ �Է��Ͻÿ� ";

	// a,b,c ����ڿ��� �Է¹���
	cin >> a >> b >> c;

	// a�� b���� ũ�� a�� c���� ũ�� largest�� a �� ����
	if (a > b && a > c)
		largest = a;
	// b�� a���� ũ�� b�� c���� ũ�� largest�� b �� ����
	else if (b > a && b > c)
		largest =b;
	// ������ ��� largest�� c �� ����
	else
		largest =c;
	// ���Ե� largest �� ǥ��
	cout << "���� ū ������ " << largest << endl;

	return 0;
}