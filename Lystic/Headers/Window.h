#ifndef _WINDOW_H
#define _WINDOW_H



#pragma once


// THIS IS MY STANDARD GRAPHICS AND MULTIPURPOSE LIB I ADD TO ALMOST ALL MY FILES. JUST WINDOW MANAGEMENT, CALLBACKS FOR THE WINDOW, GUI STUFF ETC.
// ALL WINDOW STATE DATA IS RETRIEVED FROM GLFW CALLBACKS AND SENT TO THE WINDOW OBJECT
// PATHS TO BE SET IN THE PROJECT FOLDER.
// Headers:
//     GLFW Headers location
//     GLEW Header  location
// 
// Location of GLFW Libraries
//
//
// DEPENDENT ON GLFW 3.0+
// DEPENDENT ON GLEW 

#define GLEW_STATIC





#include <iostream>
#include <ctime>
#include <stdint.h>

#include"Common.h"

// FORWARD DECLARATION TO AVOID HAVING TO ADD IMPLEMENTING HEADERS IN HERE;

struct GLFWwindow;

class Window;
class Scene;
class Viewport;


void *GetAnyGLFuncAddress(const char *name); //------------------------ Extract the function Address of any OpenGL function from their Dynamic Link Library
float WrapAngle(float angle); //--------------------------------------- Rolls Angle defined in Degrees over when it is less then 0 or greater than 360	
Matrix MatCast(float arr[16]); //-------------------------------------- Cast an Array into a 4x4 Matrix
inline double Max(float p1, float p2); // ----------------------------- High precision Hi/Low test returning the Max value
inline double Min(float p1, float p2); // ----------------------------- High precision Hi/Low test returning the Low value



Window* GetApplicationWindow(); // ----------------------------------------- Returns a pointer to my Window Structure
Window* GetWindowHandle(GLFWwindow *win);
GLFWwindow* GetActiveWindowContext(); // ------------------------------ Returns a pointer to GLFW active Window Context



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                                         WINDOW CLASS                                                                                                                            
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


class MYSTIC Window // TODO:: WARNING!! DO NOT FORGET TO SET USERWINDOWPOINTER to point to this Structure Else NONE!!! of this will work.
{
public:
	Window::Window() {}
	Window::~Window();
	Window::Window(int, int, int, int, char*);

	Vec2 Position;
	Vec2 Size;
	char           *Title;
	unsigned int    Handle;

	unsigned  long  TIMER;
	unsigned   int  FRAME_COUNT;
	unsigned   int  FPS;

	struct FrameBuffer
	{
		Vec2 Size;
		GLuint ID;
	}FrameBuffer;

	struct MouseProperties
	{
		Vec2 Position;
		Vec2 RealPosition;
		Vec2 Velocity;
		Vec2 Offset; // NEEDED TO FIX SCALING ISSUES FOR RELATIVE MOUSE POSITION OF WINDOW SIZE IS CHANGES
		int
			Action,
			Modifications;

		struct
		{
			bool Left, Right, Center, X1, X2;
			short Clicks;
		}Button;

		inline void Hide() { glfwSetInputMode(GetActiveWindowContext(), GLFW_CURSOR, GLFW_CURSOR_HIDDEN); }
		inline void Show() { glfwSetInputMode(GetActiveWindowContext(), GLFW_CURSOR, GLFW_CURSOR_NORMAL); }
	}Mouse;

	struct Key_Board
	{
		int Key,
			Scancode,
			Action,
			Modifications;
		int KeyStates[350];
		inline bool IsKeyPressed(int keycode) { return (KeyStates[keycode] != 0); }
	}Keyboard;

	struct
	{
		float Rate;
		void Set(float rate)
		{
			Coefficient = 1000.0 / rate;
		}
		float Get() { return Rate; }
		float PreviousTime = 0.0f;
		float Coefficient = 0.0f;
		float CurrentTime = 0.0f;
		float Tracker = 0.0f;
		unsigned int Counter = 0.0f;

		float LastFrame = 0.0;
	}Framerate;

	
private: 

	GLFWwindow *glCONTEXT;
public:
	Scene *World;
	static Window *GetInstance() { return Instance; }

	void Destroy();

	GLFWwindow *GetContext();
	unsigned int GetHandle();

	inline Vec2 GetPosition();
	inline void SetPosition(GLFWwindow *, int x, int y);
	inline void SetPosition(GLFWwindow *w, Vec2 pos) { SetPosition(w, pos.x, pos.y); }

	inline void Show() { glfwShowWindow(this->glCONTEXT); }
	inline void Hide() { glfwHideWindow(this->glCONTEXT); }

	void SetClearColor(int r, int g, int b);

