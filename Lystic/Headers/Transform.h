#pragma once
 
#include"Common.h"
#include"Component.h"
 
struct Transform : public Component
{
	Transform();
	Transform(Vec3 p, Vec3 r, Vec3 s);
	void Set_Position(Vec3 pos);
	void Set_Rotation(Vec3 pos);
	void Set_Scale(Vec3 pos);
	void Set_Transform(Vec3, Vec3, Vec3);
	  
private:
	void Update();
	Vec3 Position;
	Vec3 Rotation;
	Vec3 Scale;

	Vec3 Up, Forward, Right;
	Matrix Mat4 = Matrix(0.0);
};
/*

Transform
class in UnityEngine/Inherits from:Component/Implemented in:UnityEngine.CoreModuleOther VersionsLeave feedback
SWITCH TO MANUAL
Description
Position, rotation and scale of an object.

Every object in a Scene has a Transform.
It's used to store and manipulate the position,
rotation and scale of the object.
Every Transform can have a parent, which allows you to apply position, rotation and scale hierarchically.
This is the hierarchy seen in the Hierarchy pane.
They also support enumerators so you can loop through children using:

using UnityEngine;


Properties
childCount	The number of children the parent Transform has.
eulerAngles	The rotation as Euler angles in degrees.
forward	The blue axis of the transform in world space.
hasChanged	Has the transform changed since the last time the flag was set to 'false'?
hierarchyCapacity	The transform capacity of the transform's hierarchy data structure.
hierarchyCount	The number of transforms in the transform's hierarchy data structure.
localEulerAngles	The rotation as Euler angles in degrees relative to the parent transform's rotation.
localPosition	Position of the transform relative to the parent transform.
localRotation	The rotation of the transform relative to the transform rotation of the parent.
localScale	The scale of the transform relative to the parent.
localToWorldMatrix	Matrix that transforms a point from local space into world space (Read Only).
lossyScale	The global scale of the object (Read Only).
parent	The parent of the transform.
position	The world space position of the Transform.
right	The red axis of the transform in world space.
root	Returns the topmost transform in the hierarchy.
rotation	The rotation of the transform in world space stored as a Quaternion.
up	The green axis of the transform in world space.
worldToLocalMatrix	Matrix that transforms a point from world space into local space (Read Only).
Public Methods
DetachChildren	Unparents all children.
Find	Finds a child by n and returns it.
GetChild	Returns a transform child by index.
GetSiblingIndex	Gets the sibling index.
InverseTransformDirection	Transforms a direction from world space to local space. The opposite of Transform.TransformDirection.
InverseTransformPoint	Transforms position from world space to local space.
InverseTransformVector	Transforms a vector from world space to local space. The opposite of Transform.TransformVector.
IsChildOf	Is this transform a child of parent?
LookAt	Rotates the transform so the forward vector points at /target/'s current position.
Rotate	Use Transform.Rotate to rotate GameObjects in a variety of ways. The rotation is often provided as a Euler angle and not a Quaternion.
RotateAround	Rotates the transform about axis passing through point in world coordinates by angle degrees.
SetAsFirstSibling	Move the transform to the start of the local transform list.
SetAsLastSibling	Move the transform to the end of the local transform list.
SetParent	Set the parent of the transform.
SetPositionAndRotation	Sets the world space position and rotation of the Transform component.
SetSiblingIndex	Sets the sibling index.
TransformDirection	Transforms direction from local space to world space.
TransformPoint	Transforms position from local space to world space.
TransformVector	Transforms vector from local space to world space.
Translate	Moves the transform in the direction and distance of translation.
Inherited Members
Properties
gameObject	The game object this component is attached to. A component is always attached to a game object.
tag	The tag of this game object.
transform	The Transform attached to this GameObject.
hideFlags	Should the object be hidden, saved with the Scene or modifiable by the user?
name	The name of the object.
Public Methods
BroadcastMessage	Calls the method named methodName on every MonoBehaviour in this game object or any of its children.
CompareTag	Is this game object tagged with tag ?
GetComponent	Returns the component of Type type if the game object has one attached, null if it doesn't.
GetComponentInChildren	Returns the component of Type type in the GameObject or any of its children using depth first search.
GetComponentInParent	Returns the component of Type type in the GameObject or any of its parents.
GetComponents	Returns all components of Type type in the GameObject.
GetComponentsInChildren	Returns all components of Type type in the GameObject or any of its children.
GetComponentsInParent	Returns all components of Type type in the GameObject or any of its parents.
SendMessage	Calls the method named methodName on every MonoBehaviour in this game object.
SendMessageUpwards	Calls the method named methodName on every MonoBehaviour in this game object and on every ancestor of the behaviour.
GetInstanceID	Returns the instance id of the object.
ToString	Returns the name of the GameObject.
Static Methods
Destroy	Removes a gameobject, component or asset.
DestroyImmediate	Destroys the object obj immediately. You are strongly recommended to use Destroy instead.
DontDestroyOnLoad	Do not destroy the target Object when loading a new Scene.
FindObjectOfType	Returns the first active loaded object of Type type.
FindObjectsOfType	Returns a list of all active loaded objects of Type type.
Instantiate	Clones the object original and returns the clone.
Operators
bool	Does the object exist?
operator !=	Compares if two objects refer to a different object.
operator ==	Compares two object references to see if they refer to the same object.


*/