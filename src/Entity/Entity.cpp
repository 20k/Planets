#include "Entity.h"
#include "Engine/Engine.h"

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

std::string Entity::ClassName()
{
	return m_className;
}

void Entity::Tick()
{
}

void* CreateGenericEntity()
{
	return (void*)new Entity("generic");
}

static EntityFactory GenericFactory("generic", CreateGenericEntity);

EntityFactory::EntityFactory(std::string className, CreateEntFunc fnc) : m_className(className), m_fnc(fnc)
{
	Engine *myEngine = Engine::GetSingleton();
	myEngine->AddEntityFactory(this);
}

Entity* EntityFactory::CreateEntity()
{
	return (Entity*)m_fnc();
}

std::string EntityFactory::ClassName()
{
	return m_className;
}