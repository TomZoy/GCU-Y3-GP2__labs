#include "Component.h"
#include  <string>

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