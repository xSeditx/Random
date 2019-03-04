#ifndef _COMPONENT_H
#define _COMPONENT_H
#pragma once

#include<vector>
#include<unordered_map>
#include"Common.h"
#include"Object.h"

#include"GameObject.h"
class Component : public Object
{
public:
	Component(TagName name)
		:Object(name)
	{
		// ComponentCount++; If this works it will be prefered over using ComponentCount Variable as it will be more robust and ensure the ID is the Index of the Component in the ComponentList Array;
		//     ~ 
		ID = ComponentList.size() + 1; 
		ComponentList.push_back(this);
	}


	virtual void Render() {}
	virtual void Update() {}
	virtual void Bind() {}
	virtual void Unbind() {}

	Component *Copy(Component& other) { return &other; }

 	template<typename T>
	T* Get();
	Component *Get(TagID Index) { return ComponentList[Index]; }
	TagID ID;

private:
	GameObject *ParentObject;
	// I STILL FEEL THE NEED TO ENCAPSLE THIS FUNCTIONALITY SOMEHOW IN A TEMPLATE SO THAT I CAN MAKE AN EASY TO IMPLEMENT ID SYSTEM
	static TagID ComponentCount;
 	static std::vector<Component*> ComponentList;
	static size_t size() { return ComponentList.size(); }
	static std::unordered_map<TagName, TagID> ComponentMap;
};
#endif


// In Unity A GameObject contains components
// Different components that you can add to a GameObject.
//=====================================================================
// Every Scene has a Main Camera GameObject by default. It has several components. 
// Camera Component
// GUILayer
// Flare Layer
// Audio Listener
// All of these components provide functionality to this GameObject.
// Rigidbody
// Collider
// Particle System
// Audio



// Create Component. For each component created a new templated class is created which manages that specific componenet type and stores them all appropriately in memory and makes accessing them easier.
/// [UPDATE:] I changed it to a vector. I think cache performance will make up for any latency generated through larger size objects or random access to the vector.
//           Might possibly make the List an std::vector<> to ensure the memory is contiguous for cache performance.


// NOTE: ON CACHE . Row Major order is more cache efficient.

//template<typename T>






/*

==========================================================================================================================================================================================================================================================================================================================================
_________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________

Component
=========
    class in UnityEngine /
    Inherits from : Object /
    Implemented in : UnityEngine.CoreModule
    
    Description
    ===========
        Base class for everything attached to GameObjects.
        
        NOTE: that your code will never directly create a Component.Instead, you write script code, and attach the script to a GameObject.
        
    
    Properties
    ==========
        gameObject --- The game object this component is attached to.A component is always attached to a game object.
        tag        --- The tag of this game object.
        transform  --- The Transform attached to this GameObject.
        
    
    Public Methods
    ==============
        BroadcastMessage	     ---  Calls the method named methodName on every MonoBehaviour in this game object or any of its children.
        CompareTag	             ---  Is this game object tagged with tag ?
        GetComponent	         ---  Returns the component of Type type if the game object has one attached, null if it doesn't.
        GetComponentInChildren	 ---  Returns the component of Type type in the GameObject or any of its children using depth first search.
        GetComponentInParent	 ---  Returns the component of Type type in the GameObject or any of its parents.
        GetComponents	         ---  Returns all components of Type type in the GameObject.
        GetComponentsInChildren	 ---  Returns all components of Type type in the GameObject or any of its children.
        GetComponentsInParent	 ---  Returns all components of Type type in the GameObject or any of its parents.
        SendMessage	             ---  Calls the method named methodName on every MonoBehaviour in this game object.
        SendMessageUpwards	     ---  Calls the method named methodName on every MonoBehaviour in this game object and on every ancestor of the behaviour.
    
    
    
    Inherited Members
    ==================
        Properties
        ==========
            hideFlags	--- Should the object be hidden, saved with the Scene or modifiable by the user ?
            name	    --- The name of the object.
        
        Public Methods
        ==============
            GetInstanceID	--- Returns the instance id of the object.
            ToString	    --- Returns the name of the GameObject.
            
        
        Static Methods
        ==============
            Destroy	            ---  Removes a gameobject, component or asset.
            DestroyImmediate	---  Destroys the object obj immediately.You are strongly recommended to use Destroy instead.
            DontDestroyOnLoad	---  Do not destroy the target Object when loading a new Scene.
            FindObjectOfType	---  Returns the first active loaded object of Type type.
            FindObjectsOfType	---  Returns a list of all active loaded objects of Type type.
            Instantiate   	    ---  Clones the object original and returns the clone.
            
        
        Operators
        =========
            bool	Does the object exist ?
            operator !=	Compares if two objects refer to a different object.
            operator ==	Compares two object references to see if they refer to the same object.
            
    ______________________________________________________________________________________________________________________________________________________________________________________________________________________
======================================================================================================================================================================================================================

*/
