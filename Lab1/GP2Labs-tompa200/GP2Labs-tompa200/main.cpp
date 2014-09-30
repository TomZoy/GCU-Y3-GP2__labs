//headerfiles
#include <iostream> //include for input/output handling
#include <gl/glew.h>
#include <SDL.h> //header for SDL functionality
#include <SDL_opengl.h>
#include <gl\GLU.h>
#include <time.h>
#include "Vertex.h" //"" for includes from the same directory


//test

//global variables here
SDL_Window * window;
const int Window_Width = 640; //constant to control window creation
const int Window_Height = 480;
bool running = true;
SDL_GLContext glcontext = NULL; ////SDL GL Context
double fallSpeed = 5.00;
double rotateSpeed = 1000.00;
bool rotate = false;

ColorStruct Color[] = 
{
	{ 0.0f, 0.0f, 0.0f, 1.0f },
	{ 0.0f, 0.0f, 1.0f, 1.0f },
	{ 0.0f, 1.0f, 0.0f, 1.0f },
	{ 0.0f, 1.0f, 1.0f, 1.0f },
	{ 1.0f, 0.0f, 0.0f, 1.0f },
	{ 1.0f, 0.0f, 1.0f, 1.0f },
	{ 1.0f, 1.0f, 0.0f, 1.0f },
	{ 1.0f, 1.0f, 1.0f, 1.0f }
};


/* WHERE THE TRIANGLES ARE DEFINED*/

//3 value RGB colour + 3 value XYZ coordinates
float TR1[3][6] = {
	1.0f, 0.0f, 0.0f, -1.0f, 1.0f, 0.0f,
	0.0f, 1.0f, 0.0f, -1.0f, -1.0f, 0.0f,
	0.0f, 0.0f, 1.0f, 1.0f, -1.0f, 0.0f
};

float TR2[3][6] = {
	1.0f, 0.0f, 1.0f, 0.0f, 0.5f, 0.0f,
	0.0f, 1.0f, 0.0f, 1.0f, 0.5f, 0.0f,
	0.0f, 1.0f, 1.0f, 1.0f, -0.5f, 0.0f
};



//VERSION 1 - Triangle
/*

		float triangleData[]=
		{
			0.0f, 1.0f, 0.0f, //Top
			-1.0f, -1.0f, 0.0f, //bottom left
			1.0f, -1.0, 0.0f, //bottom right
			//2.0f,0.0f,0.0f
		};
*/


//VERSION 2 - Triangle
/* 

Vertex triangleData[]
{
	{
		0.0f,1.0f,0.0f,			 //x, y, z
		1.0f,0.0f,0.0f,1.0f		//r, g, b, a
	},

	{
		-1.0f, -1.0f, 0.0f,			 //x, y, z
		0.0f, 1.0f, 0.0f, 1.0f		//r, g, b, a
	},

	{
		1.0f, -1.0f, 0.0f,			 //x, y, z
		0.0f, 0.0f, 1.0f, 1.0f		//r, g, b, a
	}

};
*/


//Version 3 - CUBE 

float getVertex(int index)
{
	return triangleData[index];

/*	return triangleData[index].y;
	return triangleData[index].z;
	return triangleData[index].r;
	return triangleData[index].g;
	return triangleData[index].b;
	return triangleData[index].a;
	*/
	}

