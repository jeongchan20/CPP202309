#include<iostream>
using namespace std;

int main()
{
	const int maxPeople = 3; //��� ����
	cout << "�� ���� ���� �Է��϶�: ";
	//cin >> maxPeople;
	string names[maxPeople]; // ���ڿ� �迭 names�� �����ϴµ� ũ��� maxPeole��ŭ
	int ages[maxPeople]; // int �迭 ages�� �����ϴµ� ũ��� maxPeole��ŭ

	for (int i = 0; i < maxPeople; i++) // for���� Ȱ���Ͽ� �迭�� ���� �������
	{	//cout << "�� ���� ���� �Է��϶�: "

		cout << "��� " << i + 1 << "�� " << "�̸� : "; 
		cin >> names[i]; // name �迭�� �������
		cout << "��� " << i+1 << "�� " << "���� : " ;
		cin >> ages[i];// ages��  �迭���� �������

	}

	int ageThreshold;  // Ư�����̸� ����
	cout << "Ư�� ���� �̻��� ����� ã������ ���̸� �Է��ϼ���: ";
	cin >> ageThreshold; // Ư�����̸� ã�����Ͽ� �Է¹���

	cout << ageThreshold << "�� �̻��� ����:\n";
	int detectedPeople = 0;  // Ư������ �̻��� ����� ���

	for (int i = 0; i < maxPeople; i++) //for���� �̿��Ͽ� detectedPeole��  ã��
	{
		if (ages[i] > ageThreshold) // ages�� ���̰� Ŭ��� 
		{
		{
			cout << names[i] << " (" << ages[i] << "��)\n";  // ages�� ���̰� Ŭ��� ���̿� �̸��� ��½�Ŵ
			detectedPeople++; // ages�� ���̰� �� ũ�Ƿ� ��� 1���߰�!
		}
	}

	if (detectedPeople == 0) // ���ǿ� �´»���� 0���̹Ƿ� ���� ���ٰ� ���!
	{
		cout << ageThreshold << "�̻��� ���̸� ���� ���� �����ϴ�";
	}
	return 0;
}
