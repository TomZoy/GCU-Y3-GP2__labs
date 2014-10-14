#ifndef Shader_h
#define Shader_h

//add the include statements to support the  loading and compilation of the shaders
#include <GL/glew.h>
#include <SDL_opengl.h>
#include <iostream>
#include <fstream>
#include <string>

enum SHADER_TYPE
{
	VERTEX_SHADER = GL_VERTEX_SHADER,
	FRAGMENT_SHADER = GL_FRAGMENT_SHADER
};

GLuint loadShaderFromFile(const std::string& filename, SHADER_TYPE shaderType);

//load a shader from a char array
GLuint loadShaderFromMemory(const char * pMem, SHADER_TYPE shaderType);

bool checkForCompilerErrors(GLuint shaderProgram);

bool checkForLinkErrors(GLuint program);

#endif