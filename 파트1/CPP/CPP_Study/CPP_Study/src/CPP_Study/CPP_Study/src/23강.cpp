#include <iostream>
using namespace std;

// 분기문

int main() {
	int hp = 100;	// 몬스터 hp
	int damage = 90;	// 플레이어 데미지

	hp -= damage;	// 피격 판정
	bool isDead = (hp <= 0);	// 처치 판정

	// 몬스터가 죽었으면 경험치 추가
	// 어셈블리어에서 CMP JMP
	
	if (isDead)
	{
		cout << "몬스터를 처치했습니다" << endl;
	}
	else if (hp <= 20)
	{
		cout << "몬스터가 도망가고 있습니다" << endl;
	}
	else
	{
		cout << "몬스터가 반격했습니다" << endl;
	}

	// ---------------------------------------------------------------

	const int ROCK = 0;
	const int PAPER = 1;
	const int SCISSORS = 2;

	int input = PAPER;

	if (input == ROCK)
	{
		cout << "바위를 냈습니다" << endl;
	}
	else if (input == PAPER)
	{
		cout << "보를 냈습니다" << endl;
	}
	else if (input == SCISSORS)
	{
		cout << "가위를 냈습니다" << endl;
	}
	else
	{
		cout << " 무엇을 낸겁니까?" << endl;
	}

	// input에는 정수 계열만 넣을 수 있음
	switch (input)
	{
		case ROCK:
			cout << "바위를 냈습니다" << endl;
			break;
		case PAPER:
			cout << "보를 냈습니다" << endl;
			break;
		case SCISSORS:
			cout << "가위를 냈습니다" << endl;
			break;
		default:
			cout << " 무엇을 낸겁니까?" << endl;
			break;	// 어차피 마지막이기 때문에 이건 해도 되고 안해도 됨
	}
}