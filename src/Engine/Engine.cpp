#include "Engine.h"
#include <cassert>

Engine* onlyEngine = NULL;

Engine::Engine(unsigned int tickRate, unsigned int FPS) : m_tickRate(tickRate), m_FPS(FPS)
{
	onlyEngine = this;
	assert(onlyEngine==NULL);
}

Engine::~Engine()
{
	assert(onlyEngine==this);
	onlyEngine = NULL;
}

Engine* Engine::GetSingleton()
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

void Engine::AddEntityFactory(EntityFactory* factory)
{
	m_entityFactories[factory->ClassName()] = factory;
}

Entity* Engine::CreateEntity(std::string className)
{
	EntityFactory *factory = m_entityFactories[className];
	if(factory!=NULL)
	{
		return factory->CreateEntity();
	}
	else
	{
		return NULL;
	}
}