	void CLS();
	void CLS(unsigned long color);
	void CLS(int r, int g, int b);
	void Sync();

	double StartTime;
	static Window *Instance; // Might make this private with a Getter in the future;
private:
};
 

//class Input
//{
//	Input() {}
//
//	Input();                                  // constructor is private
//	Input(Input const&);                 // copy constructor is private
//	Input& operator=(Input const&);  // assignment operator is private
//	~Input();                                 // destructor is private
//
//public:
//	static Input& Instance()
//	{
//		static Input InputInstance;
//		return InputInstance;
//	}
//
//	struct MouseProperties
//	{
//		MouseProperties &Mouse()
//		{
//			static MouseProperties Inst;
//			return Inst;
//		}
//		Vec2 Position;
//		Vec2 RealPosition;
//		Vec2 Velocity;
//		Vec2 Offset; // NEEDED TO FIX SCALING ISSUES FOR RELATIVE MOUSE POSITION OF WINDOW SIZE IS CHANGES
//		int
//			Action,
//			Modifications;
//
//		struct button
//		{
//			bool Left, Right, Center, X1, X2;
//			short Clicks;
//		}Button;
//  
//		inline void Hide() { glfwSetInputMode(GetActiveWindowContext(), GLFW_CURSOR, GLFW_CURSOR_HIDDEN); }
//		inline void Show() { glfwSetInputMode(GetActiveWindowContext(), GLFW_CURSOR, GLFW_CURSOR_NORMAL); }
//	}Mouse;
//
//	struct Key_Board
//	{
//		int Key,
//			Scancode,
//			Action,
//			Modifications;
//		int KeyStates[350];
//		inline bool IsKeyPressed(int keycode) { return (KeyStates[keycode] != 0); }
//	}Keyboard;
//}
//
class EventHandler;



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                                                                                  
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

double GetTime();
 






//  Not needed now since using Event Handler and Application Class... Right?
// void(*Update)();
// void(*Render)();
// void(*Idle)();
//	void SetUpdate(void(*f)()) { Update = f; }
//	void SetRender(void(*f)()) { Render = f; }
//	void SetIdle(void(*f)()) { Idle = f; }
//  
//  
//  
//  
//  
//  
//  struct Hints
//  {
//  	bool ResizeableHINT = true;
//  	bool Visible = true;
//  	bool Decorated = true;
//  	b
//  };
//  void MakeResizeable()
//  {
//  	GLFW_RESIZABLE;
//  }
//  GLFW_VISIBLE
//  GLFW_DECORATED
//  
//  RED_BITS
//  GREEN_BITS
//  BLUE_BITS
//  ALPHA_BITS
//  DEPTH_BITS
//  STENCIL_BITS
//  ACCUM_RED_BITS
//  ACCUM_GREEN_BITS
//  ACCUM_BLUE_BITS
//  ACCUM_ALPHA_BITS
//  AUX_BUFFERS
//  SAMPLES
//  REFRESH_RATE
//  STEREO = GL_FALSE
//  SRGB_CAPABLE
//  CLIENT_API
//  CONTEXT_VERSION_MAJOR
//  CONTEXT_VERSION_MINOR
//  CONTEXT_ROBUSTNESS
//  OPENGL_FORWARD_COMPAT
//  OPENGL_DEBUG_CONTEXT
//  OPENGL_PROFILE
//  
//  GLFW_VISIBLE
//  GLFW_DECORATED
//  
//  GLFW_RED_BITS
//  GLFW_GREEN_BITS
//  GLFW_BLUE_BITS
//  GLFW_ALPHA_BITS
//  GLFW_DEPTH_BITS
//  GLFW_STENCIL_BITS
//  GLFW_ACCUM_RED_BITS
//  GLFW_ACCUM_GREEN_BITS
//  GLFW_ACCUM_BLUE_BITS
//  GLFW_ACCUM_ALPHA_BITS
//  GLFW_AUX_BUFFERS
//  GLFW_SAMPLES
//  GLFW_REFRESH_RATE
//  GLFW_STEREO	GL_FALSE
//  GLFW_SRGB_CAPABLE
//  GLFW_CLIENT_API
//  GLFW_CONTEXT_VERSION_MAJOR
//  GLFW_CONTEXT_VERSION_MINOR
//  GLFW_CONTEXT_ROBUSTNESS
//  GLFW_OPENGL_FORWARD_COMPAT
//  GLFW_OPENGL_DEBUG_CONTEXT
//  GLFW_OPENGL_PROFILE

