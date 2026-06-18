#include "stdafx.h"
#include "GameClear.h"
#include "Title.h"


GameClear::GameClear()
{
	//画像読み込み
	spriteRender.Init("Assets/sprite/gameclear.dds", 1920.0f, 1080.0f);

}

GameClear::~GameClear()
{

}

void GameClear::Update()
{
	//Aボタンが押されたら
	if (g_pad[0]->IsTrigger(enButtonA))
	{
		//タイトルのオブジェクトを作る
		NewGO<Title>(0, "title");
		//自分を削除
		DeleteGO(this);
	}
}

//描画処理
void GameClear::Render(RenderContext& rc)
{
	spriteRender.Draw(rc);
}