#include "Shader.h"


//Load it from a memory buffer
GLuint loadShaderFromMemory(const char * pMem, SHADER_TYPE shaderType)
{
	GLuint program = glCreateShader(shaderType);
	glShaderSource(program, 1, &pMem, NULL);
	glCompileShader(program);
	return program;
}

/*The first line creates the program with specified shader type, the 2nd line copies the character
array  containing the shader source into the shader program, we then compile the shader and
finally  return the compiled program.*/