#ifndef _ERRORSYSTEM_H
#define _ERRORSYSTEM_H


#pragma once

#include"Common.h"
#include"Application.h"
#include"EventHandler.h""

#define ERRORSYS_RESET 0x00000000  // 0
#define ERRORSYS_AUTOBREAK  0x00000001  // 1
#define ERRORSYS_BASIC_VIEW 0x00000002  // 2
#define ERRORSYS_DECORATED_VIEW 0x00000004  // 4
#define ERRORSYS_SIGNATURE_VIEW 0x00000008  // 8

#define ERRORSYS_OPENGL_DEBUGGING    0x00000010  // 16
#define ERRORSYS_COMPILER_MESSAGES   0x00000020  // 32
#define BIT6   0x00000040  // 64
#define BIT7   0x00000080  // 128
#define BIT8   0x00000100  // 256
#define BIT9   0x00000200  // 512
#define BIT10  0x00000400  // 1024
#define BIT11  0x00000800  // 2048
#define BIT12  0x00001000  // 
#define BIT13  0x00002000  // 
#define BIT14  0x00004000  // 
#define BIT15  0x00008000  // 
#define BIT16  0x00010000  // 

#define NO_ERRORS 0x00000000

#define CONSOLE_BlackBG                 30 
#define CONSOLE_BlackFG                 40
#define CONSOLE_RedBG                   31
#define CONSOLE_RedFG                   41
#define CONSOLE_GreenBG                 32
#define CONSOLE_GreenFG                 42
#define CONSOLE_YellowBG                33
#define CONSOLE_YellowFG                43
#define CONSOLE_BlueBG                  34 
#define CONSOLE_BlueFG                  44
#define CONSOLE_MagentaBG               35 
#define CONSOLE_MagentaFG               45
#define CONSOLE_CyanBG                  36 
#define CONSOLE_CyanFG                  46
#define CONSOLE_WhiteBG                 37 
#define CONSOLE_WhiteFG                 47
#define CONSOLE_Bright_BlackBG          90
#define CONSOLE_Bright_BlackFG         100
#define CONSOLE_Bright_RedBG            91 
#define CONSOLE_Bright_RedFG           101
#define CONSOLE_Bright_GreenBG          92 
#define CONSOLE_Bright_GreenFG         102
#define CONSOLE_Bright_YellowBG         93
#define CONSOLE_Bright_YellowFG        103
#define CONSOLE_Bright_BlueBG           94
#define CONSOLE_Bright_BlueFG          104
#define CONSOLE_Bright_MagentaBG        95 
#define CONSOLE_Bright_MagentaFG       105
#define CONSOLE_Bright_CyanBG           96 
#define CONSOLE_Bright_CyanFG          106
#define CONSOLE_Bright_WhiteBG          97 
#define CONSOLE_Bright_WhiteFG         107

#define MESSAGE_TEXT_COLOR  FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY

#define TEXT_COLOR_WARNING1  FOREGROUND_RED | FOREGROUND_GREEN  
#define TEXT_COLOR_WARNING2  FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY | 
#define TEXT_COLOR_WARNING3  FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY |  BACKGROUND_RED | BACKGROUND_GREEN |

#define TEXT_COLOR_ERROR    FOREGROUND_RED | FOREGROUND_INTENSITY

#define WARNING(x)


#define ERROR_NATIVE_WIN32     0x80
#define ERROR_MYSTIC_ENGINE    0xF0000000
#define ERROR_COMPILER         0x0F000000


#define SET_ERROR(E)       CALL_INFORMATION();\
                           SetError(E);\

enum WarningLevel
{
	SHOW_NONE,
	SHOW_ALL,

	FILE_OUTPUT,
	CONSOLE_OUTPUT,

	WARNING_LEVEL_ONE,
	WARNING_LEVEL_TWO,
	WARNING_LEVEL_THREE,

