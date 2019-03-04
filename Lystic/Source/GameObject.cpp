#include"GameObject.h"
#include"EventHandler.h"

GameObject::GameObject()
	:
	Object()
{
}
GameObject::GameObject(std::string name)
	:
	Object(name)
{
}
GameObject::GameObject(std::string name, std::vector<Component*>newparts)
	:
	Object(name)
{
	Parts.insert(std::end(Parts), std::begin(newparts), std::end(newparts));
}


template<typename T>
unsigned int GameObject::AddComponent(Component *attribute)
{// Adds new Component of type T to the GameObject
	Component *part = new T();
	Parts.push_back(part);
}

void GameObject::SetState(unsigned int state)
{// Turns the State on or off( mainly a boolean however other states might exist in the future)
	Active = state;
} 




bool GameObject::CompareTag(TagID other)
{// Compare IDs via ID
	return (ID == other);
}
bool GameObject::CompareTag(GameObject *other)
{// Compare ID via passing the other GameObject
	return (ID == other->ID);
}




template<typename T> T* GameObject::GetComponent()
{  //Returns the component of Type T if the game object has one attached, null if it doesn't.
	_TRACE("Return Component of type T if Object has one else null if N/A");

}
template<typename T> T* GameObject::GetComponent(TagName name)
{  //Returns the component of Type T with a TagName of name null if it doesn't.
	_TRACE("Suppose to return Component of Type T with TagName $name");

}
template<typename T> std::vector<T*> GameObject::GetComponents()
{ //  GetComponents-- - Returns all components of Type type in the GameObject.
	_TRACE("Suppose to return All components in the GameObject of type T");
}
Object *GameObject::Find(TagName name)
{// Find a Given object by its Name given to it by the user... 
 // TODO: Possibly a name assigned to signify what exactly the thing is and not a user defined name
 // Not sure yet
	_TRACE("Run a Test on this Function");

	return ObjectList[ObjectMap[name]];
}


//  BroadcastMessage-- - Calls the method named methodName on every MonoBehaviour in this game object or any of its children.
//  SendMessageUpwards-- - Calls the method named methodName on every MonoBehaviour in this game object and on every ancestor of the behaviour.



//=============================================================================================================================================================================================================================
//_____________________________________________________________________________________________________________________________________________________________________________________________________________________________



// There are some Issues with this, Not much issues but I might implement this another way similar to my old Assets class and just have Object and other things Derive from that class so that for every object type defined
//      under that class it contains a static vector for the Avalible IDs, allowing for Tombstoning to avoid additional memory allocation, 
//      An std::map<> so that there is an std::string name attached to each object ID so that one can rapidly search the objects via its Common name;
// BELOW: Vector has been chosen. Benchmarks will be ran later but for now it is an std::vector
///      An std::list<> containing pointers(maybe references) to all the created game objects to ensure they are located in one spot for each access. 
//      Might possibly make that a vector to ensure that memory stays contiguous for cache reasons.
// void GameObject::SetHieState(unsigned int state)
// {
// 	Active = state;
// } // Turns the State on or off( mainly a boolean however other states might exist in the future)
// TagName Name;
// bool ActiveInHierachy; // Active in Search Efforts
// bool Active;           // Active in Current Scene
// TagID Layer;           // Which Layer Object exist on
// TagID Scene;           // Which Scene Object is contained in
// TagID ID;              // Tag for the game object
// 
// std::vector<Component> Parts; // Possibly make this a List or Map; Prob not map
 