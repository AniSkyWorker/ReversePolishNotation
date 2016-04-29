#include "stdafx.h"
#include "../NonPolishNotation/ExpressionConverter.h"

struct ExpressionConverter_
{
	CExpressionConverter converter;
};

BOOST_FIXTURE_TEST_SUITE(ExpressionConverter, ExpressionConverter_)

	BOOST_AUTO_TEST_CASE(convert_strings_arithmetical_expressions_to_reverse_polish_notation)
	{
		BOOST_CHECK_EQUAL(converter.ToSuffixNotation("(2.4 + 10) * ((1) + 2)"), "2.4 10 + 1 2 + *");
		BOOST_CHECK_EQUAL(converter.ToSuffixNotation("2.4 + 10 * (1 + 2)"), "2.4 10 1 2 + * +");
		BOOST_CHECK_EQUAL(converter.ToSuffixNotation("2.4 + 10 * (1 / (2 * 5))"), "2.4 10 1 2 5 * / * +");
	}

BOOST_AUTO_TEST_SUITE_END()