Vertex triangleData[] =
{
	//Front face

	{ // 1. top left
		-0.5f, 0.5f, 0.5f,
		1.0f, 0.0f, 1.0f, 1.0f
		
	},
	
	{ // 2. bottom left
		-0.5f, -0.5f, 0.5f,
		1.0f, 1.0f, 0.0f, 1.0f
		
	},

	{ // 3. bottom right
		0.5f, -0.5f, 0.5f,
		0.0f, 1.0f, 1.0f, 1.0f
		
	},

	{ // 4. top right
		0.5f, 0.5f, 0.5f,
		1.0f, 0.0f, 1.0f, 1.0f
		
	},

	{ // 5. (1.) top left
		//-0.5f, 0.5f, 0.5f,
		//1.0f, 0.0f, 1.0f, 1.0f

		/*
		triangleData[0].x, triangleData[0].y, triangleData[0].z,
		triangleData[0].r, triangleData[0].g, triangleData[0].b, triangleData[0].a
		*/
		getVertex(0);
	},

	{ // 6. (3.) bottom right
		//0.5f, -0.5f, 0.5f,
		//0.0f, 1.0f, 1.0f, 1.0f
		
		triangleData[2].x, triangleData[2].y, triangleData[2].z,
		triangleData[2].r, triangleData[2].g, triangleData[2].b, triangleData[2].a
	},


	//BACK face
	
	{ // 7. top left
		-0.5f, 0.5f, -0.5f,
		1.0f, 0.0f, 0.0f, 1.0f
	},

	{ // 8. bottom left
		-0.5f, -0.5f, -0.5f,
		1.0f, 1.0f, 1.0f, 1.0f
	},

	{ // 9. bottom right
		0.5f, -0.5f, -0.5f,
		0.0f, 1.0f, 1.0f, 1.0f
	},

	{ // 10. top right
		0.5f, 0.5f, -0.5f,
		0.0f, 0.0f, 1.0f, 1.0f
	},

	{ // 11. (1.) top left
		//-0.5f, 0.5f, 0.5f,
		//1.0f, 0.0f, 1.0f, 1.0f

		triangleData[6].x, triangleData[6].y, triangleData[6].z,
		triangleData[6].r, triangleData[6].g, triangleData[6].b, triangleData[6].a

	},

	{ // 12. (3.) bottom right
		//0.5f, -0.5f, 0.5f,
		//0.0f, 1.0f, 1.0f, 1.0f

		triangleData[8].x, triangleData[8].y, triangleData[8].z,
		triangleData[8].r, triangleData[8].g, triangleData[8].b, triangleData[8].a
	},


	

};

GLuint triangleVBO;


void InitWindow(int width, int height, bool fullscreen)

