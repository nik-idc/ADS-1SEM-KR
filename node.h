#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <string>

// Node class for stack and queue
class node
{
public:
	std::string data; // Basic data block
	node *link; // A pointer for linking lists. In the case of 'stack' points to the previous element, whereas in the case of 'queue' points to next element

	node() // Basic node constructor
	{
		data = "";
		link = NULL;
	}
};

#endif