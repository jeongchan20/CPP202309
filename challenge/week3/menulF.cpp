#include <iostream>
using namespace std;

int main()
{
	int choice;

	cout << "1. ���� ����" << endl;
	cout << "2. ���� ���� �ݱ�" << endl;
	cout << "3. ����" << endl;
	// choice ����ڷ� ���� �Է¹���
	cin >> choice;

	//choice�� 1�ΰ�� "���� ������ �����߽��ϴ�." ǥ���� if�� Ż�� �ƴ϶�� else if�� �Ѿ
	if (choice == 1)
		cout << "���� ������ �����߽��ϴ�." << endl;
	//choice�� 2�ΰ�� "���� �ݱ⸦ �����߽��ϴ�." ǥ���� if�� Ż�� else if�� �Ѿ
	else if (choice == 2)
		cout << "���� �ݱ⸦ �����߽��ϴ�." << endl;
	//choice�� 3�ΰ�� "���α׷��� �����մϴ�." ǥ���� if�� Ż�� else�� �Ѿ
	else if (choice == 3)
		cout << "���α׷��� �����մϴ�." << endl;
	//choice�� 3�� �ƴѰ��� "�߸��� �����Դϴ�." ǥ���ϰ� if�� Ż�� 
	else
		cout << "�߸��� �����Դϴ�." << endl;

	return 0;
}
