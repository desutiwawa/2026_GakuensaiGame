#pragma once
#include "sound/SoundSource.h"
//#include "Level3DRender/LevelRender.h"

class Player;
class GameCamera;
class BackGround;
class Star;
class Game : public IGameObject
{
public:
	Game();
	~Game();
	void Update();

	Player* player;
	GameCamera* gameCamera;
	BackGround* backGround;
	SoundSource* gameBGM;
	Star* star;
	/*ModelRender m_modelRender;
	Vector3 m_pos;*/
};

