#pragma once
// 매크로 모음 - 매크로는 디버깅하기 힘들어지기 때문에 필요한 부분에만 사용!

#define DECLARE_SINGLE(classname)		\
private:								\
	classname() {}						\
public:									\
	static classname* GetInstance()		\
	{									\
		static classname s_instance;	\
		return &s_instance;				\
	}			

#define GET_SINGLE(classname) classname::GetInstance()		// 싱글톤 생성
				
#define SAFE_DELETE(ptr)			\
	if (_scene)						\
	{								\
		delete _scene;				\
		_scene = nullptr;			\
	}