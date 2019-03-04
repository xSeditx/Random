#include"Application.h"
#include"Window.h"
#include"GLBuffers.h"
#include"GUI.h"

#include"ModelLoader.h"
Application::Application()
{
	_TRACE("Created:");
}
Application::~Application()
{
	_TRACE("Deleted:");
}
 
void Application::MapCurrentThread()
{// THIS IS ALL FOR FUTURE USE AS I BEGIN SHIPPING OUT JOBS TO DIFERENT THREADS. CURRENTLY NOT FUNCTIONAL
	_TRACE("ERROR: [ METHOD NOT COMPLETE ]");
	std::thread::id ID = std::this_thread::get_id();
}
void Application::CreateWindow()
{
	WindowSpecs();
	if (Size.x == 0 || Size.y == 0)
	{
		Print(" ERROR: Window Settings have not been set or have been set to NULL.");
		Print(" Define the virtual function with the specifications for your applications Window before calling CreateWindow() ");
		__debugbreak();
	}
	AppWindow = new Window(Position.x, Position.y, Size.x, Size.y, Title);
	ModelLoader::getInstance().LoadModel("box.obj");

	MessageHandler = new EventHandler();
	GLFWEventHandler = new 	InputManager(AppWindow->GetContext(), MessageHandler);
	GraphicInterface();

}
void Application::UpdateWindow()
{
	AppWindow->Sync();
}
bool Application::Run()
{
	MessageHandler->MYST_TranslateMessage();
	VertexArrayObject VAO = VertexArrayObject();
	Vec3 V[] = {
		Vec3(1,0,1),
		Vec3(1,0,0),
		Vec3(0,1,0),
		Vec3(0,0,1),
	};
//	VAO.Attach(VERTEX, &VertexBufferObject<Vec3>(&V[0], 4));

	Event msg;
	while (MessageHandler->PeekMSG(msg, 0, MSG_MAX_RANGE, MSG_H_REMOVE) != 0)
	{
 		MessageHandler->Dispatch(msg);
	}
	return true;
}


unsigned int Application::GetActiveThread()
{
	return 1;//ThreadMap[std::this_thread::get_id()];
}
inline float Application::GetTime()
{
	return glfwGetTime();
}
inline double Application::GetTicks_highp()
{
	return GetTime() - Window::Instance->StartTime;
}

 







//============================================================================================================================================================================================
//_____________________________________________  Setting Your Applications Windows Hints _____________________________________________________________________________________________________
//============================================================================================================================================================================================
/*
     Called Privately in Create Window, The Derived class WindowSpecs() defines all hints defined.
	 If Window hint is not defined Default values are set and used consistantly.
______________________________________________________________________________________________________________________________________________________________________________________________*/

void Application::SetHints()
{

	glfwWindowHint(GLFW_RESIZABLE, Hints.Window.RESIZABLE);
	glfwWindowHint(GLFW_VISIBLE, Hints.Window.VISIBLE);
	glfwWindowHint(GLFW_DECORATED, Hints.Window.DECORATED);
	// For VR type stuff
	glfwWindowHint(GLFW_STEREO, Hints.Random.STEREO);
	glfwWindowHint(GLFW_SRGB_CAPABLE, Hints.Random.SRGB_CAPABLE);
	// --------- Following Create the Default Framebuffer for the Window being created --------
	// Color Bits
	glfwWindowHint(GLFW_RED_BITS, Hints.FrameBuffer.RED_BITS);
	glfwWindowHint(GLFW_GREEN_BITS, Hints.FrameBuffer.GREEN_BITS);
	glfwWindowHint(GLFW_BLUE_BITS, Hints.FrameBuffer.BLUE_BITS);
	glfwWindowHint(GLFW_ALPHA_BITS, Hints.FrameBuffer.ALPHA_BITS);
	// Depth and Stencil Buffer bits
	glfwWindowHint(GLFW_DEPTH_BITS, Hints.FrameBuffer.DEPTH_BITS);
	glfwWindowHint(GLFW_STENCIL_BITS, Hints.FrameBuffer.STENCIL_BITS);
	// Accumulation Bits
	glfwWindowHint(GLFW_ACCUM_RED_BITS, Hints.FrameBuffer.ACCUM_RED_BITS);
	glfwWindowHint(GLFW_ACCUM_GREEN_BITS, Hints.FrameBuffer.ACCUM_GREEN_BITS);
	glfwWindowHint(GLFW_ACCUM_BLUE_BITS, Hints.FrameBuffer.ACCUM_BLUE_BITS);
	glfwWindowHint(GLFW_ACCUM_ALPHA_BITS, Hints.FrameBuffer.ACCUM_ALPHA_BITS);
	//-------------------------------------------------------------------------------------------
	glfwWindowHint(GLFW_AUX_BUFFERS, Hints.FrameBuffer.AUX_BUFFERS);
	// Anti Aliasing Sampling rates
	glfwWindowHint(GLFW_SAMPLES, Hints.FrameBuffer.SAMPLES);
	glfwWindowHint(GLFW_REFRESH_RATE, Hints.FrameBuffer.REFRESH_RATE);
	// OpenGL Context Creation
	glfwWindowHint(GLFW_CLIENT_API, Hints.Context.CLIENT_API);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, Hints.Context.CONTEXT_VERSION_MAJOR);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, Hints.Context.CONTEXT_VERSION_MINOR);
	glfwWindowHint(GLFW_CONTEXT_ROBUSTNESS, Hints.Context.CONTEXT_ROBUSTNESS);
	//glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, Hints.Context.FORWARD_COMPAT);
	//glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, Hints.Context.OPENGL_DEBUG_CONTEXT);
	glfwWindowHint(GLFW_OPENGL_PROFILE, Hints.Context.OPENGL_PROFILE);
}

