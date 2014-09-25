//headerfiles
#include <iostream>; //include for input/output handling
#include <SDL.h>; //header for SDL functionality

//global variables here
SDL_Window * window;
const int Window_Width = 640; //constant to control window creation
const int Window_Height = 480;
bool running = true;




void InitWindow(int width, int height, bool fullscreen)

{
	window = SDL_CreateWindow(

		"Lab 1", //window title
		SDL_WINDOWPOS_CENTERED, //w cetered
		SDL_WINDOWPOS_CENTERED, //h centered
		width, // width, in pixels
		height, // height, in pixels
		SDL_WINDOW_OPENGL //flags

		);

}



void CleanUp()
{
	SDL_DestroyWindow(window);
	SDL_Quit();
}



//Main Methood entry point
int main(int argc, char * arg[]){

	//init everything - SDLm if it is nonzero we have a problem
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0){
		std::cout << "ERROR SDL_Init" << SDL_GetError() << std::endl;
		return -1;
	}

	InitWindow(Window_Width, Window_Height, false);


	SDL_Event event;

	while (running)
	{
		while (SDL_PollEvent(&event))
		{
			//get event type
			if (event.type == SDL_QUIT || event.type == SDL_WINDOWEVENT_CLOSE)
			{
				//set the running controller boolean to false
				running = false;
			}

		}


	}







	CleanUp();
	return 0;

}