#include <iostream>
using namespace std;

unsigned char flag;

// �ѹ� �������� ���� �ٲ��� ���� ����
// constant�� ������ const�� ���� (������ ���ȭ �Ѵٰ� ��)
// const�� �ٿ����� �ʱⰪ�� �ݵ�� �����ؾ� ��

// �׷��� const�� �ٲ��� �ʴ� �б� ���� .rodata�� ���� ���� �³�?
// ��� C++ ǥ�ؿ��� �� �׷��� �϶�� ���� ����
// �׳� �����Ϸ�(VS) �����̶�� ��
const int AIR = 0;
const int STUN = 1;
const int POLYMORPH = 2;
const int INVINCIBLE = 3;

// [������ ����] - ���� ���� �����
// .data (�ʱⰪ�� �ִ� ���)
int a = 2;
// .bss (�ʱⰪ�� ���� ���)
int b; 
// .rodata (�б� ���� ������)
const char* msg = "Hello World";

int main() {

	// [���� ����] - ���� ���� �����
	int c = 3;

	// �ǽ�
	// 0b 0000 [����][����][����][���ߺξ�]

	// ���� ���·� �����
	flag = (1 << INVINCIBLE);	

	// ���� ���¸� �߰��Ѵ�
	flag |= (1 << POLYMORPH);	

	// �������� Ȯ���ϰ� �ʹ�? (�ٸ� ���´� ���� ����)
	bool invincible = ((flag & (1 << INVINCIBLE)) != 0);

	// �����̰ų� ���� �������� Ȯ���ϰ� �ʹٸ�?
	bool mask = (1 << INVINCIBLE) | (1 << STUN);
	bool stunnedOrInvincible = ((flag & mask) != 0);

}