#ifndef _APPLICATION_H
#define _APPLICATION_H
#pragma once


#include<vector>
#include<thread>
#include"Common.h"
#include"EventHandler.h"
 // THIS WILL BE THE NAMESPACE Mystic:: IN THE FUTURE

class Window;
class InputManager;




//=====================================================================================================================================================================
// TODO: THIS WHOLE THING WILL GO AND BE REPLACED BY A BETTER THREAD ORGANIZER BUT I JUST NEEDED SOMETHING TO RETURN AN ID REAL FAST FOR THE MESSAGE HANDLER
//=====================================================================================================================================================================

//=====================================================================================================================================================================
// XEvent Structure
// This is the key attribute that determines all the rest.Setting this value will re - bless the object to the relevant sub - class.If the type is unknown, it becomes X11::Xlib::XEvent.
// 
// display
// The handle to the X11 connection that this message came from.
// 
// serial
// The X11 serial number
// 
// send_event
// Boolean indicating whether the event was sent with XSendEvent


// WRAPPING THE TIME FUNCTION FOR LATER ALTERATIONS TO std::chrono library
//struct GLFWwindow;


class Application
{
public:
	Application::Application();
	Application::~Application();


	void CreateWindow();

	static inline float GetTime();

	bool Run();

	Vec2 Position;
	Vec2 Size;
	char *Title;

	EventHandler *MessageHandler;

private:

	virtual void WindowSpecs() = 0;

	virtual void OnUserCreate() = 0;
	virtual void OnUserUpdate() = 0;
	virtual void OnUserDestroy() = 0;
	virtual void OnUserRender() = 0;

	virtual void Start() = 0;
	virtual void Exit() = 0;
	virtual void Pause() = 0;

// THREADING STUFF
	bool WindowLive;


	inline double GetTicks_highp();

//	std::map<std::thread::id, int> ThreadMap;
	void MapCurrentThread();

	unsigned int GetActiveThread();
	int ThreadCount;

	// Will let the Application know the user has created their own Handler;
	bool UserDefinedEventHandler;

	InputManager *GLFWEventHandler;
	Window *AppWindow;
	void UpdateWindow();

// =================================================================================================================================================================================================================================================
	 
		struct HintsStruct
		{
			struct HardConstraints
			{
				bool STEREO = 0;//	GL_TRUE or GL_FALSE
				bool SRGB_CAPABLE = 0;//	GL_TRUE or GL_FALSE
				bool OPENGL_FORWARD_COMPAT = 0;//	GL_TRUE or GL_FALSE
				bool OPENGL_DEBUG_CONTEXT = 0;//	GL_TRUE or GL_FALSE
			}Random;// Dude WTF do I want to call this, Not that thats for damn sure....

			struct WindowHints
			{
				bool RESIZABLE = 1;//	GL_TRUE or GL_FALSE
				bool VISIBLE = 1;//	GL_TRUE or GL_FALSE
				bool DECORATED = 1;//	GL_TRUE or GL_FALSE
			}Window;

			struct FrameBufferHints
			{
				unsigned int RED_BITS = 8;//	0 to INT_MAX
				unsigned int GREEN_BITS = 8;//	0 to INT_MAX
				unsigned int BLUE_BITS = 8;//	0 to INT_MAX
				unsigned int ALPHA_BITS = 8;//	0 to INT_MAX
				unsigned int DEPTH_BITS = 24;//	0 to INT_MAX
				unsigned int STENCIL_BITS = 8;//	0 to INT_MAX
				unsigned int ACCUM_RED_BITS = 0;//	0 to INT_MAX
				unsigned int ACCUM_GREEN_BITS = 0;//	0 to INT_MAX
				unsigned int ACCUM_BLUE_BITS = 0;//	0 to INT_MAX
				unsigned int ACCUM_ALPHA_BITS = 0;//	0 to INT_MAX
				unsigned int AUX_BUFFERS = 0;//	0 to INT_MAX
				unsigned int SAMPLES = 0;//	0 to INT_MAX
				unsigned int REFRESH_RATE = 0;//	0 to INT_MAX
			}FrameBuffer;

			struct ContextHints
			{
				unsigned int CLIENT_API = 0x00030001;//	GLFW_OPENGL_API or GLFW_OPENGL_ES_API
				unsigned int CONTEXT_VERSION_MAJOR = 1;//	Any valid major version number of the chosen client API
				unsigned int CONTEXT_VERSION_MINOR = 0;//	Any valid minor version number of the chosen client API
				unsigned int CONTEXT_ROBUSTNESS = 0;//	GLFW_NO_ROBUSTNESS, GLFW_NO_RESET_NOTIFICATION or GLFW_LOSE_CONTEXT_ON_RESET
				unsigned int OPENGL_PROFILE = 0;//	GLFW_OPENGL_ANY_PROFILE, GLFW_OPENGL_COMPAT_PROFILE or GLFW_OPENGL_CORE_PROFILE
			}Context;
		}Hints;

		void SetHints();
		void SetStereo(bool);
		void sRGBCapable(bool);
		void ForwardCompatible(bool);
		void DebugContext(bool);
		void ResizableWindow(bool);
		void VisibleWindow(bool);
		void DecoratedWindow(bool);
		void SetRedBits(unsigned int);
		void SetGreenBits(unsigned int);
		void SetBlueBits(unsigned int);
		void SetAlphaBits(unsigned int);
		void SetDepthBits(unsigned int);
		void SetStencilBits(unsigned int);
		void SetAccumulatorRedBits(unsigned int);
		void SetAccumulatorGreenBits(unsigned int);
		void SetAccumulatorBlueBits(unsigned int);
		void SetAccumulatorAlphaBits(unsigned int);
		void SetAuxiliaryBits(unsigned int);
		void SetNumberOfSamples(unsigned int);
		void SetRefreshRate(unsigned int);
		void UseOpenGLClient(unsigned int);
		void UseOpenGLESClient(unsigned int);
		void SetMajorVersion(unsigned int);
		void SetMinorVersion(unsigned int);
		void UseOpenGLProfile(unsigned int);
	
};








#endif // END _APPLICATION_H