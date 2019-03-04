#pragma once
#include"Common.h"
#include<queue>
#include<unordered_map>

#include"Object.h"


typedef struct GLFWwindow GLFWwindow;
typedef int MSG_BOOL;


#define NO_EVENT                  0x00000000
#define EVENT_NONE                0x00000000
#define EVENT_JOYSTICK            0x00000004   // void joystick_callback(int joy, int event)
#define EVENT_TIMER			      0x00000005   
#define EVENT_CLIPBOARD		      0x00000006   
#define EVENT_DRAGDROP            0x00000007   // void drop_callback(GLFWwindow* window, int count, const char** paths)
#define EVENT_ERROR               0x00000008   // void error_callback(int error, const char* description)
#define EVENT_MODTEXTINPUT        0x0000000B   // void charmods_callback(GLFWwindow* window, unsigned int codepoint, int mods)
#define EVENT_TEXTINPUT           0x0000000C   // void character_callback(GLFWwindow* window, unsigned int codepoint)
							      
#define EVENT_MOUSECLICK          0x0000000F   // }
#define EVENT_MOUSEBUTTON         0x00000001   // void mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
#define EVENT_MOUSEMOVE           0x00000003   // static void cursor_position_callback(GLFWwindow* window, double xpos, double ypos)
#define EVENT_MOUSEBUTTON_LEFT    0x000F0001   // void mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
#define EVENT_MOUSEBUTTON_RIGHT   0x0f0F0001   // void mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
#define EVENT_MOUSEBUTTON_CENTER  0x000Ff001   // void mouse_button_callback(GLFWwindow* window, int button, int action, int mods)

#define EVENT_KEYBOARD            0x00000009   // void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
#define EVENT_KEYDOWN             0x0000000D   // { AGAIN HIGHLY REDUNDENT
#define EVENT_KEYUP               0x0000000E   // |
							      
#define EVENT_WINDOWSCROLL        0x0000000A   // void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
#define EVENT_WINDOW_ENTER        0x00000002   // void cursor_enter_callback(GLFWwindow* window, int entered)
#define EVENT_WINDOW_RESIZE       0x00000010
#define EVENT_WINDOW_CLOSE        0x00000020
#define EVENT_WINDOW_MOVE         0x00000030
#define EVENT_WINDOW_MINIMIZE     0x00000040
							      
#define MSG_H_KEEP                0x0000000F
#define MSG_H_REMOVE              0x000000F0
#define MSG_H_REPOST              0x00000F00

#define MSG_KEY_PRESS          GLFW_PRESS
#define MSG_KEY_REPEAT         GLFW_REPEAT
#define MSG_KEY_RELEASE        GLFW_RELEASE
#define MSG_KEY_UNKNOWN        GLFW_KEY_UNKNOWN

#define MSG_MAX_RANGE          0xFFFFFFFF


enum class MYSTIC MSG_t
{
	EMPTY_EVENT = EVENT_NONE,
	MOUSECLICK_EVENT = EVENT_MOUSECLICK,
	ENTERWINDOW_EVENT = EVENT_WINDOW_ENTER,
	MOUSEMOVE_EVENT = EVENT_MOUSEMOVE,
	JOYSTICK_EVENT = EVENT_JOYSTICK,
	TIMER_EVENT = EVENT_TIMER,
	CLIPBOARD_EVENT = EVENT_CLIPBOARD,
	DRAGDROP_EVENT = EVENT_DRAGDROP,
	ERRORMESSAGE_EVENT = EVENT_ERROR,
	KEYBOARD_EVENT = EVENT_KEYBOARD,
	WINDOWSCROLL_EVENT = EVENT_WINDOWSCROLL,
	MODTEXTINPUT_EVENT = EVENT_MODTEXTINPUT,
	TEXTINPUT_EVENT = EVENT_TEXTINPUT,
	LEFT_BUTTON_EVENT = EVENT_MOUSEBUTTON_LEFT,   // void mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
	RIGHT_BUTTON_EVENT = EVENT_MOUSEBUTTON_RIGHT,   // void mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
	CENTER_BUTTON_EVENT = EVENT_MOUSEBUTTON_CENTER     // void mouse_button_callback(GLFWwindow* window, int button, int action, int mods)

};

class MYSTIC Event
{
public:
	Event::Event();
	Event::~Event();

