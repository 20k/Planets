#ifndef H_ENGINE
#define H_ENGINE
#include "Global.h"
#include "Entity/Entity.h"
#include <map>
#include <string>

class Engine
{
	public:
		Engine(unsigned int tickRate = 33, unsigned int FPS = 60);
		~Engine();

		static Engine* GetSingleton();

		Entity* CreateEntity(std::string className);
		
	private:
		friend class EntityFactory;
		void AddEntityFactory(EntityFactory* factory);

		unsigned int m_tickRate;
		unsigned int m_FPS;
		std::map<std::string, EntityFactory*> m_entityFactories;
};

#endif