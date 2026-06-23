#pragma once

class Player : public IGameObject
{
public:
	Player();
	~Player();
	void Update();
	void Render(RenderContext& rc);
	void Move();
	void Rotation();
	void ManageState();
	void PlayAnimation();

	ModelRender modelRender;
	Vector3 position;
	enum EnAnimationClip {
		enAnimationClip_Idle,
		enAnimationClip_Walk,
		enAnimationClip_Jump,
		enAnimationClip_Run,
		enAnimationClip_Num,
	};
	AnimationClip animationClips[enAnimationClip_Num];
	CharacterController characterController;
	Vector3 moveSpeed;
	Quaternion rotation;
	Player* player = 0;

	//ダッシュ用のメンバ
	//Vector3 V = { 1.0f,1.0f,1.0f };
	//Vector3 DSmoveSpeed{};
	

	bool isDashing = false;//ダッシュフラグ
	float DashRenge = 0.0f;
	float DashSpeed = 1.0f;
	
	float MAX_Dash = 1.25f;//Dash倍率の最大値
	float A_Dash = 0.01f;  // 1フレームごとのDash倍率加速度
	//Quaternion suraRot = { 0.0f,0.0f,90.0f };


	int playerState = 0;
	int runState = 0;
	int jumpState = 0;
	int starCount = 0;

};

