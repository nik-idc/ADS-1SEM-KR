#include "calculator.h"
#include <conio.h>

int main()
{
	std::string infix;

	std::cout << "Enter the expression (no spaces!):" << std::endl;
	std::getline(std::cin, infix);
	queue tokens, prefix;
	int errorInd = findError(infix, tokens);
	if (errorInd == -1)
	{
		prefix = infixToPrefix(tokens);
		std::cout << std::endl;
		prefix.print();

		std::cout << std::endl;
		std::cout << eval(prefix) << std::endl;
	}
	else
		std::cout << "Error at index " << errorInd << std::endl;
}