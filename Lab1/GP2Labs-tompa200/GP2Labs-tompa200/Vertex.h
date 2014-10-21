/*
A  header  guard  ensures  that  the  code  in  the  file  between
#define
and
#endif
will  only  get  compiled
THIS SOLUTION IS PLATFORM INDEPENDENT!!!
*/

#ifndef Vertex_h
#define Vertex_h

#include  <glm/glm.hpp>
using  glm::vec2;
using  glm::vec3;
using  glm::vec4;

struct Vertex
{
	//float x, y, z;
	//float r, g, b, a;
	//float x, y, z, r, g, b, a;

	vec3 position;

	vec2 texCoords;

	// ???
	//vec4 colours;
	glm::vec4 colours;


};


/*
struct ColorStruct
{
	float r, g, b, a;
};

enum colors { black, blue, green, cyan, red, purple, yellow, white };
*/
#endif