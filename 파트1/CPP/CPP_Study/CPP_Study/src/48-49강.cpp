#include <iostream>
using namespace std;

// 오늘의 주제 : 연습 문제

int StrLen(const char* str);				// 문제1) 문자열 길이를 출력하는 함수 : strlen(str) 직접 구현해보기
char* StrCpy(char* dest, char* src);		// 문제2) 문자열을 복사하는 함수 : strcpy(dest, src) 직접 구현해보기
char* StrCpy_ptr(char* dest, char* src);	// - 문제2 포인터로 구현
char* StrCat(char* dest, char* src);		// 문제3) 문자열에 문자열을 덧붙이는 함수 : strcat(dest, src) 직접 구현해보기
int StrCmp(char* a, char* b);				// 문제4) 두 문자열을 비교하는 함수 : strcmp(a, b) 직접 구현해보기
char* ReverseStr(char* str);				// 문제5) 문자열을 뒤집는 함수 구현해보기

#pragma warning(disable: 4996)

int main()
{
	const int BUF_SIZE = 100;
	char a[BUF_SIZE] = "Hello";

	// ------------------------------------------------- 문제 1 코드

	cout << strlen(a) << " " << StrLen(a) << endl;

	// ------------------------------------------------- 문제 2 코드

	char b1[BUF_SIZE];
	char b2[BUF_SIZE];
	char b3[BUF_SIZE];

	cout << strcpy(b1, a) << " " << StrCpy(b2, a) << " " << StrCpy_ptr(b3, a) << endl;

	// ------------------------------------------------- 문제 3 코드

	char a1[BUF_SIZE] = "Hello";
	char a2[BUF_SIZE] = "Hello";
	char c1[BUF_SIZE] = "World";
	char c2[BUF_SIZE] = "World";

	cout << strcat(a1, c1) << " " << StrCat(a2, c2) << endl;

	// ------------------------------------------------- 문제 4 코드

	char d1[BUF_SIZE] = "Hella";
	char d2[BUF_SIZE] = "Hello";
	char d3_1[BUF_SIZE] = "aa";
	char d3_2[BUF_SIZE] = "aaa";

	cout << strcmp(a, d1) << " " << StrCmp(a, d1) << " " << StrCmp(a, d2) << " " << StrCmp(d3_1, d3_2) << endl;

	// ------------------------------------------------- 문제 5 코드

	cout << ReverseStr(a) << endl;

	return 0;
}

int StrLen(const char* str)
{
	int len = 0;

	while (str[len] != '\0')
		len++;

	return len;
}

char* StrCpy(char* dest, char* src)
{
	int i = 0;

	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}

	dest[i] = '\0';

	return dest;
}

char* StrCpy_ptr(char* dest, char* src)
{
	char* ret = dest;

	while (*src)
	{
		*dest = *src;
		dest++;
		src++;
	}

	*dest = '\0';

	return ret;
}

char* StrCat(char* dest, char* src)
{
	char* ret = dest;

	while (*dest)
		dest++;

	while (*src)
	{
		*dest = *src;
		dest++;
		src++;
	}

	*dest = '\0';

	return ret;
}

int StrCmp(char* a, char* b)
{
	while (*a || *b)
	{
		if (*a > *b)
			return 1;
		if (*a < *b)
			return -1;
		a++;
		b++;
	}

	return 0;
}

char* ReverseStr(char* str)
{
	int len = strlen(str);

	for (int i = 0; i < len / 2; i++)
	{
		char tmp = *(str + i);
		*(str + i) = *(str + len - i - 1);
		*(str + len - i - 1) = tmp;
	}

	return str;
}