	ERROR_LEVEL_ONE,
	ERROR_LEVEL_TWO,
	ERROR_LEVEL_THREE
};
 
  /*
  Typename DisplayProperties Stucture
  ---------------------------
  Properties.Bit
  {
  bool ERROR_AUTO_BREAK;             TODO:: Sets a breakpoint as soon as an Error or Warning is received
  bool WARNING_VIEW_BASIC;		   TODO:: Displays the simple name of the Calling Function
  bool WARNING_VIEW_DECORATED;	   TODO:: Displays the signature of calling function as it would be defined for external linking with symbol values present
  bool WARNING_VIEW_SIGNATURE;	   TODO:: Displays signature of calling function as the user would write it in te IDE

  bool ERROR_OPENGL_DEBUG;		   TODO:: Retrieves OpenGL debug state and provides further Information about current state of the program
  bool Bit5;						   TODO:: Unused
  bool Bit6;						   TODO:: Unused
  bool Bit7;						   TODO:: Unused
  }

  Properties.BitPTR->[BitX]             :: Pointer to the Display Properties Bitfield
  Properties.Flags = 0;                 :: 8 bit Value Unionized with the Bitfield to allow easy masking and enumeration of various optional Properties state
  },  *PropertiesPTR;                    :: Pointer to the Properties Structure
  };
  */

struct WarningConfig
{
	WarningConfig::WarningConfig(std::int8_t Options) 
	{
		Properties.Flags = Options;
	}
	union flagUnion
	{
		struct bitfield
		{

			bool AUTO_BREAK_ON_ERROR;
			bool WARNING_VIEW_BASIC;
			bool WARNING_VIEW_DECORATED;
			bool WARNING_VIEW_SIGNATURE;

			bool ERROR_OPENGL_DEBUG;
			bool READABLE;
			bool SHOWERRORNUM;
			bool Bit7;

		}Bit, *BitPTR;
		std::int8_t Flags = 0;
	}Properties, *PropertiesPTR;
};
 
struct Error
{
	int ErrorNumber;         // System or user defined Error key
	unsigned long Time;      // Time which Error Occured
	int WindowID;            // Associated Window Handle( Possible Windows HWND... maybe GLFWWindow.... quite possibly MYSTIC_HWND because that will give me Flexibility when it comes to the GUI
	int ThreadID;            // Instance of the Currently active calling thread
	const char *Description; // Human readable version of the Error if Availible
	 

	//::ostream& operator<<(Error const &rhv) { return  __func__ ; }

};
std::ostream& operator<<(std::ostream& stream, const Error& msg)
{
	stream << "Calling Function " << __FUNCTION__  << "\n Message" << msg.Description << "\n Line Number:" <<  __LINE__  << "\n File: " __FILE__;
	return stream;
}


#define POST_ERROR(x) 

std::ostream& operator<<(std::ostream &lhv, Vec3 const &rhv);
std::ostream& operator<<(std::ostream &lhv, Vec4 const &rhv);
 
#include<consoleapi.h>
#include<map>


// TODO:: FIX THIS IS BACKWARDS
#define WARNING_LEVEL   2
#if WARNING_LEVEL < 3   // Normal
#    define __FUNCTIONSIG  __FUNCSIG__   //   __FUNCSIG__ : returns the signature of the function.For the above code that's void __thiscall A::A::Func(class std::basic_ostream<char,struct std::char_traits<char> > &).
#elif WARNING_LEVEL < 2 // Mangled
#    define __FUNCTIONSIG  __FUNCDNAME__ //   __FUNCDNAME__ : returns the decorated name of the function.For the above code that's ?Func@A@1@QAEXAAV?$basic_ostream@DU?$char_traits@D@std@@@std@@@Z.
#elif WARNING_LEVEL < 1 // Extern C linkage
#    define __FUNCTIONSIG  __FUNCTION__  //   __FUNCTION__ : returns just the name of the function.For the above code that's A::A::Func.
#endif
 
#define _BOOL_DISPLAY_FILENAME  " In File " << __FILE__
#define _BOOL_DISPLAY_TIME      " Time: " <<  __TIME__

#define _BOOL_DISPLAY_LINENUM   " Line: "<< __LINE__

#ifndef __FUNCTIONSIG
#    define _BOOL_DISPLAY_FUNCNAME   
#else
#    define _BOOL_DISPLAY_FUNCNAME  " Function: "<< __FUNCTIONSIG 
#endif

