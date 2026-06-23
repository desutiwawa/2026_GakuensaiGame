#pragma once
#include "sound/SoundSource.h"
//#include "Level3DRender/LevelRender.h"
//前方宣言･･･こういうクラスがあることだけ伝える→実行までの時間短縮
// includeはクラス～内容全部伝える(コピー)
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

