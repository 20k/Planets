#ifndef H_ENGINE
#define H_ENGINE
#include "Global.h"
#include "Entity/Entity.h"
#include <map>
#include <string>

class Engine
{
	public:
		Engine(const unsigned int &tickRate = 33, const unsigned int &FPS = 60);
		~Engine();

		static Engine* GetSingleton();

		Entity* CreateEntity(const std::string &className);
		
	private:
		friend class EntityFactory;
		static void AddEntityFactory(EntityFactory* factory);
		void AddEntityFactory2(EntityFactory* factory);

		unsigned int m_tickRate;
		unsigned int m_FPS;
		std::map<std::string, EntityFactory*> m_entityFactories;

		float m_fTime;
};

#endif