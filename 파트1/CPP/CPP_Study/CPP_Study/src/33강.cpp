#include <iostream>
using namespace std;

// 오늘의 주제: TextRPG
enum PlayerType
{
	PT_Knight = 1,
	PT_Archer = 2,
	PT_Mage = 3,
};

enum MonsterType
{
	MT_Slime = 1,
	MT_Orc = 2,
	MT_Skeleton = 3,
};

struct ObjectInfo
{
	int type;
	int hp; 
	int attack;
	int defence;
};

ObjectInfo PlayerInfo;
ObjectInfo MonsterInfo;

void EnterLobby();
void SelectPlayer();
void EnterField();
void CreateRandomMonster();
void EnterBattle();


int main() 
{
	srand(time(0));	// 랜덤 시드 설정

	EnterLobby();

	return 0;
}

void EnterLobby()
{
	while (true)
	{
		cout << "---------------" << endl;
		cout << "로비에 입장했습니다!" << endl;
		cout << "---------------" << endl;

		// 플레이어 직업 선택
		SelectPlayer();

		cout << "---------------" << endl;
		cout << "(1) 필드 입장 (2) 게임 종료" << endl;
		cout << "---------------" << endl;

		int input;
		cin >> input;

		if (input == 1)
		{
			EnterField();
		}
		else
		{
			return;
		}
	}
}

void SelectPlayer()
{
	while (true)
	{
		cout << "---------------" << endl;
		cout << "직업을 골라주세요";
		cout << "(1) 기사 (2) 궁수 (3) 법사"<<endl;
		cout << "> ";

		cin >> PlayerInfo.type;

		if (PlayerInfo.type == PT_Knight)
		{
			cout << "기사 생성 중... !" << endl;
			PlayerInfo.hp = 150;
			PlayerInfo.attack = 10;
			PlayerInfo.defence = 5;
			break;
		}
		else if (PlayerInfo.type == PT_Archer)
		{
			cout << "궁수 생성 중... !" << endl;
			PlayerInfo.hp = 100;
			PlayerInfo.attack = 15;
			PlayerInfo.defence = 3;
			break;
		}
		else if (PlayerInfo.type == PT_Mage)
		{
			cout << "법사 생성 중... !" << endl;
			PlayerInfo.hp = 80;
			PlayerInfo.attack = 25;
			PlayerInfo.defence = 0;
			break;
		}
	}
}

void EnterField()
{
	while (true)
	{
		cout << "---------------" << endl;
		cout << "필드에 입장했습니다!" << endl;
		cout << "---------------" << endl;

		cout << "[PLAYER] HP : " << PlayerInfo.hp << " / ATT : " << PlayerInfo.attack << " / DEF : " << PlayerInfo.defence << endl;

		CreateRandomMonster();

		cout << "---------------" << endl;
		cout << "(1) 전투 (2) 도주" << endl;
		cout << "> ";

		int input;
		cin >> input;

		if (input == 1)
		{
			EnterBattle();
			if (PlayerInfo.hp == 0)
				return;
		}
		else
		{
			return;
		}
	}
}

void CreateRandomMonster()
{
	// 1~3
	MonsterInfo.type = 1 + (rand() % 3); // 1 2 3

	switch (MonsterInfo.type)
	{
	case MT_Slime:
		cout << "슬라임 생성 중... ! (HP:15 / ATT:5 / DEF:0)" << endl; 
		MonsterInfo.hp = 15;
		MonsterInfo.attack = 5;
		MonsterInfo.defence = 0;
		break;
	case MT_Orc:
		cout << "오크 생성 중... ! (HP:40 / ATT:10 / DEF:3)" << endl;
		MonsterInfo.hp = 40;
		MonsterInfo.attack = 10;
		MonsterInfo.defence = 3;
		break;
	case MT_Skeleton:
		cout << "해골병사 생성 중... ! (HP:80 / ATT:15 / DEF:5)" << endl;
		MonsterInfo.hp = 80;
		MonsterInfo.attack = 15;
		MonsterInfo.defence = 5;
		break;
	}
}

void EnterBattle()
{
	while (true)
	{
		int damage = PlayerInfo.attack - MonsterInfo.defence;
		if (damage < 0)
			damage = 0;

		// 선빵
		MonsterInfo.hp -= damage;
		if (MonsterInfo.hp < 0)
			MonsterInfo.hp = 0;

		cout << "몬스터 남은 체력 : " << MonsterInfo.hp << endl;
		if (MonsterInfo.hp == 0)
		{
			cout << "몬스터를 처치했습니다!" << endl;
			return;
		}

		damage = MonsterInfo.attack - PlayerInfo.defence;
		if (damage < 0)
			damage = 0;

		// 반격
		PlayerInfo.hp -= damage;
		if (PlayerInfo.hp < 0)
			PlayerInfo.hp = 0;

		cout << "플레이어 남은 체력 : " << PlayerInfo.hp << endl;
		if (PlayerInfo.hp == 0)
		{
			cout << "당신은 사망했습니다.. GAME OVER" << endl;
			return;
		}
	}
}