#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include  <string>
#include <vector>

using namespace std;  //to avoid putting std:: in front of every bloody thing ....

class Mesh;
class Material;
class Camera;
class Transform;
class Component;

/*The  above  snippet  is  an  example  of  'forward  declaration'  of  the  class,  this  allows  
us  to  referen
ce  the  types  without  including  all  the  header */

class GameObject
{
public:
	GameObject();
	~GameObject();

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

	std::vector<Component*> m_Components;
	std::string m_Name;

	Transform *m_Transform;
	Mesh *m_Mesh;
	Material *m_Material;
	Camera *m_Camera;


};

#endif