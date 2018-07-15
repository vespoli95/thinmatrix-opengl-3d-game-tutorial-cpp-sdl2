//namespace renderEngine;

#include "DisplayManager.h"

const char *S_APPNAME = "OpenGL 3D Game Tutorial 27: Skybox & OpenGL Water Tutorial 8: Soft Edges";

void DisplayManager::createDisplay()
{
	int val;
	GLenum error;

	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
	        cerr << "SDL_Init failed: " << SDL_GetError() << endl;
		exit(1);
	}
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);

	Uint32 flags = SDL_WINDOW_OPENGL|SDL_WINDOW_RESIZABLE;

	window = SDL_CreateWindow(S_APPNAME, S_XPOS, S_YPOS, width, height, flags);
	if (!window) {
		cerr << "Create window failed: " << SDL_GetError() << endl;
		exit(1);
	}

	glContext = SDL_GL_CreateContext(window);
	if (!glContext) {
		cerr << "Create GL context failed: " << SDL_GetError() << endl;
		exit(1);
	}

	// Init GLEW after creating gl context
	glewExperimental = GL_TRUE; 

	// $ glewinfo | less
	error = glewInit();
	if (error != GLEW_OK) {
		cerr << "glewInit error: " << glewGetErrorString(error)  << endl;
		exit(1);
	}

	val = SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	if (val < 0) {
		cerr << "Warning: Double buffering failed: " << SDL_GetError() << endl;
		//only complain, do not exit //exit(1);
	}

	val = SDL_GL_SetSwapInterval(1);
	if (val < 0) {
		cerr << "Warning: Synchronizing with vertical retrace failed: " << SDL_GetError() << endl;
		//only complain, do not exit //exit(1);
	}

	lastFrameTime = getCurrentTime();
}

void DisplayManager::updateDisplay()
{
	SDL_GL_SwapWindow(window); // should sync with max FPS_CAP
	long currentFrameTime = getCurrentTime();
	delta = (currentFrameTime - lastFrameTime) / 1000.0f;
	lastFrameTime = currentFrameTime;


	// FPS measurement
	fps++;
	time_t t = time(NULL);
	if (t != oldt) {
		cout << "Current FPS: " << fps << "\n";
		oldt = t;
		fps = 0;
	}
}

void DisplayManager::closeDisplay()
{
	SDL_GL_DeleteContext(glContext);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

long DisplayManager::getCurrentTime()
{
	Uint32 ticks = SDL_GetTicks();
	return ticks;
}

GLfloat DisplayManager::getFrameTimeSeconds()
{
	return delta;
}

void DisplayManager::setSize(GLsizei width, GLsizei height)
{
	this->width = width;
	this->height = height;
	glViewport(0, 0, width, height);
}
