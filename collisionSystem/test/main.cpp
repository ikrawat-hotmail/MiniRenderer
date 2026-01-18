#include <iostream>
#include <vector>
#include "collision.h"
#include "rect.h"
#include "vector2f.h"

int main() {

	std::vector<std::pair<Rect, Rect>> tests = {
		// Overlap
		{ Rect({0,0}, {4,3}), Rect({2,1}, {5,4}) },

		// No overlap (separated right & above)
		{ Rect({0,0}, {2,2}), Rect({3,3}, {5,5}) },

		// Edge touch (X=4)
		{ Rect({0,0}, {4,4}), Rect({4,2}, {6,3}) },

		// Partial overlap (corner intersection)
		{ Rect({1,1}, {3,3}), Rect({2,2}, {4,4}) },

		// Separated horizontally
		{ Rect({0,0}, {5,5}), Rect({6,1}, {8,4}) },

		// Separated vertically
		{ Rect({0,0}, {5,5}), Rect({1,6}, {4,8}) },

		// Containment (B inside A)
		{ Rect({0,0}, {10,10}), Rect({2,2}, {4,4}) },

		// Containment (A inside B)
		{ Rect({2,2}, {4,4}), Rect({0,0}, {10,10}) },

		// Diagonal separation
		{ Rect({0,0}, {4,4}), Rect({5,5}, {9,9}) },

		// Corner touch (exactly at (4,4))
		{ Rect({0,0}, {4,4}), Rect({4,4}, {8,8}) }
	};

	for (size_t i = 0; i < tests.size(); ++i)
	{
		bool result = algo::aabbCollisionCheck(tests[i].first, tests[i].second);
		std::cout << "Test " << i+1 << ": " << (result ? "Overlap" : "No Overlap") << std::endl;
	}

	return 0;
}
