#include"EventHandler.h"
#include"Window.h"

#include"Common.h"


InputManager::InputManager(GLFWwindow*window, EventHandler *manager)
{
	_TRACE("Error:");
	EventManager = manager;
	// _____________ SETS __________________
	glfwSetErrorCallback(Error_callback);                          // Callback when Error Encountered
	glfwSetKeyCallback(window, KeyBoard_Callback);	               // Callback for KeyPress
	glfwSetDropCallback(window, DropFile_callback);	               // Callback Allows Files to be dropped into the window and get the path read
	glfwSetMouseButtonCallback(window, Mouse_Button_Callback);     // Callback for Mouse Button Click
	glfwSetCursorPosCallback(window, MouseMove_Callback);          // Callback to return Mouse Position			 
	glfwSetWindowPosCallback(window, Window_Move_Callback);        // Callback to return Window Position
	glfwSetWindowSizeCallback(window, Resize_Callback);            // Callback when Window is Resized
	glfwSetWindowCloseCallback(window, Window_close_callback);       // Callback when Closed

}

#pragma message("Compiling Window CPP InputManager Class")


void  InputManager::Scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
	Event msg(EVENT_WINDOWSCROLL);
	EventManager->PostMSG(msg);
}
MYSTIC void  InputManager::Error_callback(int, const char* description)
{
	Event msg(EVENT_ERROR);
	EventManager->PostMSG(msg);
}
MYSTIC void  InputManager::Resize_Callback(GLFWwindow *window, int xpos, int ypos)
{
	Event msg(EVENT_WINDOW_RESIZE);
	EventManager->PostMSG(msg);
}
MYSTIC void  InputManager::Window_close_callback(GLFWwindow *window)
{
	Event msg(EVENT_WINDOW_CLOSE);
	EventManager->PostMSG(msg);
}


MYSTIC void  InputManager::KeyBoard_Callback(GLFWwindow *window, int key, int scancode, int action, int mods)
{ 
	Window *myWindow = GetWindowHandle(window);
	myWindow->Keyboard.Key = key;
	myWindow->Keyboard.Scancode = scancode;
	myWindow->Keyboard.Modifications = mods;
	myWindow->Keyboard.Action = action;


	switch (action)
	{
	case MSG_KEY_PRESS:
		Print("KeyDown");
		break;
	case MSG_KEY_RELEASE:
		Print("Key Release");
		break;
	case MSG_KEY_REPEAT:
		Print("KeyRelease");
		break;
	case MSG_KEY_UNKNOWN:
		break;
	}
	 
}
MYSTIC void  InputManager::Mouse_Button_Callback(GLFWwindow *window, int button, int action, int mods)
{

	Window *myWindow = GetWindowHandle(window);
	myWindow->Mouse.Action = action;
	myWindow->Mouse.Modifications = mods;

	switch (button)
	{
	case GLFW_MOUSE_BUTTON_LEFT:
	{
		myWindow->Mouse.Button.Left = true;
		EventManager->PostMSG(Event(EVENT_MOUSEBUTTON_LEFT));
		break;
	}
	case GLFW_MOUSE_BUTTON_RIGHT:
	{
		myWindow->Mouse.Button.Right = true;
		EventManager->PostMSG(Event(EVENT_MOUSEBUTTON_RIGHT));
		break;
	}
	case GLFW_MOUSE_BUTTON_MIDDLE:
	{
		myWindow->Mouse.Button.Center = true;
		EventManager->PostMSG(Event(EVENT_MOUSEBUTTON_CENTER));
		break;
	}
	}

}
MYSTIC void  InputManager::MouseMove_Callback(GLFWwindow *window, double xpos, double ypos)
{
	Window *myWindow = GetWindowHandle(window);
	myWindow->Mouse.Position = Vec2(xpos, ypos);
 
	EventManager->PostMSG(Event(EVENT_MOUSEMOVE));
}
MYSTIC void  InputManager::DropFile_callback(GLFWwindow *window, int, const char**)
{
	Event msg(EVENT_DRAGDROP);
	EventManager->PostMSG(msg);
}
MYSTIC void  InputManager::Window_Move_Callback(GLFWwindow *window, int, int)
{
	Event msg(EVENT_WINDOW_MOVE);
	EventManager->PostMSG(msg);
}
MYSTIC void  InputManager::SetClipBoard(char*)
{
	Event msg(EVENT_CLIPBOARD);
	EventManager->PostMSG(msg);
}
MYSTIC const char * InputManager::GetClipBoard()
{
	Event msg(EVENT_CLIPBOARD);
	EventManager->PostMSG(msg);
	return "   ";
}
MYSTIC void InputManager::Charmods_callback(GLFWwindow* window, unsigned int codepoint, int mods)
{
	Event msg(EVENT_MODTEXTINPUT);
	EventManager->PostMSG(msg);
}
MYSTIC void InputManager::Character_callback(GLFWwindow* window, unsigned int codepoint)
{
	Event msg(EVENT_TEXTINPUT);
	EventManager->PostMSG(msg);
}
MYSTIC void InputManager::Minimize_Window_callback(GLFWwindow *, int)
{
	Event msg(EVENT_WINDOW_MINIMIZE);
	EventManager->PostMSG(msg);
}
//Event msg(EVENT_WINDOW_ENTER)
//Event msg(EVENT_JOYSTICK)
//Event msg(EVENT_TIME)

