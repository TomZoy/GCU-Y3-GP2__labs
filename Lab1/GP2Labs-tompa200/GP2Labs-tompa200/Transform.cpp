#include "Transform.h"
#include  <string>

using namespace std;  //to avoid putting std:: in front of every bloody thing ....

vec3 m_Position;
vec3 m_Scale;
vec3 m_Rotation;
mat4 m_Model;



Transform::Transform() 
{

};


Transform::~Transform()
{

};


void Transform::update()
{
	if (Component::isActive())
	{

		mat4 translate = glm::translate(translate, m_Position);
		mat4 scale = glm::scale(scale, m_Scale);

		mat4 rotationX = glm::rotate(rotationX, m_Rotation.x, vec3(1.0f, 0.0f, 0.0f));
		mat4 rotationY = glm::rotate(rotationY, m_Rotation.y, vec3(0.0f, 1.0f, 0.0f));
		mat4 rotationZ = glm::rotate(rotationZ, m_Rotation.z, vec3(1.0f, 0.0f, 1.0f));
		mat4 rotation = rotationX*rotationY*rotationZ;

		m_Model = translate*rotation*scale;

	}
};



vec3 getPosition()
{
	return m_Position;
};

vec3 getScale()
{
	return m_Scale;
};

vec3 getRotation()
{
	return m_Rotation;
};


void setPosition(vec3 position)
{
	m_Position = position;
};

void setScale(vec3 scale)
{
	m_Scale = scale;
}

void setRotation(vec3 rotation)
{
	m_Rotation = rotation;
}

mat4 getModel()
{
	return m_Model;
};