#ifndef CIRCLE_H
#define CIRCLE_H
#include "vector2f.h"
#include "polygon2D.h"

class Circle : public Polygon2D {
public:
	float radius;
	Vec2f center;

	// p1 and p2 are corner points
	Circle(float radius, Vec2f& center) : radius(radius), center(center){};

	Circle() {}

	void set(float radius, Vec2f& center) {
		this->radius = radius;
		this->center = center;
	}

	BodyType getType() override {
		return BodyType::CIRCLE;
	}

};
#endif
