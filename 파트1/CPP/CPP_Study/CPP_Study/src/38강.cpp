#include <iostream>
using namespace std;

// 오늘의 주제 : 포인터 실습

struct StatInfo
{
	int hp;		
	int attack;		
	int defence;	
};

void EnterLobby();
StatInfo CreatePlayer();
void CreateMonster(StatInfo* info);
bool StartBattle(StatInfo* player, StatInfo* monster);

int main()
{
	EnterLobby();

	return 0;
}

void EnterLobby()
{
	cout << "로비에 입장했습니다" << endl;

	StatInfo player;
	player = CreatePlayer();

	StatInfo monster;
	CreateMonster(&monster);

	// 번외편 1)
	// player = monster;	아래와 똑같이 작동하기 때문에 밑에 있는 코드보다 더 효율적이지는 않음
	// 
	// player.hp = monster.hp;
	// player.attack = monster.attack;
	// player.defence = monster.defence

	bool victory = StartBattle(&player, &monster);

	if (victory)
		cout << "승리!" << endl;
	else
		cout << "패배!" << endl;
}

StatInfo CreatePlayer()
{
	StatInfo ret;
	
	cout << "플레이어 생성" << endl;

	ret.hp = 100;
	ret.attack = 10;
	ret.defence = 2;

	return ret;
}

// 이 버전이 효율이 훨씬 좋음
void CreateMonster(StatInfo* info) 
{
	cout << "몬스터 생성" << endl;

	info->hp = 40;
	info->attack = 8;
	info->defence = 1;
}

bool StartBattle(StatInfo* player, StatInfo* monster)
{
	while (true)
	{
		int damage = player->attack - monster->defence;
		if (damage < 0)
			damage = 0;

		monster->hp -= damage;
		if (monster->hp < 0)
			monster->hp = 0;

		cout << "몬스터 HP : " << monster->hp << endl;

		if (monster->hp == 0)
			return true;

		damage = monster->attack - player->defence;
		if (damage < 0)
			damage = 0;

		player->hp -= damage;
		if (player->hp < 0)
			player->hp = 0;

		if (player->hp == 0)
			return false;

		cout << "플레이어 HP : " << player->hp << endl;
	}
}