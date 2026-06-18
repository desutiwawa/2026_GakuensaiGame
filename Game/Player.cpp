#include "stdafx.h"
#include "Player.h"

Player::Player()
{
	//アニメーションのロード
	
	animationClips[enAnimationClip_Idle].Load("Assets/animData/idle.tka");
	animationClips[enAnimationClip_Idle].SetLoopFlag(true);
	animationClips[enAnimationClip_Walk].Load("Assets/animData/walk.tka");
	animationClips[enAnimationClip_Walk].SetLoopFlag(true);
	animationClips[enAnimationClip_Jump].Load("Assets/animData/jump.tka");
	animationClips[enAnimationClip_Jump].SetLoopFlag(false);
	animationClips[enAnimationClip_Run].Load("Assets/animData/run.tka");
	animationClips[enAnimationClip_Run].SetLoopFlag(true);

	modelRender.Init("Assets/modelData/unityChan.tkm", animationClips, enAnimationClip_Num, enModelUpAxisY);

	characterController.Init(25.0f, 75.0f, position);

}

Player::~Player()
{

}

void Player::Update()
{
	//移動処理
	Move();
	//回転処理
	Rotation();
	//ステートの管理
	ManageState();
	//アニメーション再生
	PlayAnimation();
	//更新処理(絵描き)
	modelRender.Update();
}



void Player::Move()
{
	moveSpeed.x = 0.0f;
	moveSpeed.z = 0.0f;
	//スティックの角度所得
	Vector3 stickL;
	stickL.x = g_pad[0]->GetLStickXF();
	stickL.y = g_pad[0]->GetLStickYF();

	Vector3 forward = g_camera3D->GetForward();
	Vector3 right = g_camera3D->GetRight();

	forward.y = 0.0f;
	right.y = 0.0f;
	//スティックの角度に240.0f乗算
	right *= stickL.x * 240.0f;
	forward *= stickL.y * 240.0f;
	//移動速度にスティックの角度を加算
	moveSpeed += right + forward;

	if (g_pad[0]->IsTrigger(enButtonB))
	{
		moveSpeed.x *= 200.0f;
		moveSpeed.z *= 200.0f;
	}

	//落下したときに位置リセット
	if (position.y <= -750.0f)
	{
		position = { 0.0f,0.0f,0.0f };
		characterController.SetPosition(position);
	}
	


	//地面に付いていたら。
	if (characterController.IsOnGround())
	{
		//重力を無くす。
		moveSpeed.y = 0.0f;
		jumpState = 0;
		//Aボタンが押されたら。
		if (g_pad[0]->IsTrigger(enButtonA))
		{
			//ジャンプさせる。
			moveSpeed.y = 240.0f;
			jumpState = 0;
		}
	}
	//地面に付いていなかったら。
	else
	{
		//重力を発生させる。
		moveSpeed.y -= 2.5f;
		
		//追加のジャンプ
		if (jumpState == 0 and g_pad[0]->IsTrigger(enButtonA))
		{
			modelRender.PlayAnimation(enAnimationClip_Idle);
			modelRender.PlayAnimation(enAnimationClip_Jump);
			moveSpeed.y = 240.0f;
			jumpState = 1;

		}
	}

	//キャラクターコントローラーを使って座標を移動させる。
	position = characterController.Execute(moveSpeed, 1.0f / 60.0f);
	//const Vector3& CharacterController::Execute(Vector3 & moveSpeed, float deltaTime)

	//絵描きさんに座標を教える。
	modelRender.SetPosition(position);

}


void Player::Rotation()
{
	if (fabsf(moveSpeed.x) >= 0.001f || fabsf(moveSpeed.z) >= 0.001f)
	{
		//キャラクターの方向を変える。
		rotation.SetRotationYFromDirectionXZ(moveSpeed);
		//絵描きさんに回転を教える。
		modelRender.SetRotation(rotation);
	}
}

//ステート管理。
void Player::ManageState()
{
	//地面に付いていなかったら。
	if (characterController.IsOnGround() == false)
	{
		//ステートを1(ジャンプ中)にする。
		playerState = 1;
		
		//ここでManageStateの処理を終わらせる。
		return;
	}
	//待機
	if (fabsf(moveSpeed.x) <= 0.0f && fabsf(moveSpeed.z) <= 0.0f)
	{
		playerState = 0;
	}
	//ブリンク
	else if (g_pad[0]->IsPress(enButtonB))
	{
		playerState = 3;
	}
	//歩き
	else
	{
		playerState = 2;
	}

}

//アニメーションの再生
void Player::PlayAnimation()
{
	switch (playerState)
	{
		//待機アニメーション
	case 0:
		modelRender.PlayAnimation(enAnimationClip_Idle);
		break;
		//ジャンプアニメーション
	case 1:
		modelRender.PlayAnimation(enAnimationClip_Jump);
		break;
		//歩きアニメーション
	case 2:
		modelRender.PlayAnimation(enAnimationClip_Walk);
		break;
		//ダッシュアニメーション
	case 3:
		modelRender.PlayAnimation(enAnimationClip_Run);
		break;
	}
}

void Player::Render(RenderContext& rc)
{
	//ユニティちゃんの描画
	modelRender.Draw(rc);
}



