#pragma once
#include"Common.h"


#include"GLBuffers.h"


class Renderer
{
public:
	Renderer();

	VertexArrayObject *VAO;
	GLuint ID;
};