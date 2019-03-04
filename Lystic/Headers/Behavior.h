#pragma once
#include<string>

class Behavoir
{
public:
	Behavoir();


	virtual void Start();
	virtual void Update()();
	virtual void FixedUpdate();
	virtual void LateUpdate();
	virtual void OnGUI();
	virtual void OnDisable();
	virtual void OnEnable();
	// METHODS

//		Public Methods
//		==============
	void CancelInvoke();                             // Cancels all Invoke calls on this MonoBehaviour.
	void InvokeRepeating(std::string methodName);    // Invokes the method methodName in time seconds, then repeatedly every repeatRate seconds.
	void IsInvoking();                               // Is any invoke on methodName pending ?\
	


	// Must implement this entire class as though it was an EventSystem.

	// void Invoke(std::string methodName, float time); // Invokes the method methodName in time seconds.
	//Invoke is replaced with Register Listener with an on timer message




	// TODO: Function call stuff for defining specific functions to be called on a specific time update instead of every frame.
// Coroutine: A function that has the ability to pause execution and return control to Unity but then to continue where it left off on the following frame.
//  void StartCoroutine(IEnumerator routine);        // Starts a coroutine. // IEnumerator is essentially an Iterator used for iterating through a container
//	void StopAllCoroutines();                        // Stops all coroutines running on this behaviour.
// Overloads for StopCoroutine
//	void StopCoroutine(std::string methodName);


// void StopCoroutine(IEnumerator routine); Pass Iterator that IDs the specific routine. 
//	void StopCoroutine(Coroutine routine);


	// PROPERTIES
	// ==========
	//runInEditMode	Allow a specific instance of a MonoBehaviour to run in edit mode(only available in the editor).
	//useGUILayout	Disabling this lets you skip the GUI layout phase.




};

 
/*

Behaviour
=========
class in UnityEngine / 
	Inherits from : Component /
	Implemented in : UnityEngine.CoreModuleOther VersionsLeave feedback

	Description
	===========
	Behaviours are Components that can be enabled or disabled.

	Properties
	==========

	enabled	Enabled Behaviours are Updated, disabled Behaviours are not.
	isActiveAndEnabled	Has the Behaviour had active and enabled called ?

	Inherited Members
	=================
	Properties
	==========

	gameObject	The game object this component is attached to.A component is always attached to a game object.
	tag	The tag of this game object.
	transform	The Transform attached to this GameObject.
	hideFlags	Should the object be hidden, saved with the Scene or modifiable by the user ?
	name	The name of the object.

	Public Methods
	==============

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
	==============

	Destroy	Removes a gameobject, component or asset.
	DestroyImmediate	Destroys the object obj immediately.You are strongly recommended to use Destroy instead.
	DontDestroyOnLoad	Do not destroy the target Object when loading a new Scene.
	FindObjectOfType	Returns the first active loaded object of Type type.
	FindObjectsOfType	Returns a list of all active loaded objects of Type type.
	Instantiate	Clones the object original and returns the clone.

	Operators
	=========
	bool	Does the object exist ?
	operator !=	Compares if two objects refer to a different object.
	operator ==	Compares two object references to see if they refer to the same object.

	*/













