#ifndef H_ENTITY
#define H_ENTITY

#include <SFML/Graphics.hpp>
#include <string>

class Entity
{
	public:
		Entity(std::string className = "generic");
		virtual ~Entity();

		sf::Sprite* GetSprite();

		std::string GetClassName();

		virtual void Tick();
	private:
		sf::Sprite *m_sprite;

		std::string m_className;
};

template <class T>
class EntityFactory
{
	public:
		EntityFactory(std::string className);
		Entity* CreateEntity();
	private:
		std::string m_className;
};

#endif