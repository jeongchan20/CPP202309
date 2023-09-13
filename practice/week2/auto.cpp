#include<iostream>
using namespace std;

//auto는 형식을 자동으로 결정시켜줌!
auto add(int x, int y) {
	return x + y;
}

int main()
{
	auto sum = add(5, 6);
	cout << sum;
	return 0;
}