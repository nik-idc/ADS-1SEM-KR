#include "calculator.h"

double binOper(std::string op1, std::string op2, std::string oprtr)
{
	double n1 = std::stod(op1), n2 = std::stod(op2);
	if (oprtr == "+")
		return (n1 + n2);
	else if (oprtr == "-")
		return (n1 - n2);
	else if (oprtr == "*")
		return (n1 * n2);
	else if (oprtr == "/")
	{
		if (n2 == 0)
			calculationError = true;
		else
			return (n1 / n2);
	}
	else if (oprtr == "^")
		return pow(n1, n2);

	return 0;
}

double funcOper(std::string func, std::string num)
{
	double n = std::stod(num);
	if (func == cosString)
		return cos(n * toRad);
	if (func == sinString)
		return sin(n * toRad);
	if (func == tgString)
	{
		if ((int)n - n == 0 && (int)n % 90 == 0 && ((int)n / 90) % 2 == 1)
			calculationError = true;
		else
			return tan(n * toRad);
	}
	if (func == ctgString)
	{
		if ((int)n - n == 0 && (int)n % 90 == 0 && ((int)n / 90) % 2 == 0)
			calculationError = true;
		else
			return cos(n * toRad) / sin(n * toRad);
	}
	if (func == arccosString)
	{
		if (n < -1 || n > 1)
			calculationError = true;
		else
			return acos(n * toRad) * (1 / toRad);
	}
	if (func == arcsinString)
	{
		if (n < -1 || n > 1)
			calculationError = true;
		else
			return asin(n * toRad) * (1 / toRad);
	}
	if (func == arctgString)
		return atan(n * toRad) * (1 / toRad);
	if (func == arcctgString)
		return 1 / atan(n * toRad) * (1 / toRad);
	if (func == lnString)
	{
		if (n <= 0)
			calculationError = true;
		else
			return log(n);
	}
	if (func == logString)
	{
		if (n <= 0)
			calculationError = true;
		else
			return log10(n);
	}
	if (func == sqrtString)
	{
		if (n < 0)
			calculationError = true;
		else
			return sqrt(n);
	}
	return 0;
}

int findError(std::string& in, queue& tokens)
{
	int i, size = in.size();

	if (!isNumber(in[0]) && !isSymbol(in[0]) && in[0] != '(' && in[0] != '-') // Check the first symbol
		return 0;
	else if (in[0] == '-')
		in = "0" + in;

	stack s;
	for (i = 0; i < size;) // Loop to check input validity
	{
		if (in[i] >= '0' && in[i] <= '9') // If current symbol is a number
		{
			bool dotPresent = false; // Flag to check if there's more than one dot in between numbers
			std::string t; // Stringing for the number token
			while (((in[i] >= '0' && in[i] <= '9') || in[i] == '.') && i < size) // While current symbol is a number
			{
				if (in[i] == '.' && !dotPresent) // If we encounter a dot for the first time
				{
					if (i == size - 1) // If dot is at the end output error index
						return i;
					else // Otherwise write the dot into 't'
					{
						t += in[i];
						i++;
						if (i < size && !isNumber(in[i]))
							return i;
						dotPresent = true;
					}
				}
				else if (in[i] == '.' && dotPresent) // If we encounter a second dot return error index
					return i;
				else // If current symbol is a number write into 't'
				{
					t += in[i];
					i++;
				}
			}
			tokens.enqueue(t); // Add the number token to token stack

			if (i < size && (isSymbol(in[i]) || in[i] == '(')) // Changing 'nfunc(...)' or 'n(...)' into 'n*func(...)' or 'n*(...)' respectively
				tokens.enqueue("*");
		}
		else if (in[i] >= 'a' && in[i] <= 'z') // If current symbol is a symbol
		{
			std::string func; // Stringing for the function token
			while (in[i] >= 'a' && in[i] <= 'z' && i < size) // Reading the word
			{
				func += in[i];
				i++;
			}
			if (isFunction(func) || func == "e" || func == "pi") // If the word is one of the functions then write it into the tokens stack
			{
				if (func == "e")
					tokens.enqueue(std::to_string(e));
				else if (func == "pi")
					tokens.enqueue(std::to_string(pi));
				else
					tokens.enqueue(func);
			}
			else // Otherwise return error index
				return i;


			if ((i < size && in[i] != '(' || i == size) && func != "e" && func != "pi") // If there are no brackets after the function return error index
				return i;
		}
		else if (isOperator(in[i])) // If current symbol is an operator
		{
			if (i == size - 1) // If operator is at the end of input string return error index
				return i;
			else if (isOperator(in[i + 1]) || in[i + 1] == ')') // If next symbol is also an opeartor or a closing bracket return error index
				return i + 1;
			else // If no errors were spotted write symbol into the tokens stack
			{
				tokens.enqueue(in[i]);
				i++;
			}
		}
		else if (in[i] == '(') // If current symbol is an opening bracket
		{
			tokens.enqueue(in[i]); // Push bracket to the tokens stack
			s.push(in[i]); // Push bracket into bracket balance checking stack
			i++;
			if (i < size && (in[i] == ')' || in[i] == ' ')) // If next element is a closing bracket or a space return error index
				return i;
			else if (i < size && in[i] == '-') // Change '...(-n...' into '...(0-n...'
				tokens.enqueue("0");
		}
		else if (in[i] == ')') // If current symbol is a closing bracket
		{
			if (s.isEmpty()) // Brackets not balanced -> return error index
				return i;
			else
				s.pop();
			tokens.enqueue(in[i]); // Push closing bracket onto tokens stack
			i++;
			if (i < size && (isNumber(in[i]) || isSymbol(in[i]) || in[i] == '(')) // Changing 'a(...)b(...)' into 'a(...)*b(...)'
				tokens.enqueue("*");
			//return i;
		}
		else // If current symbol is not a supported symbol
			return i;
	}

	if (!s.isEmpty())
		return i;

	return -1; // Return -1 to signify that the input is correct
}