#define CALL_INFORMATION() 	Print(_BOOL_DISPLAY_FUNCNAME << _BOOL_DISPLAY_LINENUM << _BOOL_DISPLAY_FILENAME << _BOOL_DISPLAY_TIME);




class ErrorSys
{
public:
	ErrorSys::ErrorSys(WarningConfig sysattribs)
	{
		WarningConfig *A = &sysattribs;

		if (A->Properties.Bit.AUTO_BREAK_ON_ERROR)
		{
			DisplayFullInfo = true;
		}
		if (A->Properties.Bit.WARNING_VIEW_BASIC)
		{
			NotificationLevel = 1;
		}
		if (A->Properties.Bit.WARNING_VIEW_DECORATED)
		{
			NotificationLevel = 2;
		}
		if (A->Properties.Bit.WARNING_VIEW_SIGNATURE)
		{
			NotificationLevel = 3;
		}
		if (A->Properties.Bit.ERROR_OPENGL_DEBUG)
		{
			ProcessOpenGL = true;
		}
		if (A->Properties.Bit.READABLE)
		{
			DisplayErrorString = true;
		}

		if (A->Properties.Bit.SHOWERRORNUM)
		{
			DisplayErrorNumber = true;
		}

		ConsoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	}

	static ErrorSys *Logger;



	//  http://www.cplusplus.com/doc/tutorial/preprocessor/ PREPROCESSOR STUFF

	unsigned int GetNativeErrors()
	{
		int RETURN = GetLastError();
		Print("Native Error Triggered - (%d)\n" << RETURN);
		Error emsg;
		emsg.WindowID = RETURN;
		emsg.Description = "Native Windows Error:";
		emsg.ErrorNumber = ERROR_NATIVE_WIN32;

		SetError(emsg);
			return RETURN;
	}





	void ClearError()                        // Erases the Error Log and sets the Error flag to reflect this clear state
	{
		ErrorList.clear();
		ErrorFlag = false;
	}


	// WARNING! THIS MAY NOT WORK CORRECTLY, IF IT CAN NOT INLINE THE LINE NUMBER WILL ORIGINATE FROM HERE
	__forceinline void SetError(Error error) // Pushes a fully generated Error onto the error stack
	{
		CALL_INFORMATION();
		ErrorFlag = true;
		ErrorList.push_back(error);
	}
	__forceinline void SetError(int er) // Generates the error struct via identification of the error number
								 // MUST BE INLINE ELSE IT WILL RETURN WRONG RESULTS
	{

		Error ErrMSG;
		ErrMSG.ErrorNumber = er;
		ErrMSG.Time = Application::GetTime(); // This should be long long I believe
	//	ErrMSG.WindowID = Window::Instance->GetHandle(); // The handle this currently returns is not its final form. I will be be embedding information about the Native Window handle and OpenGL context in it
	//	ErrMSG.ThreadID = GetActiveThread();
		ErrorFlag = true;
		ErrorList.push_back(ErrMSG);
		if (AutoBreak == true)
		{
			__debugbreak;
		}
	}
	int PopErrorNum() //Sometimes the Error Number is desired
	{
		int RETURN = ErrorList.back().ErrorNumber;   // Retrieves the Error number for the Last Error.
		ErrorList.pop_back();                 // Pop last Error off the Error stack and return its value
		if (ErrorList.empty() == true) ErrorFlag = NO_ERRORS;
		return RETURN;
	}
	Error PopError()                          // Essentially functions like the previous function however returns a full Error Struct
	{
		Error RETURN = LastError();
		ErrorList.pop_back();
		if (ErrorList.empty() == true) ErrorFlag = NO_ERRORS;
		return RETURN;
	}





	void DispatchError(Error msg)
	{
		Event ProcessedMSG;
		Print(msg);
		EventProcessor->Handler(ProcessedMSG);
	}


	void AttachListener(Listener *_handler) { EventProcessor = _handler; }


	const Error& LastError() { return ErrorList.back(); };

