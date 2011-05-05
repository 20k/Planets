#ifndef H_ENTITY
#define H_ENTITY

#include <SFML/Graphics.hpp>
#include <string>

class Entity
{
	public:
		Entity(const std::string &className = "generic");
		virtual ~Entity();

		sf::Sprite* GetSprite();

		std::string ClassName();

		unsigned int GetID();

		virtual void Tick();
	private:
		sf::Sprite *m_sprite;

		std::string m_className;

		unsigned int m_entID;
};

typedef void* (*CreateEntFunc)();
class EntityFactory
{
	public:
		EntityFactory(std::string className, CreateEntFunc fnc);

		Entity* CreateEntity();

		std::string ClassName();
	private:
		std::string m_className;
		CreateEntFunc m_fnc;
};

#endif