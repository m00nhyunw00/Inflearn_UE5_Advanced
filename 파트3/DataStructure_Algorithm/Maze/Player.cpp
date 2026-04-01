#include "pch.h"
#include "Player.h"
#include "Board.h"

void Player::Init(Board* board)
{
	_pos = board->GetEnterPos();
	_board = board;

	Pos pos = _pos;	// 시뮬레이션은 위한 임시 좌표
					// 실제로 Player가 움직이지는 않음

	// 목적지 도착하기 전에는 계속 실행
	Pos dest = board->GetExitPos();

	while (pos != dest)
	{
		// 1) 현재 바라보는 방향을 기준으로 오른쪽으로 갈 수 있는지 확인
		if ()
		{

		}
		// 2) 현재 바라보는 방향을 기준으로 직진할 수 있는지 확인
	}
}

void Player::Update(uint64 deltaTick)
{

}
