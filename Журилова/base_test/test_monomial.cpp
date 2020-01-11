#include "Monomial.h"
#include "Monomial.cpp"
#include <gtest.h>

TEST(Monomial, can_create_monom)
{
	ASSERT_NO_THROW(Monomial m);
}

TEST(Monomial, can_create_monom_with_data)
{
	ASSERT_NO_THROW(Monomial m(0, -1, -1, -1));
}

TEST(Monomial, can_get_coeff_of_monom)
{
	Monomial m(0, -1, -1, -1);

	EXPECT_EQ(m.GetCoeff(), 0);
}


TEST(Monomial, can_get_degree_x_of_monom_)
{
	Monomial m(0, -1, -2, -3);

	EXPECT_EQ(m.GetDegreeX(), -1);
}

TEST(Monomial, can_get_degree_y_of_monom_)
{
	Monomial m(0, -1, -2, -3);

	EXPECT_EQ(m.GetDegreeY(), -2);
}

TEST(Monomial, can_get_degree_z_of_monom_)
{
	Monomial m(0, -1, -2, -3);

	EXPECT_EQ(m.GetDegreeZ(), -3);
}

TEST(Monomial, can_set_coeff_of_monom_)
{
	Monomial m;
	m.SetCoeff(1);

	EXPECT_EQ(m.GetCoeff(), 1);
}

TEST(Monomial, can_set_degree_x_of_monom_)
{
	Monomial m;
	m.SetDegreeX(1);

	EXPECT_EQ(m.GetDegreeX(), 1);
}

TEST(Monomial, can_set_degree_y_of_monom_)
{
	Monomial m;
	m.SetDegreeY(1);

	EXPECT_EQ(m.GetDegreeY(), 1);
}

TEST(Monomial, can_set_degree_z_of_monom_)
{
	Monomial m;
	m.SetDegreeZ(1);

	EXPECT_EQ(m.GetDegreeZ(), 1);
}

TEST(Monomial, can_set_data_of_monom_)
{
	Monomial m;
	m.SetData(0, 1, 2, 3);
	EXPECT_EQ(m.GetCoeff(), 0);
	EXPECT_EQ(m.GetDegreeX(), 1);
	EXPECT_EQ(m.GetDegreeY(), 2);
	EXPECT_EQ(m.GetDegreeZ(), 3);
}


TEST(Monomial, can_create_monom_with_other_monom)
{
	Monomial m1(10, 2, 3, 4);
	ASSERT_NO_THROW(Monomial m(m1));
	Monomial m(m1);
	EXPECT_EQ(m.GetCoeff(), 10);
	EXPECT_EQ(m.GetDegreeX(), 2);
	EXPECT_EQ(m.GetDegreeY(), 3);
	EXPECT_EQ(m.GetDegreeZ(), 4);
}

TEST(Monomial, can_clean_monom)
{
	Monomial m1(10, 2, 3, 4);
	m1.CleanMon();
	EXPECT_EQ(m1.GetCoeff(), 0);
	EXPECT_EQ(m1.GetDegreeX(), 0);
	EXPECT_EQ(m1.GetDegreeY(), 0);
	EXPECT_EQ(m1.GetDegreeZ(), 0);
}

TEST(Monomial, EQ_of_monoms)
{
	Monomial m(0, 0, 1, 1);
	Monomial m1(0, 0, 1, 1);
	EXPECT_TRUE(m1 == m);
}

TEST(Monomial, not_EQ_of_monoms)
{
	Monomial m(0, 0, 1, 1);
	Monomial m1(0, 1, 1, 1);
	EXPECT_TRUE(m1 != m);
} 

TEST(Monomial, operator_multiplication_is_correct1)
{
	Monomial m1(2, 2, 3, 4);
	Monomial m2(5, 3, 1, 8);
	Monomial res;
	res = m1 * m2;
	EXPECT_EQ(res.GetCoeff(), 10);
	EXPECT_EQ(res.GetDegreeX(), 5);
	EXPECT_EQ(res.GetDegreeY(), 4);
	EXPECT_EQ(res.GetDegreeZ(), 12);
}

TEST(Monomial, operator_assignment_is_correct1)//оператор присваивания
{
	Monomial m1;
	Monomial m2(5, 3, 1, 8);
	m1 = m2;
	EXPECT_EQ(m1.GetCoeff(), 5);
	EXPECT_EQ(m2.GetDegreeX(), 3);
	EXPECT_EQ(m2.GetDegreeY(), 1);
	EXPECT_EQ(m2.GetDegreeZ(), 8);
}
/*
TEST(Monomial, can_print_monom)
{
	Monomial mon(10, 1, 2, 4);
	Monomial mon1(-10, 3, 6, 9);
	Monomial mon2(-20, 0, 0, 0);
	mon.PrintMon();
	cout << endl;
	mon1.PrintMon();
	cout << endl;
	mon2.PrintMon();
}
*/