	Event::Event(unsigned int MSG);
 
	unsigned int WindowHandle;         //	HWND   hwnd;
	unsigned int Message;        //	UINT   message;
	unsigned long Time;          //	64Bit DWORD  time;
	Vec2 Location;               //	Vec2  X/Y Mouse Position;
	MSG_t Type;

	union MsgUnion
	{
		MsgUnion() {}
		MsgUnion& operator=(const MsgUnion&other) // Without this inside of the union the default assignment operator is deleted/
		{
			MsgStruct.wParam = other.MsgStruct.wParam;
			MsgStruct.lParam = other.MsgStruct.lParam;
			MsgStruct.Padding = other.MsgStruct.Padding;
			return *this;
		}
		// !!! WARNING: !!! 
		// WILL BLOCKING THIS EXTEND TO THE REST OF THE UNION? 
		// ANSWER:: No, It appears that it had not. Placing Const on one Union Member did not spill over to the other Union Members allows for a cheep(dangerous) way to access const variables which should not otherwise be access. 
		//     This is interesting considering its possible for the compiler to assign a static address for the const member meaning I will not essentially be accessing memory I otherwise should not. The question is 
		//     What area does it store those static const objects.  Perhaps try the same with const expression as its slightly(very) possible that it will point me in the direction of the .code block in my Executable.
		//     Doubtful... but slighly possible. Perform some hack test and data dump large  const and constexp arrays using the union to access the memory areas and inject itself into those positions.

		struct msgstruct
		{
			unsigned int wParam;         //	32Bit WPARAM wParam;   
			unsigned long lParam;        //	64Bit LPARAM lParam;
			unsigned long Padding; 
		}MsgStruct;
		struct kbstruct
		{
			unsigned int KeyCode;        //	WPARAM wParam;
			unsigned int ScanCode;
			unsigned int Action;         // Top 32Bits of Padding
			unsigned int Mods; // Bottom 32 Bits of Padding ;
		}KeyBoardStruct;
		struct mmstruct
		{

			struct mButtonStruct //unsigned int *Buttons;        //	WPARAM wParam;
			{
				unsigned char
					Left,
					Right,
					Middle,
					Wheel;
			}Buttons, &ButtonArray; // 32Bits
			const unsigned long Unused;  //64 UnusedBits	LPARAM lParam;
			const unsigned long Unused2; // 64Bit Padding
		}MouseMoveStruct;
		struct mcstruct
		{
										 //---- PROB JUST OUTRIGHT REMOVE THIS. SURE IT STRUCTURES IT SLIGHTLY MORE BUT AT TO MUCH OF A COST
			struct mButtonStruct //unsigned int *Buttons;        //	WPARAM wParam;
			{
				unsigned char
					Left,
					Right,
					Middle,
					Wheel;
			}Buttons, &ButtonArray;
			//---------------------------------------------------------------------------------------------
			int Action;//unsigned long *lParam;       //	LPARAM lParam;
			int Modification;
			const unsigned long Padding; //??? // lPrivate;

		}MouseClickStruct;
		struct ewstruct
		{
			unsigned int wParam;        //	WPARAM wParam;
			unsigned long lParam;       //	LPARAM lParam;

			const unsigned long Padding; //??? // lPrivate;

		}EnterWindowStruct;
		struct wsstruct
		{
			unsigned int Something;        //Dunno what to do with this yet	WPARAM wParam;
			unsigned int XOffset;
			unsigned int YOffset;       //X and Y make up 64bit	LPARAM lParam;
			unsigned long Unused = NULL; // Unused

		}WindowScrollStruct;
		struct jsstruct
		{
			unsigned int ScrollValue;        //	WPARAM wParam;
			unsigned long *lParam;       //	LPARAM lParam;
			const unsigned long Padding; //??? // lPrivate;

		}JoystickStruct;
		struct ddstruct
		{
			unsigned int wParam;        //	WPARAM wParam;
			unsigned long lParam;       //	LPARAM lParam;
			const unsigned long Padding; //??? // lPrivate;

		}DragdropStruct;
		struct tistruct
		{
			unsigned int *wParam;        //	WPARAM wParam;
			unsigned long *lParam;       //	LPARAM lParam;
			const unsigned long Padding; //??? // lPrivate;

		}TextInputStruct;
		struct timstruct
		{
			unsigned int *wParam;        //	WPARAM wParam;
			unsigned long *lParam;       //	LPARAM lParam;
			const unsigned long Padding; //??? // lPrivate;

		}TextInputModStruct;
		struct emstruct
		{

