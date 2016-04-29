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

private:
	Operators GetOperatorType(const char & chr) const;
};

