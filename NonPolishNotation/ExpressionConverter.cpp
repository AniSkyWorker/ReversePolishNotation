#include "stdafx.h"
#include "ExpressionConverter.h"

std::string CExpressionConverter::ToSuffixNotation(const std::string & expression) const
{
	std::stack<char> operationStack;
	std::string convertedExpression;

	for (auto chr : expression)
	{
		if (isdigit(chr) || chr == '.')
		{
			convertedExpression += chr;
			continue;
		}

		if (chr == ' ')
		{
			if (*(convertedExpression.end() - 1) != ' ')
			{
				convertedExpression += chr;
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
					convertedExpression += ' ';
					convertedExpression += operationStack.top();
					operationStack.pop();
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
				convertedExpression += ' ';
				convertedExpression += chr;
				chr = operationStack.top();
				operationStack.pop();
			}
		}
	}

	while (!operationStack.empty())
	{
		convertedExpression += ' ';
		convertedExpression += operationStack.top();
		operationStack.pop();
	}

	return convertedExpression;
}

Operators CExpressionConverter::GetOperatorType(const char & chr) const
{
	switch (chr)
	{
	case '(':
		return Operators::Braket;
	case '+': case '-':
		return Operators::PlusMinus;
	case '*': case '/':
		return Operators::Multiply;
	default:
		return Operators::None;
	}
}