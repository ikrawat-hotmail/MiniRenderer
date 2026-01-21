#include "collisionManager.h"

namespace algo {
	bool aabbCollisionCheck(Rect& rect1, Rect& rect2) {
		return !(
			rect1.maxX < rect2.minX ||
			rect1.minX > rect2.maxX ||
			rect1.maxY < rect2.minY ||
			rect1.minY > rect2.maxY
		);
	}

    bool circleCollisionCheck(Circle& c1, Circle& c2) {
        if (c1.radius <= 0.0f || c2.radius < 0.0f) {
#ifdef DEBUG_ENABLED
            std::cout << "ERROR: Invalid circle" << std::endl;
#endif
            return false;
        }

        float dy = c2.center.y - c1.center.y;
        float dx = c1.center.y - c1.center.x;

        float sumRadius = c1.radius + c2.radius;

        if ((sumRadius * sumRadius) > (dy*dy + dx*dx))
            return true;
        return false;
    }
}
