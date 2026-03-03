#include <iostream>
using namespace std;

// 오늘의 주제 : 얕은 복사 vs 깊은 복사

class Pet
{
public:
	Pet()
	{
		cout << "Pet()" << endl;
	}

	~Pet()
	{
		cout << "~Pet()" << endl;
	}

	Pet(const Pet& pet)
	{
		cout << "Pet(const Pet&)" << endl;
	}
};

class Knight
{
public:
	Knight()
	{
		_pet = new Pet();
	}

	Knight(const Knight& knight)
	{
		cout << "Knight(const Knight&)" << endl;

		_hp = knight._hp;
		_pet = new Pet(*(knight._pet));	// 깊은 복사
	}

	Knight& operator=(const Knight& knight)
	{
		_hp = knight._hp;
		_pet = new Pet(*(knight._pet));	// 깊은 복사
		return *this;
	}

	~Knight()
	{
		delete _pet;
	}

public:
	int _hp = 100;
	Pet* _pet;	// 보통 Pet이 아니라 Pet*의 형태로 가지고 있음
				// 1. 내가 소멸하면 Pet도 의도치않게 강제적으로 같이 소멸함 -> 생명 주기 관리 어려움
				// 2. 포인터로 관리해야 Pet의 자식 클래스가 있다고 하더라고 Knight에서 _pet 하나만으로 관리할 수 있음
};

int main()
{
	Pet* pet = new Pet();
	Knight knight;	// 기본 생성자
	knight._hp = 200;	

	Knight knight2 = knight;	// 복사 생성자
	// Knight knight2(knight);

	Knight knight3;		// 기본 연산자
	knight3 = knight;	// 복사 대입 연산자

	// [복사 생성자] + [복사 대입 연산자]
	// 둘 다 안 만들어주면 컴파일러가 '암시적으로' 만들어준다.

	// 중간 결론) 컴파일러가 알아서 잘 만들어준다?
	// 수고하세요~ 다음 주제 넘어갈까요? >> NO

	// 만약 복사 생성자나 복사 대입 연산자를 따로 정의하여 처리하지 않았다면 기본적으로는
	// [ 얕은 복사 Shallow Copy ]
	// 멤버 데이터를 비트열 단위로 '똑같이' 복사 (메모리 영역 값을 그래도 복사)
	// 포인터는 주소값 바구니 -> 주소값을 똑같이 복사 -> 동일한 객체를 가리키는 상태가 됨
	// Stack : Knight[ hp, 0x1000 ]		-> Heap : 0x1000 Pet[  ]
	// Stack : Knight2[ hp, 0x1000 ]	-> Heap : 0x1000 Pet[  ]
	// Stack : Knight3[ hp, 0x1000 ]	-> Heap : 0x1000 Pet[  ]
	// 따라서 소멸자가 3번 호출되면서 delete _pet;을 3번 하는데 이미 knight가 소멸하면서 _pet도 같이 소멸되었는데 2번 더 _pet을 delete하고 있는 셈이다.
	// 즉, Double-Free 문제가 발생한다.

	// 우리가 원하는건
	// [ 깊은 복사 Deep Copy ]
	// 멤버 데이터가 참조(주소)값이라면, 데이터를 새로 만들어준다. (원본 객체가 참조하는 대상까지 새로 만들어서 복사)
	// 포인터는 주소값 바구니 -> 새로운 객체를 생성 -> 상이한 객체를 가리키는 상태가 됨
	// Stack : Knight[ hp, 0x1000 ]		-> Heap : 0x1000 Pet[  ]
	// Stack : Knight2[ hp, 0x2000 ]	-> Heap : 0x2000 Pet[  ]
	// Stack : Knight3[ hp, 0x3000 ]	-> Heap : 0x3000 Pet[  ]

	return 0;
}