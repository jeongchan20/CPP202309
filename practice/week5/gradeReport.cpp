#include<iostream>
#include<string>
using namespace std;

int main()
{
	const int STUDENT = 5; //�������
	const int SUBJECT = 3;//�������

	int scores[STUDENT][SUBJECT]; //2�����迭 scores ����

	string studentNames[STUDENT] = { "����","����","ö��","�̹�","����" }; //STUDENT�迭�� �̸� ����
	string subjectNames[SUBJECT] = { "����","����","CPP"};//SUBJECT�迭�� ���� ����

	for (int i = 0; i < STUDENT; i++)
	{
		cout << studentNames[i] << "�� ������ �ϳ��� �Է��ϼ���." << endl; //����̸� i�����̸��� ���
		for (int j = 0; j < SUBJECT; j++)
		{
			cout << subjectNames[j] << ":"; //������ �Է��� ��½�Ŵ
			cin >> scores[i][j]; // ������,����迭�� �迭���ٰ� ������ �Է½�Ŵ
		}
	}

	for (int i = 0; i < STUDENT; i++)
	{
		cout << studentNames[i] << "�� ��� ������";
		double sum = 0;
		double average = 0;

		for (int j = 0; j < SUBJECT; j++) { //sum�������� scores�� ���� �־�а��� ������.. for���� ������ ����
			sum += scores[i][j];
		}
		average = sum / SUBJECT;
		cout << average << "�Դϴ�" << endl;
	}
	return 0;
}
