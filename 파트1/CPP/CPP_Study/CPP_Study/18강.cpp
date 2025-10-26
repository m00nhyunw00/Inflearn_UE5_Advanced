#include <iostream>
using namespace std;

int a = 1;
int b = 2;

int main() {
	// 산술 연산자

// 대입 연산
#pragma region 대입 연산

	a = b;	// a에 b를 대입하고 b를 반환하라 -> b를 반환하기 때문에 a = b = 3 같은 것도 가능

#pragma endregion


// 사칙 연산
#pragma region 사칙 연산

	a = b + 3;
	a = b - 3;
	a = b * 3;
	a = b / 3;
	a = b % 3;

	a += 3;
	a -= 3;
	a *= 3;
	a /= 3;
	a %= 3;

	// 증감 연산자
	a++; // a = a + 1l
	++a;
	a--;
	--a;
	// b = a++;  vs  b = ++a;  ->  b에 대입 후, a 증가  vs  a 증가 후, b 대입
	
#pragma endregion
}