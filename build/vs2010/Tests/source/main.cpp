#include <PMath/Vector2.hpp>

#include <iostream>

using namespace pmath;

int main()
{
	Vec2 vec1, vec2;

	vec1.x = 5;
	vec1.y = 10;

	vec2.x = 10;
	vec2.y = 5;

	Vec2 vec3 = vec1 - vec2;

	// Stop the program
	std::cout << "Press any key to continue..." << std::endl;
	std::cin.get();

	return 0;
}