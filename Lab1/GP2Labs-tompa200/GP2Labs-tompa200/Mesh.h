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
#include <gl/glew.h>

using namespace std;  //to avoid putting std:: in front of every bloody thing ....




class Mesh : public Component // !!!OWN SOLUTION!!! to derive from component, so functions can be accessed :P OWN SOLUTION
{
public:
	Mesh();
	virtual ~Mesh();

	virtual void init();  //as 1.2
	virtual void destroy(); //as 1.3
	virtual void copyVertexData(int count,int stride, void** data);
	virtual void copyIndexData(int count, int stride, void** data);

	void bind();

	GLuint getIndexCount();
	GLuint getVertexCount();

protected:

private:
	GLuint m_VBO;
	GLuint m_EBO;
	GLuint m_VAO;
	int m_VertexCount;
	int m_IndexCount;

};

#endif