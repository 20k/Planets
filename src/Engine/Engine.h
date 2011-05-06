#ifndef H_ENGINE
#define H_ENGINE
#include "Global.h"
#include "Entity/Entity.h"
#include <map>
#include <string>
#include <SFML/Graphics.hpp>
#include "ResourceMgr.h"

class Engine
{
	public:
		Engine(const unsigned int &tickRate = 33, const unsigned int &FPS = 60);
		~Engine();

		static Engine* GetSingleton();

		Entity* CreateEntity(const std::string &className);

		bool ShouldTick();
		bool ShouldRender();

		void Tick();
		void Render();

		bool IsRunning();

		void Shutdown();

		ResourceMgr* GetResourceMgr();
		
	private:
		friend class EntityFactory;
		static void AddEntityFactory(EntityFactory* factory);
		void AddEntityFactory2(EntityFactory* factory);

		friend class Entity;
		unsigned int HiEntity(Entity* hiEnt);
		void ByeEntity(Entity* byeEnt);

		unsigned int m_tickRate;
		unsigned int m_FPS;

		std::map<std::string, EntityFactory*> m_entityFactories;
		std::vector<Entity*> m_entList;

		float m_fTimeOfLastTick;
		float m_fTimeOfLastRender;

		sf::RenderWindow *m_app;
		sf::RenderImage *m_renderTex;

		sf::Shader *m_gShader;

		bool m_isRunning;

		ResourceMgr *m_rsrcMgr;
};

#endif