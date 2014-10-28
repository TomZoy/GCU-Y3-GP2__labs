#include "GameObject.h"

GameObject::GameObject()
{

};


GameObject::~GameObject()
{

};

void GameObject::init()
{
	for (auto iter = m_Components.begin(); iter != m_Components.end(); iter++)
	{
		(*iter)->init();
	}
}

void GameObject::update()
{
	for (auto iter = m_Components.begin(); iter != m_Components.end(); iter++)
	{
		(*iter)->update();
	}
};


void GameObject::render()
{
	for (auto iter = m_Components.begin(); iter != m_Components.end(); iter++)
	{
		(*iter)->render();
	}
};

void GameObject::destroy()
{};

const std::string& getName()
{};

void setName(const std::string& name)
{};

void addCompnent(Component*component) // NOT SURE ABOUT THIS ....
{};