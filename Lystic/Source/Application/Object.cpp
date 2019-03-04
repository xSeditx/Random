#include"Object.h"

#include"Transform.h"


//Object::Object()
//{
//	Parts.push_back(new Transform(Vec3(0.0f), Vec3(0.0f), Vec3(1.0f)));
//	AddComponent
//}
//
unsigned int Object::AddComponent(Component *attribute)
{
	Component *part = new T();
	Parts.push_back(part);
}


// Check Musings.txt for more information about following function Roughly line 120
void Object::SetListener(Event msg, Listener *method)
{// Set this up so that the EventHandler Registers the Listener defined
}



// oid Object::Set_Transform(Vec3 pos, Vec3 rot, Vec3 scale)
// /// Sets the Transform for the Given GameObject
// 	Transform = glm::mat4(1.0f); // Set Identity and Rotate all axis followed with the Translation.
// 	Transform = glm::translate(Transform, pos);
// 	Transform = glm::rotate(Transform, glm::radians(rot.x), Vec3(1.0f, 0.0f, 0.0f));
// 	Transform = glm::rotate(Transform, glm::radians(rot.y), Vec3(0.0f, 1.0f, 0.0f));
// 	Transform = glm::rotate(Transform, glm::radians(rot.z), Vec3(0.0f, 0.0f, 1.0f));
// 	Transform = glm::scale(Transform, scale);
// 	// WARNING: NOT SURE SCALING IN THE PROPER ORDER
// 	Print("GameObject::Set_Transform() -  Unsure if Scaling is being applied properly. Double check.");
// 
// 