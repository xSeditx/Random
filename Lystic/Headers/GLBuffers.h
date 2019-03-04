#pragma once

#include"Common.h"
#include<vector>

#define BUFFER_OFFSET(i)   ((char *)NULL + (i))


struct Vertex
{
	Vec3 Position;
	Vec3 Normals;
	Vec2 Uv;
};
struct Polygon3D
{
	Vertex Vertices[3];
}; 
enum BufferTypes
{
	VERTEX, COLOR, NORMAL, UVCOORD, TEXTURE, INDICE
};

class Attribute
{
public:
	Attribute() {}
	Attribute(BufferTypes t)
	{
		AttributeType = t;
	}
	BufferTypes AttributeType;
};

template<class T>
class VertexBufferObject : public Attribute
{ // OpenGL Buffer Object which holds raw Buffer data which can be given to the VAO as a specific Attribute type by assigning it that usecase.
public:
	VertexBufferObject() {}
	VertexBufferObject(T *data, GLsizei count)
		: /// Assume Dynamic Draw as the default buffer access
		ElementCount(count),
		ID(0)
	{
		Data.resize(count);
		Data.insert(Data.begin(), count, *data);
		Stride = sizeof(T);
		glGenBuffers(1, &ID);
		glBindBuffer(GL_ARRAY_BUFFER, ID);
		glBufferData(GL_ARRAY_BUFFER, ElementCount * sizeof(T), data, GL_DYNAMIC_DRAW);
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}
	VertexBufferObject(GLenum access, T *data, GLsizei count)
		: /// Specify default access
		ElementCount(count),
		ID(0)
	{
		Data.resize(count);
		Data.insert(Data.begin(), count, *data);
		Stride = sizeof(T);
		glGenBuffers(1, &ID);
		glBindBuffer(GL_ARRAY_BUFFER, ID);
		glBufferData(GL_ARRAY_BUFFER, ElementCount * sizeof(T), data, access);
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}

	void Bind()
	{
		glBindBuffer(GL_ARRAY_BUFFER, ID);
	}
	void Unbind()
	{
		glBindBuffer(GL_ARRAY_BUFFER, NULL);
	}
	void Map(GLenum accessflags)
	{
		glMapBuffer(GL_ARRAY_BUFFER, accessflags);
	}
	void MapRange(int offset, int count, GLenum accessflags)
	{// Possibly only avalible on later versions of OpenGL > 3.0
		glMapBufferRange(GL_ARRAY_BUFFER, offset, count, accessflags);
	}
	void Release()
	{// Should I just orphan this? Shoudl I delete it? I wish to reclaim the name and free any allocation associate with it.
		Print("Yeah, idk what the fuck to do with this. Release in VertexBufferObject class"); // Maybe I just need to delete it and forget it ever existed
	}
	void Destroy()
	{// Totaly remove the VAO from Graphic Memory and recover it by the Operating system
		glDeleteBuffer(ID);
		delete(this); // This may or maynot work.
	}

	VertexBufferObject operator = (std::vector<T> data);          // Map the whole buffer, resize if needed and make the data of the buffer equal to that of the Rvalue
	VertexBufferObject operator = (VertexBufferObject &other) { return other; }  // Same but perform a shallow copy of the buffer
	VertexBufferObject operator += (VertexBufferObject &data); // Map the buffer and add to the end of it, updating the data, and size while retaining access type and ID

	size_t size() const { return Data.size(); }

	GLuint ID = 0;
	GLuint ElementCount = 0;

protected:
	GLuint Stride;
	std::vector<T> Data;
};
class VertexArrayObject
{ // OpenGL VAO container which holds the state information for the Object contained on the GPU
public:
	VertexArrayObject()
	{
		glGenVertexArrays(1, &VAO);
	}

	GLuint VAO;
	int ElementCount;
	std::vector<Attribute> Buffers;


	void Bind()
	{
		glBindVertexArray(VAO);
	}
	void Unbind()
	{
		glBindVertexArray(0);
	}

	template<typename T>
	void Attach(BufferTypes bufferT, VertexBufferObject<T> *buffer)
	{
		Bind(); // First Bind the buffer to make it Current in the OpenGL Context

		GLint
			Amount = 0,
			Attrib = 0;

		switch (bufferT)
		{/// Case statement of Buffer types. Indices pushback then exit the function so that EnableVertexAttribArray and glVertexAttribPointer are never called.

		case BufferTypes::VERTEX:
			Amount = sizeof(T) / sizeof(float);
			buffer->AttributeType = VERTEX;
			glBindBuffer(GL_ARRAY_BUFFER, buffer->ID);
			Buffers.push_back(*buffer);
			break;

		case BufferTypes::COLOR:
			Amount = sizeof(T) / sizeof(float);
			buffer->AttributeType = COLOR;
			glBindBuffer(GL_ARRAY_BUFFER, buffer->ID);
			Buffers.push_back(*buffer);
			break;

		case BufferTypes::NORMAL:
			Amount = sizeof(T) / sizeof(float);
			buffer->AttributeType = NORMAL;
			glBindBuffer(GL_ARRAY_BUFFER, buffer->ID);
			Buffers.push_back(*buffer);
			break;

		case BufferTypes::UVCOORD:
			Amount = sizeof(T) / sizeof(float);
			buffer->AttributeType = UVCOORD;
			glBindBuffer(GL_ARRAY_BUFFER, buffer->ID);
			Buffers.push_back(*buffer);
			break;

		case BufferTypes::INDICE:
			ElementCount = buffer->ElementCount;
			buffer->AttributeType = INDICE;
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, buffer->ID);
			Buffers.push_back(*buffer);
			return; //  Exit since the Element Buffer is not an Attribute and continuing through in the function would result in attempting to bind the element buffer to an attribute slot
		}

		glEnableVertexAttribArray(Attrib);
		glVertexAttribPointer(Attrib, Amount, GL_FLOAT, GL_FALSE, 0, (char *)NULL);
	}
};
