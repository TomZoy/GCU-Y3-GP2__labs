#include "Component.h"
#include  <string>
#include "GameObject.h"

GameObject *m_Parent; // pointer to the GameObject

Component::Component()
{
	m_Type = "Component";
	m_Active = true;




}

void Component::init()
{}

void Component::update()
{}

void Component::render()
{}

void Component::destroy()
{}

const std::string& Component::getType()
{
	return m_Type;
}

bool Component::isActive()
{
	return m_Active;
}


Component::~Component()
{

}

GameObject *getParent()
{
	return m_Parent;
};

void setParent(GameObject *parent)
{
	m_Parent = parent;
};