#include "vector.h"
#include <gtest.h>

TEST(TVector, can_create_vector_with_positive_length) // �������� ������� ������ � ������������� ��������� �����
{
	ASSERT_NO_THROW(TVector<int> v(5));
}

TEST(TVector, throws_when_create_vector_with_negative_length) // ���������� ������� ������ � ������������� ��������� �����
{
	ASSERT_ANY_THROW(TVector<int> v(-5));
}

TEST(TVector, throws_when_create_vector_with_negative_startindex) // ���������� ������� ������ � ������������� �������� ���������� �������
{
	ASSERT_ANY_THROW(TVector<int> v(5, -5));
}

TEST(TVector, can_create_copied_vector) // ������ ������������ �����������
{
	TVector<int> v(5);

	ASSERT_NO_THROW(TVector<int> v_first(v));
}

TEST(TVector, copied_vector_is_equal_to_source_one) // ������, ���������� � ���������� ������ ������������ �����������, ����� ��������� �������
{
	TVector<int> v_first;

	for (int i = 0; i < v_first.GetSize(); i++)
		v_first[i] = i;

	TVector<int> v_second(v_first);

	EXPECT_EQ(v_first, v_second);
}

TEST(TVector, copied_vector_has_its_own_memory) // ������, ���������� � ���������� ������ ������������ �����������, � �������� ������ ����� ������ ������� ������
{
	TVector<int> v_first;
	TVector<int> v_second(v_first);

	EXPECT_NE(&v_first, &v_second);
}

TEST(TVector, can_get_size) // �������� �������� ������ �������
{
	TVector<int> v(5);

	EXPECT_EQ(5, v.GetSize());
}

TEST(TVector, can_get_start_index) // ������� �������� ��������� ������ �������
{
	TVector<int> v(5, 1);

	EXPECT_EQ(1, v.GetStartIndex());
}

TEST(TVector, can_set_and_get_element) // �������� ������ � �������� ������� �� �������
{
	TVector<int> v(5);
	v[0] = 1;

	EXPECT_EQ(1, v[0]);
}

TEST(TVector, throws_when_set_element_with_negative_index) // ���������� ���������� � ������ ������� � ������������� ��������
{
	TVector<int> v(5);

	ASSERT_ANY_THROW(v[-1] = 1);
}

TEST(TVector, throws_when_set_element_with_too_large_index) // ���������� ���������� � ������ �������, ����� ������� ������� �� ������� ������� �������
{
	TVector<int> v(5);

	ASSERT_ANY_THROW(v[6] = 1);
}

TEST(TVector, can_assign_vector_to_itself) // �������� ����������� ������ ������ ����
{
	TVector<int> v;

	ASSERT_NO_THROW(v = v);
}

TEST(TVector, can_assign_vectors_of_equal_size) // ����� ��������� �������� ������������, ���� ������� �������� �����
{
	TVector<int> v_first(5);
	TVector<int> v_second(5);

	EXPECT_EQ(v_second.GetSize(), v_first.GetSize());

	for (int i = 0; i < v_second.GetSize(); i++)
		v_second[i] = i;

	EXPECT_EQ(v_second, v_first = v_second);
}

TEST(TVector, assign_operator_change_vector_size) // �������� ������������ �������� ������ �������, �� ������� ����������� ������������
{
	TVector<int> v_first(5);
	TVector<int> v_second(10);

	EXPECT_NE(v_first.GetSize(), v_second.GetSize());

	v_second = v_first;

	EXPECT_EQ(v_first.GetSize(), v_second.GetSize());
}

TEST(TVector, can_assign_vectors_of_different_size_and_change_size) // ����� ��������� �������� ������������, ���� ������� �������� ����������, �������� ��.
{
	TVector<int> v_first(5);
	TVector<int> v_second(10);

	EXPECT_NE(v_second.GetSize(), v_first.GetSize());

	for (int i = 0; i < v_second.GetSize(); i++)
		v_second[i] = i;

	EXPECT_EQ(v_second, v_first = v_second);
}

TEST(TVector, compare_equal_vectors_return_true) // ��������� ���������� �������� 
{
	TVector<int> v_first;

	for (int i = 0; i < v_first.GetSize(); i++)
	{
		v_first[i] = i;
	}

	TVector<int> v_second(v_first);

	EXPECT_EQ(true, v_first == v_second);
}

