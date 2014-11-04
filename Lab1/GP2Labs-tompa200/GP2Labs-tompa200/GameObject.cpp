#include "GameObject.h"
#include  <string>

#include "Mesh.h"
#include "Material.h"
#include "Camera.h"
#include "Transform.h"
#include "Component.h"

using namespace std;  //to avoid putting std:: in front of every bloody thing ....




GameObject::GameObject()
{
	m_Name = "GameObject";


	m_Transform = NULL;


	m_Mesh = NULL;
	m_Material = NULL;
	m_Camera = NULL;


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




void GameObject::setTransform(Transform *t)
{
	m_Transform = t;  //NOT WORKING - WHAT'S m_Transform ???
	addCompnent(t);
}

Transform *GameObject::getTransform()
{
	return m_Transform;  // DONT REALLY SEE WHERE THIS SHOULD COMMING FROM ...
}

void GameObject::setMesh(Mesh *mesh)
{
	m_Mesh = mesh;
	addCompnent(mesh);
}

void GameObject::setMaterial(Material *material)
{
	m_Material = material;
	addCompnent(material);
}

void GameObject::setCamera(Camera *camera)
{
	m_Camera = camera;
	addCompnent(camera);
}


Mesh * GameObject::getMesh()
{
	return m_Mesh;
}


Material *  GameObject::getMaterial()
{
	return m_Material;
}


Camera * GameObject::getCamera()
{
	return m_Camera;
}