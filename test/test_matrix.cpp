#include "vector.h"
#include "matrix.h"
#include <gtest.h>

TEST(TMatrix, can_create_matrix_with_positive_size) // �������� ������� ��������, �������� �������� ������ ������ ����
{
  ASSERT_NO_THROW(TMatrix<int> mtrx(5));
}

TEST(TMatrix, throws_when_create_matrix_with_negative_size) // ���������� �������� ������� � ������������� ��������� ����� 
{
  ASSERT_ANY_THROW(TMatrix<int> mtrx(-5));
}

TEST(TMatrix, can_create_copied_matrix) // ������ ������������ ����������� �� �������� ������
{
  TMatrix<int> mtrx_first(5);

  ASSERT_NO_THROW(TMatrix<int> mtrx_second(mtrx_first));
}

TEST(TMatrix, copied_matrix_is_equal_to_source_one) // ��������� ��������� ���������� ������������ ����������� 
{
  TMatrix<int> mtrx_first(5);
  TMatrix<int> mtrx_second(mtrx_first);

  EXPECT_EQ(mtrx_first, mtrx_second);
}

TEST(TMatrix, copied_matrix_has_its_own_memory) // �������, ���������� � ���������� ���������� ������������ �����������, ����� ����������� ������� ������
{
  TMatrix<int> mtrx_first(5);
  TMatrix<int> mtrx_second(mtrx_first);

  EXPECT_NE(&mtrx_first, &mtrx_second);
}

TEST(TMatrix, can_get_size) // �������� ������ �������
{
  TMatrix<int> mtrx(5);

  EXPECT_EQ(5, mtrx.GetSize());
}

TEST(TMatrix, can_set_and_get_element) // ��������/������ ������� ������� 
{
  TMatrix<int> mtrx(5);
  
  mtrx[2][2] = 5;

  EXPECT_EQ(5, mtrx[2][2]);
}

TEST(TMatrix, throws_when_set_element_with_negative_index) // ���������� �������� ������ � ������ ������� � ������������� �������� � ������ � �� �������
{
  TMatrix<int> mtrx(5);

  ASSERT_ANY_THROW(mtrx[-1][0] = 1);
}

TEST(TMatrix, throws_when_set_element_with_too_large_index) // ���������� �������� ������ � ������ �������, ��������� �� ������� ������� ����� ������� ��� ������� ���������
{
  TMatrix<int> mtrx(5);

  ASSERT_NO_THROW(mtrx[4][0] = 1);
  ASSERT_ANY_THROW(mtrx[4][4] = 1);
  ASSERT_ANY_THROW(mtrx[5][5] = 1);
}

TEST(TMatrix, can_assign_matrix_to_itself) // �������� ���������� ������� ����� ���� 
{
  TMatrix<int> mtrx(5);

  ASSERT_NO_THROW(mtrx = mtrx);
}

TEST(TMatrix, can_assign_matrices_of_equal_size) // ����� ��������� �������� ������������, ���� ������� ������ �����
{
  TMatrix<int> mtrx_firts(5);
  TMatrix<int> mtrx_second(5);

  ASSERT_NO_THROW(mtrx_firts = mtrx_second);
}

TEST(TMatrix, assign_operator_change_matrix_size) // �������� ������������ �������� ������ �������, ��� ������� ����������� ������������ 
{
  TMatrix<int> mtrx_firts(5);
  TMatrix<int> mtrx_second(10);

  ASSERT_NO_THROW(mtrx_firts = mtrx_second);
}

TEST(TMatrix, can_assign_matrices_of_different_size_and_change_size) // ����� ��������� ������ ������� �������� � �������� ��
{
  TMatrix<int> mtrx_firts(5);
  TMatrix<int> mtrx_second(10);

  EXPECT_NE(mtrx_firts.GetSize(), mtrx_second.GetSize());

  mtrx_second = mtrx_firts;

  EXPECT_EQ(mtrx_firts.GetSize(), mtrx_second.GetSize());
}

TEST(TMatrix, can_assign_elements_and_sizes_of_matrices) // ����� �������� �������� � ������� ������
{
  TMatrix<int> mtrx_first(5);
  TMatrix<int> mtrx_second(10);

  EXPECT_NE(mtrx_first, mtrx_second);

  for (int i = 0; i < mtrx_first.GetSize(); i++)
    for (int j = i; j < mtrx_first.GetSize() - i; j++)
      mtrx_first[i][j] = i + j;

  mtrx_second = mtrx_first;

  EXPECT_EQ(mtrx_second, mtrx_first);
}


