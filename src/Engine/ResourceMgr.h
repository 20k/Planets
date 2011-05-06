#ifndef H_RESOURCEMGR
#define H_RESOURCEMGR
#include <SFML/Graphics.hpp>
#include <map>

class ResourceMgr
{
	public:
		ResourceMgr();
		~ResourceMgr();

		sf::Image& LoadImageFromFile(std::string path);
		
	private:
		//()_()
		//(0.o)
		//(___)
		//() () <---- Bunny will take over the world
		std::map<std::string, sf::Image*> m_imageList;
};

#endif