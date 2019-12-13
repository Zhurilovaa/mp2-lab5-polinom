#include "Polynomial.h"
#include <gtest.h>
#include <string>

// Создание полинома
TEST(Polynomial, can_create_polinom)
{
	ASSERT_NO_THROW(Polynomial p(""));
}
TEST(Polynomial, calculate_in_point_is_correct_1)
{
	Polynomial pol("2X^4Y^5Z^2-3X^3Y^2Z^8+7XYZ^6+2Z");
	EXPECT_EQ(pol.CalcInPoint(1, 1, 1), 8);
}
TEST(Polynomial, calculate_in_point_is_correct_2)
{
	Polynomial pol("5X^5Y^3Z^2+X^4Y^5Z^2-33X^3Y^5+5X^2Y^5Z^6+3");
	EXPECT_EQ(pol.CalcInPoint(1, 1, 1), -19);
}
TEST(Polynomial, can_sort_polinom)
{
	Polynomial pol("Y^2Z+XZ+X^6+X^5Y^2+4");
	pol.SortPolynom();
	EXPECT_EQ(pol.GetPolinom(), "1X^6+1X^5Y^2+1X^1Z^1+1Y^2Z^1+4");
}
TEST(Polynomial, can_add_two__polinoms)
{
	Polynomial pol1("2X^4Y^5Z^2-3X^3Y^2Z^8+7XYZ^6+2Z");
	Polynomial pol2("5X^5Y^3Z^2+X^4Y^5Z^2-33X^3Y^5+5X^2Y^5Z^6+3 ");
	Polynomial pol3("");
	pol3 = pol1 + pol2;
	EXPECT_EQ(pol3.GetPolinom(), "5X^5Y^3Z^2+3X^4Y^5Z^2-33X^3Y^5-3X^3Y^2Z^8+5X^2Y^5Z^6+7X^1Y^1Z^6+2Z^1+3");
}
TEST(Polynomial, can_sub_two_polinoms)
{
	Polynomial pol1("2X^4Y^5Z^2-3X^3Y^2Z^8+7XYZ^6+2Z");
	Polynomial pol2("5X^5Y^3Z^2+X^4Y^5Z^2-33X^3Y^5+5X^2Y^5Z^6+3 ");
	Polynomial pol3("");
	pol3 = pol1 - pol2;
	EXPECT_EQ(pol3.GetPolinom(), "-5X^5Y^3Z^2+1X^4Y^5Z^2+33X^3Y^5-3X^3Y^2Z^8-5X^2Y^5Z^6+7X^1Y^1Z^6+2Z^1-3");
}
TEST(Polynomial, EQ_of_two_polinoms)
{
	Polynomial pol1("2X^4Y^5Z^2-3X^3Y^2Z^8+7XYZ^6+2Z");
	Polynomial pol2("2X^4Y^5Z^2-3X^3Y^2Z^8+7XYZ^6+2Z");
	EXPECT_EQ(pol1 == pol2, true);
}
TEST(Polynomial, not_EQ_of_two_polinoms)
{
	Polynomial pol1("2X^4Y^5Z^2-3X^3Y^2Z^8+7XYZ^6+2Z");
	Polynomial pol2("5X^5Y^3Z^2+X^4Y^5Z^2-33X^3Y^5+5X^2Y^5Z^6+3 ");
	EXPECT_EQ(pol1 == pol2, false);
}
TEST(Polynomial, multiplication_of_polynomials)
{
	Polynomial pol1("X^2Y^7+XY^5+Z");
	Polynomial pol2("X^5+Y^6Z+5");
	Polynomial pol3 = pol1 * pol2;
	EXPECT_EQ(pol3.GetPolinom(), "1X^7Y^7+1X^6Y^5+1X^5Z^1+1X^2Y^13Z^1+5X^2Y^7+1X^1Y^11Z^1+5X^1Y^5+1Y^6Z^2+5Z^1");
}
TEST(Polynomial, operator_assignment_is_correct1)
{
	Polynomial pol1("X^2Y^7+XY^5+Z");
	Polynomial pol2("");
	pol2 = pol1;
	EXPECT_EQ(pol2== pol1,true);
}
TEST(Polynomial, function_milt_const_is_correct)
{
	Polynomial pol("X^2Y^7+XY^5+Z");
	pol.MultConst(5);
	EXPECT_EQ(pol.GetPolinom(), "5X^2Y^7+5XY^5+5Z");
}

