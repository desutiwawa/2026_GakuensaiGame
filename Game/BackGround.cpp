#include "stdafx.h"
#include "BackGround.h"

BackGround::BackGround()
{
	modelRender.Init("Assets/modelData/stage/stage.tkm");
	modelRender.Update();
	physicsStaticObject.CreateFromModel(modelRender.GetModel(), modelRender.GetModel().GetWorldMatrix());

	//PhysicsWorld::GetInstance()->EnableDrawDebugWireFrame();
}

BackGround::~BackGround()
{

}

void BackGround::Render(RenderContext& rc)
{
	modelRender.Draw(rc);
}



