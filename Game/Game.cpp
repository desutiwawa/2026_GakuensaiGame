#include "stdafx.h"
#include "Game.h"
#include "Player.h"
#include "GameCamera.h"
#include "BackGround.h"
#include "sound/SoundEngine.h"
#include "Star.h"
#include "Time.h"
#include "GameClear.h"

Game::Game()
{
	//プレイヤーオブジェクト作成
	player = NewGO<Player>(0, "player");
	//ゲームカメラオブジェクト作成
	gameCamera = NewGO<GameCamera>(0, "gamecamera");
	//背景オブジェクト作成
	backGround = NewGO<BackGround>(0);

	Star* star1 = NewGO<Star>(0, "star");
	star1->position = { 100.0f,150.0f,-200.0f };
	star1->firstPosition = star1->position;

	Star* star2 = NewGO<Star>(0, "star");
	star2->position = { 1000.0f,150.0f,-200.0f };
	star2->firstPosition = star2->position;

	Star* star3 = NewGO<Star>(0, "star");
	star3->position = { 100.0f,250.0f,400.0f };
	star3->firstPosition = star3->position;

	Star* star4 = NewGO<Star>(0, "star");
	star4->position = { 2300.0f,50.0f,-200.0f };
	star4->firstPosition = star4->position;

	Star* star5 = NewGO<Star>(0, "star");
	star5->position = { 2700.0f,450.0f,400.0f };
	star5->firstPosition = star5->position;

	Star* star6 = NewGO<Star>(0, "star");
	star6->position = { 3700.0f,150.0f,-400.0f };
	star6->firstPosition = star6->position;




	//UI
	//Time
	Time* time = NewGO<Time>(0, "time");



}

Game::~Game()
{
	//プレイヤー削除
	DeleteGO(player);
	//ゲームカメラ削除
	DeleteGO(gameCamera);
	//ゲーム内BGM削除
	DeleteGO(gameBGM);
	//背景削除
	DeleteGO(backGround);
	//星削除
	for (auto star : FindGOs<Star>("star"))
	{
		DeleteGO(star);
	}
}





void Game::Update()
{
	player->starCount;
	if (player->starCount >= 6)
	{
		NewGO<GameClear>(0, "gameClear");
		DeleteGO(this);
		player->starCount = 0;
	}



	// g_renderingEngine->DisableRaytracing();
	//m_modelRender.Update();
}

