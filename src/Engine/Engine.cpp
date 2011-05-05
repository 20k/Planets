#include "Engine.h"
#include <cassert>

Engine* onlyEngine = NULL;

std::map<std::string, EntityFactory*> entityFactories;

Engine::Engine(const unsigned int &tickRate, const unsigned int &FPS) : m_tickRate(tickRate), m_FPS(FPS), m_fTime(0), 
	m_entityFactories(entityFactories), m_entList()
{
	assert(onlyEngine==NULL);
	onlyEngine = this;
	entityFactories.clear();
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
	Engine* myEngine = GetSingleton();
	if(myEngine==NULL)
	{
		entityFactories[factory->ClassName()] = factory;
	}
	else
	{
		myEngine->AddEntityFactory2(factory);
	}
}

void Engine::AddEntityFactory2(EntityFactory* factory)
{
	entityFactories[factory->ClassName()] = factory;
}

unsigned int Engine::HiEntity(Entity* hiEnt)
{
	for(unsigned int i = 0; i < m_entList.size(); i++)
	{
		if(m_entList[i] = NULL)
		{
			m_entList[i] = hiEnt;
			return i;
		}
	}
	unsigned int i = m_entList.size();
	i++;
	m_entList.resize(i+254);
	m_entList[i] = hiEnt;
	return i;
}

void Engine::ByeEntity(Entity* byeEnt)
{
	m_entList[byeEnt->GetID()] = NULL;
}

Entity* Engine::CreateEntity(const std::string &className)
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