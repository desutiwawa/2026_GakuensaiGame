#include "stdafx.h"
#include "Time.h"


Time::Time()
{
	
	fontRender.SetColor(g_vec4White);
	fontRender.SetScale(1.5f);
	position = { -100.0f,500.0f,0.0f };
	fontRender.SetPosition(position);
	
	
}

Time::~Time()
{
	
}

void Time::Update()
{
	LimitTime -= g_gameTime->GetFrameDeltaTime();
	wchar_t timeText[32]{};
	swprintf(timeText, 32, L"TIME : %.0f", LimitTime);
	fontRender.SetText(timeText);
	
	

}

void Time::Render(RenderContext& rc)
{
	fontRender.Draw(rc);
}