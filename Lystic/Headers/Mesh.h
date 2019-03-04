#pragma once

#include"Component.h"
#include"GLBuffers.h"

class Mesh : public Component
{
public:
	Mesh();

	size_t size() { return VertexCount; }
private:
	VertexArrayObject VAO;
	size_t VertexCount;
};