#pragma once


// https://www.gamedev.net/articles/programming/general-and-gameplay-programming/the-entity-component-system-c-game-design-pattern-part-1-r4803/
typedef unsigned int EntityId;
typedef unsigned int EntityTypeId;
// EntityTypeId = _decltype()type.id;
class MysticAllocator
{
public:

	virtual void* allocate(size_t size) = 0; //allocate – which allocates a certain amount of bytes and returns the memory - address to this chunk and
	virtual void free(void* p) = 0;          //	free – to de - allocates a previously allocated chuck of memory given it’s address.
};

class IEntity
{
	// code not complete!
	EntityId m_Id;

public:
	IEntity();
	virtual ~IEntity();

	virtual const EntityTypeId GetStaticEntityTypeID() const = 0;
	inline const EntityId GetEntityID() const { return this->m_Id; }
};

template<class T>
class Entity : public IEntity
{
	void operator delete(void*) = delete;
	void operator delete[](void*) = delete;
public:

	static const EntityTypeId STATIC_ENTITY_TYPE_ID;
	Entity() {}
	virtual ~Entity() {}
	virtual const EntityTypeId GetStaticEntityTypeID() const override { return STATIC_ENTITY_TYPE_ID; }
};





//#include<iostream>
//#include<string>


//void Print(const char *Params);



//template <class type> ret - type func - name(parameter list) {
	// body of function
//}




//TODO: MAKE A UNIVERSAL CASTER SIMILAR TO STD::ANY SINCE MSVC++ 2015 does not have std::any

// 
// Equality test:
//      template<typename a, typename b> 
//          bool isSame()
//          {
//          	return (typeid(a) == typeid(b));
//          }
 

//template<class T t, U u> T* _PointerCast() { return (T*)u; }
//
//float B = 10.43;
//int *VariableA = _PointerCast<10, B>();
//
//
//class Any
//{
//public:
//
//
//	template<typename _Tp>
//	void* __any_caster(const any* __any) {
//		if constexpr (is_copy_constructible_v<decay_t<_Tp>>) {
//			if (__any->_M_manager == &any::_Manager<decay_t<_Tp>>::_S_manage) {
//				any::_Arg __arg;
//				__any->_M_manager(any::_Op_access, __any, &__arg);
//				return __arg._M_obj;
//			}
//		}
//		return nullptr;
//	}
//private:
//
//
//
//	void bad_any_cast()
//	{
//
//	}
//};
// struct msgt
// {
// 
// };
// class EVENTTEST
// {
// 	void *data;
//     size_t size;
// };
// 

