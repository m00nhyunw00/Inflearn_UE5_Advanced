#include "Field.h"
#include <stdlib.h>
#include "Monster.h"
#include "Player.h"
#include <iostream>
using namespace std;

Field::Field() : _monster(nullptr)
{

}

Field::~Field()
{
	if (_monster != nullptr)
		delete _monster;
}

void Field::Update(Player* player)
{
	if (_monster == nullptr)
		CreateMonster();
	
	StartBattle(player);
}

void Field::CreateMonster()
{
	int randValue = 1 + rand() % 3;

	switch (randValue)
	{
	case MT_SLIME:
		_monster = new Slime();
		break;
	case MT_ORC:
		_monster = new Orc();
		break;
	case MT_SKELETON:
		_monster = new Skeleton();
		break;
	}
}

void Field::StartBattle(Player* player)
{
	while (true)
	{
		player->PrintInfo();
		_monster->PrintInfo();

		// 플레이어 -> 몬스터 공격
		_monster->OnAttacked(player);

		if (_monster->IsDead())
		{
			_monster->PrintInfo();
			delete _monster;
			_monster = nullptr;
			cout << "------------------------" << endl;
			cout << "<<<< 몬스터를 해치웠습니다! >>>>" << endl;
			cout << "------------------------" << endl;
			break;
		}

		// 몬스터 -> 플레이어 공격
		player->OnAttacked(_monster);

		if (player->IsDead())
		{
			player->PrintInfo();
			// player는 game에서 관리하기 때문에 여기서 삭제하지 않음
			cout << "------------------------" << endl;
			cout << "<<<< 당신은 사망하였습니다... >>>>" << endl;
			cout << "------------------------" << endl;
			break;
		}
	}
}