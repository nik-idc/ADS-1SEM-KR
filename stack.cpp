#include "stack.h"

stack::stack()
{
	top = NULL;
	size = 0;
}

stack::stack(int *arr, int size)
{
	top = NULL;
	this->size = 0;

	for (int i = 0; i < size; i++)
		push(0);

	node* cur = top;

	for (int i = size - 1; i >= 0; i--)
	{
		cur->data = arr[i];
		cur = cur->link;
	}
}

stack::stack(const stack& toCopy)
{
	top = NULL;
	this->size = 0;

	for (int i = 0; i < toCopy.size; i++)
		push(0);

	node* curR = toCopy.top;
	node* curL = top;
	for (int i = 0; i < toCopy.size; i++)
	{
		curL->data = curR->data;
		curL = curL->link;
		curR = curR->link;
	}
}

stack::~stack()
{
	if (!isEmpty())
		clear();
	top = NULL;
}

void stack::push(std::string data)
{
	node *temp = new node;
	temp->data = data;
	
	temp->link = top;
	top = temp;
	size++;
}

void stack::push(char data)
{
	node* temp = new node;
	temp->data = data;

	temp->link = top;
	top = temp;
	size++;
}

std::string stack::pop()
{
	if (!isEmpty())
	{
		std::string temp = top->data;
		node *prev = top->link;

		delete top;
		top = prev;

		size--;
		return temp;
	}
}

std::string stack::getTop()
{
	if (!isEmpty())
		return top->data;
}

bool stack::isEmpty()
{
	if (top)
		return false;
	else
		return true;
}

void stack::clear()
{
	while (!isEmpty())
		pop();
}

int stack::getSize()
{
	return size;
}

std::string& stack::operator[](int ind)
{
	if (ind >= 0 && ind < size)
	{
		int i = size - 1;
		node* current = top;
		for (; i != ind; i--)
			current = current->link;
		return current->data;
	}
}

stack& stack::operator=(const stack& rightStack)
{
	clear();

	for (int i = 0; i < rightStack.size; i++)
		push(0);
	
	node* curR = rightStack.top;
	node* curL = top;
	for (int i = 0; i < rightStack.size; i++)
	{
		curL->data = curR->data;
		curL = curL->link;
		curR = curR->link;
	}

	return *this;
}

bool stack::operator==(const stack& rightStack)
{
	if (size == rightStack.size)
	{
		node* curL = top;
		node* curR = rightStack.top;
		while (curL != NULL)
		{
			if (curL->data != curR->data)
				return false;
			else
			{
				curL = curL->link;
				curR = curR->link;
			}
		}
		return true;
	}
	else
		return false;
}