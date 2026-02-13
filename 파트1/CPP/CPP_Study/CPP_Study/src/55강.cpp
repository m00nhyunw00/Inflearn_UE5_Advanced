#include <iostream>
using namespace std;

// 오늘의 주제 : 상속성

// 객체 지행 (OOP Object Oriented Programming)
// - 상속성
// - 은닉성
// - 다형성

// 메모리

//   [ Knight ]
// [ [ Player ] ]

// 건축학적으로 생각해보아도 건물을 올릴 때 기반을 먼저 쌓고 위에 건물을 쌓지만, 철거할 때는 위부터 철거한 후에 기반을 철거할 것이다.

// 상속(Inheritance) ? 부모 -> 자식에게 유산을 물려주는 것

// 생성자(N)/소멸자(1)

// 생성자는 탄생을 기념해서 호출되는 함수?
// ~Knight를 생성하면 -> Player의 생성자? Knight의 생성자?
// -> 솔로몬의 선택! 그냥 둘 다 

class Player
{
public:
	Player()
	{
		_hp = 0;
		_attack = 0;
		_defence = 0;
		cout << "Player() 기본 생성자 호출" << endl;
	}

	Player(int hp)
	{
		_hp = hp;
		_attack = 0;
		_defence = 0;
		cout << "Player(int hp) 기본 생성자 호출" << endl;
	}

	~Player()
	{
		cout << "~Player() 소멸자 호출" << endl;
	}

	void Move() { cout << "Player Move 호출" << endl; }
	void Attack() { cout << "Player Attack 호출" << endl; }
	void Die() { cout << "Player Die 호출" << endl; }
public:
	int _hp;
	int _attack;
	int _defence;
};

class Knight : public Player
{
public:
	Knight()
	{
		/*
		선(먼저)처리 영역
		- 여기서 Player() 생성자를 호출
		*/

		_stamina = 0;
		cout << "Knight() 기본 생성자 호출" << endl;
	}

	Knight(int stamina) : Player(100)
	{
		/*
		선처리 영역
		- 여기서 Player(100) 생성자를 호출
		*/

		_stamina = stamina;
		cout << "Knight(int stamina) 기본 생성자 호출" << endl;
	}

	~Knight()
	{
		cout << "~Knight() 소멸자 호출" << endl;

		/*
		후처리 영역
		- 여기서 ~Player() 생성자를 호출
		*/
	}

	// 재정의 : 부모님의 유산을 거부하고 새로운 이름으로 만든
	void Move() { cout << "Knight Move 호출" << endl; }
public:
	int _stamina;
};

class Mage : public Player
{
public:

public:
	int _mp;
};

int main()
{
	Knight k(100);

	k._hp = 100;
	k._attack = 10;
	k._defence = 5;

	k.Attack();
	k.Move();
	k.Player::Move();	// 재정의한 함수가 아닌 부모의 함수를 호출하는 문법
	k.Die();

	return 0;
}