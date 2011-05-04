#include "Entity.h"

Entity::Entity(std::string className) : m_className(className)
{
	m_sprite = new sf::Sprite();
}

Entity::~Entity()
{
	delete m_sprite;
}

sf::Sprite* Entity::GetSprite()
{
	return m_sprite;
}

std::string Entity::GetClassName()
{
	return m_className;
}

void Entity::Tick()
{
}

static EntityFactory<Entity> GenericFactory("generic");

template <class T>
EntityFactory<T>::EntityFactory(std::string className)
{
	m_className = className;
}

template <class T>
Entity* EntityFactory<T>::CreateEntity()
{
	return static_cast<Entity*>(new T(className));
}