#include <iostream>
using namespace std;

// 오늘의 주제 : 은닉성

// 객체 지행 (OOP Object Oriented Programming)
// - 상속성
// - 은닉성
// - 다형성

 //은닉성(Data Hiding) = 캡슐화(Encapsulation)
 //몰라도 되는 것은 깔끔하게 숨기겠다!
 //숨기는 이유는?
 //1) 정말 위험하고 건드리면 안되는 경우
 //2) 다른 경로로 접근하기를 원하는 경우

// 자동차
// - 핸들
// - 페달
// - 엔진
// - 문
// - 각종 전기회로

// 일반 구매자 입장에서 사용하는 것?
// - 핸들
// - 페달
// - 문
// 몰라도 되는 부분
// - 엔진
// - 각종 전기 회로

// 멤버 접근 지정자 종류
// public(공개적)   protected(보호받는)   private(개인의)
// - public	   : 어디에서나 접근 가능
// - protected : 자식 클래스에서는 접근 가능
// - private   : class 내부에서만 접근 가능

// 상속 접근 지정자 : 다음 세대한테 부모님의 유산을 어떻게 물려줄지?
// 부모님한테 물려받은 유산을 꼭 나의 자손들한테도 똑같이 물려줘야 하지는 않음
// 실전에서는 public 말고는 쓸 일이 99.9% 없음
// - public	   : 부모님의 유산 설계 그대로 물려줌    ( public > public    / protected > protected )
// - protected : 앞으로는 자식들한테만 물려줌	     ( public > protected / protected > protected )
// - private   : 나까지만 쓰고 자식들한테는 안물려줌 ( public > private   / protected > private   )

class Car
{
public:	// 멤버 접근 지정자
	void MoveHandle() { }
	void PushPedal() { }
	void OpenDoor() { }
	void TurnKey()
	{
		// ...
		RunEngine();
	}
protected:
	void RunEngine() {}
	void DisassembleCar() {}
private:
	void ConnectCircuit() { }

public:
	// 핸들
	// 페달
	// 엔진
	// 문
	// 각종 전기 회로
};

class SuperCar : public Car	// 상속 접근 지정자 (멤버 접근 지정자와 다름)
{
public:
	void PushRemoteController()
	{
		// ...
		RunEngine();
	}
};

// '캡슐화'
// 연관된 데이터와 함수를 논리적으로 묶어놓은 것

class Berserker
{
public:
	// 사양 : 체력이 50 이하로 떨어지면 버서커 모드 발동 (강해짐)

	int GetHp() { return _hp; }

	void SetHp(int hp) 
	{ 
		_hp = hp;
		if (_hp <= 50)	// 캡슐화의 예시 : 유기적으로 연결된 로직은 묶어놓기
			SetBerserkerMode();
	}

private:
	void SetBerserkerMode()
	{
		cout << "매우 강해짐!" << endl;
	}

private:
	int _hp = 100;
};

int main()
{
	SuperCar car;
	car.PushRemoteController();

	Berserker b;
	b.SetHp(20);
	  
	return 0;
}