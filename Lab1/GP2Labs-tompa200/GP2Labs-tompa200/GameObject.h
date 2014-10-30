#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include  <string>
#include "Component.h"
#include <vector>

using namespace std;  //to avoid putting std:: in front of every bloody thing ....

class Mesh;
class Material;
class Camera;
class Transform;

/*The  above  snippet  is  an  example  of  'forward  declaration'  of  the  class,  this  allows  
us  to  referen
ce  the  types  without  including  all  the  header */

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

	 Mesh *getMesh();
	 Material *getMaterial();
	 Camera *getCamera();
	 Transform *getTransform();

	 void setMesh(Mesh *mesh);
	 void setMaterial(Material *material);
	 void setCamera(Camera *camera);
	 void setTransform(Transform *m_Transform);


protected:

private:

	string m_Name;
	vector<Component*>m_Components;
	
	//declare pointers to a classes
	Mesh *mesh;
	Material *material;
	Camera *camera;
	Transform *transform;


};

#endif