#include "linalg.h"
#include <gtest/gtest.h>

// TODO: Add all tests
TEST(MatrixTests, Addition)
{
  linalg::Matrix<double> mat({{1, 2}, {3, 4}, {5, 6}});

  std::cout << "Mat2:" << std::endl;
  std::cout << mat << std::endl;

  std::cout << "Transpose:" << std::endl;
  std::cout << mat.Transpose().ToString() << std::endl;

  std::cout << "Rows and columns:" << std::endl;
  std::cout << mat.Row(0).ToString() << std::endl;
  std::cout << mat.Row(1).ToString() << std::endl;
  std::cout << mat.Column(0).ToString() << std::endl;
  std::cout << mat.Column(1).ToString() << std::endl;

  std::vector<linalg::Vector<double>> columns;
  for (int i = 1; i < 4; i++)
    columns.push_back({(double)(i + 1 + 10 / i), (double)(i + 2 + 10 / i), (double)(i + 3 + 10 / i)});

  linalg::Matrix<double> mat3(columns);
  linalg::Matrix<double> mat4({{1, 2, 3}, {4, 5, 6}, {7, 8, 9}});
  linalg::Matrix<double> mat5({{1, 2, 3}, {4, 5, 6}, {7, 8, 9}});

  std::cout << "Mat3:" << std::endl;
  std::cout << mat3.ToString() << std::endl;
  std::cout << mat3.Column(2).ToString() << std::endl;
  std::cout << std::endl;

  std::cout << "Mat4:" << std::endl;
  std::cout << mat4.ToString() << std::endl;

  std::cout << "Identity:" << std::endl;
  std::cout << linalg::Identity<double>(2).ToString() << std::endl;
  std::cout << (-linalg::Identity<double>(3)).ToString() << std::endl;
  std::cout << (mat4 - linalg::Identity<double>(3)).ToString() << std::endl;

  std::cout << "Mat5:" << std::endl;
  std::cout << mat5.ToString() << std::endl;
  std::cout << mat5.Transpose().ToString() << std::endl;

  std::cout << "Mat4 * Mat5:" << std::endl;
  std::cout << (mat4 * mat5).ToString() << std::endl;
}

int main(int argc, char** argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}