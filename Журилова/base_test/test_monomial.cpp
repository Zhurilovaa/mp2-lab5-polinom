#include "Monomial.h"
#include <gtest.h>

//Создание монома
TEST(Monomial, can_create_monom_without_parameters)
{
	ASSERT_NO_THROW(Monomial m);
}
TEST(Monomial, can_create_monom_with_positive_degree)
{
	ASSERT_NO_THROW(Monomial m(10, 5, 6, 7));
}
//Работа с мономом
TEST(Monomial, can_create_monom_with_other_monom)
{
	Monomial m1(10, 2, 3, 4);
	ASSERT_NO_THROW(Monomial m(m1));
	Monomial m(m1);
	EXPECT_EQ(m.GetCoeff(), 10);
	EXPECT_EQ(m.GetDegreeeX(), 2);
	EXPECT_EQ(m.GetDegreeeY(), 3);
	EXPECT_EQ(m.GetDegreeeZ(), 4);
}
TEST(Monomial, can_clean_monom)
{
	Monomial m1(10, 2, 3, 4);
	m1.CleanMon();
	EXPECT_EQ(m1.GetCoeff(), 0);
	EXPECT_EQ(m1.GetDegreeeX(), 0);
	EXPECT_EQ(m1.GetDegreeeY(), 0);
	EXPECT_EQ(m1.GetDegreeeZ(), 0);	
}
TEST(Monomial, function_get_coeff_is_correct)
{
	Monomial m1(10, 2, 3, 4);
	EXPECT_EQ(m1.GetCoeff(), 10);
}
TEST(Monomial, function_get_degreeX_is_correct)
{
	Monomial m1(10, 2, 3, 4);
	EXPECT_EQ(m1.GetDegreeeX(), 2);
}
TEST(Monomial, function_get_degreeY_is_correct)
{
	Monomial m1(10, 2, 3, 4);
	EXPECT_EQ(m1.GetDegreeeY(), 3);
}
TEST(Monomial, function_get_degreeZ_is_correct)
{
	Monomial m1(10, 2, 3, 4);
	EXPECT_EQ(m1.GetDegreeeZ(), 4);
}
TEST(Monomial, function_set_data_is_correct)
{
	Monomial m1;
	m1.SetData(10, 2, 3, 4);
	EXPECT_EQ(m1.GetCoeff(), 10);
	EXPECT_EQ(m1.GetDegreeeX(), 2);
	EXPECT_EQ(m1.GetDegreeeY(), 3);
	EXPECT_EQ(m1.GetDegreeeZ(), 4);
}
TEST(Monomial, function_set_DegreeeX_is_correct)
{
	Monomial m1;
	m1.SetDegreeeX(2);
	EXPECT_EQ(m1.GetDegreeeX(), 2);
}
TEST(Monomial, function_set_DegreeeY_is_correct)
{
	Monomial m1;
	m1.SetDegreeeY(2);
	EXPECT_EQ(m1.GetDegreeeY(), 2);
}
TEST(Monomial, function_set_DegreeeZ_is_correct)
{
	Monomial m1;
	m1.SetDegreeeZ(2);
	EXPECT_EQ(m1.GetDegreeeZ(), 2);
}
TEST(Monomial, function_set_coeff_is_correct)
{
	Monomial m1;
	m1.SetCoeff(2);
	EXPECT_EQ(m1.GetCoeff(), 2);
}

//Операции
TEST(Monomial, operator_not_equal_is_correct1)
{
	Monomial m1(10,2,3,4);
	Monomial m2(20, 2, 3, 4);
	EXPECT_EQ(m1!=m2, true);
}
TEST(Monomial, operator_not_equal_is_correct2)
{
	Monomial m1(10, 2, 3, 4);
	Monomial m2(10, 2, 3, 4);
	EXPECT_EQ(m1 != m2, false);
}
TEST(Monomial, operator_equal_is_correct1)
{
	Monomial m1(10, 2, 3, 4);
	Monomial m2(20, 2, 3, 4);
	EXPECT_EQ(m1 == m2, false);
}
TEST(Monomial, operator_equal_is_correct2)
{
	Monomial m1(10, 2, 3, 4);
	Monomial m2(10, 2, 3, 4);
	EXPECT_EQ(m1 == m2, true);
}
TEST(Monomial, operator_multiplication_is_correct1)
{
	Monomial m1(2, 2, 3, 4);
	Monomial m2(5, 3, 1, 8);
	Monomial res;
	res = m1 * m2;
	EXPECT_EQ(res.GetCoeff(), 10);
	EXPECT_EQ(res.GetDegreeeX(), 5);
	EXPECT_EQ(res.GetDegreeeY(), 4);
	EXPECT_EQ(res.GetDegreeeZ(), 12);
}
TEST(Monomial, operator_assignment_is_correct1)//оператор присваивания
{
	Monomial m1;
	Monomial m2(5, 3, 1, 8);
	m1 = m2;
	EXPECT_EQ(m1.GetCoeff(), 5);
	EXPECT_EQ(m2.GetDegreeeX(), 3);
	EXPECT_EQ(m2.GetDegreeeY(), 1);
	EXPECT_EQ(m2.GetDegreeeZ(), 8);
}

