#pragma once

#include"Common.h"

#include<unordered_map>

#include"Scene.h"

/*==================================================================================================================================================

  ===================================================================================================================================================*/
  // TODO: SET THESE UP SO EACH VISBIT IS ASSOCIATED WITH A DIFFERENT BIT IN A 32 BIT Uint TO DENOTE STATE OF ATTRIBUTE
#define VISBIT_HIDDEN        // Hide from all activity in the scene essentially turning object off for that period of time
#define VISBIT_VISIBLE       // Actively display the object
#define VISBIT_DESTRUCTABLE  // Prevent destruction when parent is destroyed
#define VISBIT_UPDATABLE     // Turn Physics on or off NOTE: Might slightly change this meaning
#define VISBIT_ACTIVE_SEARCH // Active in Search Efforts
#define VISBIT_ACTIVE        // Active in Current Scene NOTE: Possibly just ignore and use HIDDEN instead for this

class Event;
class Listener;


class Object
{
public:
	Object(); // Creates an Empty object consisting of only a Transform Component and even thats Position is set to 0.f as well as its rotation.
	Object(TagName name) :Name(name){}
	virtual void Render() {}
	virtual void Update() {}
	virtual void Bind() {}
	virtual void Unbind() {}

	TagID  Get_ID() { return ID; }
	TagName GetName() { return Name; }


	void SetListener(Event msg, Listener *method);
	void BroadcastMessage(Event msg); // Pass Message to all child components
	static std::unordered_map<TagName, TagID> ObjectMap;

	template<typename T> unsigned int AddComponent(Component *attribute);

private:

	Scene Environment;
	unsigned int Layer;
	unsigned int Visibility;

	TagName Name;
	TagID     ID;
 };


// void SetListener(Event msg, Listener *method); //  SendMessage-- - Calls the method named methodName on every MonoBehaviour in this game object.
// 
// std::unordered_map<unsigned int, Listener*> BehaviorMap;
// static std::vector<TagID> AvalibleIDs;
// static std::vector<Object*> ObjectList;

//  UNITY GAME ENGINE COMPONENT STRUCTURE
// https://www.youtube.com/watch?v=JxI3Eu5DPwE
/*
https://www.agner.org/optimize/    Software Optimization
==========================================================================================================================================================================================================================================================================================================================================
_________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________

Component
=========
_____________________________________________________________________________________________________________________________________________________________________________________

class in UnityEngine / 
	Inherits from : Object /
	Implemented in : UnityEngine.CoreModule 
	_____________________________________________________________________________________________________________________________________________________________________________________

	Description
	===========
	Base class for everything attached to GameObjects.
	_____________________________________________________________________________________________________________________________________________________________________________________

	NOTE: that your code will never directly create a Component. Instead, you write script code, and attach the script to a GameObject.
	_____________________________________________________________________________________________________________________________________________________________________________________

	Properties
	==========
	gameObject --- The game object this component is attached to.A component is always attached to a game object.
	tag        --- The tag of this game object.
	transform  --- The Transform attached to this GameObject.
	_____________________________________________________________________________________________________________________________________________________________________________________

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
	_____________________________________________________________________________________________________________________________________________________________________________________

	Inherited Members
	==================
	_____________________________________________________________________________________________________________________________________________________________________________________

	Properties
	==========
	hideFlags	--- Should the object be hidden, saved with the Scene or modifiable by the user ?
	name	    --- The name of the object.
	_____________________________________________________________________________________________________________________________________________________________________________________

	Public Methods
	==============
	GetInstanceID	--- Returns the instance id of the object.
	ToString	    --- Returns the name of the GameObject.
	_____________________________________________________________________________________________________________________________________________________________________________________


	Static Methods
	==============
	Destroy	            ---  Removes a gameobject, component or asset.
	DestroyImmediate	---  Destroys the object obj immediately.You are strongly recommended to use Destroy instead.
	DontDestroyOnLoad	---  Do not destroy the target Object when loading a new Scene.
	FindObjectOfType	---  Returns the first active loaded object of Type type.
	FindObjectsOfType	---  Returns a list of all active loaded objects of Type type.
	Instantiate   	    ---  Clones the object original and returns the clone.
	_____________________________________________________________________________________________________________________________________________________________________________________


	Operators
	=========
	bool	Does the object exist ?
	operator !=	Compares if two objects refer to a different object.
	operator ==	Compares two object references to see if they refer to the same object.

______________________________________________________________________________________________________________________________________________________________________________________________________________________
======================================================================================================================================================================================================================

*/

// FOR REFERENCE
//================================
// for_each() TEMPLATE 
//
// template<class InputIterator, class Function>
// Function for_each(InputIterator first, InputIterator last, Function fn)
// {
// 	while (first != last) {
// 		fn(*first);
// 		++first;
// 	}
// 	return fn;      // or, since C++11: return move(fn);
// }

/*


DATA && CODE
============
-- Properties    <--> Get/Set       |\
-- Methods       <--> Call            } APPLICATION
-- Events        <--> Respond to    |/

EVENTS->SCHEDULER->vector<EventHandler> ListenerMap;

Application class has the EventHandler, this Objects should be able to call Event Handler so I think I should make it a singleton. Yup... Lemme do that

*/

// 
// class Action
// {
// public:
// 	Action()
// 	{}
// 	Object *TargetObject;
// 	MsgID Msg;
// };
// 