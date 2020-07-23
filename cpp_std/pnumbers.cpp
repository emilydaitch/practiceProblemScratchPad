#include <iostream>

int main() {

    int numbers[] = {1, 2, 3};
	
	int* pNumbers = numbers;
	
	std::cout << "numbers: " << numbers << " &numbers: " << &numbers << std::endl;
	std::cout << "numbers[0]: " << numbers[0] << std::endl << std::endl;
	std::cout << "pNumbers: " << pNumbers << " *pNumbers: " << *pNumbers << std::endl;
	std::cout << "pNumbers[0]: " << pNumbers[0] << " pNumbers[1]: " << pNumbers[1] << std::endl;

    return 0;
}