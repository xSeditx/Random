#include"Gui.h"

#include"Application.h"

#include"Window.h"

GraphicInterface::GraphicInterface()
	:Component("GUI")
{// Initializes ImGUI

	ImGui::CreateContext();
	ImGui_ImplGlfw_InitForOpenGL(Window::Instance->GetContext(), true);
	ImGui::StyleColorsDark();
}






void GraphicInterface::Update()
{
}
void GraphicInterface::Render()
{
	ImGui::Render();
}






void Widget::Update()
{
}
void Widget::Render()
{
}