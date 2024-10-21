#pragma once
#include <cmath>
#include <windows.h>

// 변수를 편리하게 사용하기 위해

using int8 = __int8;
using int16 = __int16;
using int32 = __int32;
using int64 = __int64;

using uint8 = unsigned __int8;
using uint16 = unsigned __int16;
using uint32 = unsigned __int32;
using uint64 = unsigned __int64;

struct Stat
{
	int32 hp = 0;
	int32 maxHp = 0;
	float speed = 0;
};

struct Vector
{
	Vector() {}
	Vector(int32 x, int32 y) : x(x), y(y) {}
	Vector(POINT pt) : x((float)pt.x), y((float)pt.y) {}

	// Operator 
	Vector operator+(const Vector& other)
	{
		Vector ret;
		ret.x = x + other.x;
		ret.y = y + other.y;
		return ret;
	}

	Vector operator-(const Vector& other)
	{
		Vector ret;
		ret.x = x - other.x;
		ret.y = y - other.y;
		return ret;
	}
		
	Vector operator*(float value)
	{
		Vector ret;
		ret.x = x * value;
		ret.y = y * value;
		return ret;
	}
		
	Vector operator+=(const Vector& other)
	{
		Vector ret;
		x += other.x;
		y += other.y;
		return ret;
	}

	Vector operator-=(const Vector& other)
	{
		Vector ret;
		x -= other.x;
		y -= other.y;
		return ret;
	}
		
	Vector operator*=(float ratio)
	{
		Vector ret;
		x *= ratio;
		y *= ratio;
		return ret;
	}

	float LengthSquared()
	{
		return x * x + y * y;
	}

	float Length()
	{
		return ::sqrt(LengthSquared());
	}

	void Normalize()
	{
		float length = Length();
		if (length < 0.00000000001f)
			return;

		x /= length;
		y /= length;
	}

	float Dot(Vector other)
	{
		return x * other.x + y * other.y;
	}

	float Cross(Vector other)
	{
		return x * other.y - y * other.x;
	}

	float x = 0;
	float y = 0;
};

// int 버전의 Vector 자료형
struct VectorInt
{
	VectorInt() {}
	VectorInt(int32 x, int32 y) : x(x), y(y) {}
	VectorInt(POINT pt) : x(pt.x), y(pt.y) { }

	VectorInt operator+(const VectorInt& other)
	{
		VectorInt ret;
		ret.x = x + other.x;
		ret.y = y + other.y;
		return ret;
	}

	VectorInt operator-(const VectorInt& other)
	{
		VectorInt ret;
		ret.x = x - other.x;
		ret.y = y - other.y;
		return ret;
	}

	VectorInt operator*(int32 value)
	{
		VectorInt ret;
		ret.x = x * value;
		ret.y = y * value;
		return ret;
	}

	void operator+=(const VectorInt& other)
	{
		x += other.x;
		y += other.y;
	}

	void operator-=(const VectorInt& other)
	{
		x -= other.x;
		y -= other.y;
	}

	int32 LengthSquared()
	{
		return x * x + y * y;
	}

	float Length()
	{
		return (float)::sqrt(LengthSquared());
	}

	int32 Dot(VectorInt other)		// 내적
	{
		return x * other.x + y * other.y;
	}

	int32 Cross(VectorInt other)	// 외적
	{
		return x * other.y - y * other.x;
	}

	int32 x = 0;
	int32 y = 0;
};


using Pos = Vector;
// vector 자료형과 헷갈리기 때문에 Vec2로 바꿈
using Vec2 = Vector;
using Vec2Int = VectorInt;

