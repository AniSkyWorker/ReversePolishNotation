#include "stdafx.h"
#include "ExpressionConverter.h"

int main()
{
	CExpressionConverter conv;
	std::cout << conv.ToSuffixNotation("(2.4 + 10) * ((1) + 2)");
	return 0;
}