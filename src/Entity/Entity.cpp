#include "Entity.h"
#include "Engine/Engine.h"

Entity::Entity(const std::string &className) : m_className(className), m_sprite(new sf::Sprite())
{
	Engine* myEngine = Engine::GetSingleton();
	m_entID = myEngine->HiEntity(this);
}

Entity::~Entity()
{
	Engine::GetSingleton()->ByeEntity(this);
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

unsigned int Entity::GetID()
{
	return m_entID;
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
	Engine::AddEntityFactory(this);
}

Entity* EntityFactory::CreateEntity()
{
	return (Entity*)m_fnc();
}

std::string EntityFactory::ClassName()
{
	return m_className;
}