#include <iostream>
using namespace std;

int a = 1;
int b = 2;

int main() {
	// ��� ������

// ���� ����
#pragma region ���� ����

	a = b;	// a�� b�� �����ϰ� b�� ��ȯ�϶� -> b�� ��ȯ�ϱ� ������ a = b = 3 ���� �͵� ����

#pragma endregion


// ��Ģ ����
#pragma region ��Ģ ����

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

	// ���� ������
	a++; // a = a + 1l
	++a;
	a--;
	--a;
	// b = a++;  vs  b = ++a;  ->  b�� ���� ��, a ����  vs  a ���� ��, b ����
	
#pragma endregion
}