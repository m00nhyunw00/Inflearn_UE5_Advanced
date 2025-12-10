#include <iostream>
using namespace std;

// 오늘의 주제 : 참조

struct StatInfo
{
	int hp;
	int attack;
	int defence;
};

void CreateMonster(StatInfo& info)
{
	info.hp = 100;
	info.attack = 8;
	info.defence = 5;
}

int main()
{
	int number = 1;

	int* pointer = &number;

	// 참조 전달 방식
	// number라는 바구니에 또 다른 이름을 부여한 것
	// 앞으로 reference 바구니에다가 뭘 꺼내거나 넣으면,
	// 실제 number 바구니(진퉁)에다가 그 값을 꺼내거나 넣을 수 있음
	int& reference = number;

	cout << number << " " << reference << endl;

	reference = 3;

	cout << number << " " << reference << endl;

	StatInfo info;
	CreateMonster(info);
	
	return 0;
}