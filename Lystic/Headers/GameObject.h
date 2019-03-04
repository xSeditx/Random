#pragma once

#include"Transform.h"

#include"Object.h"
#include"Component.h"



class MYSTIC GameObject : public Object
{

public:

	GameObject();
	GameObject(std::string name);
	GameObject(std::string name, std::vector<Component*>parts);

	//template<typename T> unsigned int AddComponent(Component *attribute);
	bool CompareTag(TagID other);
	bool CompareTag(GameObject *other);
	void SetState(unsigned int state); // Turns the State on or off( mainly a boolean however other states might exist in the future)
												   //  BroadcastMessage-- - Calls the method named methodName on every MonoBehaviour in this game object or any of its children.
												   //  SendMessageUpwards-- - Calls the method named methodName on every MonoBehaviour in this game object and on every ancestor of the behaviour.
	Transform Location;

	unsigned int hasTag() { return (ID != 0); }
	unsigned int hasName() { return (Name.empty() != 0); }

	//Object *Find(TagName obj);
	//static std::vector<Object*> ObjectList;
	//static std::unordered_map<TagName, TagID> ObjectMap; // To organize and make rapidly searchable the ObjectList array by returning the Objects ID when given a string;
	//static std::vector<unsigned int> ValidIDs;
	//
	//Transform *ObjectTransform;
	//


	template<typename T> T* GetComponent();                    //Returns the component of Type T if the game object has one attached, null if it doesn't.
	template<typename T> T* GetComponent(TagName name); 	   //  GetComponents-- -Components of Type T that contains the TagName of name
	template<typename T> std::vector<T*> GetComponents(); 	   //  GetComponents-- - Returns all components of Type type in the GameObject.

	static Object Instantiate(Object original);
	static Object Instantiate(Object original, Transform parent);
	static Object Instantiate(Object original, Transform parent, bool instantiateInWorldSpace);
	static Object Instantiate(Object original, Vec3 position, Vec3 rotation);
	static Object Instantiate(Object original, Vec3 position, Vec3 rotation, Transform parent);

private:

	TagName Name;
	TagID Layer;           // Which Layer Object exist on
	TagID Scene;           // Which Scene Object is contained in
	TagID ID;              // Tag for the game object

	std::vector<Component> Parts; // Possibly make this a List or Map; Prob not map
};



//  GetComponentInChildren-- - Returns the component of Type type in the GameObject or any of its children using depth first search.
//  GetComponentInParent-- - Returns the component of Type type in the GameObject or any of its parents.
//  GetComponentsInChildren-- - Returns all components of Type type in the GameObject or any of its children.
//  GetComponentsInParent-- - Returns all components of Type type in the GameObject or any of its parents.












/*
===================================================================================================================================================================================================================================================================
___________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________

                                                  REFERENCE FOR UNITY IMPLEMENTATION OF GAMEOBJECT
===================================================================================================================================================================================================================================================================

GameObject
==========
class in UnityEngine / 
Inherits from : Object / 
Implemented in : UnityEngine.CoreModuleOther VersionsLeave feedback

	SWITCH TO MANUAL
	================

	Description
	===========
	Base class for all entities in Unity Scenes.

	Note : Many variables in the GameObject class have been removed.To access, for example GameObject.renderer in csharp use GetComponent<Renderer>() instead.
	 
	Properties
	==========

	activeInHierarchy	--- Defines whether the GameObject is active in the Scene.
	activeSelf	        --- The local active state of this GameObject. (Read Only)
	isStatic	        --- Editor only API that specifies if a game object is static.
	layer	            --- The layer the game object is in.
	scene	            --- Scene that the GameObject is part of.
	tag	                --- The tag of this game object.
X	transform	        --- The Transform attached to this GameObject.

	Constructors
	============

	GameObject	--- Creates a new game object, named name.
	public GameObject();
	public GameObject(string name);
	public GameObject(string name, params Type[] components);


	Public Methods
	==============

	AddComponent	        --- Adds a component class named className to the game object.
	BroadcastMessage	    --- Calls the method named methodName on every MonoBehaviour in this game object or any of its children.
	CompareTag             	--- Is this game object tagged with tag ?
	GetComponent	        --- Returns the component of Type type if the game object has one attached, null if it doesn't.
	GetComponentInChildren	--- Returns the component of Type type in the GameObject or any of its children using depth first search.
	GetComponentInParent	--- Returns the component of Type type in the GameObject or any of its parents.
	GetComponents	        --- Returns all components of Type type in the GameObject.
	GetComponentsInChildren	--- Returns all components of Type type in the GameObject or any of its children.
	GetComponentsInParent	--- Returns all components of Type type in the GameObject or any of its parents.
	SendMessage	            --- Calls the method named methodName on every MonoBehaviour in this game object.
	SendMessageUpwards	    --- Calls the method named methodName on every MonoBehaviour in this game object and on every ancestor of the behaviour.
	SetActive	            --- Activates / Deactivates the GameObject.

	Static Methods
	==============

	CreatePrimitive	        --- Creates a game object with a primitive mesh renderer and appropriate collider.
	Find	                --- Finds a GameObject by name and returns it.
	FindGameObjectsWithTag	--- Returns a list of active GameObjects tagged tag.Returns empty array if no GameObject was found.
	FindWithTag	            --- Returns one active GameObject tagged tag.Returns null if no GameObject was found.
	

	Inherited Members
	=================

	Properties
	==========

	hideFlags	        --- Should the object be hidden, saved with the Scene or modifiable by the user ?
	name	            --- The name of the object.

	Public Methods
	==============
	GetInstanceID	    --- Returns the instance id of the object.
	ToString	        --- Returns the name of the GameObject.

	Static Methods
	==============
	Destroy	            --- Removes a gameobject, component or asset.
	DestroyImmediate	--- Destroys the object obj immediately.You are strongly recommended to use Destroy instead.
	DontDestroyOnLoad	--- Do not destroy the target Object when loading a new Scene.
	FindObjectOfType	--- Returns the first active loaded object of Type type.
	FindObjectsOfType	--- Returns a list of all active loaded objects of Type type.
	Instantiate	        --- Clones the object original and returns the clone.

	Operators
	=========
	bool	Does the object exist ?
	operator !=	Compares if two objects refer to a different object.
	operator ==	Compares two object references to see if they refer to the same object.

_________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________
=========================================================================================================================================================================================================================================================================================

	*/