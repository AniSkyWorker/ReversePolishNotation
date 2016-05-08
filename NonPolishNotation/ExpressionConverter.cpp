#include "stdafx.h"
#include "ExpressionConverter.h"

std::string CExpressionConverter::ToSuffixNotation(const std::string & expression) const
{
	std::stack<char> operationStack;
	std::string convertedExpression;
	bool isSpaceAgain = false;

	for (auto chr : expression)
	{
		if (isdigit(chr) || chr == '.')
		{
			convertedExpression += chr;
			isSpaceAgain = false;
			continue;
		}

		if (chr == ' ')
		{
			if (!isSpaceAgain && !convertedExpression.empty())
			{
				convertedExpression += ' ';
				isSpaceAgain = true;
			}
			continue;
		}

		Operators expOperator = GetOperatorType(chr);
		if (expOperator == Operators::Braket)
		{
			operationStack.push(chr);
		}
		else if (expOperator != Operators::None)
		{
			if (!operationStack.empty())
			{
				while (expOperator <= GetOperatorType(operationStack.top()))
				{
					AddOperatorToExpressionFromStack(convertedExpression, operationStack);
				}
			}
			operationStack.push(chr);
		}
		else
		{
			chr = operationStack.top();
			operationStack.pop();
			while (GetOperatorType(chr) != Operators::Braket)
			{
				if (*(convertedExpression.end() - 1) != ' ')
				{
					convertedExpression += ' ';
				}
				convertedExpression += chr;
				chr = operationStack.top();
				operationStack.pop();
			}
		}
	}

	while (!operationStack.empty())
	{
		AddOperatorToExpressionFromStack(convertedExpression, operationStack);
	}

	return convertedExpression;
}
