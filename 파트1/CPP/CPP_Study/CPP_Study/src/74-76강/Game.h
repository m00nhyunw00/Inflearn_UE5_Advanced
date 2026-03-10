#pragma once

// 전방 선언
class Player;
class Field;

class Game
{
public:
	Game();
	~Game();

	void Init();
	void Update();

	void CreatePlayer();

private:
	Player* _player;
	Field* _field;
};