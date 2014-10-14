#include "Shader.h"


bool checkForCompilerErrors(GLuint shaderProgram)
{
	GLint isCompiled = 0;
	glGetShaderiv(shaderProgram, GL_COMPILE_STATUS, &isCompiled);
	if (isCompiled == GL_FALSE)
	{
		GLint maxLength = 0;
		glGetShaderiv(shaderProgram, GL_INFO_LOG_LENGTH, &maxLength);
		//The maxLength includes the NULL character
		std::string infoLog;
		infoLog.resize(maxLength);
		glGetShaderInfoLog(shaderProgram, maxLength, &maxLength, &infoLog[0]);
		std::cout << "Shader not compiled " << infoLog << std::endl;
		//We don't need the shader anymore.
		glDeleteShader(shaderProgram);
		return true;
	}
	std::cout << "Shader IS compiled!" << std::endl;
	return false;
}

/*• GL_COMPILE_STATUS
–
returns GL_TRUE if compile was successful, or GL_FALSE if not 
• GL_INFO_LOG_LENGTH – returns the number of characters in the log that is generated*/

//Load it from a memory buffer
GLuint loadShaderFromMemory(const char * pMem, SHADER_TYPE shaderType)
{
	GLuint program = glCreateShader(shaderType);
	glShaderSource(program, 1, &pMem, NULL);
	glCompileShader(program);

	if (checkForCompilerErrors(program))
	{
		return	0;
	}

	return program;
}

//Load Shader from File 
GLuint loadShaderFromFile(const std::string&filename,SHADER_TYPE shaderType)
{
	std::string fileContents;
	std::ifstream file;

	file.open(filename.c_str(),	std::ios::in);
	
	if (!file)
	{
		return	0;
	}
	//calculate file size
		if	(file.good())
		{
		file.seekg(0, std::ios::end);
		unsigned long len =	file.tellg();
		file.seekg(std::ios::beg);
		if
			(len==0)
		{
			std::cout <<"File	has no	contents"	<<	std::endl;
			return	0;
		}
		fileContents.resize(len);
		file.read(&fileContents[0],	len);
		file.close();
		GLuint program	= loadShaderFromMemory(fileContents.c_str(),shaderType);
		std::cout << "Shader IS read from file!" << std::endl;
		return	program;
		}


	return	0;
}

bool checkForLinkErrors(GLuint program)
{
	GLint isLinked	=	0;
	glGetProgramiv(program,	GL_LINK_STATUS,	&isLinked);
	if
		(isLinked == GL_FALSE)
	{
		GLint
		
		maxLength =	0;
		glGetProgramiv(program,	GL_INFO_LOG_LENGTH,	&maxLength);
		
		//The maxLength	includes the NULL character
		std::string	infoLog;
		glGetShaderInfoLog(program,	maxLength,	&maxLength,	&infoLog[0]);
		std::cout << "Shader not linked " << infoLog <<	std::endl;
		
		//We don't need	the	shader	anymore.
		glDeleteProgram(program);
		
			return true;
	}
	std::cout << "Shader IS linked!" << std::endl;
	return	false;
}


/*The first line creates the program with specified shader type, the 2nd line copies the character
array  containing the shader source into the shader program, we then compile the shader and
finally  return the compiled program.*/