class User {

public:
	int hp;

	void DecreaseHP(int dec_hp) {
		hp = hp - dec_hp;
	}

	int GetHP() {
		return hp;
	}

};