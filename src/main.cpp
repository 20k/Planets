// Planets.cpp : Defines the entry point for the console application.
//

#include "Entity/Entity.h"
#include "Engine/Engine.h"

class FrogEnt : public Entity
{
	public:
		FrogEnt(std::string className) : Entity(className)
		{
			GetSprite()->SetImage(Engine::GetSingleton()->GetResourceMgr()->LoadImageFromFile("frog.png"));
		}
};

void* CreateFrogEnt()
{
	return (void*)new FrogEnt("frog");
}

static EntityFactory FrogFactory("frog", CreateFrogEnt);

int main(int argc, char* argv[])
{
	Engine *myEngine = new Engine();
	myEngine->CreateEntity("frog")->GetSprite()->SetPosition(400, 300);
	while(myEngine->IsRunning())
	{
		if(myEngine->ShouldTick())
		{
			myEngine->Tick();
		}
		if(myEngine->ShouldRender())
		{
			myEngine->Render();
		}
	}
	delete myEngine;
	return 0;
}

