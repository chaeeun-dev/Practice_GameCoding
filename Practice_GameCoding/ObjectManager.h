#pragma once

class Object;	// 전방 선언

class ObjectManager
{
	DECLARE_SINGLE(ObjectManager);

	~ObjectManager();

	void Add(Object* object);
	void Remove(Object* object);
	void Clear();

	const vector<Object*>& GetObjects() { return _objects; }	// 외부로 목록 꺼내줌

	// 오브젝트 생성
	template<typename T>
	T* CreateObject()
	{
		static_assert(std::is_convertible_v<T*, Object*>);	// type trait(컴파일 시간에), T를 Object로 변환

		T* object = new T();
		object->Init();

		return object;
	}

private:
	vector<Object*> _objects;
};

