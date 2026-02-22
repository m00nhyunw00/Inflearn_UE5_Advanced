#include <iostream>
using namespace std;

// 오늘의 주제 : 연산자 오버로딩(Operator Overloading)

// 연산자 vs 함수
// - 연산자는 피연산자의 개수/타입이 고정되어 있음

// 연산자 오버로딩?
// 일단 [연산자 함수]를 정의해야 함
// 함수도 멤버 함수 vs 전역 함수가 존재하는 것처럼, 연산자 함수도 두가지 방식으로 만들 수 있음

// - 멤버 연산자 함수 version
// -- a op b 형태에서 왼쪽 기준으로 실행됨 (a가 클래스여야 가능함. a를 '기준 피연산자'라고 함)
// -- 한계) a가 클래스가 아니면 사용 못함

// - 전역 연산자 함수 version
// -- a op b 형태라면 a,b 모두를 연산자 함수의 피연산자로 만들어준다.

// 그럼 무엇이 더 좋은가? 그런거 없음. 심지어 둘 중 하나만 지원하는 경우도 있기 때문.
// - 대표적으로 대입 연산자 (a = b)는 전역 연산자 version으로는 못 만든다.

// 복사 대입 연산자
// - 대입 연산자가 나온 김에 [복사 대입 연산자]에 대해서 알아보자
// 용어가 좀 헷갈린다 [복사 생성자] [대입 연산자] [복사 대입 연산자]
// - 복사 대입 연산자 = 대입 연산자 중 자기 자신의 참조 타입을 인자로 받는것

// 기타
// - 모든 연산자를 다 오버로딩 할 수 있는 것은 아니다 (:: . .* 이런건 안됨)
// - 모든 연산자가 다 2개 항이 있는 것은 아님. ++ --가 대표적 (단항 연산자)
// - 증감 연산자 ++ --
// -- 전위형 (++a) operator++()
// -- 후위형 (a++) operator++(int)

class Position
{
public:
	Position operator+(const Position& arg)	// 멤버 연산자 함수
	{ 
		Position pos;

		pos._x = _x + arg._x;
		pos._y = _y + arg._y;

		return pos;
	}

	Position operator+(int arg)	// 멤버 연산자 함수
	{
		Position pos;

		pos._x = _x + arg;
		pos._y = _y + arg;

		return pos;
	}

	bool operator==(const Position& arg)
	{
		return (_x == arg._x) && (_y == arg._y);
	}

	Position& operator=(int arg)
	{
		_x = arg;
		_y = arg;
		// Position* this = 내 자신의 주소;
		return *this;
	}

	// [복사 생성자] [복사 대입 연산자] 등 특별 대우를 받는 이유는
	// 말 그대로 객체가 '복사'되기를 원하는 특징 때문
	// TODO ) 동적 할당 시간에 더 자세히 알아볼 것
	Position& operator=(const Position& arg)
	{
		_x = arg._x;
		_y = arg._y;
		return *this;
	}

	Position& operator++()
	{
		_x++;
		_y++;
		return *this;
	}

	Position operator++(int)
	{
		Position ret = *this;
		_x++;
		_y++;
		return ret;
	}

public:
	int _x;
	int _y;
};

// 전역 연산자 함수
Position operator+(int a, const Position& b)
{
	Position ret;

	ret._x = a + b._x;
	ret._y = a + b._y;

	return ret;
}

// 아래의 경우는 멤버 연산자 함수만 가능
//void operator=(const Position& a, int b)
//{
//	a._x = b;
//	a._y = b;
//}

int main()
{
	Position pos1;
	pos1._x = 0;
	pos1._y = 0;

	Position pos2;
	pos2._x = 1;
	pos2._y = 1;

	Position pos3 = pos1 + pos2;	// pos1.operator+(pos2);도 가능하지만 가독성이 떨어짐
	Position pos4 = pos3 + 1;		// 멤버 연산자 함수 version에서는 1 + pos3 와 같이 순서를 뒤바꾸면 안됨 
	Position pos5 = 1 + pos4;		// 전역 연산자 함수 version을 활용하면 순서를 바꿔도 됨

	bool isSame = (pos3 == pos4);

	Position pos6;
	pos6 = 6;
	// Position pos6 = 6;은 전혀 다른 의미임. 이 경우에는 5라는 인자를 받는 생성자를 찾게 됨

	Position pos7 = (pos6 = 7);

	Position pos8;
	pos8 = pos7++;	
	// 위에서 대입 연산자 함수 '=' 는 Position& 타입을 매개변수 타입으로 요구함
	// 그러나 후위 연산자 함수 '++'의 반환 타입을 Position으로 설정한다면 타입이 서로 맞지 않아 오류가 발생함
	// 대입 연산자의 매개변수 타입을 const Position&으로 설정한다면 위 문제가 해결됨

	++(++pos8);

	return 0;
}