#include <iostream>
#include <vector>
#include <algorithm>

const int MIN_VECTOR_SIZE = 0;
const int MAX_VECTOR_SIZE = 10000;
const int MAX_ELEMENT_MAGNITUDE = 1000;
const int NUMBER_OF_RANDOM_TESTS = 10;

std::vector<int> sortedSquaredArrayGenerator(std::vector<int> inputVector) {
	return inputVector;
}

std::vector<int> sortedSquaredArraySolutionGenerator(std::vector<int> inputVector) {
	return inputVector;
}

void testSortedSquaredArray(std::vector<int> key, std::vector<int> result) {
	if(std::equal(key.begin(), key.end(), result.begin())) {
		std::cout << "Test passed!" << std::endl;
	}
	else {
		std::cout << "Test failed!" << std::endl;
	}
}

int randomizeSign(int toBeSigned) {
	rand() % 2 ? toBeSigned : toBeSigned = (-1 * toBeSigned);
	return toBeSigned;
}

int main() {
	std::vector<int> key;
	std::vector<int> result;
	std::vector<int> emptyVec;

	
	std::cout << "Let's test things:" << std::endl;
	std::cout << "Testing vector with length 0... ";
	
	result = sortedSquaredArrayGenerator(emptyVec);
	key = sortedSquaredArraySolutionGenerator(emptyVec);
	testSortedSquaredArray(key, result);
	
	for (int tests = 1; tests <= NUMBER_OF_RANDOM_TESTS; ++tests){
		std::vector<int> inputVector;
		int vectorLengthToBeTested = std::rand() % MAX_VECTOR_SIZE;
		
		std::cout << "Starting test " << tests << " with vector length " << vectorLengthToBeTested << ". ";
	
		for(int i = 0; i < vectorLengthToBeTested; ++i) {
			int randomNumber = rand() % MAX_ELEMENT_MAGNITUDE;
			randomNumber = randomizeSign(randomNumber);
			inputVector.push_back(randomNumber);
		}
	
		result = sortedSquaredArrayGenerator(inputVector);
		key = sortedSquaredArraySolutionGenerator(inputVector);
		
		testSortedSquaredArray(key, result);
	}
	return 0;
}