TEST(TMatrix, compare_equal_matrices_return_true) // ��������� ���������� ������ ���������� ������
{
  TMatrix<int> mtrx_first(5);
  TMatrix<int> mtrx_second(5);

  for (int i = 0; i < mtrx_first.GetSize(); i++)
    for (int j = i; j < mtrx_first.GetSize() - i; j++)
      mtrx_first[i][j] = i + j;

  for (int i = 0; i < mtrx_second.GetSize(); i++)
    for (int j = i; j < mtrx_second.GetSize() - i; j++)
      mtrx_second[i][j] = i + j;

  EXPECT_EQ(true, mtrx_second == mtrx_first);
}

TEST(TMatrix, compare_matrix_with_itself_return_true) // ��������� ������� � ����� ���������� ������
{
  TMatrix<int> mtrx_first(5);

  for (int i = 0; i < mtrx_first.GetSize(); i++)
    for (int j = i; j < mtrx_first.GetSize() - i; j++)
      mtrx_first[i][j] = i + j;

  EXPECT_EQ(true, mtrx_first == mtrx_first);
}

TEST(TMatrix, matrices_with_different_size_are_not_equal) // ������� � ������� ���������� �� ����� ���� ������� ���� �����  
{
  TMatrix<int> mtrx_first(5);
  TMatrix<int> mtrx_second(5);

  for (int i = 0; i < mtrx_first.GetSize(); i++)
    for (int j = i; j < mtrx_first.GetSize() - i; j++)
      mtrx_first[i][j] = i + j;

  for (int i = 0; i < mtrx_second.GetSize(); i++)
    for (int j = i; j < mtrx_second.GetSize() - i; j++)
      mtrx_second[i][j] = i - j;

  EXPECT_NE(true, mtrx_second == mtrx_first);
}

TEST(TMatrix, can_add_matrices_with_equal_size) // �������� ������ ��������, ���� �� ������� �����
{
  TMatrix<int> mtrx_first(3);
  TMatrix<int> mtrx_second(3);

  mtrx_first[0][0] = 1;
  mtrx_first[0][1] = 2;
  mtrx_first[0][2] = 2;
  mtrx_first[1][0] = 1;
  mtrx_first[1][1] = 2;
  mtrx_first[2][0] = 1;

  mtrx_second[0][0] = 3;
  mtrx_second[0][1] = 2;
  mtrx_second[0][2] = 2;
  mtrx_second[1][0] = 3;
  mtrx_second[1][1] = 2;
  mtrx_second[2][0] = 3;

  ASSERT_NO_THROW(mtrx_first + mtrx_second);
}

TEST(TMatrix, cant_add_matrices_with_not_equal_size) // �������� ������ ����������, ���� �� ������� ������
{
  TMatrix<int> mtrx_first(5);
  TMatrix<int> mtrx_second(10);

  ASSERT_ANY_THROW(mtrx_first + mtrx_second);
}

TEST(TMatrix, can_subtract_matrices_with_equal_size) // ��������� ������ ��������, ���� �� ������� �����
{
  TMatrix<int> mtrx_first(3);
  TMatrix<int> mtrx_second(3);

  mtrx_first[0][0] = 1;
  mtrx_first[0][1] = 2;
  mtrx_first[0][2] = 2;
  mtrx_first[1][0] = 1;
  mtrx_first[1][1] = 2;
  mtrx_first[2][0] = 1;

  mtrx_second[0][0] = 3;
  mtrx_second[0][1] = 2;
  mtrx_second[0][2] = 2;
  mtrx_second[1][0] = 3;
  mtrx_second[1][1] = 2;
  mtrx_second[2][0] = 3;

  ASSERT_NO_THROW(mtrx_first - mtrx_second);
}

TEST(TMatrix, cant_subtract_matrixes_with_not_equal_size) // ��������� ������ ����������, ���� �� ������� ������
{
  TMatrix<int> mtrx_first(5);
  TMatrix<int> mtrx_second(10);

  ASSERT_ANY_THROW(mtrx_first - mtrx_second);
}

TEST(TMatrix, can_multiply_matrixes_with_equal_size)
{
  TMatrix <int> mtrx_first(3), mtrx_second(3), mtrx_third(3);

  mtrx_first[0][0] = 1;
  mtrx_first[0][1] = 2;
  mtrx_first[0][2] = 2;
  mtrx_first[1][0] = 1;
  mtrx_first[1][1] = 2;
  mtrx_first[2][0] = 1;

  mtrx_second[0][0] = 3;
  mtrx_second[0][1] = 2;
  mtrx_second[0][2] = 2;
  mtrx_second[1][0] = 3;
  mtrx_second[1][1] = 2;
  mtrx_second[2][0] = 3;

  mtrx_third[0][0] = 3;
  mtrx_third[0][1] = 8;
  mtrx_third[0][2] = 12;
  mtrx_third[1][0] = 3;
  mtrx_third[1][1] = 8;
  mtrx_third[2][0] = 3;

  EXPECT_EQ(mtrx_third, (mtrx_first * mtrx_second));
}