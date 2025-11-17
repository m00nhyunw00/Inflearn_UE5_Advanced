#include <iostream>
using namespace std;

unsigned char flag;

// 한번 정해지면 절대 바뀌지 않을 값들
// constant의 약자인 const를 붙임 (변수를 상수화 한다고 함)
// const를 붙였으면 초기값을 반드시 지정해야 함

// 그러면 const도 바뀌지 않는 읽기 전용 .rodata에 들어가는 것이 맞나?
// 사실 C++ 표준에서 꼭 그렇게 하라는 말이 없음
// 그냥 컴파일러(VS) 마음이라는 것
const int AIR = 0;
const int STUN = 1;
const int POLYMORPH = 2;
const int INVINCIBLE = 3;

// [데이터 영역] - 전역 변수 저장됨
// .data (초기값이 있는 경우)
int a = 2;
// .bss (초기값이 없는 경우)
int b; 
// .rodata (읽기 전용 데이터)
const char* msg = "Hello World";

int main() {

	// [스택 영역] - 지역 변수 저장됨
	int c = 3;

	// 실습
	// 0b 0000 [무적][변이][스턴][공중부양]

	// 무적 상태로 만든다
	flag = (1 << INVINCIBLE);	

	// 변이 상태를 추가한다
	flag |= (1 << POLYMORPH);	

	// 무적인지 확인하고 싶다? (다른 상태는 관심 없음)
	bool invincible = ((flag & (1 << INVINCIBLE)) != 0);

	// 무적이거나 스턴 상태인지 확인하고 싶다면?
	bool mask = (1 << INVINCIBLE) | (1 << STUN);
	bool stunnedOrInvincible = ((flag & mask) != 0);

}