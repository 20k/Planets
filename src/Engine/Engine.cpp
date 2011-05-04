#include "Engine.h"
#include <cassert>

Engine* onlyEngine = NULL;

Engine::Engine(unsigned int tickRate, unsigned int FPS)
{
	m_tickRate = tickRate;
	m_FPS = FPS;
	onlyEngine = this;
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
		return NULL;
	}
}