#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>
#include <math.h>

const int MIN_VECTOR_SIZE = 0;
const int MAX_VECTOR_SIZE = 10;
const int MAX_ELEMENT_MAGNITUDE = 1000;
const int NUMBER_OF_RANDOM_TESTS = 10;


void printVector(std::vector<int> toPrint) {
	if(MAX_VECTOR_SIZE < 20) {
		for(int i=0; i < toPrint.size(); i++)
		std::cout << toPrint.at(i) << ' ';
		std::cout << std::endl;
	}
}

void printKeyAndResult(std::vector<int> key, std::vector<int> result) {
	if(MAX_VECTOR_SIZE < 20) {
		std::cout << "result   : ";
		printVector(result);
		
		std::cout << "key      : ";
		printVector(key);
	}
}

std::vector<int> sortedSquaredArrayGenerator(std::vector<int> inputVector) {
	return inputVector;
}

std::vector<int> sortedSquaredArraySolutionGenerator(std::vector<int> inputVector) {
	for(int el = 0; el < inputVector.size(); ++el) { // O(n)
		inputVector.at(el) = pow(inputVector.at(el), 2);
	}
	std::cout << "squared   : ";
	printVector(inputVector);
	std::sort(inputVector.begin(), inputVector.end());
	std::cout << "sorted   : ";
	printVector(inputVector);
	return inputVector;
}

void testSortedSquaredArray(std::vector<int> key, std::vector<int> result) {
	if(std::equal(key.begin(), key.end(), result.begin())) {
		std::cout << "Test passed!" << std::endl;
	}
	else {
		std::cout << "Test failed!" << std::endl;
		printKeyAndResult(key, result);
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

	srand(time(0));
	
	std::cout << "Let's test things:" << std::endl;
	std::cout << "Testing vector with length 0... ";
	
	result = sortedSquaredArrayGenerator(emptyVec);
	key = sortedSquaredArraySolutionGenerator(emptyVec);
	testSortedSquaredArray(key, result);
	
	for (int tests = 1; tests <= NUMBER_OF_RANDOM_TESTS; ++tests){
		std::vector<int> inputVector;
		int vectorLengthToBeTested = std::rand() % MAX_VECTOR_SIZE;
		
		std::cout << "Starting test " << tests << " with vector length " << vectorLengthToBeTested << ". " << std::endl;
	
		for(int i = 0; i < vectorLengthToBeTested; ++i) {
			int randomNumber = rand() % MAX_ELEMENT_MAGNITUDE;
			randomNumber = randomizeSign(randomNumber);
			inputVector.push_back(randomNumber);
		}
		
		std::cout << "input   : ";
		printVector(inputVector);
		
		result = sortedSquaredArrayGenerator(inputVector);
		key = sortedSquaredArraySolutionGenerator(inputVector);
		
		testSortedSquaredArray(key, result);
	}
	return 0;
}