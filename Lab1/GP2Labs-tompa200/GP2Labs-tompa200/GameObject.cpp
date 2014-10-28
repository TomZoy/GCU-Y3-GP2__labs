#include "GameObject.h"
#include  <string>

using namespace std;  //to avoid putting std:: in front of every bloody thing ....




GameObject::GameObject()
{
	std::string m_Name;
	vector<Component*>m_Components;

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
{
	auto iter = m_Components.begin();
	while (iter != m_Components.end())
	{
		(*iter)->destroy();
		if ((*iter))
		{
			delete (*iter);
			(*iter) = NULL;
			iter = m_Components.erase(iter);
		}
	}
};

const std::string& GameObject::getName()
{
	return m_Name;
};

void GameObject::setName(const std::string& name)
{
	m_Name = name;
};

void GameObject::addCompnent(Component*component) // NOT SURE ABOUT THIS ....
{
	m_Components.push_back(component);
};