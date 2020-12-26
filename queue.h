#include "node.h"
#include "funcs.h"

#ifndef QUEUE_H
#define QUEUE_H

class queue
{
public:

	// Basic constructor
	queue();

	// Destructor
	~queue();

	// Copy constructor
	queue(const queue& toCopy);

	// Enqueue
	void enqueue(std::string data);

	// Enqueue
	void enqueue(char data);

	// Dequeue
	void dequeue();

	// Check if queue is empty
	bool empty();

	// Returns the size of the queue
	int getSize();

	// Reverses teh queue
	void reverse(bool toChangePars);

	// Returns front element
	std::string peek();

	// Clears the queue
	void clear();

	// Prints all elements
	void print();

	// [] opeartor for queue
	std::string& operator[](int ind);

	// = operator overload
	queue& operator=(const queue& right);

private:
	node *front;
	node *rear;
	int size;
};
#endif