{
	window = SDL_CreateWindow(

		"Lab 2", //window title
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
	glDeleteBuffers(1, &triangleVBO);  // This will delete the number of buffers specified(1st parameter), with the actual buffers being passed in as the 2nd parametr
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


	//init GLEW

	GLenum err = glewInit();
	if (GLEW_OK != err)
	{
		/*Problem: glewInt failed to, something is wrong*/
		std::cout << "Error: " << glewGetErrorString(err) << std::endl;
	}



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
	glViewport(0, 0, (GLsizei)width, (GLsizei)height);


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

// OLD function to draw the triangle
/*

void DrawTriangle(float Tri[3][6])
{
	//switch to ModelView
	glMatrixMode(GL_MODELVIEW);
	//reset using the identity matrix
	glLoadIdentity();
	//translate to -5f on Z axis
	glTranslatef(0.0f, 0.0f, -5.0f);

	//begin drawing the triangles
	glBegin(GL_TRIANGLES);

	for (int i = 0; i < 3; i++)
	{
		glColor3f(Tri[i][0], Tri[i][1], Tri[i][2]); //colour of the vertices
		glVertex3f(Tri[i][3], Tri[i][4], Tri[i][5]); //top/left/rigt
	}
	glEnd();

	

	glMatrixMode(GL_MODELVIEW);
	This switches the matrix mode state to the Model View mode, this mode is used to position our vertices in 3D space. We will often carry out a rotation, translation or scaling after this call.

	glLoadIdentity();
	This will push the identity matrix onto the current matrix(in this case ModelView , see above).  The identity matrix is like setting a value to 1(a gross simplification but will do for now).

	glTranslatef(0.0f,0.0f,-5.0f);
	Will push a translation matrix  onto the current matrix, in this case it will translate the current matrix -5.0f units.

	glBegin(GL_TRIANGLES);
	This begins the drawing process, we pass in the primitive type we are going to draw.

	glColor(1.0f,0.0f,0.0f);
	This sets the colour of the vertices where each component is a floating point number(0.0f � 1.0f) and represents red, green and blue.

	glVertex3f(1.0f,0.0f,0.0f);
	This specifies a Vertex using an x. y and z positional values.

	glEnd();
	This ends the drawing process

	

}
*/


void DrawTriLab2(int NoOfTri)
{
	for (int i = 0; i < NoOfTri; i++)
	{
		//reset using identity matrix
		glLoadIdentity();

		//enable 3D space
		gluLookAt(0.0,0.0,0.0,0.0,0.0,-1.0f,0.0,1.0f,0.0);
		/*
			1st three parameters: is the camera position in 3D space(x, y ,z)
			2nd set of three parameters: the centre(look at point) in 3D space(x, y, z)
			Last set of three parameter is the Up axis of the camera
		*/



		//translate
		glTranslatef((-2.0f+i*2), 0.0f, -6.0f);

		//actually draw the triangle, giving the number of vertecies provided
		glDrawArrays(GL_TRIANGLES, 0, sizeof(triangleData) / (sizeof(Vertex)));

	}
}




//function to draw
void render()
{
	//set the clear colour
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

	//clear the colour and depth-buffer
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	
	//LAB 1 TASK DRAW 
	/*
	DrawTriangle(TR1);
	DrawTriangle(TR2);
	*/

	/*
	LAB 2 TAKS DRAW START 
	*/

	//Make the new VBO active. Repeat here as sanity check (may have changed since inisialisation)
	glBindBuffer(GL_ARRAY_BUFFER,triangleVBO);

	//Establish its 3 coordinates per vertex with zero stride (pace between elements) in array and contaon floating point numbers
	glVertexPointer(3, GL_FLOAT, sizeof(Vertex), NULL);


	//to slise up the buffer
	glColorPointer(4,GL_FLOAT,sizeof(Vertex),(void**)(3*sizeof(float)));

	//Establish array contains vertecies (not normals, colours, texture coords etc)
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);


	//switch to model view
	glMatrixMode(GL_MODELVIEW);

	DrawTriLab2(3);

	//PULLED OUT AS A FUNCTION
	/* 
			//reset using identity matrix
			glLoadIdentity();

			//translate
			glTranslatef(0.0f,0.0f,-6.0f);

			//actually draw the triangle, giving the number of vertecies provided
			glDrawArrays(GL_TRIANGLES, 0, sizeof(triangleData) / (3 * sizeof(float)));
	*/


	/* LAB 2 END */

	//requirte to swap the back and front buffer
	SDL_GL_SwapWindow(window);

}

//custom animation
/*
void MoveTriangle() //the "animation"
{
	TR2[0][4] -= 0.1f;
	TR2[1][4] -= 0.1f;
	TR2[2][4] -= 0.1f;

	// initialize random seed: 
	srand(time(NULL));

	if (TR2[0][4] < -2.0f)
	{
		//reset to the top
		TR2[0][4] = 4.0f;
		TR2[1][4] = 4.0f;
		TR2[2][4] = 3.0f;

		//randomise the colour

		for (int h = 0; h < 3; h++)
		{
			for (int i = 0; i < 3; i++)
			{
				TR2[i][h] = ((rand() % 100 + 1) / 100.00);
				// std::cout << "colour randomised = " << TR2[i][h] << ", "; //DEBUG INFO
			}
		}
	}
}


*/



//function to update game state
void update()
{

}

void initGeometry()
{
	//create buffer
	glGenBuffers(1, &triangleVBO);
	//Make the new VBO active
	glBindBuffer(GL_ARRAY_BUFFER, triangleVBO);
	//copy vertex data to VBO
	glBufferData(GL_ARRAY_BUFFER, sizeof(triangleData), triangleData, GL_STATIC_DRAW);

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
	initGeometry();
	//Set out Viewport
	setViewport(Window_Width, Window_Height);


	SDL_Event event;


	double tFall = 0.0; //timer for the game loop for falling
	double tRotate = 0.0; //timer for the game loop for rotation



	// --- GAME LOOP START --- //
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

			/*EXPERIMENTAL BEGGINS*/

			switch (event.type){
				/* Look for a keypress */
			case SDL_KEYDOWN:
				/* Check the SDLKey values and move change the coords */
				switch (event.key.keysym.sym){
				case SDLK_LEFT:
					TR2[0][3] -= 0.1f;
					TR2[1][3] -= 0.1f;
					TR2[2][3] -= 0.1f;
					break;
				case SDLK_RIGHT:
					TR2[0][3] += 0.1f;
					TR2[1][3] += 0.1f;
					TR2[2][3] += 0.1f;
					break;
				case SDLK_UP:
					TR2[1][4] += 0.1f;
					break;
				case SDLK_DOWN:
					TR2[1][4] -= 0.1f;
					break;

				default:
					break;
				}
			}


			/*EXPERIMENTAL ENDS*/

		} //event checking ends here

		//animation bit - DISABLED
		/*
		if (tFall > fallSpeed)
		{
			MoveTriangle();
			tFall = 0.0;
		}
		tFall++;

		if (tRotate > rotateSpeed)
		{
			rotate = 1;
			tRotate = 0.0;
		}
		tRotate++;
		*/

		update();
		render();


	}

	CleanUp();
	return 0;

}
