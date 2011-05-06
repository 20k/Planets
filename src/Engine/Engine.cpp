#include "Engine.h"
#include <cassert>
#include <SFML/System.hpp>

Engine* onlyEngine = NULL;

std::map<std::string, EntityFactory*> entityFactories;

static sf::Clock globalClock;

Engine::Engine(const unsigned int &tickRate, const unsigned int &FPS) : m_tickRate(tickRate), m_FPS(FPS), m_fTimeOfLastTick(0), 
	m_entityFactories(entityFactories), m_entList(), m_fTimeOfLastRender(0), m_gShader(NULL), m_isRunning(true)
{
	assert(onlyEngine==NULL);
	onlyEngine = this;
	entityFactories.clear();

	//options manager will be used here later
	m_app = new sf::RenderWindow(sf::VideoMode(800, 600, 32U), "Planets");
	m_renderTex = new sf::RenderImage();
	m_renderTex->Create(800, 600);
}

Engine::~Engine()
{
	assert(onlyEngine==this);
	onlyEngine = NULL;
	delete m_app;
	delete m_renderTex;
	for(unsigned int i = 0; i < m_entList.size(); i++)
	{
		if(m_entList[i] != NULL)
		{
			delete m_entList[i];
			m_entList[i] = NULL;
		}
	}
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

bool Engine::ShouldTick()
{
	if(!IsRunning()) return false;

	float fElapsed = globalClock.GetElapsedTime();
	if(fElapsed - m_fTimeOfLastTick >= 1.0f/(float)m_tickRate)
	{
		return true;
	}
	return false;
}

bool Engine::ShouldRender()
{
	if(!IsRunning()) return false;

	float fElapsed = globalClock.GetElapsedTime();
	if(fElapsed - m_fTimeOfLastRender >= 1.0f/(float)m_FPS)
	{
		return true;
	}
	return false;
}

void Engine::Tick()
{
	sf::Event evt;
	m_app->PollEvent(evt);
	switch(evt.Type)
	{
		case sf::Event::Closed:
			Shutdown();
			return;
			break;
	}
	for(unsigned int i = 0; i < m_entList.size(); i++)
	{
		if(m_entList[i] != NULL)
		{
			m_entList[i]->Tick();
		}
	}
}

void Engine::Render()
{
	m_app->Clear();
	m_renderTex->Clear();
	for(unsigned int i = 0; i < m_entList.size(); i++)
	{
		if(m_entList[i] != NULL)
		{
			m_renderTex->Draw(*(m_entList[i]->GetSprite()));
		}
	}
	static sf::Sprite renderSpr(m_renderTex->GetImage());
	if(m_gShader!=NULL)
	{
		m_app->Draw(renderSpr, *m_gShader);
	}
	else
	{
		m_app->Draw(renderSpr);
	}
}

bool Engine::IsRunning()
{
	return m_isRunning;
}

void Engine::Shutdown()
{
	m_isRunning = false;
}