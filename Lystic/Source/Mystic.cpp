

//                                           DISSERTATION            
//==================================================================================================================
// Scenes are composed of Multiple Objects
// Objects are composed of multiple Components
// Components consist of data specifying the state of that specific part of an Object
// Each Component should have an Interface manager which handles the data for that specific type of Component.
// This should effectively seperate the Logic blocks from the Data allowing for...
//     faster performance, lower memory overhead and greater flexibility in Engine Design







//#include"Common.h"
//
//
//
//std::ostream& operator<<(std::ostream &lhv, Vec2 const &rhv)
//{
//	lhv << "X: " << rhv.x << " | " << "Y: " << rhv.y;
//	return lhv;
//}
//std::ostream& operator<<(std::ostream &lhv, Vec3 const &rhv)
//{
//	lhv << "X: " << rhv.x << " | " << "Y: " << rhv.y << " | " << "Z: " << rhv.z;
//	return lhv;
//}
//std::ostream& operator<<(std::ostream &lhv, Vec4 const &rhv)
//{
//	lhv << "X: " << rhv.x << " | " << "Y: " << rhv.y << " | " << "Z: " << rhv.z << " | " << "W: " << rhv.a;
//	return lhv;
//}