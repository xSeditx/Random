#include"Transform.h"

#include"Common.h"


Transform::Transform()
	:Component("Transform")
{

}
Transform::Transform(Vec3 p, Vec3 r, Vec3 s)
	: Component("Transform")
{
	Set_Transform(p, r, s);
}

void Transform::Set_Position(Vec3 pos)
{
	Position = pos;
}
void Transform::Set_Rotation(Vec3 rot)
{
	Rotation = rot;
}
void Transform::Set_Scale(Vec3 scale)
{
	Scale = scale;
}
void Transform::Set_Transform(Vec3 pos, Vec3 rot, Vec3 scale)
{
	Mat4 = glm::mat4(1.0f); // Set Identity and Rotate all axis followed with the Translation.
	Mat4 = glm::translate(Mat4, pos);
	Mat4 = glm::rotate(Mat4, glm::radians(rot.x), Vec3(1.0f, 0.0f, 0.0f));
	Mat4 = glm::rotate(Mat4, glm::radians(rot.y), Vec3(0.0f, 1.0f, 0.0f));
	Mat4 = glm::rotate(Mat4, glm::radians(rot.z), Vec3(0.0f, 0.0f, 1.0f));
	Mat4 = glm::scale(Mat4, scale);
}
void Transform::Update()
{
	Set_Transform(Position, Rotation, Scale);
}


