#pragma once
#include "sound/SoundSource.h"
//#include "Level3DRender/LevelRender.h"
//前方宣言･･･こういうクラスがあることだけ伝える→実行までの時間短縮
// includeはクラス～内容全部伝える(コピー)
class Player;
class GameCamera;
class BackGround;
class Star;
class Time;
class Game : public IGameObject
{
public:
	Game();
	~Game();
	void Update();

	SpriteRender spriteRender;
	FontRender fontRender;
	Player* player;
	GameCamera* gameCamera;
	BackGround* backGround;
	SoundSource* gameBGM;
	Star* star;
	Time* time;
	/*ModelRender m_modelRender;
	Vector3 m_pos;*/
};