queue infixToPrefix(queue infix)
{
	queue prefix;
	stack s;
	std::string curToken = "";
	int size = infix.getSize();

	infix.reverse(1);

	for (int i = 0; i < infix.getSize(); i++)
	{
		curToken = infix[i];

		if (isNumber(curToken) || isFunction(curToken))
			prefix.enqueue(curToken);
		else if (curToken == "(")
			s.push(curToken);
		else if (curToken == ")")
		{
			while (s.getTop() != "(" && !s.isEmpty())
				prefix.enqueue(s.pop());
			if (s.getTop() == "(")
				s.pop();
		}
		else if (isOperator(curToken))
		{
			if (s.isEmpty())
				s.push(curToken);
			else
			{
				if (precedence(curToken) > precedence(s.getTop()))
					s.push(curToken);
				else if (precedence(curToken) == precedence(s.getTop()) && curToken == "^")
				{
					while (precedence(curToken) == precedence(s.getTop()))
						prefix.enqueue(s.pop());
					s.push(curToken);
				}
				else if (precedence(curToken) == precedence(s.getTop()))
					s.push(curToken);
				else if (precedence(curToken) < precedence(s.getTop()))
				{
					while (!s.isEmpty() && precedence(curToken) < precedence(s.getTop()))
						prefix.enqueue(s.pop());
					s.push(curToken);
				}
			}
		}
	}

	while (!s.isEmpty())
		prefix.enqueue(s.pop());

	prefix.reverse(0);
	return prefix;
}

double eval(queue prefix)
{
	stack calc;
	double res = 0, t = 0;

	for (int i = prefix.getSize() - 1; i >= 0; i--)
	{
		std::string cur = prefix[i];

		if (isNumber(cur))
			calc.push(cur);
		else if (isOperator(cur) || isFunction(prefix[i]))
		{
			if (isOperator(cur))
			{
				std::string num1 = calc.pop();
				std::string num2 = calc.pop();
				t = binOper(num1, num2, cur);
				if (calculationError)
				{
					std::cout << "Calculation error: cannot divide by 0" << std::endl;
					break;
				}
				else
					calc.push(std::to_string(t));
			}
			else
			{
				std::string num = calc.pop();
				t = funcOper(cur, num);
				if (calculationError)
				{
					std::cout << "Calculation error: function " << cur << " can't take " << num << " as an argument" << std::endl;
					break;
				}
				else
					calc.push(std::to_string(t));
			}
		}
	}
	if (!calculationError)
		return std::stod(calc.getTop());
	else
		return 0;
}