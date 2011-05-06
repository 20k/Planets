// Planets.cpp : Defines the entry point for the console application.
//

#include "Entity/Entity.h"
#include "Engine/Engine.h"

int main(int argc, char* argv[])
{
	Engine *myEngine = new Engine();
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

