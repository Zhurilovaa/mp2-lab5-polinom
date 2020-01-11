#include "TList.h"

#include <gtest.h>

//�������� ������
TEST(TList, can_create_list_without_parameters)
{
	ASSERT_NO_THROW(TList<int> list);//�������� ���������� ����������
}
//�������� �������
TEST(TList, can_insert_connect_node)
{
	TList<int> list;
	list.InsertConnect(2);
	EXPECT_EQ(list.GetDataCur(), 2);
}
TEST(TList, can_insert_first_node)
{
	TList<int> list;
	list.InsertConnect(2);
	list.InsertFirst(3);
	list.Reset();//������� - ������ �������
	EXPECT_EQ(list.GetDataCur(), 3);
}
TEST(TList, can_insert_last_node)
{
	TList<int> list;
	list.InsertConnect(2);
	list.InsertLast(3);
	EXPECT_EQ(list.GetDataCur(), 3);
}
TEST(TList, can_insert_current_node)
{
	TList<int> list;
	list.InsertConnect(2);
	list.InsertFirst(3);
	list.Insert�urrent(4);
	list.StepBack();
	EXPECT_EQ(list.GetDataCur(), 4);
}
//�������� �������, ����� ������ � ���������� ��������
TEST(TList, function_empty_is_correct1)
{
	TList<int> list;
	list.InsertConnect(2);
	EXPECT_EQ(list.Empty(), true);
}
TEST(TList, function_empty_is_correct2)
{
	TList<int> list;
	list.InsertConnect(2);
	list.InsertFirst(3);
	EXPECT_EQ(list.Empty(), false);
}
TEST(TList, list_is_end)
{
	TList<int> list;
	list.InsertConnect(2);
	EXPECT_EQ(list.ListEnd(), true);
}

TEST(TList, list_is_not_End)
{
	TList<int> list;
	list.InsertConnect(2);
	list.InsertFirst(3);
	EXPECT_EQ(list.ListEnd(), false);
}
TEST(TList, elem_is_last)
{
	TList<int> list;
	list.InsertConnect(2);
	list.InsertFirst(3);
	EXPECT_EQ(list.LastElem(), true);
}
TEST(TList, elem_is_not_last)
{
	TList<int> list;
	list.InsertConnect(2);
	list.InsertFirst(3);
	list.InsertFirst(4);
	list.Reset();
	EXPECT_EQ(list.ListEnd(), false);
}
//�������� ����� �� ������
TEST(TList, function_step_next_is_correct)
{
	TList<int> list;
	list.InsertConnect(2);
	list.InsertFirst(3);
	list.InsertLast(4);
	list.Reset();
	list.StepNext();
	EXPECT_EQ(list.GetDataCur(), 4);
}
TEST(TList, function_step_back_is_correct)
{
	TList<int> list;
	list.InsertConnect(2);
	list.InsertFirst(3);
	list.StepBack();
	EXPECT_EQ(list.GetDataCur(), 2);
}

//��������� � ���������
TEST(TList, function_get_data_current_is_correct)
{
	TList<int> list;
	list.InsertConnect(2);
	EXPECT_EQ(list.GetDataCur(), 2);
}
TEST(TList, function_set_current_data_is_correct)
{
	TList<int> list;
	list.InsertConnect(2);
	list.SetCurrentData(5);
	EXPECT_EQ(list.GetDataCur(), 5);
}
TEST(TList, can_Reset)
{
	TList<int> list;
	list.InsertConnect(2);
	list.InsertFirst(3);
	list.InsertLast(4);
	list.Reset();
	EXPECT_EQ(list.GetDataCur(), 3);
}

//��������
TEST(TList, can_delete_first_node)
{
	TList<int> list;
	list.InsertConnect(2);
	list.InsertFirst(3);
	list.InsertLast(4);
	list.DeleteFirst();
	EXPECT_EQ(list.GetDataCur(), 4);
}
TEST(TList, can_not_delete_first_node)
{
	TList<int> list;
	list.InsertConnect(2);
	ASSERT_ANY_THROW(list.DeleteFirst(););
}
TEST(TList, can_delete_last_node)
{
	TList<int> list;
	list.InsertConnect(2);
	list.InsertFirst(3);
	list.InsertLast(4);
	list.DeleteLast();//������� ������� ����� �� ���������
	list.StepBack();
	EXPECT_EQ(list.GetDataCur(), 3);
}
TEST(TList, can_delete_current_node)
{
	TList<int> list;
	list.InsertConnect(2);
	list.InsertFirst(3);
	list.Insert�urrent(4);
	list.Insert�urrent(5);
	list.DeleteCurrent();
	EXPECT_EQ(list.GetDataCur(), 5);
}
TEST(TList, can_delete_all_list)
{
	TList<int> list;
	list.InsertConnect(2);
	list.InsertFirst(3);
	list.Insert�urrent(4);
	list.DeleteAllList();
	EXPECT_EQ(list.Empty(), true);
}