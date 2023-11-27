#include"user.h"

//헤더파일 원형에 있는 함수식
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
	cout << "공격합니다" << endl;
}

class Magician : public User {
public:
	void doAttack() {
		cout << "마법 사용" << endl;
	};
};

class Warrior : public User {
public:
	void doAttack() {
		cout << "베기 사용" << endl;
	};
};