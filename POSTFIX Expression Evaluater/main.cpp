#include <iostream>
#include <string>
#include <stack>

using namespace std;


int evaluatePostfixExpression(string& expression)
{

	// Iterate over string and create a stack and strore your operand into your stack.
	stack<int> Operands;
	int index = 0;

	while (index < expression.length())
	{

		if (isdigit(expression[index]))
		{
			Operands.push(expression[index] - '0');
		}
		else {
			int val1 = Operands.top();
			Operands.pop();
			int val2 = Operands.top();
			Operands.pop();

			if (expression[index] == '+')
			{
				Operands.push(val2 + val1);
			}
			else if (expression[index] == '-')
			{
				Operands.push(val2 - val1);
			}
			else if (expression[index] == '*')
			{
				Operands.push(val2 * val1);
			}
			else if (expression[index] == '/')
			{
				Operands.push(val2 / val1);
			}
		}
			index++;
	}

	return Operands.top();

}


int main()
{

	string exp = "12+34-*3/";

	cout << "Result: " << evaluatePostfixExpression(exp) << endl;

	return 0;
}