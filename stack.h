#ifndef STACK_H
#define STACK_H

#include "node.h"

class stack
{
public:
	// Constructor
	stack();

	// Construct from existing array
	stack(int* arr, int size);

	// Copy constructor
	stack(const stack& toCopy);

	// Destructor
	~stack();

	// Add an element to the stack
	void push(std::string data);

	// Add an element to the stack
	void push(char data);

	// Delete element from stack
	std::string pop();

	// Return top element
	std::string getTop();

	// Check if the stack is empty
	bool isEmpty();

	// Clear the stack
	void clear();

	// Return size of the stack
	int getSize();

	// [] operator overload
	std::string& operator[](int ind);

	// = operator overload
	stack& operator=(const stack &rightStack);

	// == operator overload
	bool operator==(const stack& rightStack);
private:
	// The top node
	node *top;
	// Size variable
	int size;
};

#endif