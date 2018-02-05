#include "Box.hpp"
#include <iostream>

/* Unit Test */
int main() {
	// Test 1: Default Constructor
	std::cout << "[TEST_1]: Calling default constructor w/ 0 args" << std::endl;
	Box box1;
	// box1.toString();

	// Test 2: Box Constructor w/ 3 args
	std::cout << "[TEST_2]: Calling constructor w/ 3 args" << std::endl;
	Box box2(2.0, 3.0, 4.0);
	// box2.toString();

	// Test 3: box1 setHeight(2.0)
	std::cout << "[TEST_3]: Setting box1 height = 2 using box1.setHeight(2.0)" << std::endl;
	box1.setHeight(2.0);

	// Test 4: box1 setWidth(3.0)
	std::cout << "[TEST_4]: Setting box1 width = 3 using box1.setWidth(3.0)" << std::endl;
	box1.setWidth(3.0);

	// Test 5: box1 setLength(4.0)
	std::cout << "[TEST_5]: Setting box1 length = 4 using box1.setLength(4.0)" << std::endl;
	box1.setLength(4.0);

	// Test 6: calcVolume()
	std::cout << "[TEST_6]: Verify box1 and box2 volume is equal" << std::endl;
	if (box1.calcVolume() == box2.calcVolume()) {
		std::cout << "[PASS]" << std::endl;
	} else {
		std::cout << "[FAIL]" << std::endl;
	}
	std::cout << "box1's volume = " << box1.calcVolume() << std::endl;
	std::cout << "box2's volume = " << box2.calcVolume() << std::endl;
	// box1.toString();
	// box2.toString();

	// Test 7: calcSurfaceArea()
	std::cout << "[TEST_7]: Verify box1 and box2 surface area is equal" << std::endl;
	if (box1.calcSurfaceArea() == box2.calcSurfaceArea()) {
		std::cout << "[PASS]" << std::endl;
	} else {
		std::cout << "[FAIL]" << std::endl;
	}
	std::cout << "box1's volume = " << box1.calcSurfaceArea() << std::endl;
	std::cout << "box2's volume = " << box2.calcSurfaceArea() << std::endl;
	// box1.toString();
	// box2.toString();

    return 0;
}