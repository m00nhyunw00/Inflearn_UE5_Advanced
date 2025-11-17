#include <iostream>
using namespace std;

// 오늘의 주제 : 함수 (프로시저, 메소드, 루틴)

/* 
input으로 무엇을 받고, output으로 무엇을 뱉을지 정해준다

반환타입 함수이름([인자타입 매개변수])
{
	함수 내용

	return ---;
}
*/

void PrintHelloWorld() 
{
	cout << "Hello World" << endl;
}

// 정수를 입력(함수) 받아서, 콘솔에 출력하는 함수를 만들어보자
void PrintNumber(int num)
{
	cout << "넘겨주신 숫자는 " << num << "입니다" << endl;
}

// 2를 곱하고 결과물을 뱉는 함수를 만들어보자
int MultiplyBy2(int num)
{
	return num * 2;
}

// 두 숫자를 곱해서 결과물을 뱉는 함수를 만들어보자
int MultiplyBy(int a, int b)
{
	return a * b;
}

int main() 
{
	PrintHelloWorld();

	PrintNumber(2);

	int num = 3;
	cout << num << "에 2를 곱한 값은 " << MultiplyBy2(3) << "입니다" << endl;

	int a = 5, b = 6;
	cout << a << "에 " << b << "를 곱한 값은 " << MultiplyBy(a, b) << "입니다" << endl;

	return 0;	// 생략 가능
}