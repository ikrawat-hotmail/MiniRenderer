#ifndef VECTOR3F_H
#define VECTOR3F_H

class Vec3f {
public:
	float x;
	float y;
    float z;

	Vec3f() : x(0.0f), y(0.0f), z(0.0f) {}
	
	Vec3f(const Vec3f& vec3f) : x(vec3f.x), y(vec3f.y), z(vec3f.z) {}
	
	Vec3f& operator=(const Vec3f& vec3f)  {
		if (this == &vec3f) {
			return *this;
		}
		x = vec3f.x;
		y = vec3f.y;
		z = vec3f.z;
		return *this;
	}

	Vec3f(float x, float y, float z) : x(x), y(y), z(z) {}
};

#endif
