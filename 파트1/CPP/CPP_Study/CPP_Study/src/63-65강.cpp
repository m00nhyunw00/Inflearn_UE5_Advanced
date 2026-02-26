#include <iostream>
using namespace std;

// 오늘의 주제 : 동적 할당

// 메모리 구조 복습
// - 실행할 코드가 저장되는 영역 -> 코드 영역
// - 전역(global)/정적(static) 변수 -> 데이터 영역
// - 지역 변수/매개 변수 -> 스택 영역

// 지금까지는 데이터 영역 / 스택 영역 이용해서
// 이런 저런 프로그램을 잘 만들어왔다!
// 굳이 새로운 영역이 필요할까?

// 실제 상황)
// - MMORPG 동접 1명~5만명, 몬스터 1마리~500만마리
// - 몬스터 생성 이벤트 -> 5분동안 몬스터가 10배 많이 나옴

// - 스택 영역
// 함수가 끝나면 같이 정리되는 불안정한 메모리
// 잠시 함수에 매개변수를 넘긴다거나 하는 용도로는 OK
// - 메모리 영역
// 프로그램이 실행되는 도중에는 '무조건' 사용되는

// 희망사항)
// - 필요할 때만 사용하고, 필요없으면 반납할 수 있는!
// - 그러면서도 (스택과는 다르게) 우리사 생성/소멸 시점을 관리할 수 있는!
// - 그런 아름다운 메모리 없냐? -> HEAP
// 동적 할당과 연관된 함수/연산자 : [malloc / free], [new / delete], [new[] / delete[]]

// 1)
// malloc
// - 할당량 메모리 크리를 건네준다
// - 메모리 할당 후 시작 주소를 가르키는 포인터를 반환해준다 (메모리 부족 NULL)
// free
// - malloc (혹은 기타 calloc, realloc 등의 사촌) 을 통해 할당된 영역을 해제
// - 힙 관리자가 할당/미할당 여부를 구분해서 관리

// 2)
// new / delete
// - C++에 추가됨
// - malloc/free 함수! new/delete는 연산자(operator)!

// 3)
// new[] / delete[]
// - new가 malloc에 비해 좋기는 한데~ 배열과 같이 N개 데이터를 같이 할당하려면?

// malloc/free vs new/delete
// - 사용 편의성 -> new/delete 승!
// - 타입에 상관없이 특정한 크기의 메모리 영역을 할당받으려면? -> malloc/free 승!

// 그런데 둘의 가장 근본적인 중요한 차이는 따로 있음!
// new/delete는 생성 타입이 클래스일 경우, 생성자/소멸자를 호출해준다!!!

class Monster
{
public:
	Monster()
	{
		cout << "Monster()" << endl;
	}
	Monster(int num)
	{
		cout << "Monster(" << num << ")" << endl;
	}
	~Monster()
	{
		cout << "~Monster()" << endl;
	}
public:
	int _hp;
	int _x;
	int _y;
};

int main()
{
	// 유저 영역 [메모장][LOL][곰플레이어]
	//-------------------------------------------
	// 커널 영역 (Window 등의 핵심 코드)

	// 유저 영역) 운영체제에서 제공하는 API 호출
	// 커널 영역) 메모리 할당해서 건네줌
	// 유저 영역) ㄳㄳ 잘 쓸게요~~

	// [                                       ]
	// C++에서는 기본적으로 CRT(C 런타임 라이브러리)의 [힙 관리자]를 통해 힙 영역 사용
	// 단, 정말 원한다면 우리가 직접 API를 통해 힙을 생성하고 관리할 수도 있음 (MMORPG 서버 메모리 풀링)

	// 그런데 잠깐! void* ?? 무엇일까
	// * 가 있으니까 포인터는 포인터 (주소를 담는 바구니) => OK
	// 타고 가면 void 아무것도 없다? => NO
	// 타고 가면 void 뭐가 있는지 모르겠으니까 너가 적당히 변환해서 사용해라 => OK

	// 1) malloc/free ---------------------------------------------------------------------------------------

	void* pointer = malloc(sizeof(Monster));
	// void* pointer = malloc(sizeof(Monster));		=> Heap Overflaw
	Monster* m1 = (Monster*)pointer;
	m1->_hp = 100;
	m1->_x = 1;
	m1->_y = 2;

	free(pointer);

	// free(pointer);	=> Double Free

	//m1->_hp = 100;
	//m1->_x = 1;
	//m1->_y = 2;		=> Use-After-Free
	// - 프로그래머 입장 : omg 망했다!
	// - 해커 입장 : 심봤다!

	pointer = nullptr;
	m1 = nullptr;

	// 2) new/delete ---------------------------------------------------------------------------------------

	Monster* m2 = new Monster(3);

	m2->_hp = 200;
	m2->_x = 2;
	m2->_y = 3;

	delete m2;

	// 3) new[]/delete[] ---------------------------------------------------------------------------------------
	// 사실 이 버전은 사용 잘 안하고 2) 버전을 많이 사용함

	Monster* m3 = new Monster[5];

	m3->_hp = 300;
	m3->_x = 3;
	m3->_y = 4;

	Monster* m4 = (m3 + 1);

	m4->_hp = 400;
	m4->_x = 4;
	m4->_y = 5;

	delete[] m3;


	return 0;
}