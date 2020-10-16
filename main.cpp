/** @file main.cpp
* Statement of Purpose: To evaluate a postfix expression
* @author Daniel Targonski
* @date 9/30/2020
*/

#include<iostream>
#include"StackInterface.h"
#include"LinkedStack.h"
#include"Node.h"

using namespace std;

int main()
{
	string postfix{};
	int i{};
	float result{}, operand1{}, operand2{};
	LinkedStack<float> operandStack;
	
	cout << "Input a postfix expression: ";
	cin >> postfix;
	cout << "\n\n";

	// Parses the postfix expression to evaluate the
	// value of the postfix expression
	for (i = 0; i < postfix.length(); i++)
	{
		if (postfix[i] >= '0' && postfix[i] <= '9')
		{
			//push the value of the operand ch onto the stack
			operandStack.push(postfix[i] - '0');
		} // end if
		else
		{
			// Evaluate and push the result
			operand2 = operandStack.peek();
			operandStack.pop();
			operand1 = operandStack.peek();
			operandStack.pop();

			// Perform the correct operation on the operands
			// and store it in result, then push result
			// onto the stack
			switch (postfix[i])
			{
			case '+':
				result = operand1 + operand2;
				break;
			case '-':
				result = operand1 - operand2;
				break;
			case '*':
				result = operand1 * operand2;
				break;
			case '/':
				if (operand2 == 0) // cannot divide by zero
				{
					cout << "Undefined.\nCannot divide by zero.\n";
					return 0;
				} // end if
				result = operand1 / operand2;
				break;

			default:
				break;
			}
			operandStack.push(result);
		} // end else
	} // end for loop

	cout << "The result is: " << operandStack.peek() << "\n";

	return 0;
} // end main