			unsigned int *wParam;        //	WPARAM wParam;
			unsigned long *lParam;       //	LPARAM lParam;
			const unsigned long Padding; //??? // lPrivate;

		}ErrorMessageStruct;
	}data;
 
	unsigned int MSG_Handle() { return Message; }
};
 
struct MYSTIC Listener
{
	Listener::Listener() {}
	virtual void Handler(Event msg) = 0;
};
 
class MYSTIC EventHandler
{
	EventHandler() {}
public:

	static EventHandler& GetInstance()
	{// Local Static Initialization allowing for singleton creation and instance returned subsequent times.
		static EventHandler instance;
		return instance;
	}

	void  MYST_TranslateMessage();// I WILL NOT NEED THIS, GLFW callbacks will do this for me
	MSG_BOOL PeekMSG(Event &msg, unsigned int rangemix, unsigned int rangemax, int howtohandle);
//	MSG_BOOL MYST_GetMessage(Event msg, unsigned int rangemin, unsigned int rangemax);

	Event MYST_GetInteruptMessage(double itimer);
	void PostMSG(Event msg);
	void RegisterListener(unsigned int msg, Listener *handler);

	void Dispatch(Event msg);

private:
	std::queue<Event> Messages;
	std::unordered_map<unsigned int, std::vector<Listener*>> EventMap;
 };






////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                          HELPER FUNCTIONS                                                                                                                            
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class InputManager
{
public:
	InputManager(GLFWwindow*window, EventHandler *handler);

	static void Scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
	static void Error_callback(int, const char*);
	static void Resize_Callback(GLFWwindow *window, int, int);
	static void Window_close_callback(GLFWwindow *window);
	static void KeyBoard_Callback(GLFWwindow *window, int, int, int, int);
	static void Mouse_Button_Callback(GLFWwindow *window, int, int, int);
	static void MouseMove_Callback(GLFWwindow *window, double, double);
	static void DropFile_callback(GLFWwindow *window, int, const char**);
	static void Window_Move_Callback(GLFWwindow *window, int, int);
	static void SetClipBoard(char*);
	static void Charmods_callback(GLFWwindow* window, unsigned int codepoint, int mods);
	static void Character_callback(GLFWwindow* window, unsigned int codepoint);
	static void WindowClose_callback(GLFWwindow *);
	static void Minimize_Window_callback(GLFWwindow *, int);
	static const char *GetClipBoard();

	static EventHandler *EventManager; // This is just Temp till I get a better solution for this shit.
};
// ============================================================================================================================================================================================================================================================
// ................................................................................. NOTES ....................................................................................................................................................................
// ============================================================================================================================================================================================================================================================
// Would it maybe be better to just store the Data in each struct as a void * along with a size Value for the memory block so that each message was as flexible as humanly possible;
// Each structure would just manage its own memory
// That way Each Message type would essentially be a Typedef struct designed to index and create reference for the Memory block returned from the Message
// ============================================================================================================================================================================================================================================================


//      
//      struct MYSTIC EventStructure
//      {
//      	EventStructure::EventStructure(int window, unsigned int msg, unsigned int *wP, unsigned long *lP);
//      	// Windows tagMSG structure
//      	unsigned int Handle;         //	HWND   hwnd;
//      	unsigned long Time;          //	DWORD  time;
//      
//      	unsigned int Message;        //	UINT   message;
//      	unsigned int *wParam;        //	WPARAM wParam;
//      	unsigned long *lParam;       //	LPARAM lParam;
//      	Vec2 Location;               //	POINT  pt;
//      	unsigned long Padding; //??? // lPrivate;
//      
//      };


/*
Maybe...
struct
{
private:
void *data;
const &size;
}
struct MouseType
{
unsigned char ButtonLeft;
unsigned char ButtonRight;
unsigned char ButtonCenter;
unsigned char ButtonX1;
unsigned char ButtonLX2;
unsigned char ButtonWheel;
}
size_t Size(){ return sizeof(MouseType);
*/