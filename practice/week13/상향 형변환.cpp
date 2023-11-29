#include<iostream>
#include<vector>
using namespace std;

class Animal {
public:
	virtual void speak() {
		cout << "Animal speak()" << endl;
	}
};

class Dog :public Animal {
public:
	int age;
	void speak() {
		cout << "�۸�" << endl;
	}
};

class Cat :public Animal {
public:
	void speak() {
		cout << "�߿�" << endl;
	}
};

int main()
{
	vector<Animal*>animals;
	animals.push_back(new Dog());
	animals.push_back(new Cat());

	for (const auto& animal : animals) {
		animal->speak();
	}
	return 0;
}