#ifndef TRANSFORM_H
#define TRANSFORM_H

#include  <string>
#include "Component.h"
#include <vector>
#include <glm/glm.hpp>
using glm::mat4;
using glm::vec3;
using glm::vec4;
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

using namespace std;  //to avoid putting std:: in front of every bloody thing ....




class Transform : public Component // !!!OWN SOLUTION!!! to derive from component, so functions can be accessed :P OWN SOLUTION
{
public:
	Transform();
	virtual ~Transform();

	virtual void update();  //as 1.2

	vec3 getPosition();
	vec3 getScale();
	vec3 getRotation();

	void setPosition(vec3 position);
	void setScale(vec3 scale);
	void setRotation(vec3 rotation);

	mat4 getModel();

protected:

private:
	vec3 m_Position;
	vec3 m_Scale;
	vec3 m_Rotation;
	mat4 m_Model;

};

#endif