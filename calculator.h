#pragma once

#ifndef CALC_H
#define CALC_H

#include "stack.h"
#include "queue.h"
#include <math.h>

// Error flag, sets to true if value is incalculable
static bool calculationError = false;

// Binary operator counter
double binOper(std::string op1, std::string op2, std::string oprtr);

// Function counter
double funcOper(std::string func, std::string num);

// Error finder, also creates tokens queue
int findError(std::string& in, queue& tokens);

// Turns infix queue to prefix queue
queue infixToPrefix(queue infix);

// Calculates value
double eval(queue prefix);
#endif