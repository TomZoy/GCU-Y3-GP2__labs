#ifndef COMPONENT_H
#define COMPONENT_H

#include  <string>

class GameObject;  //forward declaration

class Component
{
public:
	Component();
	virtual ~Component();

	virtual void init();
	virtual void update();
	virtual void render();
	virtual void destroy();


	const std::string& getType(); // & and const combined means -> once set, can't be changed!!!
	void toggleActive();
	bool isActive();

	void setParent(GameObject *parent);
	GameObject *getParent();

protected:
	std::string m_Type;
	bool m_Active;

	GameObject *m_Parent; // pointer to the GameObject

private:
};

#endif