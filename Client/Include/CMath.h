#pragma once

#include <math.h>
#define PI 3.141592

struct Vector2
{
	//static Vector2 Up;
	//static Vector2 Right;
	static Vector2 One;
	static Vector2 Zero;

	float x, y;

	Vector2()
		: x(0.f)
		, y(0.f)
	{
	}

	Vector2(float _x, float _y)
		: x(_x)
		, y(_y)
	{
	}

	Vector2(int _x, int _y)
		: x((float)_x)
		, y((float)_y)
	{
	}

	Vector2(const Vector2&) = default;
	Vector2& operator=(const Vector2&) = default;

	Vector2(Vector2&&) = default;
	Vector2& operator=(Vector2&&) = default;
	
	// comp
	bool operator ==(const Vector2& v) const
	{
		return x == v.x && y == v.y;
	}

	bool operator !=(const Vector2& v) const
	{
		return x != v.x || y != v.y;
	}

	// +
	Vector2 operator+(const Vector2& v) const
	{
		Vector2 result;

		result.x = x + v.x;
		result.y = y + v.y;

		return result;
	}

	Vector2 operator+(float f) const
	{
		Vector2 result;

		result.x = x + f;
		result.y = y + f;

		return result;
	}

	Vector2 operator+(int i) const
	{
		Vector2 result;

		result.x = x + i;
		result.y = y + i;

		return result;
	}

	// +=

	void operator+= (const Vector2& v)
	{
		x += v.x;
		y += v.y;
	}

	void operator+= (float f)
	{
		x += f;
		y += f;
	}

	void operator+= (int i)
	{
		x += (float)i;
		y += (float)i;
	}

	// -
	Vector2 operator-(const Vector2& v) const
	{
		Vector2 result;

		result.x = x - v.x;
		result.y = y - v.y;

		return result;
	}

	Vector2 operator-(float f) const
	{
		Vector2 result;

		result.x = x - f;
		result.y = y - f;

		return result;
	}

	Vector2 operator-(int i) const
	{
		Vector2 result;

		result.x = x - (float)i;
		result.y = y - (float)i;

		return result;
	}

	Vector2 operator-() const
	{
		return Vector2(-x, -y);
	}

	// -=
	void operator-=(const Vector2& v)
	{
		x -= v.x;
		y -= v.y;
	}

	void operator-=(float f)
	{
		x -= f;
		y -= f;
	}

	void operator-=(int i)
	{
		x -= i;
		y -= i;
	}

	// *
	Vector2 operator*(const Vector2& v) const
	{
		Vector2 result;
		
		result.x = x * v.x;
		result.y = y * v.y;

		return result;
	}

	Vector2 operator*(double d) const
	{
		Vector2 result;

		result.x = x * d;
		result.y = y * d;

		return result;
	}

	Vector2 operator*(float f) const
	{
		Vector2 result;

		result.x = x * f;
		result.y = y * f;

		return result;
	}

	Vector2 operator*(int i) const
	{
		Vector2 result;

		result.x = x * i;
		result.y = y * i;

		return result;
	}

	// *=
	void operator*=(const Vector2& v)
	{
		x *= v.x;
		y *= v.y;
	}

	void operator*=(float f)
	{
		x *= f;
		y *= f;
	}

	void operator*=(int i)
	{
		x *= i;
		y *= i;
	}

	// /
	Vector2 operator/(const Vector2& v) const
	{
		Vector2 result;

		result.x = x / v.x;
		result.y = y / v.y;

		return result;
	}

	Vector2 operator/(float f) const
	{
		Vector2 result;

		result.x = x / f;
		result.y = y / f;

		return result;
	}

	Vector2 operator/(int i) const
	{
		Vector2 result;

		result.x = x / i;
		result.y = y / i;

		return result;
	}

	// /=

	void operator/=(const Vector2& v)
	{
		x /= v.x;
		y /= v.y;
	}

	void operator/=(float f)
	{
		x /= f;
		y /= f;
	}

	void operator/=(int i)
	{
		x /= i;
		y /= i;
	}
	
	float Length()
	{
		return sqrtf(x * x + y * y);
	}

	Vector2& Normalize()
	{
		float length = Length();
		x /= length;
		y /= length;

		return *this;
	}

	void Clear()
	{
		x = 0;
		y = 0;
	}
};

namespace kyr::math
{
	//float x = dir.x * cosf(PI / 5.0f) - dir.y * sinf(PI / 5.0f);
//float y = dir.x * sinf(PI / 5.0f) + dir.y * cosf(PI / 5.0f);

	inline static Vector2 Rotate(Vector2 vector, float degree)
	{
		float radian = (degree / 180.0f) * PI;
		vector.Normalize();

		float x = vector.x * cosf(radian) - vector.y * sinf(radian);
		float y = vector.x * sinf(radian) + vector.y * cosf(radian);
		//atan
		//atan();
		return Vector2(x, y);
	}

	inline static float Dot(Vector2& v1, Vector2& v2)
	{
		return v1.x * v2.x + v1.y * v2.y;
	}

	inline static float Cross(Vector2& v1, Vector2& v2)
	{
		return v1.x * v2.y - v1.y * v2.x;
	}

}