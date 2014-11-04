#include "Material.h"
#include "Shader.h"
#include  <string>

using namespace std;  //to avoid putting std:: in front of every bloody thing ....

GLuint m_ShaderProgram;


Material::Material()
{

};


Material::~Material()
{

};

/*
Material();
virtual ~Material();

void destroy(); //as 1.3
bool loadShader(const string& vertexFilename, const string& fragmentFilename);
void bind();
GLint getUniformLocation(const string& name);

*/

void Material::destroy()
{
	glDeleteProgram(m_ShaderProgram);
};

bool loadShader(const string& vertexFilename, const string& fragmentFilename)
{

	m_ShaderProgram = glCreateProgram();


	GLuint vertexShaderProgram = 0;
	std::string	vsPath = vertexFilename;
	vertexShaderProgram = loadShaderFromFile(vsPath, VERTEX_SHADER);

	GLuint fragmentShaderProgram = 0;
	std::string fsPath = fragmentFilename;
	fragmentShaderProgram = loadShaderFromFile(fsPath, FRAGMENT_SHADER);

	glBindAttribLocation(m_ShaderProgram, 0, "vertexPosition");
	glBindAttribLocation(m_ShaderProgram, 1, "vertexTexCoords");
	glBindAttribLocation(m_ShaderProgram, 2, "vertexColour");


	glAttachShader(m_ShaderProgram, vertexShaderProgram);
	glAttachShader(m_ShaderProgram, fragmentShaderProgram);
	glLinkProgram(m_ShaderProgram);
	bool SErr = checkForLinkErrors(m_ShaderProgram);

	//now we can delete	the	VS	&	FS	Programs
	glDeleteShader(vertexShaderProgram);
	glDeleteShader(fragmentShaderProgram);

	return true;

};

void Material::bind()
{
	glUseProgram(m_ShaderProgram);
};

GLint Material::getUniformLocation(const string& name)
{
	// original: 	GLint  MVPLocation	=	glGetUniformLocation(shaderProgram,	"MVP");
	return glGetUniformLocation(m_ShaderProgram, name.c_str()); 
};