/*
NOTES: This appears to be Unity Answer to my EventHandler. 
       At the very least something similar that sets up the messaging system for the entire engine and for scripts and game objects to use.

MonoBehaviour
=============
class in UnityEngine /
	Inherits from : Behaviour /
	Implemented in : UnityEngine.CoreModuleOther VersionsLeave feedback

	Description
	===========

	MonoBehaviour is the base class from which every Unity script derives.
	When you use C#, you must explicitly derive from MonoBehaviour.
	This class doesn't support the null-conditional operator (?.) and the null-coalescing operator (??).
	Note : There is a checkbox for disabling MonoBehaviour on the Unity Editor.It disables functions when unticked.If none of these functions are present in the script, the Editor does not display the checkbox.The functions are :

    Start()
    Update()
    FixedUpdate()
    LateUpdate()
    OnGUI()
    OnDisable()
    OnEnable()


Properties
==========
	    
        runInEditMode	Allow a specific instance of a MonoBehaviour to run in edit mode(only available in the editor).
        useGUILayout	Disabling this lets you skip the GUI layout phase.
        Public Methods
        CancelInvoke	Cancels all Invoke calls on this MonoBehaviour.
        Invoke	Invokes the method methodName in time seconds.
        InvokeRepeating	Invokes the method methodName in time seconds, then repeatedly every repeatRate seconds.
        IsInvoking	Is any invoke on methodName pending ?
        StartCoroutine	Starts a coroutine.
        StopAllCoroutines	Stops all coroutines running on this behaviour.
        StopCoroutine	Stops the first coroutine named methodName, or the coroutine stored in routine running on this behaviour.

Static Methods
==============
        print	Logs message to the Unity Console(identical to Debug.Log).

Messages
========
        Awake	Awake is called when the script instance is being loaded.
        FixedUpdate	Frame - rate independent MonoBehaviour.FixedUpdate message for physics calculations.
        LateUpdate	LateUpdate is called every frame, if the Behaviour is enabled.
        OnAnimatorIK	Callback for setting up animation IK(inverse kinematics).
        OnAnimatorMove	Callback for processing animation movements for modifying root motion.
        OnApplicationFocus	Sent to all GameObjects when the player gets or loses focus.
        OnApplicationPause	Sent to all GameObjects when the application pauses.
        OnApplicationQuit	Sent to all game objects before the application quits.
        OnAudioFilterRead	If OnAudioFilterRead is implemented, Unity will insert a custom filter into the audio DSP chain.
        OnBecameInvisible	OnBecameInvisible is called when the renderer is no longer visible by any camera.
        OnBecameVisible	OnBecameVisible is called when the renderer became visible by any camera.
        OnCollisionEnter	OnCollisionEnter is called when this collider / rigidbody has begun touching another rigidbody / collider.
        OnCollisionEnter2D	Sent when an incoming collider makes contact with this object's collider (2D physics only).
        OnCollisionExit	OnCollisionExit is called when this collider / rigidbody has stopped touching another rigidbody / collider.
        OnCollisionExit2D	Sent when a collider on another object stops touching this object's collider (2D physics only).
        OnCollisionStay	:ref::OnCollisionStay is called once per frame for every collider / rigidbody that is touching rigidbody / collider.
        OnCollisionStay2D	Sent each frame where a collider on another object is touching this object's collider (2D physics only).
        OnConnectedToServer	Called on the client when you have successfully connected to a server.
        OnControllerColliderHit	OnControllerColliderHit is called when the controller hits a collider while performing a Move.
        OnDestroy	Destroying the attached Behaviour will result in the game or Scene receiving OnDestroy.
        OnDisable	This function is called when the behaviour becomes disabled.
        OnDisconnectedFromServer	Called on the client when the connection was lost or you disconnected from the server.
        OnDrawGizmos	Implement OnDrawGizmos if you want to draw gizmos that are also pickable and always drawn.
        OnDrawGizmosSelected	Implement OnDrawGizmosSelected to draw a gizmo if the object is selected.
        OnEnable	This function is called when the object becomes enabled and active.
        OnFailedToConnect	Called on the client when a connection attempt fails for some reason.
        OnFailedToConnectToMasterServer	Called on clients or servers when there is a problem connecting to the MasterServer.
        OnGUI	OnGUI is called for rendering and handling GUI events.
        OnJointBreak	Called when a joint attached to the same game object broke.
        OnJointBreak2D	Called when a Joint2D attached to the same game object breaks.
        OnMasterServerEvent	Called on clients or servers when reporting events from the MasterServer.
        OnMouseDown	OnMouseDown is called when the user has pressed the mouse button while over the GUIElement or Collider.
        OnMouseDrag	OnMouseDrag is called when the user has clicked on a GUIElement or Collider and is still holding down the mouse.
        OnMouseEnter	Called when the mouse enters the GUIElement or Collider.
        OnMouseExit	Called when the mouse is not any longer over the GUIElement or Collider.
        OnMouseOver	Called every frame while the mouse is over the GUIElement or Collider.
        OnMouseUp	OnMouseUp is called when the user has released the mouse button.
        OnMouseUpAsButton	OnMouseUpAsButton is only called when the mouse is released over the same GUIElement or Collider as it was pressed.
        OnNetworkInstantiate	Called on objects which have been network instantiated with Network.Instantiate.
        OnParticleCollision	OnParticleCollision is called when a particle hits a Collider.
        OnParticleSystemStopped	OnParticleSystemStopped is called when all particles in the system have died, and no new particles will be born.New particles cease to be created either after Stop is called, or when the duration property of a non - looping system has been exceeded.
        OnParticleTrigger	OnParticleTrigger is called when any particles in a Particle System meet the conditions in the trigger module.
        OnPlayerConnected	Called on the server whenever a new player has successfully connected.
        OnPlayerDisconnected	Called on the server whenever a player disconnected from the server.
        OnPostRender	OnPostRender is called after a camera finished rendering the Scene.
        OnPreCull	OnPreCull is called before a camera culls the Scene.
        OnPreRender	OnPreRender is called before a camera starts rendering the Scene.
        OnRenderImage	OnRenderImage is called after all rendering is complete to render image.
        OnRenderObject	OnRenderObject is called after camera has rendered the Scene.
        OnSerializeNetworkView	Used to customize synchronization of variables in a script watched by a network view.
        OnServerInitialized	Called on the server whenever a Network.InitializeServer was invoked and has completed.
        OnTransformChildrenChanged	This function is called when the list of children of the transform of the GameObject has changed.
        OnTransformParentChanged	This function is called when the parent property of the transform of the GameObject has changed.
        OnTriggerEnter	OnTriggerEnter is called when the GameObject collides with another GameObject.
        OnTriggerEnter2D	Sent when another object enters a trigger collider attached to this object(2D physics only).
        OnTriggerExit	OnTriggerExit is called when the Collider other has stopped touching the trigger.
        OnTriggerExit2D	Sent when another object leaves a trigger collider attached to this object(2D physics only).
        OnTriggerStay	OnTriggerStay is called once per physics update for every Collider other that is touching the trigger.
        OnTriggerStay2D	Sent each frame where another object is within a trigger collider attached to this object(2D physics only).
        OnValidate	This function is called when the script is loaded or a value is changed in the inspector(Called in the editor only).
        OnWillRenderObject	OnWillRenderObject is called for each camera if the object is visible and not a UI element.
        Reset	Reset to default values.
        Start	Start is called on the frame when a script is enabled just before any of the Update methods are called the first time.
        Update	Update is called every frame, if the MonoBehaviour is enabled.

Inherited Members
_________________
=================
    
    Properties
    ==========
        enabled	Enabled Behaviours are Updated, disabled Behaviours are not.
        isActiveAndEnabled	Has the Behaviour had active and enabled called ?
        gameObject	The game object this component is attached to.A component is always attached to a game object.
        tag	The tag of this game object.
        transform	The Transform attached to this GameObject.
        hideFlags	Should the object be hidden, saved with the Scene or modifiable by the user ?
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
        DestroyImmediate	Destroys the object obj immediately.You are strongly recommended to use Destroy instead.
        DontDestroyOnLoad	Do not destroy the target Object when loading a new Scene.
        FindObjectOfType	Returns the first active loaded object of Type type.
        FindObjectsOfType	Returns a list of all active loaded objects of Type type.
        Instantiate	Clones the object original and returns the clone.
    Operators
    =========
        bool	Does the object exist ?
        operator !=	Compares if two objects refer to a different object.
        operator ==	Compares two object references to see if they refer to the same object.


*/