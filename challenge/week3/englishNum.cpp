#include <iostream>
using namespace std;

int main()
{
	int number;
	cout << "���ڸ� �Է��Ͻÿ�";
	
	//number�� �Է¹���
	cin >> number;

	//number�� 0�̸� zero�� ǥ���ϰ� if�� Ż��
	if (number == 0)
		cout << "zero\n";
	//number�� 1�̸� one�� ǥ���ϰ� if�� Ż��
	else if (number == 1)
		cout << "one\n";
	//number�� 1�� �ƴϸ� many�� ǥ���ϰ� if�� Ż��
	else
		cout << "many\n";

	return 0;
}
