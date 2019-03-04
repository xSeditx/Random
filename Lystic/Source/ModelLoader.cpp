#include"Common.h" // TODO: CLEAR ALL THIS ADDED MESS OF UNNEEDED INCLUDES
#include <fstream>
#include <iostream>
#include <algorithm>
#include <vector>
#include <list>

#include"ModelLoader.h"
#include"GLBuffers.h"
#include"Mesh.h"

  
ModelType ModelLoader::Get_Format(std::string path)
{ // Checks the Extension of the named file to determine what Load Method will be used to parse the File

	ModelType RETURN = ModelType::ERROR_TYPE;;
	size_t Position = path.find_last_of(".");

	if (Position != std::string::npos)
	{
		std::string Extension = path.substr(path.find_last_of(".") + 1);

 		std::transform(Extension.begin(), Extension.end(), Extension.begin(), ::tolower);
 
		if (Extension == "obj")
		{
			RETURN = ModelType::OBJ;
		}
		else if(Extension == "fbx")
		{
			RETURN = ModelType::OBJ;
		}
		else if(Extension == "dae")
		{
			RETURN = ModelType::DAE;
		}
		//TODO: etc..... FIGURE OUR THE OTHER FORMATS
 	}
	return RETURN;
}
void ModelLoader::LoadModel(std::string path)
{
	ModelType format = ModelLoader::getInstance().Get_Format(path);
	switch (format)
	{
	case ModelType::OBJ:
	{
		LoadOBJ(path);
	}break;

	case ModelType::STL: //  NOTHING BELOW THIS POINT IS COMPLETE AND THE OBJ LOADER COULD USE SOME WORK AS WELL BUT IT HAS BEEN KNOW TO WORK
	{

	}break;
	case ModelType::FBX:
	{

	}break;
	case ModelType::_3DS:
	{

	}break;
	case ModelType::DAE:
	{

	}break;
	case ModelType::STO:
	{

	}break;
	case ModelType::IGS:
	{

	}break;
	case ModelType::WRL:
	{

	}break;
	case ModelType::PLY:
	{

	}break;
	case ModelType::PRT:
	{

	}break;
	};
}
void ModelLoader::LoadOBJ(std::string path)
{// Loads an OBJ 3D file into a Mesh Object/ TODO: Include the MeshObject as either A parameter as a reference or use Mesh as the return type for this Model Loader.

//	__debugbreak();// WORKING BUT FURTHER EFFORT NEEDS TO BE PUT IN TOMORROW TO CLEAR THIS UP FOLLOWED BY THE LOADING OF _3DS as well as define the Mesh Structure. That is Tomorrow Goal
	FILE *file;
	fopen_s(&file, path.c_str(), "r");

	if (file == nullptr)
	{
		Print("Cannot open the file: " << path.c_str());
		__debugbreak();
		exit(0x20);
	}


	std::vector<Vec3>   Vertices;
	std::vector<Vec3>   Normals;
	std::vector<Vec2>   UVCoords;
	std::vector<GLuint> Indices;

	while (TRUE)
	{
		char lineHeader[128];
		// read the first word of the line
		int res = fscanf_s(file, "%s", lineHeader, 128);
		 
		if (res == EOF)
		{
			break; // EOF = End Of File. Quit the loop.
		}
		if (strcmp(lineHeader, "v") == 0)
		{
			glm::vec3 Vert;
			fscanf_s(file, "%f %f %f\n", &Vert.x, &Vert.y, &Vert.z);
			Vertices.push_back(Vert);
		}
		else if (strcmp(lineHeader, "vt") == 0)
		{
			glm::vec2 uv;
			fscanf_s(file, "%f %f\n", &uv.x, &uv.y);
			UVCoords.push_back(uv);
		}
		else if (strcmp(lineHeader, "vn") == 0)
		{
			glm::vec3 normal;
			fscanf_s(file, "%f %f %f\n", &normal.x, &normal.y, &normal.z);
			Normals.push_back(normal);
		}
		else if (strcmp(lineHeader, "f") == 0)
		{
			glm::vec3 inds;
			GLuint I1 = 0, I2 = 0, I3 = 0;
			fscanf_s(file, "%d %d %d\n", &I1, &I2, &I3);// %f %f
			I1--;
			I2--;
			I3--;
			Indices.push_back(I1);
			Indices.push_back(I2);
			Indices.push_back(I3);
		}

	}

	Normals.resize(Vertices.size(), glm::vec3(0.0, 0.0, 0.0));

	for (int i = 0; i < Indices.size(); i += 3)
	{
		GLushort ia = Indices[i];
		GLushort ib = Indices[i + 1];
		GLushort ic = Indices[i + 2];
		glm::vec3 normal = glm::normalize(glm::cross(
			glm::vec3(Vertices[ib]) - glm::vec3(Vertices[ia]),
			glm::vec3(Vertices[ic]) - glm::vec3(Vertices[ia])));
		Normals[ia] = Normals[ib] = Normals[ic] = normal;
	}
	std::vector<Vec2> cord;
	for_loop(Index, Vertices.size())
	{
		cord.push_back(Vec2(Vertices[Index].x, Vertices[Index].y));
	}

 // TODO
	// OBVIOUSLY REPLACE THIS WITH THE MESH THAT IS BEING LOADED
	VertexArrayObject VAO;
VAO.Attach(BufferTypes::VERTEX, new VertexBufferObject<Vec3>(&Vertices[0], Vertices.size()));
VAO.Attach(BufferTypes::NORMAL, new VertexBufferObject<Vec3>(&Normals[0], Normals.size()));
VAO.Attach(BufferTypes::UVCOORD, new VertexBufferObject<Vec2>(&cord[0], Normals.size()));
VAO.Attach(BufferTypes::COLOR, new VertexBufferObject<Vec3>(&Normals[0], Normals.size()));
VAO.Attach(BufferTypes::INDICE, new VertexBufferObject<GLuint>(&Indices[0], Indices.size()));
}

// WaveFront format etc... https://www.fileformat.info/format/wavefrontobj/egff.htm
// PDF of OBJ Format: http://www.cs.utah.edu/~boulos/cs3505/obj_spec.pdf

// NOTES: https://all3dp.com/1/obj-file-format-3d-printing-cad/
//    The most commonly used file formats in 3D Graphics applications are OBJ, FBX, and COLLADA.
//    The OBJ file format does not support scene information and animations while FBX and COLLADA does.
//    The OBJ file format lets you store color and texture information in a companion file format called the Material Template Library (MTL) format. This partner file has the extension .MTL.
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//_____________________________________________________________
// OBJ Format structure
//_____________________________________________________________
//         Type	                         v     3D Vector
//         Colors	                          Unlimited
//         Compression	                      Uncompressed
//         Maximum Image Size	              Unlimited
//         Multiple Images Per File	          Yes
//         Numerical Format	                  NA
//         Originator	                      Wavefront
//         Platform	                          UNIX
//         Supporting Applications	          Advanced Visualizer
//_____________________________________________________________