//   
//   
//   
//   typedef void(*GLFWframebuffersizefun) (GLFWwindow *, int, int)
//   This is the function signature for framebuffer resize callback functions.
//   
//   typedef struct GLFWwindow GLFWwindow
//   Opaque window object.
//   
//   typedef void(*GLFWwindowclosefun) (GLFWwindow *)
//   This is the function signature for window close callback functions.
//   
//   typedef void(*GLFWwindowfocusfun) (GLFWwindow *, int)
//   This is the function signature for window focus callback functions.
//   
//   
//   typedef void(*GLFWwindowiconifyfun) (GLFWwindow *, int)
//   This is the function signature for window iconify / restore callback functions.
//   
//   typedef void(*GLFWwindowposfun) (GLFWwindow *, int, int)
//   This is the function signature for window position callback functions.
//   
//   typedef void(*GLFWwindowrefreshfun) (GLFWwindow *)
//   This is the function signature for window refresh callback functions.
//   
//   typedef void(*GLFWwindowsizefun) (GLFWwindow *, int, int)
//   This is the function signature for window size callback functions.
//   
//   
//   
//   
//   
//   
//   typedef struct GLFWwindow 	GLFWwindow
//   Opaque window object.More...
//   
//   typedef void(*GLFWwindowposfun) (GLFWwindow *, int, int)
//   The function signature for window position callbacks.More...
//   GLFWwindowposfun 	glfwSetWindowPosCallback(GLFWwindow *window, GLFWwindowposfun cbfun)
//   Sets the position callback for the specified window.More...
//   
//   typedef void(*GLFWwindowsizefun) (GLFWwindow *, int, int)
//   The function signature for window resize callbacks.More...
//   GLFWwindowsizefun 	glfwSetWindowSizeCallback(GLFWwindow *window, GLFWwindowsizefun cbfun)
//   Sets the size callback for the specified window.More...
//   
//   
//   typedef void(*GLFWwindowclosefun) (GLFWwindow *)
//   The function signature for window close callbacks.More...
//   GLFWwindowclosefun 	glfwSetWindowCloseCallback(GLFWwindow *window, GLFWwindowclosefun cbfun)
//   Sets the close callback for the specified window.More...
//   
//   
//   
//   typedef void(*GLFWframebuffersizefun) (GLFWwindow *, int, int)
//   GLFWframebuffersizefun 	glfwSetFramebufferSizeCallback(GLFWwindow *window, GLFWframebuffersizefun cbfun)
//   Sets the framebuffer resize callback for the specified window.More...
//   The function signature for framebuffer resize callbacks.More...
//   
//   
//   
//   typedef void(*GLFWwindowrefreshfun) (GLFWwindow *)
//   The function signature for window content refresh callbacks.More...
//   GLFWwindowrefreshfun 	glfwSetWindowRefreshCallback(GLFWwindow *window, GLFWwindowrefreshfun cbfun)
//   Sets the refresh callback for the specified window.More...
//   
//   
//   
//   typedef void(*GLFWwindowfocusfun) (GLFWwindow *, int)
//   The function signature for window focus / defocus callbacks.More...
//   GLFWwindowfocusfun 	glfwSetWindowFocusCallback(GLFWwindow *window, GLFWwindowfocusfun cbfun)
//   Sets the focus callback for the specified window.More...
//   
//   
//   
//   
//   typedef void(*GLFWwindowiconifyfun) (GLFWwindow *, int)
//   The function signature for window iconify / restore callbacks.More...
//   GLFWwindowiconifyfun 	glfwSetWindowIconifyCallback(GLFWwindow *window, GLFWwindowiconifyfun cbfun)
//   Sets the iconify callback for the specified window.More...
//   
//   
//   
//   GLFWwindowclosefun 	cbfun
//   glfwRestoreWindow
//   glfwMaximizeWindow
//   GLFWmonitor* glfwGetWindowMonitor(GLFWwindow * 	window)


#endif



