#ifndef H_ENGINE
#define H_ENGINE
#include "Global.h"
#include "Entity/Entity.h"

class Engine
{
	public:
		Engine(unsigned int tickRate = 33, unsigned int FPS = 60);
		~Engine();

		static Engine* getSingleton();

	private:
		unsigned int m_tickRate;
		unsigned int m_FPS;
};

#endif