TEST(TVector, compare_vector_with_itself_return_true) // ��������� ������� � ����� ������
{
	TVector<int> v_first;

	for (int i = 0; i < v_first.GetSize(); i++)
	{
		v_first[i] = i;
	}

	EXPECT_EQ(true, v_first == v_first);
}

TEST(TVector, vectors_with_different_size_are_not_equal) // ������� � ������ ������ �� �����
{
	TVector<int> v_first(5);
	TVector<int> v_second(10);

	EXPECT_NE(v_second.GetSize(), v_first.GetSize());
	EXPECT_EQ(true, v_first != v_second);
}

TEST(TVector, can_add_scalar_to_vector) // �������� �������� ������� � ������
{
	TVector<int> v_first(5);
	TVector<int> v_second(5);
	int temp = 10;

	for (int i = 0; i < v_first.GetSize(); i++)
	{
		v_first[i] = i + temp;
		v_second[i] = i;
	}

	EXPECT_EQ(v_first, v_second + temp);
}

TEST(TVector, can_subtract_scalar_from_vector) // �������� ��������� ����� �� �������
{
	TVector<int> v_first(5);
	TVector<int> v_second(5);
	int temp = 10;

	for (int i = 0; i < v_first.GetSize(); i++)
	{
		v_first[i] = i;
		v_second[i] = i + temp;
	}

	EXPECT_EQ(v_first, v_second - temp);
}

TEST(TVector, can_multiply_scalar_by_vector) // �������� ��������� ������� �� ������
{
	TVector<int> v_first(5);
	TVector<int> v_second(5);

	for (int i = 0; i < v_first.GetSize(); i++)
	{
		v_first[i] = i * 13;
		v_second[i] = i;
	}

	EXPECT_EQ(v_first, v_second * 13);
}

TEST(TVector, can_add_vectors_with_equal_size) // �������� ������� ������� ������ �������
{
	TVector<int> v_first(5);
	TVector<int> v_second(5);

	ASSERT_NO_THROW(v_first + v_second);
}

TEST(TVector, cant_add_vectors_with_not_equal_size) // ���������� ������� ������� ������� �������
{
	TVector<int> v_first(5);
	TVector<int> v_second(6);

	ASSERT_ANY_THROW(v_first + v_second);
}

TEST(TVector, can_subtract_vectors_with_equal_size) // �������� ��������� �������� ������ �������
{
	TVector<int> v_first(5);
	TVector<int> v_second(5);

	ASSERT_NO_THROW(v_first - v_second);
}

TEST(TVector, cant_subtract_vectors_with_not_equal_size) // ���������� ��������� �������� ������� ������� 
{
	TVector<int> v_first(5);
	TVector<int> v_second(6);

	ASSERT_ANY_THROW(v_first - v_second);
}

TEST(TVector, can_multiply_vectors_with_equal_size) // �������� ��������� �������� ������ �������
{
	TVector<int> v_first(5);
	TVector<int> v_second(5);

	for (int i = 0; i < v_first.GetSize(); i++)
	{
		v_first[i] = i * 10;
		v_second[i] = i - 10;
	}

	ASSERT_NO_THROW(v_first * v_second);
}

TEST(TVector, cant_multiply_vectors_with_not_equal_size) // ���������� ��������� �������� ������� �������
{
	TVector<int> v_first(5);
	TVector<int> v_second(6);

	for (int i = 0; i < v_first.GetSize(); i++)
	{
		v_first[i] = i * 10;
		v_second[i] = i - 10;
	}

	ASSERT_ANY_THROW(v_first * v_second);
}

TEST(TVector, can_division_vectors_with_equal_size) // �������� ��������� �������� ������ �������
{
	TVector<int> v_first(5);
	TVector<int> v_second(5);

	for (int i = 0; i < v_first.GetSize(); i++)
	{
		v_first[i] = i * 10;
		v_second[i] = i - 10;

	}

	ASSERT_NO_THROW(v_first / v_second);
}

TEST(TVector, cant_division_vectors_with_not_equal_size) // ���������� ��������� �������� ������� �������
{
	TVector<int> v_first(5);
	TVector<int> v_second(6);

	for (int i = 0; i < v_first.GetSize(); i++)
	{
		v_first[i] = i * 13;
		v_second[i] = i - 13;
	}

	ASSERT_ANY_THROW(v_first / v_second);
}