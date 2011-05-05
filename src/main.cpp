// Planets.cpp : Defines the entry point for the console application.
//

#include "Entity/Entity.h"
#include "Engine/Engine.h"

int main(int argc, char* argv[])
{
	Engine *myEngine = new Engine();
	Entity *lol = myEngine->CreateEntity("generic");
	return 0;
}

