#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include <time.h>
#include <math.h>

const int MIN_VECTOR_SIZE = 0;
const int MAX_VECTOR_SIZE = 10000;
const int MAX_ELEMENT_MAGNITUDE = 10000;
const int NUMBER_OF_RANDOM_TESTS = 1000;
static int NumberOfFailures = 0;

void printVector(std::vector<int> toPrint) {
	if(MAX_VECTOR_SIZE <= 20) {
		for(int i=0; i < toPrint.size(); i++)
		std::cout << toPrint.at(i) << ' ';
		std::cout << std::endl;
	}
}

void printKeyAndResult(std::vector<int> key, std::vector<int> result) {
	if(MAX_VECTOR_SIZE <= 20) {
		std::cout << "result   : ";
		printVector(result);
		
		std::cout << "key      : ";
		printVector(key);
	}
}

std::vector<int> sortedSquaredArrayGenerator(std::vector<int> inputVector) {
	if(inputVector.size() == 1) {
		inputVector.at(0) = pow(inputVector.at(0), 2);
		return inputVector;
	}
	
	std::deque<int> absoluteSortedDeque;
	int front = 0;
	int back = inputVector.size() - 1;
	while(front <= back) {
		if(abs(inputVector.at(front)) > abs(inputVector.at(back))) {
			absoluteSortedDeque.push_front(ceil(pow(inputVector.at(front), 2)));
			front++;
		}
		else {
			absoluteSortedDeque.push_front(ceil(pow(inputVector.at(back), 2)));
			back--;
		}
	}
	
	std::vector<int> absoluteSortedVector;
	int saveSize = absoluteSortedDeque.size();
	for(int i = 0; i < saveSize; ++i) {
		absoluteSortedVector.push_back(absoluteSortedDeque.front());
		absoluteSortedDeque.pop_front();
	}
	
	return absoluteSortedVector;
}

std::vector<int> sortedSquaredArraySolutionGenerator(std::vector<int> inputVector) {
	for(int el = 0; el < inputVector.size(); ++el) { // O(n)
		inputVector.at(el) = pow(inputVector.at(el), 2);
	}
	printVector(inputVector);
	std::sort(inputVector.begin(), inputVector.end());
	printVector(inputVector);
	return inputVector;
}

void testSortedSquaredArray(std::vector<int> key, std::vector<int> result) {
	if(std::equal(key.begin(), key.end(), result.begin())) {
		std::cout << "Test passed!" << std::endl << std::endl;
	}
	else {
		printKeyAndResult(key, result);
		NumberOfFailures++;
		std::cout << "Test failed!" << std::endl << std::endl;
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
	
	std::cout << "Let's test things:" << std::endl << std::endl;
	std::cout << "Testing vector with length 0... " << std::endl;
	
	result = sortedSquaredArrayGenerator(emptyVec);
	key = sortedSquaredArraySolutionGenerator(emptyVec);
	testSortedSquaredArray(key, result);
	
	std::cout << "Testing vector with length 1... " << std::endl;
	emptyVec.push_back(8);
	
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
		
		std::sort(inputVector.begin(), inputVector.end());
		
		std::cout << "input  : ";
		printVector(inputVector);
		
		result = sortedSquaredArrayGenerator(inputVector);
		key = sortedSquaredArraySolutionGenerator(inputVector);
		
		testSortedSquaredArray(key, result);
	}
	
	std::cout << "Total of failures: " << NumberOfFailures << std::endl;
	
	return 0;
}