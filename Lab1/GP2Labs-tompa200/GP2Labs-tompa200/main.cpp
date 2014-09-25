//headerfiles
#include <iostream>; //include for input/output handling
#include <SDL.h>; //header for SDL functionality
#include <SDL_opengl.h>
#include <gl\GLU.h>

//global variables here
SDL_Window * window;
const int Window_Width = 640; //constant to control window creation
const int Window_Height = 480;
bool running = true;
SDL_GLContext glcontext = NULL; ////SDL GL Context




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

//function to clean up resources after the code closes
void CleanUp()
{
	SDL_GL_DeleteContext(glcontext);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

//function to initialise OpenGL
void initOpenGL()
{
	//create openGL context
	glcontext = SDL_GL_CreateContext(window);

	//if it's still empty, something went wrong
	if (!glcontext)
	{
		std::cout << "ERROR CREATING OPENGL CONTEXT" << SDL_GetError() <<
		std::endl;
	}

	//setting up some initial OpenGL states
		//smooth shading
		glShadeModel(GL_SMOOTH);
		//clear the background to black
		glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
		//clear the depht buffer to 1.0
		glClearDepth(1.0f);
		//enable depht testing
		glEnable(GL_DEPTH_TEST);
		//the type of depht test to use
		glDepthFunc(GL_LEQUAL);
		//set perspective correction to best
		glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

}

//function to set/reset viewport
void setViewport(int width, int height)
{
	//sreen ratio
	GLfloat ratio;

	//make sure height is always above 0
	if (height == 0)
	{
		height = 1;
	}

	//calculate screen ratio
	ratio = (GLfloat)width / (GLfloat)height;

	//set-up viewport
	glViewport(0,0,(GLsizei)width, (GLsizei)height);


	//change to project matrix mode
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	//calculate perspective matrix, using glu libary functions
	gluPerspective(45.0f, ratio, 0.1f, 100.0f);

	//switch to Model View
	glMatrixMode(GL_MODELVIEW);

	//reset using identity matrix
	glLoadIdentity();

}




//Main Methood entry point
int main(int argc, char * arg[]){

	//init everything - SDLm if it is nonzero we have a problem
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0){
		std::cout << "ERROR SDL_Init" << SDL_GetError() << std::endl;
		return -1;
	}

	//initialise the app window
	InitWindow(Window_Width, Window_Height, false);

	//Call out InitOpenGL Function
	initOpenGL();
	//Set out Viewport
	setViewport(Window_Width,Window_Height);


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