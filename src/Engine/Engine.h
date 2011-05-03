#ifndef H_ENGINE
#define H_ENGINE
#include "Global.h"

class Engine
{
	public:
		Engine();
		~Engine();

		static Engine* getSingleton();
};

#endif