#include "funcs.h"

bool isNumber(std::string ch)
{
	if (ch[0] >= '0' && ch[0] <= '9')
		return true;
	else
		return false;
}

bool isNumber(char ch)
{
	if (ch >= '0' && ch <= '9')
		return true;
	else
		return false;
}


bool isSymbol(char ch)
{
	if (ch >= 'a' && ch <= 'z')
		return true;
	else
		return false;
}

bool isOperator(std::string ch)
{
	if (ch == "+" || ch == "-" || ch == "*" || ch == "/" || ch == "^")
		return true;
	else
		return false;
}

bool isOperator(char ch)
{
	if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^')
		return true;
	else
		return false;
}

bool isFunction(std::string func)
{
	if (func == cosString || func == sinString || func == tgString || func == ctgString || func == arccosString ||
		func == arcsinString || func == arctgString || func == arcctgString || func == lnString || func == logString || func == sqrtString)
		return true;
	else
		return false;
}

bool isOpenBr(std::string ch)
{
	if (ch == "(")
		return true;
	else
		return false;
}

bool isCloseBr(std::string ch)
{
	if (ch == ")")
		return true;
	else
		return false;
}

int precedence(std::string op)
{
	if (op == "+" || op == "-")
		return 1;
	else if (op == "*" || op == "/")
		return 2;
	else if (op == "^")
		return 3;
	else
		return -1;
}