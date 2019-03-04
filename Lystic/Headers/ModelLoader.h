#pragma once
#include<string>
 
class Mesh; // Placeholder set in the CPP till proper Mesh class is created


enum class ModelType
{
	ERROR_TYPE,
	OBJ = 0x01, // WaveFront OBJ
	_3DS,
	FBX,
	DAE, // COLLAB file
	STL,
	STO,
	IGS,
	WRL,
	PLY,
	PRT
};



// STACK OVERFLOW Singleton design patterns
/// https://stackoverflow.com/questions/1008019/c-singleton-design-pattern
 class ModelLoader
 {
 public:
	 static ModelLoader& getInstance()
	 {// Local Static Initialization allowing for singleton creation and instance returned subsequent times.
		 static ModelLoader instance;  
		 return instance;
	 }

	 static void LoadModel(std::string path);
	 static void LoadOBJ(std::string path);

 private:
	 ModelLoader() {}
	 ModelLoader(ModelLoader const&) = delete;
	 void operator=(ModelLoader const&) = delete;

	 ModelType Get_Format(std::string path);
 };



//  MIGHT BE USEFUL IN SOME FUTURE SITUATIONS, HAVE NOT DECIDED YET BUT STORING HERE FOR NOW
//  Another non - allocating alternative : create a singleton, say of class C, as you need it :
//  
//  singleton<C>()
//  	 using
//  
//  	 template <class X>
//  X& singleton()
//  {
//  	 static X x;
//  	 return x;
//  }