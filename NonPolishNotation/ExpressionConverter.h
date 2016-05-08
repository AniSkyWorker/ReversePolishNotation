#pragma once

enum class Operators
{
	None,
	Braket,
	PlusMinus,
	Multiply
};

class CExpressionConverter
{
public:
	std::string CExpressionConverter::ToSuffixNotation(const std::string & expression) const;
};

namespace
{
	Operators GetOperatorType(const char & chr)
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

	void AddOperatorToExpressionFromStack(std::string & convertedExpression, std::stack<char> & operationStack)
	{
		if (*(convertedExpression.end() - 1) != ' ')
		{
			convertedExpression += ' ';
		}
		convertedExpression += operationStack.top();
		operationStack.pop();
	}
}