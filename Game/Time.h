#pragma once

class Time:public IGameObject
{
public:
	Time();
	~Time();
	void Update();
	void Render(RenderContext& rc);
	FontRender fontRender;
	Vector3 position;
	float LimitTime = 60.0f;

	
};

