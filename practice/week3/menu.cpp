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
	// ���̽��� ������ �׿����� ��°��� ��ȭ�� 
	switch (choice) {
		// 1���� �´ٸ� ����ġ�� �� Ż��
	case 1:
		cout << "���� ������ �����߽��ϴ�." << endl;
		break;
		// 2���� �´ٸ� ����ġ�� �� Ż��
	case 2:
		cout << "���� �ݱ⸦ �����߽��ϴ�." << endl;
		break;
		// 3���� �´ٸ� ����ġ�� �� Ż��
	case 3:
		cout << "���α׷��� �����մϴ�." << endl;
		break;
		//�������� ���̽��� �����Ƿ� default�� ����� ����ġ�� Ż�� 
	default:
		cout << "�߸��� �����Դϴ�." << endl;
		break;
	}

	return 0;

}