void Application::SetStereo(bool param)
{
	Hints.Random.STEREO = param;
}
void Application::sRGBCapable(bool param)
{
	Hints.Random.SRGB_CAPABLE = param;
}
void Application::ForwardCompatible(bool param)
{
	Hints.Random.OPENGL_FORWARD_COMPAT = param;
}
void Application::DebugContext(bool param)
{
	Hints.Random.OPENGL_DEBUG_CONTEXT = param;
}
void Application::ResizableWindow(bool param)
{
	Hints.Window.RESIZABLE = param;
}
void Application::VisibleWindow(bool param)
{
	Hints.Window.VISIBLE = param;
}
void Application::DecoratedWindow(bool param)
{
	Hints.Window.DECORATED = param;
}
void Application::SetRedBits(unsigned int param)
{
	Hints.FrameBuffer.RED_BITS = param;
}
void Application::SetGreenBits(unsigned int param)
{
	Hints.FrameBuffer.GREEN_BITS = param;
}
void Application::SetBlueBits(unsigned int param)
{
	Hints.FrameBuffer.BLUE_BITS = param;
}
void Application::SetAlphaBits(unsigned int param)
{
	Hints.FrameBuffer.ALPHA_BITS = param;
}
void Application::SetDepthBits(unsigned int param)
{
	Hints.FrameBuffer.DEPTH_BITS = param;
}
void Application::SetStencilBits(unsigned int param)
{
	Hints.FrameBuffer.STENCIL_BITS = param;
}
void Application::SetAccumulatorRedBits(unsigned int param)
{
	Hints.FrameBuffer.ACCUM_RED_BITS = param;
}
void Application::SetAccumulatorGreenBits(unsigned int param)
{
	Hints.FrameBuffer.ACCUM_GREEN_BITS = param;
}
void Application::SetAccumulatorBlueBits(unsigned int param)
{
	Hints.FrameBuffer.ACCUM_BLUE_BITS = param;
}
void Application::SetAccumulatorAlphaBits(unsigned int param)
{
	Hints.FrameBuffer.ACCUM_ALPHA_BITS = param;
}
void Application::SetAuxiliaryBits(unsigned int param)
{
	Hints.FrameBuffer.AUX_BUFFERS = param;
}
void Application::SetNumberOfSamples(unsigned int param)
{
	Hints.FrameBuffer.SAMPLES = param;
}
void Application::SetRefreshRate(unsigned int param)
{
	Hints.FrameBuffer.REFRESH_RATE = param;
}
void Application::UseOpenGLClient(unsigned int param)
{
	Hints.Context.CLIENT_API = param;
}
void Application::UseOpenGLESClient(unsigned int param)
{
	Hints.Context.CONTEXT_VERSION_MAJOR = param;
}
void Application::SetMajorVersion(unsigned int param)
{
	Hints.Context.CONTEXT_VERSION_MINOR = param;
}
void Application::SetMinorVersion(unsigned int param)
{
	Hints.Context.CONTEXT_ROBUSTNESS = param;
}
void Application::UseOpenGLProfile(unsigned int param)
{
	Hints.Context.OPENGL_PROFILE = param;
}
