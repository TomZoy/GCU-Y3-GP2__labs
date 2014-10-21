#include  "Texture.h"



GLuint  loadTextureFromFile(const  std::string&  filename)
{
	GLuint  textureID = 0;


	SDL_Surface  *imageSurface = IMG_Load(filename.c_str());

	if (!imageSurface){
		std::cout << "Can'  Load  image  " << filename << "  " << IMG_GetError();
		return  textureID;
	}



	return	textureID;
}