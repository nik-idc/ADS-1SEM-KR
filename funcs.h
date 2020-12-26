#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <iostream>

const double pi = 3.1415926535897932384626433; // pi constant
const double e = 2.7182818284590452353602874713527; // e constant
const double toRad = pi / 180; // to pass degrees into trig. functions

// Function names

static const char* cosString = "cos";
static const char* sinString = "sin";
static const char* tgString = "tg";
static const char* ctgString = "ctg";
static const char* arccosString = "arccos";
static const char* arcsinString = "arcsin";
static const char* arctgString = "arctg";
static const char* arcctgString = "arcctg";
static const char* lnString = "ln";
static const char* logString = "log";
static const char* sqrtString = "sqrt";

/////////////////

// Checks if 'ch' is a number
bool isNumber(std::string ch);

// Checks if 'ch' is a number
bool isNumber(char ch);

// Checks if 'ch' is a symbol
bool isSymbol(char ch);

// Checks if 'ch' is a operator
bool isOperator(std::string ch);

// Checks if 'ch' is a operator
bool isOperator(char ch);

// Checks if 'func' is a function
bool isFunction(std::string func);

// Returns precedence of 'op'
int precedence(std::string op);

#endif