//Event msg(EVENT_WINDOWSCROLL)
//
//





















Event::Event()
{
}
Event::~Event()
{
}





Event::Event(unsigned int MSG)
{
	_TRACE("Created: " << MSG);
	this->Type = (MSG_t)MSG;
	this->Message = MSG;
	this->Time = GetTime();
	this->Location = Window::GetInstance()->Mouse.Position;

	this->data.MsgStruct.wParam = 0;
	this->data.MsgStruct.lParam = 0;
	this->data.MsgStruct.Padding = 0;

	this->WindowHandle = Window::GetInstance()->GetHandle();
}





void  EventHandler::MYST_TranslateMessage()
{
	glfwPollEvents();
}// I WILL NOT NEED THIS, GLFW callbacks will do this for me

int EventHandler::PeekMSG(Event &msg, unsigned int rangemin, unsigned int rangemax, int howtohandle)
{
	// (return -1 on error.)
	if (Messages.size() > 0)
	{
		msg = Messages.back();
		if (msg.MSG_Handle() > rangemin && msg.MSG_Handle() < rangemax)
		{
			if (howtohandle == MSG_H_REMOVE) // REMOVE MESSAGE FROM THE QUEUE
			{
				Messages.pop(); // Return the Message via the *msg pointer and pop the message off of the Message Queue
			}
			else if (howtohandle == MSG_H_KEEP) // KEEP MESSAGE ON THE STACK FOR POSSIBLY OTHER HANDLERS
			{
				// WARNING: NO IDEA WTF TO DO HERE.... This will be for Sending the Message further down the event handler chain for multiple layers... or is that what the next oe is for?
			}
			else if (howtohandle == MSG_H_REPOST)// SEND THE MESSAGE FURTHER DOWN A CHAIN OF EVENT HANDLERS OR POSSIBLY FUTURE STRINGED HANDLERS
			{
				// WARNING: OR HERE..... BUT SOMETHING NEEDS TO GET DONE AND I SHOULD CHANGE THE MANNER FROM WHICH THIS WORKS AND STRAY FROM THE NORM A LITTLE >>>>> LIKE I ALWAYS DO ANYWAY
			}
			return msg.MSG_Handle(); // Not really needed, Could be removed for performance reasons to avoid one more call but really... is it going to be that much of a difference...
		}
	}
	else
	{
		return false;
	}
	return false;
}

//  int EventHandler::MYST_GetMessage(Event *msg, unsigned int rangemix, unsigned int rangemax)
//  {
//  	// (return -1 on error.)
//  	while (Messages.size() == 0)
//  	{
//  		MYST_TranslateMessage();
//  	} // BLOCK UNTIL MESSAGE IS RECIEVED
//  	Event RETURN = Messages.back();
//  	Messages.pop();
//  	return true;
//  }
Event EventHandler::MYST_GetInteruptMessage(double itimer)
{
	// Na wait... That aint right... I want this set to pause the system in an instant and perform any action specified.
	// (Block until Timer is reached)
	return Event(0); // Just Placeholder because it has to return a value
}
void  EventHandler::PostMSG(Event msg)
{
	Messages.push(msg);
}
void EventHandler::RegisterListener(unsigned int msg, Listener *handler)
{
	EventMap[msg].push_back(handler);
}
void EventHandler::Dispatch(Event msg)
{
	for (auto &H : EventMap[msg.MSG_Handle()])
	{
		H->Handler(msg);
	}
}
 











// TODO: HOW TO HANDLE A TIMER MESSAGE: 
// If the lpmsg parameter points to a WM_TIMER message and the lParam parameter of the WM_TIMER message is not NULL, 
// lParam points to a function that is called instead of the window procedure.
//      
//    while (peekmessage(&MSG) != 0)
//    {
//    	translatemessage(&MSG);
//    	dispatchmessage(MSG);
//    }
//    
//    
//    
//    DispatchMessage function
//    12 / 04 / 2018
//    2 minutes to read
//    Dispatches a message to a window procedure.It is typically used to dispatch a message retrieved by the GetMessage function.
// TODO: USEFUL FOR GUI STUFF TO DECODE AND PASS MESSAGES TO DIALOG BOXESX
// IsDialogMessage sends WM_GETDLGCODE messages to the dialog box procedure to determine which keys should be processed.