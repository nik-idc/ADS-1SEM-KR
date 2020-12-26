#include "queue.h"

queue::queue()
{
	front = NULL;
	rear = NULL;
	size = 0;
}

queue::queue(const queue& toCopy)
{
	front = NULL;
	rear = NULL;
	size = 0;

	for (int i = 0; i < toCopy.size; i++)
		enqueue("0");

	node* curR = toCopy.front;
	node* curL = front;
	for (int i = 0; i < toCopy.size; i++)
	{
		curL->data = curR->data;
		curL = curL->link;
		curR = curR->link;
	}
}

queue::~queue()
{
	clear();
}

void queue::enqueue(std::string data)
{
	node* temp = new node;
	temp->data = data;

	if (!front)
	{
		front = temp;
		front->link = NULL;
	}
	else if (front && !rear)
	{
		rear = temp;
		front->link = rear;
		rear->link = NULL;
	}
	else
	{
		rear->link = temp;
		rear = temp;
		rear->link = NULL;
	}

	size++;
}

void queue::enqueue(char data)
{
	node* temp = new node;
	temp->data = data;

	if (!front)
	{
		front = temp;
		front->link = NULL;
	}
	else if (front && !rear)
	{
		rear = temp;
		front->link = rear;
		rear->link = NULL;
	}
	else
	{
		rear->link = temp;
		rear = temp;
		rear->link = NULL;
	}

	size++;
}

void queue::dequeue()
{
	if (!empty())
	{
		if (front && !rear)
		{
			delete front;
			front = NULL;
		}
		else if(front->link == rear)
		{
			delete front;
			front = rear;
			rear = NULL;
		}
		else
		{
			node* temp = front->link;
			delete front;
			front = temp;
		}

		size--;
	}
}

bool queue::empty()
{
	if (front)
		return false;
	else
		return true;
}

int queue::getSize()
{
	return size;
}

void queue::reverse(bool toChangePars)
{
	if (!empty())
	{
		int i = 0;
		std::string temp;
		int start = 0, end = getSize() - 1;

		while (end - start > 0)
		{
			std::string temp = (*this)[start];
			(*this)[start] = (*this)[end];
			(*this)[end] = temp;
			start++; end--;
		}

		if (toChangePars)
		{
			node* current = front;
			while (i < size)
			{
				if ((*this)[i] == "(")
					(*this)[i] = ")";
				else if ((*this)[i] == ")")
					(*this)[i] = "(";
				current = current->link;
				i++;
			}
		}
	}
}

std::string queue::peek()
{
	if(!empty())
		return front->data;
}

void queue::clear()
{
	if (!empty())
	{
		int i = 0, s = size;
		while (i < s)
		{
			dequeue();
			i++;
		}
	}
}

void queue::print()
{
	if (!empty())
	{
		int i = 0;
		node* current = front;
		while (i < size)
		{
			std::cout << current->data;
			current = current->link;
			i++;
		}
	}
}

std::string& queue::operator[](int ind)
{
	if (ind <= size && !empty())
	{
		int i = 0;
		node* current = front;
		while (i < ind)
		{
			current = current->link;
			i++;
		}

		return current->data;
	}
}

queue& queue::operator=(const queue& right)
{
	clear();

	for (int i = 0; i < right.size; i++)
		enqueue("0");

	node* curR = right.front;
	node* curL = front;
	for (int i = 0; i < right.size; i++)
	{
		curL->data = curR->data;
		curL = curL->link;
		curR = curR->link;
	}

	return *this;
}