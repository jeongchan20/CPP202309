#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int maxPeople = 0;
	vector<int>Age;
	vector<string>Name;
	cout << "�� ���� ���� �Է��϶�: ";
	//cin >> maxPeople;
	cin >> maxPeople;
	

	for (int i = 0; i < maxPeople; i++) // for���� Ȱ���Ͽ� �迭�� ���� �������
	{	//cout << "�� ���� ���� �Է��϶�: "

		cout << "��� " << i + 1 << "�� " << "�̸� : ";
		string name;
		cin >> name;
		Name.push_back(name);
		cout << "��� " << i + 1 << "�� " << "���� : ";
		int age;
		cin >> age;
		Age.push_back(age);
		

	}

	int ageThreshold;  // Ư�����̸� ����
	cout << "Ư�� ���� �̻��� ����� ã������ ���̸� �Է��ϼ���: ";
	cin >> ageThreshold; // Ư�����̸� ã�����Ͽ� �Է¹���

	cout << ageThreshold << "�� �̻��� ����:\n";
	int detectedPeople = 0;  // Ư������ �̻��� ����� ���

	for (int i = 0; i < maxPeople; i++) //for���� �̿��Ͽ� detectedPeole��  ã��
	{
		if (Age[i] > ageThreshold) // ages�� ���̰� Ŭ��� 
		{
			{
				cout << Name[i] << " (" << Age[i] << "��)\n";  // ages�� ���̰� Ŭ��� ���̿� �̸��� ��½�Ŵ
				detectedPeople++; // ages�� ���̰� �� ũ�Ƿ� ��� 1���߰�!
			}
		}

		if (detectedPeople == 0) // ���ǿ� �´»���� 0���̹Ƿ� ���� ���ٰ� ���!
		{
			cout << ageThreshold << "�̻��� ���̸� ���� ���� �����ϴ�";
		}
		return 0;
	}

}