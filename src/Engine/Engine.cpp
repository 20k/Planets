#include "Engine.h"
#include <cassert>

Engine* onlyEngine = NULL;

Engine::Engine()
{
	assert(onlyEngine==NULL);
}

Engine::~Engine()
{
	assert(onlyEngine==this);
	onlyEngine = NULL;
}

Engine* Engine::getSingleton()
{
	if(onlyEngine)
	{
		return onlyEngine;
	}
	else
	{
		onlyEngine = new Engine();
		return onlyEngine;
	}
}