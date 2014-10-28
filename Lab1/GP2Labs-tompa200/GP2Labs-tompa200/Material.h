#ifndef MATERIAL_H
#define MATERIAL_H

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




class Material : public Component // !!!OWN SOLUTION!!! to derive from component, so functions can be accessed :P OWN SOLUTION
{
public:
	Material();
	virtual ~Material();

	 void destroy(); //as 1.3

	 bool loadShader(const string& vertexFilename, const string& fragmentFilename);

	 void bind();

	 GLint getUniformLocation(const string& name);




protected:

private:
	GLuint m_ShaderProgram;
};

#endif