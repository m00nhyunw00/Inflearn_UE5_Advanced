#pragma once
// #include "Monster.h"

// class Monster;	// 전방 선언

// Class는 설계도
class Player
{
public:
	void KillMonster();

	// 이 경우도 빌드가 안됨
	// 따라서 cpp 파일로 따로 빼서 관리하는 것이 용이
	//void KillMonster2()
	//{
	//	_target2->_hp = 0;
	//}

public:
	int _hp;
	int _attack;

	// Monster _target;
	class Monster* _target2;	// 전방 선언

	// 아래와 같이 헷갈릴 경우는, 
	// Player는 과연 몇바이트인 것일까? 를 생각
	// Player _target;	// 4 + 4 + ? -> 불가능
	Player* _target3;	// 4 + 4 + (4 or 8) -> 가능
};