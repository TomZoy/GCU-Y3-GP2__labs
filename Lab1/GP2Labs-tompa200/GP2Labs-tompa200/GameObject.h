#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include  <string>
#include "Component.h"
#include <vector>

using namespace std;  //to avoid putting std:: in front of every bloody thing ....

class GameObject
{
public:
	GameObject();
	virtual ~GameObject();

	 void init();
	 void update();
	 void render();
	 void destroy();

	 const std::string& getName();
	 void setName(const std::string& name);
	 void addCompnent(Component*component); // NOT SURE ABOUT THIS ....


protected:


private:

	string m_Name;
	vector<Component*>m_Components;

};

#endif