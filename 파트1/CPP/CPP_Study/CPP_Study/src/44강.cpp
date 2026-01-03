#include <iostream>
using namespace std;

// 오늘의 주제 : 다중 포인터

void SetNumber(int* a)
{
	*a = 1;
}

void SetMessage(const char* a)
{
	a = "Bye";
}

void SetMessage(const char** a)
{
	*a = "Bye";
}

void SetMessage2(const char*& a)
{
	a = "Wow";
}

int main()
{
	//int a = 0;
	//SetNumber(&a);
	//cout << a << endl;

	// .rdata	Hello주소[H][e][l][l][o][\n]
	// .rdata	Bye주소[B][y][e][\n]
	// msg[ Hello 주소 ] << 8바이트

	// [매개변수][RET][지역변수(msg(Hello주소))]
	//		[매개변수(a(Hello주소))][RET][지역변수]

	const char* msg = "Hello";
	SetMessage(msg);
	cout << msg << endl;

	// 기본적인 이중포인터의 구조
	// 
	// 주소2[ ] << 1바이트
	// 주소1[ 주소2 ] << 8바이트
	// pp[ 주소1 ] << 8바이트

	const char** pp = &msg;
	SetMessage(pp);
	cout << msg << endl;

	// .rdata	Hello주소[H][e][l][l][o][\n]
	// msg[ Hello주소 ] << 8바이트
	// pp[ &msg ] << 8바이트

	SetMessage2(msg);
	cout << msg << endl;

	return 0;
}

