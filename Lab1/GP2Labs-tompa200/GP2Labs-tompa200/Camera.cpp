#include "Camera.h"

#include "GameObject.h"
#include "Transform.h"
#include "Component.h"

#include  <string>

using namespace std;  //to avoid putting std:: in front of every bloody thing ....

vec3 m_Position;
vec3 m_LookAt;
vec3 m_Up;

float m_FOV;
float m_NearClip;
float m_AspectRatio;
float m_FarClip;

mat4 m_ViewMatrix;
mat4 m_ProjectionMatrix;

/*
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
*/

Camera::Camera()
{

};


Camera::~Camera()
{

};

void update()
{
	m_Position = m_Parent->getTransform()->getPosition();
	// m_Position = Component::getParent ??? instead?

	m_ProjectionMatrix = glm::perspective(45.0f, (float)WINDOW_WIDTH / (float)WINDOW_HEIGHT, 0.1f, 100.0f);
	m_ViewMatrix = glm::lookAt(vec3(0.0f, 0.0f, 10.0f), vec3(0.0f, 0.0f, 0.0f), vec3(0.0f, 1.0f, 0.0f));
	worldMatrix = glm::translate(mat4(1.0f), vec3(0.0f, 0.0f, 0.0f));
};

void setPosition(vec3 position)
{
	m_Position = position;
};

void setLookAt(vec3 lokkat)
{
	m_LookAt = lokkat;
};

void setUp(vec3 up)
{
	m_Up = up;
};

void setFOV(float fov)
{
	m_FOV = fov;
};

void setNearClip(float nearclip)
{
	m_NearClip = nearclip;
};

void setAspectRatio(float aspratio)
{
	m_AspectRatio = aspratio;
};

void setFarClip(float farclip)
{
	m_FarClip = farclip;
};

mat4 getViewMatrix()
{
	return m_ViewMatrix;
};

mat4 getProjectionMatrix()
{
	return m_ProjectionMatrix;
};