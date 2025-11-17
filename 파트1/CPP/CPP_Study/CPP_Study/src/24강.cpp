#include <iostream>
using namespace std;

// 반복문

int main() 
{
	// while (조건식) { 명령문 }

	// 조건이 참인 경우, 계속 실행
	// 거짓인 순간, 탈출

	int count = 0;

	while (count < 5) 
	{
		cout << "Hello World" << endl;
		count++;
	}

	cout << endl;

	// 조건과 상관없이 한번은 실행된 후, 조건식 실행
	do
	{
		cout << "Hello World" << endl;
		count++;
	} while (false);

	cout << endl;

	// ------------------------------------------------

	// for (초기식; 조건식; 제어식) { 명령문 }

	// 초기식 딱 한번 실행된 후, 조건식 -> 명령문 -> 제어식 순서로 반복됨

	for (int count = 0; count < 5; count++)
	{
		cout << "Hello World" << endl;
	}

	cout << endl;

	// ------------------------------------------------

	// break; continue;

	// break : 반복문에서 빠져나가는 키워드
	// 예제) 5라운드제 몬스터와 싸우는 게임
	int round = 1;
	int hp = 100;
	int damage = 10;

	while (true)
	{
		hp -= damage;
			if (hp < 0)
				hp = 0;	// 음수 체력 0으로 보정

		// 시스템 메세지
		cout << "Round " << round << " 몬스터 체력 " << hp << endl;

		if (hp == 0)
		{
			cout << "몬스터 처치!" << endl;
			break;
		}

		if (round == 5)
		{
			cout << "제한 라운드 종료" << endl;
			break;
		}

		round++;
	}

	// continue : continue 이후 명령문 스킵하고 다음 사이클 시작
	// 예제) 1~10 사이의 홀수만 출력하기
	for (int count = 1; count <= 10; count++)
	{
		bool isEven = (count % 2) == 0;

		if (isEven)
			continue;	// 짝수면 스킵

		cout << count << endl;
	}
}