//  
//  bool STEREO = GL_FALSE;//	GL_TRUE or GL_FALSE
//  bool SRGB_CAPABLE = GL_FALSE;//	GL_TRUE or GL_FALSE
//  bool OPENGL_FORWARD_COMPAT = GL_FALSE;//	GL_TRUE or GL_FALSE
//  bool OPENGL_DEBUG_CONTEXT = GL_FALSE;//	GL_TRUE or GL_FALSE
//  bool RESIZABLE = GL_TRUE;//	GL_TRUE or GL_FALSE
//  bool VISIBLE = GL_TRUE;//	GL_TRUE or GL_FALSE
//  bool DECORATED = GL_TRUE;//	GL_TRUE or GL_FALSE
//  unsigned int RED_BITS = 8;//	0 to INT_MAX
//  unsigned int GREEN_BITS = 8;//	0 to INT_MAX
//  unsigned int BLUE_BITS = 8;//	0 to INT_MAX
//  unsigned int ALPHA_BITS = 8;//	0 to INT_MAX
//  unsigned int DEPTH_BITS = 24;//	0 to INT_MAX
//  unsigned int STENCIL_BITS = 8;//	0 to INT_MAX
//  unsigned int ACCUM_RED_BITS = 0;//	0 to INT_MAX
//  unsigned int ACCUM_GREEN_BITS = 0;//	0 to INT_MAX
//  unsigned int ACCUM_BLUE_BITS = 0;//	0 to INT_MAX
//  unsigned int ACCUM_ALPHA_BITS = 0;//	0 to INT_MAX
//  unsigned int AUX_BUFFERS = 0;//	0 to INT_MAX
//  unsigned int SAMPLES = 0;//	0 to INT_MAX
//  unsigned int REFRESH_RATE = 0;//	0 to INT_MAX
//  unsigned int CLIENT_API = GLFW_OPENGL_API;//	GLFW_OPENGL_API or GLFW_OPENGL_ES_API
//  unsigned int CONTEXT_VERSION_MAJOR = 1;//	Any valid major version number of the chosen client API
//  unsigned int CONTEXT_VERSION_MINOR = 0;//	Any valid minor version number of the chosen client API
//  unsigned int CONTEXT_ROBUSTNESS = GLFW_NO_ROBUSTNESS;//	GLFW_NO_ROBUSTNESS, GLFW_NO_RESET_NOTIFICATION or GLFW_LOSE_CONTEXT_ON_RESET
//  unsigned int OPENGL_PROFILE = GLFW_OPENGL_ANY_PROFILE;//	GLFW_OPENGL_ANY_PROFILE, GLFW_OPENGL_COMPAT_PROFILE or GLFW_OPENGL_CORE_PROFILE
//  













//  
//  
//  GL_TRUE	GL_TRUE or GL_FALSE
//  GL_TRUE	GL_TRUE or GL_FALSE
//  GL_TRUE	GL_TRUE or GL_FALSE
//  8	0 to INT_MAX
//  8	0 to INT_MAX
//  8	0 to INT_MAX
//  8	0 to INT_MAX
//  24	0 to INT_MAX
//  8	0 to INT_MAX
//  0	0 to INT_MAX
//  0	0 to INT_MAX
//  0	0 to INT_MAX
//  0	0 to INT_MAX
//  0	0 to INT_MAX
//  0	0 to INT_MAX
//  0	0 to INT_MAX
//  GL_TRUE or GL_FALSE
//  GL_FALSE	GL_TRUE or GL_FALSE
//  GLFW_OPENGL_API	GLFW_OPENGL_API or GLFW_OPENGL_ES_API
//  1	Any valid major version number of the chosen client API
//  0	Any valid minor version number of the chosen client API
//  GLFW_NO_ROBUSTNESS	GLFW_NO_ROBUSTNESS, GLFW_NO_RESET_NOTIFICATION or GLFW_LOSE_CONTEXT_ON_RESET
//  GL_FALSE	GL_TRUE or GL_FALSE
//  GL_FALSE	GL_TRUE or GL_FALSE
//  GLFW_OPENGL_ANY_PROFILE	GLFW_OPENGL_ANY_PROFILE, GLFW_OPENGL_COMPAT_PROFILE or GLFW_OPENGL_CORE_PROFILE
//  
//  



//  
//  
//  
//  
//  GLFW_RESIZABLE
//  GLFW_VISIBLE
//  GLFW_DECORATED
//  Hints.Framebuffer.RED_BITS
//  Hints.Framebuffer.GREEN_BITS
//  Hints.Framebuffer.BLUE_BITS
//  Hints.Framebuffer.ALPHA_BITS
//  Hints.Framebuffer.DEPTH_BITS
//  Hints.Framebuffer.STENCIL_BITS
//  Hints.Framebuffer.ACCUM_RED_BITS
//  Hints.Framebuffer.ACCUM_GREEN_BITS
//  Hints.Framebuffer.ACCUM_BLUE_BITS
//  Hints.Framebuffer.ACCUM_ALPHA_BITS
//  Hints.Framebuffer.AUX_BUFFERS
//  Hints.Framebuffer.SAMPLES
//  Hints.Framebuffer.REFRESH_RATE
//  GLFW_STEREO	                            
//  GLFW_SRGB_CAPABLE
//  GLFW_CLIENT_API
//  GLFW_CONTEXT_VERSION_MAJOR
//  GLFW_CONTEXT_VERSION_MINOR
//  GLFW_CONTEXT_ROBUSTNESS
//  GLFW_OPENGL_FORWARD_COMPAT
//  GLFW_OPENGL_DEBUG_CONTEXT
//  GLFW_OPENGL_PROFILE
//  






