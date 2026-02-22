#include <iostream>
using namespace std;

// 오늘의 주제 : 객체지향 마무리

// 1) struct vs class --------------------------------------------------------------

// C++에서는 struct나 class나 종이 한장 차이다.
// struct는 기본 접근 지정자가 public이고 class는 private
// 왜 이렇게 했을까? C++은 C언어에서 파생되어 발전했기 때문에, 호환성을 지키지 위함.
// -> struct는 그냥 구조체 (데이터 묶음)을 표현하는 용도
// -> class는 객체 지향 프로그래밍의 특징을 타나대는 용도

struct TestStruct
{
	int _a;
	int _b;
};

class TestClass
{
	int _a;
	int _b;
};

// 2) static 변수, static 함수 (static = 정적 = 고정된) ----------------------------

class Marine
{
public:
	// 특정 마린 객체에 종속적
	int _hp;

	void TakeDamage(int damage)
	{
		_hp -= damage;
	}

	// 특정 마린 객체와 무관
	// 마린이라는 '클래스' 자체와 연관
	static void SetAttack()
	{
		s_attack = 7;
	}

	static int s_attack;	//설계도상으로만 존재
};

// static 변수는 어떤 메모리에 저장될까?
// 초기화 하면 .data
// 초기화 안하면 .bss
// 어쨌든 .data 영역에 올라간다고 할 수 있음

int Marine::s_attack = 0;

// 3) static의 활용 ------------------------------------------------------------------
// 함수 내부에서 static을 사용하면 스택이 아닌 .data 영역에 올라감

int GenerateId()
{
	// 생명주기 : 프로그램 시작/종료 (메모리에 항상 올라가 있음)
	// 가시범위 : 함수 내부에서만 사용 가능

	// 정적 지역 객체
	static int s_id = 1;

	return s_id++;
}

// 정적 전역 객체
static int s_global = 1;

int main()
{
	// 1) -------------------------------------------------
	TestStruct ts;
	ts._a = 1;

	TestClass tc;
	// tc._a = 1;

	// 2) -------------------------------------------------
	Marine m1;
	m1._hp = 35;
	// m1.s_attack = 6;

	Marine::s_attack = 6;

	Marine m2;
	m2._hp = 14;
	// m2.s_attack = 6;

	// 마린 공격력 업그레이드 완료! (Academy에서 업그레이드 끝)
	// m1.s_attack = 7;
	// m2.s_attack = 7;
	Marine::SetAttack();

	// 3) -------------------------------------------------	
	cout << GenerateId() << endl;
	cout << GenerateId() << endl;
	cout << GenerateId() << endl;
	cout << GenerateId() << endl;
	cout << GenerateId() << endl;
	
	return 0;
}