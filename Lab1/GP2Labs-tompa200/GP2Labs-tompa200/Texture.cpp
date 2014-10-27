#include  "Texture.h"
#include <SDL_ttf.h>

int  internalFormat;


GLuint  loadTextureFromFile(const  std::string&  filename)
{
	GLuint  textureID = 0;


	SDL_Surface  *imageSurface = IMG_Load(filename.c_str());

	if (!imageSurface){
		std::cout << "Can'  Load  image  " << filename << "  " << IMG_GetError();
		return  textureID;
	}

	/*
	he  first  line  gets  the  number  of  bytes  per  pixel(https://wiki.libsdl.org/SDL_PixelFormat#bytesperpixel),ű
	this  determines what  the  surface  contains.  If  the  value  is  4  then  that  means  the  surface  contains  
	red,  green,  blue  and  alpha  channels.  If  the  value  is  3  then  it  means  the  surface  only  contains  red,  green  and  blue  ch
	*/

	GLint nOfColors = imageSurface->format->BytesPerPixel;
	
	GLenum texture_format = GL_RGB;
	GLenum internalFormat = GL_RGB8;


	if (nOfColors == 4)          //  contains  an  alpha  channel
	{
		if (imageSurface->format->Rmask == 0x000000ff)
		{
			texture_format = GL_RGBA;
			internalFormat = GL_RGBA8;

		}
		else
		{
			texture_format = GL_BGRA;
			internalFormat = GL_RGBA8;

		}
	}

	else  if (nOfColors == 3)          //  no alpha  channel
	{
		if (imageSurface->format->Rmask == 0x000000ff)
		{
			texture_format = GL_RGB;
			internalFormat = GL_RGB8;
		}

		else
		{
			texture_format = GL_BGR;
			internalFormat = GL_RGB8;
		}
	}
	else  {
		std::cout << "warning:  the  image  is  not  truecolor..    this  will  probably  break";
		//  this error  should  not  go  unhandled
	}

	//This  will  generate  one  OpenGL  texture  and  then  bind  it  as  the  active texture
	glGenTextures(1, &textureID);
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, textureID);



	/*
	The  parameters  of  the  function  as  follows:
	1. Target,  the  type  of  texture  we  are  working  with.  In  this  case  a  2D  Texture
	2. Is  the  mip-­‐map  level  of  the  texture  we  are  working  with,  in  this  case  0  is  the  first  level
	3. The  format  of  the  OpenGL  texture,  this  was  worked  out  in  our  if...else  statement
	4. The  width  of  the  texture
	5. The  height  of  the  texture
	6. Border,  this  value  should  always  be  zero(unused)
	7. The  format  of  the  pixels  we  are  passing  in(SDL  surface  pixels  in  our  case)
	8. The  data  type  of  the  pixels(in  this  case  unsigned  bytes  0  -­‐255  for  each  component  of  the  pixel)
	9. The  actual  pixel  data,  notethat  this  comes  from  the  SDL  Surface
	These  parameters  for  this  function  are  explained  in  more  detail  at  following  URL  
	https://www.opengl.org/sdk/docs/man3/xhtml/glTexImage2D.xm

	*/

	glTexImage2D(GL_TEXTURE_2D, 0, texture_format, imageSurface->w, imageSurface->h, 0, texture_format, GL_UNSIGNED_BYTE, imageSurface->pixels);

	/*
	The  first  two  lines  setup  Linear  filtering  on  the  texture,  the  next  two  lines  set  the  
	texture  addressing  mode to  CLAMP and  the  last  line  generates  Mipmaps  for  the  
	texture (ref  Texturing  Lecture  in  Week)
	*/

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	
	glGenerateMipmap(GL_TEXTURE_2D);

	SDL_FreeSurface(imageSurface);
	return	textureID;
}

GLuint loadTextureFromFont(const std::string& fontFilename, int pointSize, const std::string& text)
{
	GLuint TextureID = 0;

	TTF_Font*font = TTF_OpenFont(fontFilename.c_str(), pointSize);

	if (!font)
	{
		std::cout << "Unable to load font " << fontFilename << TTF_GetError();
		return TextureID;
	}

	SDL_Surface*textSurface = TTF_RenderText_Blended(font, text.c_str(), { 255, 255, 255 });

	return TextureID;
}