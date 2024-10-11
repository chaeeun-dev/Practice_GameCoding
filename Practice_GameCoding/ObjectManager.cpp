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
	
	auto findIt = std::find(_objects.begin(), _objects.end(), object);
	if (findIt != _objects.end())
		return;
}

void ObjectManager::Remove(Object* object)
{
}

void ObjectManager::Clear()
{
}
