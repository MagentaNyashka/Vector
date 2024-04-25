#include <iostream>
#include "Vector.h"

using namespace PB_C;

int main() {
	Vector<int> a = { 1, 2, 3 };

	a -= 3;

	std::cout << a << std::endl;
	
	return 0;
}
