#include "pch.h"
#include "CppUnitTest.h"

#include "..\calculator.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace KRUT
{
	TEST_CLASS(KRUT)
	{
	public:
		
		TEST_METHOD(TestFindError)
		{
			std::string testStr1 = "cos(23sin(30)cos(45)-log(23))+cos(43)-45*(-23)^(";
			std::string testStr2 = "cos(23sin(30)cos(45)-log(23))+cos(43)-45*(-23)^(23-cos(30))";
			queue tokens;

			Assert::IsTrue(findError(testStr1, tokens) != -1);
			tokens.clear();
			Assert::IsTrue(findError(testStr2, tokens) == -1);
		}

		TEST_METHOD(TestInfixToPrefix)
		{
			queue infix, prefix, result;
			infix.enqueue("cos");
			infix.enqueue("(");
			infix.enqueue("30");
			infix.enqueue(")");	
			infix.enqueue("*");
			infix.enqueue("sin");
			infix.enqueue("(");
			infix.enqueue("30");
			infix.enqueue(")");

			prefix.enqueue("*");
			prefix.enqueue("cos");
			prefix.enqueue("30");
			prefix.enqueue("sin");
			prefix.enqueue("30");

			result = infixToPrefix(infix);
			for (int i = 0; i < prefix.getSize(); i++)
				Assert::IsTrue(prefix[i] == result[i]);
		}

		TEST_METHOD(TestEvaluate)
		{
			std::string inputExpr = "cos(23sin(30)cos(30))^(sin(45)-tg(45))-8arccos(0)";
			queue infix, prefix;
			findError(inputExpr, infix);
			prefix = infixToPrefix(infix);
			double result = 0, rightResult = -718.99554300000000;
			result = eval(prefix);
			Assert::IsTrue(result == rightResult);
		}
	};
}
