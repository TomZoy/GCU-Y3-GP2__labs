#version 150
out vec4 FragColor;
in  vec2  vertexTexCoordsOut;
uniform  sampler2D texture0;

void main()
{
	// The above  line  using  the  built‐in  GLSL  function  called  texture,
	// this function like most GLSL functions are fairly generic and will do operations
	// dependent  on  what  is  passed  in.  
	// The above  code  shows  how  you  can  carry  out  a  texture  lookup  into  a  
	// 2D Texture,  but  similar  syntax  will  be  used  for  1D  and  3D  textures.  For  more  
	// details  have  a  look  at  the  following  URL https://www.opengl.org/wiki/Sampler_(GLSL)#Basic_texture_access


	FragColor  =  texture(texture0,  vertexTexCoordsOut);
}