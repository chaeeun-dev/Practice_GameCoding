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

struct Pos
{
	float x = 0;
	float y = 0;
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
