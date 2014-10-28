#ifndef CAMERA_H
#define CAMERA_H

#include  <string>
#include "Component.h"
#include <vector>
#include <glm/glm.hpp>
using glm::mat4;
using glm::vec3;
using glm::vec4;
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <gl/glew.h>

using namespace std;  //to avoid putting std:: in front of every bloody thing ....




class Camera : public Component // !!!OWN SOLUTION!!! to derive from component, so functions can be accessed :P OWN SOLUTION
{
public:
	Camera();
	virtual ~Camera();

	void update();

	void setPosition(vec3 position);
	void setLookAt(vec3 position);
	void setUp(vec3 position);

	void setFOV(float fov);
	void setNearClip(float nearclip);
	void setAspectRatio(float aspratio);
	void setFarClip(float farclip);

	mat4 getViewMatrix();
	mat4 getProjectionMatrix();


protected:

private:

	vec3 m_Position;
	vec3 m_LookAt;
	vec3 m_Up;
	
	float m_FOV;
	float m_NearClip;
	float AspectRatio;
	float m_FarClip;

	mat4 m_ViewMatrix;
	mat4 m_ProjectionMatrix;


};

#endif