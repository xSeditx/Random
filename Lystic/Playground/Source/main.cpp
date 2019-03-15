#include"Application.h"
//#include"Mystic.h"
#include<iostream>
// __PRETTY_FUNCTION__
// https://social.msdn.microsoft.com/Forums/vstudio/en-US/02c69018-a182-48b3-94d1-250252aa00a7/prettyfunction?forum=vclanguage



#pragma message("Compiling SandBox Project")


class KB : public Listener
{
	void Handler(Event msg)
	{
		Print("Keyboard Message Handler:" << msg.MSG_Handle());
	}
}KeyH;
class Mouse : public Listener
{
	void Handler(Event msg)
	{
		Print("Mouse Event Message Handler " << msg.MSG_Handle());
	}
}MouseH;
class LeftClick : public Listener
{
	void Handler(Event msg)
	{
		Print("Mouse Left Event Message Handler " << msg.MSG_Handle());
	}
}LeftC;
class RightClick : public Listener
{
	void Handler(Event msg)
	{
		Print("Mouse Right Event Message Handler " << msg.MSG_Handle());
	}
}RightC;
 

class Mygame :  public Application
{
public:
	Mygame::Mygame()
	{
		CreateWindow();
		OnUserCreate();
	}
	Mygame::~Mygame() 
	{
	}
	void Start()
	{
		Print("Start");
		while (Running())
		{
			//MYST_GetMe
			Run();
		}
	}
	void Exit()
	{
		OnUserDestroy();
		Print("Exit");
	}
	void Pause()
	{
	}

	void OnUserCreate()
	{
		MessageHandler->RegisterListener(EVENT_KEYBOARD, &KeyH);
//		MessageHandler->RegisterListener(EVENT_MOUSEBUTTON, &MouseH);

		MessageHandler->RegisterListener(EVENT_MOUSEMOVE, &MouseH);
		MessageHandler->RegisterListener(EVENT_MOUSEBUTTON_LEFT, &LeftC);
		MessageHandler->RegisterListener(EVENT_MOUSEBUTTON_RIGHT, &RightC);
		MessageHandler->RegisterListener(EVENT_MOUSEBUTTON_CENTER, &MouseH);

	}
	void OnUserUpdate() {}
	void OnUserDestroy() {}
	void OnUserRender() {}


	void WindowSpecs()
	{
		Position.x = 0;
		Position.y = 0;
		Size.x = 640;
		Size.y = 480;
		Title = "Application Messaging System Test";

	}
 };



int main()
{
 	Mygame Game;
	//DONE("#pragma");
//	__debugbreak();
	Game.Start();
	Game.Exit();
}










/*

//#pragma message("Finished off attempting to implement some sort of Behavior of Monobehavior type script. Need to make a messaging system for the Render. I think I am going to make a System class like the event system and have all Render, Input,.. all systems maybe even the ECS derive from it")
//	Print("Finished with it Finally working, It is highly broken and much much more work needs to go into the component,object, entity gameobject classes but it compiles now and runs");
//	Print("Also, take this debug break stuff and this text stuff and make a Finshed for the night Macro so that I can remind myself where I finished, what changes i have made the time date etc incase I get seperated for sometime from the project i can pick back up where I left off");












struct Edge
{
Edge(Vertex *p1, Vertex *p2);
{
   Length = sqrt(Squared(p1 - p2));
}
Vertex *Other;
Vec3 Length;
float Tension;
};

struct Vertex
{
    Vec3 Position;
	Vec3 Start;
	std::vector<Edge> Edges;

	Vec3 Force(){ return 
	Vec3 Displacement(){ return Start-Position; }
};

class ALIEN
{
public:
    ALIEN(){}

	std::vector<Vertex> Vertices;

};






*/