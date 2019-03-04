#ifndef _NATIVE_H
#define _NATIVE_H
#pragma once

#include<Windows.h>

#ifdef _WIN32
#ifndef _NATIVE_H
#define _NATIVE_H

// 2.12 - What window system APIs does GLFW use ?
//   On Windows, plain Win32 is used for window and input management, and WGL or EGL to create OpenGL and OpenGL ES contexts.
//   
//   On macOS, Cocoa is used for window and input management, and NSOpenGL to create OpenGL contexts.
//   
//   On Unix - like systems using the X Window System, the Xlib API is used for window and input management, and GLX or EGL to create OpenGL and OpenGL ES contexts.
//   
//   On Linux systems using Wayland, the Wayland API is used for window and input management, and EGL to create OpenGL and OpenGL ES contexts.
//   



#include"Window.h"
#include"Application.h"

#define GLFW_EXPOSE_NATIVE_WIN32
#include"GLFW/glfw3native.h"

#pragma comment(lib, "shell32.lib")
#pragma comment(lib, "glfw3.lib")
#pragma comment(lib, "user32.lib")
#pragma comment(lib, "gdi32.lib")

#pragma comment(lib, "vcruntime.lib")
#pragma comment(lib, "msvcrt.lib")
#pragma comment(lib, "Ws2_32.lib")

#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "gdiplus.lib")

#include <GL/glew.h>
#include <GL/gl.h>
#include <GL/glu.h>

class EventSys;

const char *MonitorAdaptorName()
{
	return MonitorAdaptorName();
	// Need to expose the EventSys
//	if (EventSys::Exist())return glfwGetWin32Adapter();    //Returns the adapter device name of the specified monitor.More...
}

HWND GetWindowHandle()
{
	return glfwGetWin32Window(Window::Instance->GetContext());   //Returns the HWND of the specified window.More...
}


#endif
// 
// 
// GLFW_EXPOSE_NATIVE_WIN32
// GLFW_EXPOSE_NATIVE_COCOA
// GLFW_EXPOSE_NATIVE_X11
// GLFW_EXPOSE_NATIVE_WAYLAND
// GLFW_EXPOSE_NATIVE_MIR
// 
// The available context API macros are :
// GLFW_EXPOSE_NATIVE_WGL
// GLFW_EXPOSE_NATIVE_NSGL
// GLFW_EXPOSE_NATIVE_GLX
// GLFW_EXPOSE_NATIVE_EGL
// 


/*
Functions
const char * 	glfwGetWin32Monitor(GLFWmonitor *monitor)
Returns the display device name of the specified monitor.More...

HGLRC 	glfwGetWGLContext(GLFWwindow *window)
Returns the HGLRC of the specified window.More...

CGDirectDisplayID 	glfwGetCocoaMonitor(GLFWmonitor *monitor)
Returns the CGDirectDisplayID of the specified monitor.More...

id 	glfwGetCocoaWindow(GLFWwindow *window)
Returns the NSWindow of the specified window.More...

id 	glfwGetNSGLContext(GLFWwindow *window)
Returns the NSOpenGLContext of the specified window.More...

Display * 	glfwGetX11Display(void)
Returns the Display used by GLFW.More...

RRCrtc 	glfwGetX11Adapter(GLFWmonitor *monitor)
Returns the RRCrtc of the specified monitor.More...

RROutput 	glfwGetX11Monitor(GLFWmonitor *monitor)
Returns the RROutput of the specified monitor.More...

Window 	glfwGetX11Window(GLFWwindow *window)
Returns the Window of the specified window.More...

GLXContext 	glfwGetGLXContext(GLFWwindow *window)
Returns the GLXContext of the specified window.More...

GLXWindow 	glfwGetGLXWindow(GLFWwindow *window)
Returns the GLXWindow of the specified window.More...

struct wl_display * 	glfwGetWaylandDisplay(void)
	Returns the struct wl_display* used by GLFW.More...

	struct wl_output * 	glfwGetWaylandMonitor(GLFWmonitor *monitor)
	Returns the struct wl_output* of the specified monitor.More...

	struct wl_surface * 	glfwGetWaylandWindow(GLFWwindow *window)
	Returns the main struct wl_surface* of the specified window.More...

	MirConnection * 	glfwGetMirDisplay(void)
	Returns the MirConnection* used by GLFW.More...

	int 	glfwGetMirMonitor(GLFWmonitor *monitor)
	Returns the Mir output ID of the specified monitor.More...

	MirSurface * 	glfwGetMirWindow(GLFWwindow *window)
	Returns the MirSurface* of the specified window.More...

	EGLDisplay 	glfwGetEGLDisplay(void)
	Returns the EGLDisplay used by GLFW.More...

	EGLContext 	glfwGetEGLContext(GLFWwindow *window)
	Returns the EGLContext of the specified window.More...

	EGLSurface 	glfwGetEGLSurface(GLFWwindow *window)
	Returns the EGLSurface of the specified window.More...

	*/

#undef GLFW_EXPOSE_NATIVE_WIN32
#endif






#ifdef _LINUX
	Display * glfwGetX11Display(void) // Returns the Display used by GLFW.More...
	RRCrtc 	glfwGetX11Adapter(GLFWmonitor *monitor) //Returns the RRCrtc of the specified monitor.More...
	RROutput 	glfwGetX11Monitor(GLFWmonitor *monitor) //Returns the RROutput of the specified monitor.More...
	Window 	glfwGetX11Window(GLFWwindow *window) //Returns the Window of the specified window.More...
	GLXContext 	glfwGetGLXContext(GLFWwindow *window) //Returns the GLXContext of the specified window.More...
	GLXWindow 	glfwGetGLXWindow(GLFWwindow *window) //Returns the GLXWindow of the specified window.More...

	struct wl_display * 	glfwGetWaylandDisplay(void);//Returns the struct wl_display* used by GLFW.More...
struct wl_output * 	glfwGetWaylandMonitor(GLFWmonitor *monitor);//Returns the struct wl_output* of the specified monitor.More...
struct wl_surface * 	glfwGetWaylandWindow(GLFWwindow *window); //Returns the main struct wl_surface* of the specified window.More...

#endif






#endif