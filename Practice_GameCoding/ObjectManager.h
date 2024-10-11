#pragma once

class Object;	// ���� ����

class ObjectManager
{
	DECLARE_SINGLE(ObjectManager);

	~ObjectManager();

	void Add(Object* object);
	void Remove(Object* object);
	void Clear();

	const vector<Object*>& GetObjects() { return _objects; }	// �ܺη� ��� ������

	// ������Ʈ ����
	template<typename T>
	T* CreateObject()
	{
		static_assert(std::is_convertible_v<T*, Object*>);	// type trait(������ �ð���), T�� Object�� ��ȯ

		T* object = new T();
		object->Init();

		return object;
	}

private:
	vector<Object*> _objects;
};

