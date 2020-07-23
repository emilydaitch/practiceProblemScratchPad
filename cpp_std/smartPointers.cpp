#include <iostream>
#include <memory>
#include <string>

class Data{
public:
	Data() {
		std::cout << "Created Data\n" << std::endl;
	}
	~Data() {
		std::cout << "Destroyed Data\n" << std::endl;
	}
	
	void printNothing() {};
};

int main() {
	std::cout << "Creating weak pointer in scope 0.\n" << std::endl;
	std::weak_ptr<Data> weakOutOfScope;
	
	std::cout << "Entering scope 1.\n" << std::endl;
	{ //scope 1
		std::shared_ptr<Data> sharedCopyDifferentScope;
		std::cout << "Creating shared pointer in scope 1." << std::endl;
		
		std::cout << "Entering scope 2.\n" << std::endl;
		{ // scope 2
	
			// UNIQUE POINTERS
			//std::unique_ptr<Data> unique(new Data()); 						// OK, but not exception safe
			//std::unique_ptr<Data> unique = new Data(); 						// compiler error - unique_ptr constructor is explicit
			std::cout << "Creating unique pointer in scope 2.\n" << std::endl;
			std::unique_ptr<Data> unique = std::make_unique<Data>(); 			// good practice
			//std::unique_ptr<Data> uniqueCopy = unique; 						// compiler error, copy ctor and assignment operator deleted in unique_ptr
			
			// SHARED POINTERS
			//std::shared_ptr<Data> shared(new Data()); 						// OK for tiny projects. Avoid it. If you use make_shared, it can allocate the control
																				// block for reference counting in the same allocation as Data. Allocations are expensive.
			std::cout << "Creating shared pointer in scope 2. Ref count is one." << std::endl;
			std::shared_ptr<Data> shared = std::make_shared<Data>(); 			// reference count is one
			std::cout << "Creating shared pointer copy in scope 2. Ref count is two." << std::endl;
			std::shared_ptr<Data> sharedCopy = shared;  						// OK, reference count increased to 2
			std::cout << "Assigning shared pointer from scope 1 to shared pointer from scope 2. Ref count is three.\n" << std::endl;
			sharedCopyDifferentScope = shared; 									// OK, reference count increased to 3
			
			// WEAK POINTERS
			std::cout << "Creating and assigning weak pointer in scope 2 to shared pointer from scope 2. Ref count not increased." << std::endl;
			std::weak_ptr<Data> weak = shared; 									// no make_weak function
			std::cout << "Assigning weak pointer from scope 0 to shared pointer from scope 2. Ref count not increased.\n" << std::endl;
			weakOutOfScope = shared;
			
			unique->printNothing(); 											// call functions like a normal pointer for all smart pointers
			
		} 																		// unique, shared, and sharedCopy out of scope -- reference count becomes one -- shared is not destroyed
		
																				// weak goes out of scope. reference count not increased for weak_ptrs
		std::cout << "Exiting second scope. Ref count becomes one as two shared pointers from scope two go out of scope." << std::endl;
		
		std::cout << "Is weak pointer created in scope 0 expired? \n" << (weakOutOfScope.expired() ? "true" : "false") << std::endl;
	}																			// shared is destroyed as sharedCopyDifferentScope goes out of scope and reference count goes to 0
	std::cout << "Exiting first scope. Original shared pointer is destroyed as final reference from scope 1 goes out of scope. Ref count 0." << std::endl;
	
																				// here, shared is out of scope. since weakOutOfScope points to shared, it points to deleted memory.
																				// we can ensure safety by checking:
	std::cout << "Is weak pointer created in scope 0 expired? " << (weakOutOfScope.expired() ? "true" : "false") << std::endl;
	
	return 0;
}