	const bool isError() { return ErrorFlag; }
	const bool Exist(){ return (Logger == NULL);}
private:

	int NotificationLevel = 0;
	bool ProcessOpenGL = false;
	bool DisplayErrorString = false;
	bool DisplayErrorNumber = true;
	bool DisplayFullInfo = false;
	bool AutoBreak = false;
	bool ErrorFlag = false;

	std::map<unsigned int, const char *> ErrorMapper
	{
		std::make_pair(ERROR_NATIVE_WIN32, "Native Win32 Error"),
		std::make_pair(ERROR_MYSTIC_ENGINE, "Mystic Application Error"),
		std::make_pair(ERROR_COMPILER, "Internal Compiler Error or conflict with current Engine state"),
	};
	void SetTextColor(int _color)
	{
		SetConsoleTextAttribute(ConsoleHandle, _color);
	}

	HANDLE ConsoleHandle;

	std::vector<Error> ErrorList;

	Listener *EventProcessor;

	struct CompilerDebugInfo
	{
		CompilerDebugInfo()
		{
			Date = __DATE__;
			CPPVersion = __cplusplus;
		}

		char *Date;
		int CPPVersion;

		void Display()
		{
#ifdef  __STDC__
			Print("Standard C compliant Version: " << __STDC_VERSION__);
#endif
#ifdef __STDC_MB_MIGHT_NEQ_WC__
			Print("Multibyte Encoding:");
			WARNING("Might give a character a different value in character literals")
#endif
		}
	}SystemInfo;
};




ErrorSys *ErrorSys::Logger = new ErrorSys(ERRORSYS_AUTOBREAK);

ErrorSys ERRORSYSTEM;

void error_callback(int error, const char* description)
{
	Error msg;
	msg.ErrorNumber = error;
	msg.Description = description;
	//msg.WindowID = Window::Instance->GetHandle();
	ErrorSys::Logger->SetError(error); // PASS THESE INTO PROCESSGLFWERROR Further more send that to the Event Handler
}



Event ProcessGLFW_Error(Error _IN)
{
	Event _OUT;

	//_OUT.data.MsgStruct.Handle = _IN.WindowID;
	//_OUT.data.MsgStruct.Time = _IN.Time;
	//_OUT.data.MsgStruct.Message = _IN.ErrorNumber; // TODO: PROCESS THIS
	//_OUT.data.MsgStruct.Location = Vec2(0);

	_OUT.data.MsgStruct.wParam = 0;
	_OUT.data.MsgStruct.lParam = 0;

	//_OUT.data.MsgStruct.Padding = 0;
}


 






// Error GenerateHeader(int er)
// {
// 	Error RETURN;
// 	RETURN.WindowID = Window::Instance->GetHandle();
// 	RETURN.ThreadID = GetActiveThread();
// }


//TODO: Create Method Based on This
/*
BOOL WINAPI SetStdHandle(
_In_ DWORD  nStdHandle,
_In_ HANDLE hHandle
);
Value	Meaning
STD_INPUT_HANDLE(DWORD) - 10
The standard input device.

STD_OUTPUT_HANDLE(DWORD) - 11
The standard output device.

STD_ERROR_HANDLE(DWORD) - 12
The standard error device. */






// #define 0x00000000  // 0
// #define 0x00000001  // 1
// #define 0x00000002  // 2
// #define 0x00000004  // 4
// #define 0x00000008  // 8
// #define 0x00000010  // 16
// #define 0x00000020  // 32
// #define 0x00000040  // 64
// #define 0x00000080  // 128
// #define 0x00000100  // 256
// #define 0x00000200  // 512
// #define 0x00000400  // 1024
// #define 0x00000800  // 2048
// #define 0x00001000  // 
// #define 0x00002000  // 
// #define 0x00004000  // 
// #define 0x00008000  // 
// METHODS
/* you can use these constants
FOREGROUND_BLUE
FOREGROUND_GREEN
FOREGROUND_RED
FOREGROUND_INTENSITY
BACKGROUND_BLUE
BACKGROUND_GREEN
BACKGROUND_RED
BACKGROUND_INTENSITY
*/




#endif