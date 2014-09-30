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

struct Vertex
{
	//float x, y, z;
	//float r, g, b, a;

	float x, y, z, r, g, b, a;

};

struct ColorStruct
{
	float r, g, b, a;
};

enum colors { black, blue, green, cyan, red, purple, yellow, white };

#endif