#ifndef VECTOR_2F_H
#define VECTOR_2F_H
#include <iostream>

class Vec2f {
public:
	float x;
	float y;

	Vec2f() : x(0.0f), y(0.0f) {}

	Vec2f(const Vec2f& vec2f) : x(vec2f.x), y(vec2f.y) {}
	
	Vec2f& operator=(const Vec2f& vec2f) {
		if (this == &vec2f) {
			return *this;
		}
		x = vec2f.x;
		y = vec2f.y;
		return *this;
	}

	Vec2f(float x, float y) : x(x), y(y) {}
};

#endif
