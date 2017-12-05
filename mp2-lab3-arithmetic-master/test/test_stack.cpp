// тесты для стека

#include "stack.h"
#include <gtest.h>

class GlobalStack : public ::testing::Test
{
protected:
	Stack<int> s;
public:
	GlobalStack()
	{
		for (int i = 0; i < 10; i++)
			s.push(i);
	}
	~GlobalStack() {}
};
TEST(Stack, negative_number)
{
	ASSERT_ANY_THROW(Stack<int> s(-1));
}
TEST(Stack, too_big_number)
{
	ASSERT_ANY_THROW(Stack<int> s(MAXElem + 1));
}
TEST_F(GlobalStack, work_get_nElem)
{
	EXPECT_EQ(10, s.get_nElem());
}
TEST_F(GlobalStack, work_top)
{
	EXPECT_EQ(9, s.top());
}
TEST_F(GlobalStack, work_push)
{
	s.push(5);
	EXPECT_EQ(5, s.top());
	EXPECT_EQ(11, s.get_nElem());
}
TEST_F(GlobalStack, work_pop)
{
	s.push(5);
	s.pop();
	EXPECT_NE(5, s.top());
	EXPECT_EQ(10, s.get_nElem());
}
TEST_F(GlobalStack, work_clean_stack)
{
	s.clean_stack();
	EXPECT_EQ(0, s.get_nElem());
}
TEST_F(GlobalStack, work_check_void)
{
	EXPECT_EQ(false, s.check_void());
	s.clean_stack();
	EXPECT_EQ(true, s.check_void());
}
TEST_F(GlobalStack, work_copy_constructor)
{
	Stack<int> s1 = s;
	EXPECT_EQ(s, s1);
}
TEST_F(GlobalStack, work_operator_same)
{
	Stack<int> s1;
	s1 = s;
	EXPECT_EQ(s, s1);
}
TEST_F(GlobalStack, work_converter)
{
	Stack<int> s1;
	for (int i = 9; i >= 0; i--)
		s1.push(i);
	s1.convert();
	EXPECT_EQ(s, s1);
}