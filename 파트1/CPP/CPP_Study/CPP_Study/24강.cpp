#include <iostream>
using namespace std;

// �ݺ���

int main() 
{
	// while (���ǽ�) { ��ɹ� }

	// ������ ���� ���, ��� ����
	// ������ ����, Ż��

	int count = 0;

	while (count < 5) 
	{
		cout << "Hello World" << endl;
		count++;
	}

	cout << endl;

	// ���ǰ� ������� �ѹ��� ����� ��, ���ǽ� ����
	do
	{
		cout << "Hello World" << endl;
		count++;
	} while (false);

	cout << endl;

	// ------------------------------------------------

	// for (�ʱ��; ���ǽ�; �����) { ��ɹ� }

	// �ʱ�� �� �ѹ� ����� ��, ���ǽ� -> ��ɹ� -> ����� ������ �ݺ���

	for (int count = 0; count < 5; count++)
	{
		cout << "Hello World" << endl;
	}

	cout << endl;

	// ------------------------------------------------

	// break; continue;

	// break : �ݺ������� ���������� Ű����
	// ����) 5������ ���Ϳ� �ο�� ����
	int round = 1;
	int hp = 100;
	int damage = 10;

	while (true)
	{
		hp -= damage;
			if (hp < 0)
				hp = 0;	// ���� ü�� 0���� ����

		// �ý��� �޼���
		cout << "Round " << round << " ���� ü�� " << hp << endl;

		if (hp == 0)
		{
			cout << "���� óġ!" << endl;
			break;
		}

		if (round == 5)
		{
			cout << "���� ���� ����" << endl;
			break;
		}

		round++;
	}

	// continue : continue ���� ��ɹ� ��ŵ�ϰ� ���� ����Ŭ ����
	// ����) 1~10 ������ Ȧ���� ����ϱ�
	for (int count = 1; count <= 10; count++)
	{
		bool isEven = (count % 2) == 0;

		if (isEven)
			continue;	// ¦���� ��ŵ

		cout << count << endl;
	}
}


