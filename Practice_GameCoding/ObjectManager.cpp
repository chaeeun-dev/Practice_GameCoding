#include "pch.h"
#include "ObjectManager.h"

ObjectManager::~ObjectManager()
{
	Clear();	// �����ϰ� �޸� ������
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
