#include "Mesh.h"
#include  <string>

using namespace std;  //to avoid putting std:: in front of every bloody thing ....

GLuint m_VBO;
GLuint m_EBO;
GLuint m_VAO;
int m_VertexCount;
int m_IndexCount;


Mesh::Mesh()
{

};


Mesh::~Mesh()
{

};

/*
virtual void init();  //as 1.2
virtual void destroy(); //as 1.3
virtual void copyVertexData(int count, int stride, void** data);
virtual void copyIndexData(int count, int stride, void** data);

void bind();

GLuint getIndexCount();
GLuint getVertexCount();

*/



void Mesh::init()
{
	glGenVertexArrays(1, &m_VAO);
	glBindVertexArray(m_VAO);

	//create buffer
	glGenBuffers(1, &m_VBO);
	//Make the new VBO active
	glBindBuffer(GL_ARRAY_BUFFER, m_VBO);


	/*

	glGenBuffers call	takes	in	an	integer	which	specifies the	number	of	buffers	you
	are	going	to	generate	and	the	2nd parameter	is	a	pointer	to	one	or	an	array	of
	integers.

	glBindBuffer call	binds	the	specified	buffer(2nd parameter)	to	the	pipeline(this
	is	a	state!),	the	1st parameter	specifies what	type	of	buffer	we	are	binding(Array
	Buffer)	will	hold	vertices.

	glBufferData copies	data	to	the	bound	buffer,	1st	parameter	is	what	type	of
	buffer	we	are	copying	too,	2nd parameter	is	the	size	of	the	data	we	are	copying
	into	the	buffer,	3rd parameter	is	the	actual	data	we	are	copying,	and the	last
	parameter	is	a	hint	to	OpenGL	on	what	do	with	the	buffer	data,	in	this	case	the
	data	in	the	buffer	will	not	be	updated.

	*/


	//create buffer
	glGenBuffers(1, &m_EBO);
	//Make the EBO active
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_EBO);


}


void Mesh::destroy()
{
	glDeleteBuffers(1, &m_VBO);  // This will delete the number of buffers specified(1st parameter), with the actual buffers being passed in as the 2nd parametr
	glDeleteBuffers(1, &m_EBO);
	glDeleteVertexArrays(1, &m_VAO);
};

void bind()
{
	glBindVertexArray(m_VAO);

	//Make the new VBO active
	glBindBuffer(GL_ARRAY_BUFFER, m_VBO);

	//Make the EBO active
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_EBO);
};

void copyVertexData(int count, int stride, void** data)
{
	//Make the new VBO active
	glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
	//copy vertex data to VBO
	glBufferData(GL_ARRAY_BUFFER, count*stride, data, GL_STATIC_DRAW);

	m_VertexCount = count;

};

void copyIndexData(int count, int stride, void** data)
{
	//Make the EBO active
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_EBO);
	//Copy Index data to the EBO
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, count*stride, data, GL_STATIC_DRAW);

	m_IndexCount = count;
};

GLuint getIndexCount()
{
	return m_IndexCount;
};

GLuint getVertexCount()
{
	return m_VertexCount;
};