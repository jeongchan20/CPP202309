#include"user.h"

//헤더파일 원형에 있는 함수식
void User::DecreaseHP(int dec_hp) {
	hp = hp - dec_hp;
}

int User::GetHP() {
	return hp;
}
