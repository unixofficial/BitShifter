#include <iostream>
#include <string>
#include <limits>
#include <Windows.h>

int main() {
	SetConsoleOutputCP(CP_UTF8);
	SetConsoleCP(CP_UTF8);
	int a, b;
	std::string c;
	int result;
	std::cout << "Input a number to shift left or right." << std::endl;
	std::cin >> a;
	std::cout << "How many bits to shift? (from 1 to 31)" << std::endl;
	std::cin >> b;
	std::cout << "Enter the shift direction." << std::endl;
	std::cin >> c;

	if (c == "left") {
		if (a < 0) {
			std::cout << "Only non-negative numbers are supported for left shifts!";
		}
		else if (b <= 0 || b >= 32) {
			std::cout << "Trying to cause undefined behavior? Not today!";
		}
		else {
			if (a > (std::numeric_limits<int>::max)() >> b) {
				std::cout << "Overflow!" << std::endl;
			}
			else {
				result = a << b;
				std::cout << "Result of left shift: " << result << std::endl;
			}
		}
	}
	else if (c == "right") {
		if (b <= 0 || b >= 32) {
			std::cout << "Trying to cause undefined behavior? Not today!";
		}
		else {
			result = a >> b;
			std::cout << "Result of right shift: " << result << std::endl;
		}
	}
	else {
		std::cout << "Unknown shift direction!" << std::endl;
	}
	std::cout << "Press Enter to close the program...";
	std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
	std::cin.get();
	return 0;
}
