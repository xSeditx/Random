#pragma once
#include"Imgui.h"
#include"imgui_impl_glfw.h"

#include"Object.h"
#include"Component.h"

class Widget : Component
{
public:
	Widget(): Component("Widget"){}
	void Update();
	void Render();
};


class Button : public Widget
{
public:
	Button(){}
};


class GraphicInterface : Component
{
public:
	GraphicInterface();

	void Update();
	void Render();
};
 