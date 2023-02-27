#pragma once

#include <math.h>

struct Vector2
{
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
		x += x + v.x;
		y += y + v.y;
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
};