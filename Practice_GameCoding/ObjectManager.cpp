#include "pch.h"
#include "ObjectManager.h"

ObjectManager::~ObjectManager()
{
	Clear();	// 안전하게 메모리 정리함
}

void ObjectManager::Add(Object* object)
{
	if (object == nullptr)
		return;
	
	auto findIt = std::find(_objects.begin(), _objects.end(), object);	// 같은 object가 있다면 return 함
	if (findIt != _objects.end())
		return;

	_objects.push_back(object);
}

void ObjectManager::Remove(Object* object)
{
	if (!object)
		return;

	auto it = std::remove(_objects.begin(), _objects.end(), object);
	_objects.erase(it, _objects.end());
	
	delete object;	// 괜찮을까?
}

void ObjectManager::Clear()	// 메모리 정리
{
	std::for_each(_objects.begin(), _objects.end(), [=](Object* obj) { delete obj; });
	_objects.clear();
}
