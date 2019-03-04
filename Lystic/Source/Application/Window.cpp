#include"Window.h"
#include"Application.h"


Window *Window::Instance = NULL;
EventHandler *InputManager::EventManager = NULL;
 
Window::~Window() { glfwTerminate(); }

Window* GetApplicationWindow()
{
	return 	(Window*)glfwGetWindowUserPointer(glfwGetCurrentContext());
}
GLFWwindow* GetActiveWindowContext()
{
	return 	glfwGetCurrentContext();
}








//======================================================================================================================================================================
//                                                                                                                                                                        
//                                                  OPENGL 2.0 Abstraction API
//                                                       January 24 2018
//                                                      -----------------                                                                                                                                                        
//                                                                                                                                                                        
//                                                                                                                                                                        
//                                                 OPEN_GL WINDOW MANAGEMENT LIB                                                                                                                     
//                                                                                                                                                                        
//                                                                                                                                                                        
//                                                                                                                                                                        
//======================================================================================================================================================================
#include"Window.h"
 
#pragma message( "Compiling for Using GLFW based Window System" )


#include<Thread>
 #include"Common.h"

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                      /* Construct Window */                                                                                        //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Window::Window(int x, int y, int w, int h, char* title)
	:
	Position(Vec2(0)),
	Size(Vec2(0)),
	Title(title),
	TIMER(std::clock()),
	FRAME_COUNT(0),
	FPS(0)
{ 
	_TRACE("Created:");

	glewExperimental = GL_TRUE;
	if (!glfwInit())exit(-1);


	//------------------------------------------------------- GLFW Window Hints	--------------------------------------------------------------------------------------------  
//	glfwWindowHint(GLFW_SAMPLES, 1); // 4x antialiasing

									 //        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,   3); // Min and Max supported OpenGL versions
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
//	glfwWindowHint(GLFW_RESIZABLE, true);
	//----------------------------------------------------------------------------------------------------------------------------------------------------------------------	    
 
	glCONTEXT = glfwCreateWindow(w, h, title, NULL, NULL);
	if (!glCONTEXT)
	{
		glfwTerminate();  // Kill if Creation Failed
		exit(EXIT_FAILURE);
	}

	//----------------------------------------------------------------------------------------------------------------------------------------------------------------------	    
	//        Hwnd = GetActiveWindow ();

	//---------------------------------------------------- SET WINDOW CONTEXT & CALLBACK FUNCTIONS -------------------------------------------------------------------------    
	glfwMakeContextCurrent(glCONTEXT);

	//----------------------------------------------------------------------------------------------------------------------------------------------------------------------	    
	glViewport(0, 0, Size.x, Size.y);

	for (int count = 0; count < 350;count++)
	{
		Keyboard.KeyStates[count] = 0;	// NULLIFY the KEYBOARD ARRAY
	}

	if (glewInit())
	{
		printf("GLEW ERROR: %s\n", glewGetErrorString(glewInit()));
		system("PAUSE");
		exit(EXIT_FAILURE);
	}
	Handle = 10;
	// --------------- Initialize Matrices ----------------------------------------------------
	glShadeModel(GL_SMOOTH);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
	glEnable(GL_COLOR_MATERIAL);
	glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45, 640.0 / 480.0, .1, 1000);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(0, 0, 0);
	FRAME_COUNT = 0;
	Mouse.Offset = Vec2(1);
	//-------------------------------------------------------------------------------------------      
	glViewport(0, 0, w, h);

	Instance = this;
	glfwSetWindowUserPointer(glCONTEXT, this);
}

GLFWwindow *Window::GetContext() { return glCONTEXT; }
unsigned int Window::GetHandle() {
	return Handle;
}


/*================================================== Free the memory Allocated for the Window ========================================================================*/
void Window::Destroy()
{
	glfwDestroyWindow(glCONTEXT);
}

/*================================================== Return the current Window position as a Vec2 ====================================================================*/

void Window::SetPosition(GLFWwindow *, int x, int y)
{
	glfwSetWindowPos(glCONTEXT, x, y);
}
Vec2 Window::GetPosition()
{
	int X, Y;
	glfwGetWindowPos(glCONTEXT, &X, &Y);
	return Vec2((int)X, (int)Y);
}

void Window::SetClearColor(int r, int g, int b)
{
//	glClearColor(GL_Color(r), GL_Color(g), GL_Color(b), 1);
}
void Window::CLS()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}
void Window::CLS(unsigned long color)
{
	int R = color % 255,
		G = (color / 256) % 256,
		B = (color / 65536) % 256;
	glClearColor(R, G, B, 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}
void Window::CLS(int r, int g, int b)
{
//	_GL(glClearColor(GL_Color(r), GL_Color(g), GL_Color(b), 1));
//	_GL(glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT));
}
float WrapAngle(float angle) {
	while (angle < 0)   angle += 360;
	while (angle > 360) angle -= 360;
	return angle;
}


void Window::Sync()
{
	glfwSwapBuffers(this->glCONTEXT);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}









// ==============================================================================================================================================================================================================
// _______________________________________________________________________ HELPER FUNCTIONS _____________________________________________________________________________________________________________________
// ==============================================================================================================================================================================================================


Window *GetWindowHandle(GLFWwindow *win)
{
	return (Window*)glfwGetWindowUserPointer(win);
}

double GetTime()
{
	return glfwGetTime();
}
