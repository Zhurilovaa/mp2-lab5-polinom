#include <gtest.h>
#include <string>
#include "Polynomial.h"
#include "Polynomial.cpp"



// Создание полинома

TEST(Polynomial, can_create_polinom)
{
	ASSERT_NO_THROW(Polynomial p(""));
}

TEST(Polynomial, can_create_polinom_with_string)
{
	ASSERT_NO_THROW(Polynomial p("4X^4Y^5Z^2-3X^3Y^2Z^8+7X^1Y^1Z^6+2Z^1"));
}


TEST(Polynomial, calculate_in_point_is_correct_1)
{
	Polynomial pol("4X^4Y^5Z^2-3X^3Y^2Z^8");
	EXPECT_EQ(pol.CalcInPoint(1, 1, 1), 1);
}

TEST(Polynomial, can_add_two__polinoms)
{
	Polynomial p1("2X^4Y^5Z^2-3X^3Y^2Z^8+7XYZ^6+2Z");
	Polynomial p2("5X^5Y^3Z^2+X^4Y^5Z^2-33X^3Y^5+5X^2Y^5Z^6+3 ");
	Polynomial p3("");
	p3 = p1 + p2;

	EXPECT_EQ(p3.GetPolinom(), "+5X^5Y^3Z^2+3X^4Y^5Z^2-33X^3Y^5-3X^3Y^2Z^8+5X^2Y^5Z^6+7X^1Y^1Z^6+2Z^1+3");
}

TEST(Polynomial, can_sub_two_polinoms)
{
	Polynomial p1("2X^4Y^5Z^2-3X^3Y^2Z^8+7XYZ^6+2Z");
	Polynomial p2("5X^5Y^3Z^2+X^4Y^5Z^2-33X^3Y^5+5X^2Y^5Z^6+3 ");
	Polynomial p3("");
	p3 = p1 - p2;

	EXPECT_EQ(p3.GetPolinom(), "-5X^5Y^3Z^2+1X^4Y^5Z^2+33X^3Y^5-3X^3Y^2Z^8-5X^2Y^5Z^6+7X^1Y^1Z^6+2Z^1-3");
}

TEST(Polynomial, EQ_of_two_polinoms)
{
	Polynomial p1("2X^4Y^5Z^2-3X^3Y^2Z^8+7XYZ^6+2Z");
	Polynomial p2("2X^4Y^5Z^2-3X^3Y^2Z^8+7XYZ^6+2Z");


	EXPECT_EQ(p1 == p2, true);
}

TEST(TPolinom, not_EQ_of_two_polinoms)
{
	Polynomial p1("2X^4Y^5Z^2-3X^3Y^2Z^8+7XYZ^6+2Z");
	Polynomial p2(" + 5X^5Y^3Z^2+X^4Y^5Z^2-33X^3Y^5+5X^2Y^5Z^6+3 ");


	EXPECT_EQ(p1 == p2, false);
}

TEST(Polynomial, 1_multiplication_of_polynomials)
{
	Polynomial p1("X^2Y^7+XY^5+Z");
	Polynomial p2("X^5+Y^6Z+5");
	Polynomial p3 = p1 * p2;

	EXPECT_EQ(p3.GetPolinom(), "+1X^7Y^7+1X^6Y^5+1X^5Z^1+1X^2Y^13Z^1+5X^2Y^7+1X^1Y^11Z^1+5X^1Y^5+1Y^6Z^2+5Z^1");
}

TEST(Polynomial, 2_multiplication_of_polynomials)
{
	Polynomial p1("X^4+X^2");
	Polynomial p2("X^2+1");
	Polynomial p3 = p1 * p2;

	EXPECT_EQ(p3.GetPolinom(), "+1X^6+2X^4+1X^2");
}

/*
TEST(Polynomial, can_print_polynomial)
{
	Polynomial pol("4X^4Y^5Z^2-3X^3Y^2Z^8+7X^1Y^1Z^6+2Z^1");
	pol.PrintPol();
}*/



