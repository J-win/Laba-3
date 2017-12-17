// тесты для вычисления арифметических выражений
#include "stack.h"
#include "arithmetic.h"
#include <gtest.h>

class GlobalStackLexmem : public ::testing::Test
{
protected:
	Stack<Lexmem> s;
	Stack<Lexmem> sp;
	
public:
	GlobalStackLexmem()
	{
		s.push(25.0);    sp.push(25.0);
		s.push('+');     sp.push(5.0);
		s.push(5.0);     sp.push('+');
		s.push('+');     sp.push(10.0);
		s.push(10.0);    sp.push('+');
		s.push('-');     sp.push(3.0);
		s.push('(');     sp.push(2.0);
		s.push(3.0);     sp.push('*');
		s.push('*');     sp.push(1.0);
		s.push(2.0);     sp.push('-');
		s.push('-');     sp.push('-');
		s.push(1.0);
		s.push(')');
	}
	~GlobalStackLexmem() {}
};

string t[18] = { "", "+", "25+-5", "*25+5", "25+5*", "25 + 5", "(", ")", "(25+5", "25+5)", "25(5+5)", "(25+5)5", "25.5.5", "25..5", "a.5+5", "(2+3)(5+6)", "(25+5+)", "(+25+5)" };
string tt[3] = { "25+5+10-(3*2-1)", "-5", "(-5)" };
string ttt[5] = { "6+4", "13-3", "5*2", "50/5", "-5+15" };

class ParArithmetic : public ::testing::TestWithParam<string>
{
protected:
	string s;
public:
	ParArithmetic() { s = GetParam(); }
	~ParArithmetic() {}
};
class ParArithmetic2 : public ParArithmetic
{
protected:
	string s2;
public:
	ParArithmetic2() { s2 = GetParam(); }
	~ParArithmetic2() {}
};
class ParArithmetic3 : public ParArithmetic2
{
protected:
	string s3;
public:
	ParArithmetic3() { s3 = GetParam(); }
	~ParArithmetic3() {}
};

TEST_P(ParArithmetic, isIncorrect1)
{
	EXPECT_EQ(false, check_for_correctness(s));
}
INSTANTIATE_TEST_CASE_P(i1, ParArithmetic, ::testing::ValuesIn(t));

TEST_P(ParArithmetic2, isIncorrect2)
{
	EXPECT_EQ(true, check_for_correctness(s2));
}
INSTANTIATE_TEST_CASE_P(i2, ParArithmetic2, ::testing::ValuesIn(tt));

TEST_P(ParArithmetic3, isIncorrect3)
{
	Stack<Lexmem> b = convert_string_to_stack(s3);
	b = polish_notation(b);
	EXPECT_EQ(10, the_solution_of_the_expression(b));
}
INSTANTIATE_TEST_CASE_P(i3, ParArithmetic3, ::testing::ValuesIn(ttt));

TEST_F(GlobalStackLexmem, work_convert_string_to_stack)
{
	string a = "25+5+10-(3*2-1)";
	Stack<Lexmem> b = convert_string_to_stack(a);
	EXPECT_EQ(s, b);
}
TEST_F(GlobalStackLexmem, work_polish_notation)
{
	EXPECT_EQ(sp, polish_notation(s));
}
TEST_F(GlobalStackLexmem, work_the_solution_of_the_expression)
{

	EXPECT_EQ(35, the_solution_of_the_expression(sp));
}