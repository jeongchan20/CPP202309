#include"user.h"

//������� ������ �ִ� �Լ���
void User::DecreaseHP(int dec_hp) {
	hp = hp - dec_hp;
}

int User::GetHP() {
	return hp;
}

void User::IncreaseHP(int inc_hp) {
	hp = hp + inc_hp;
}
void User::doAttack() {
	cout << "�����մϴ�" << endl;
}

class Magician : public User {
public:
	void doAttack() {
		cout << "���� ���" << endl;
	};
};

class Warrior : public User {
public:
	void doAttack() {
		cout << "���� ���" << endl;
	};
};