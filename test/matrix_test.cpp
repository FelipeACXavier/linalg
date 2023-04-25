#include "linalg.h"
#include <gtest/gtest.h>

TEST(MatrixTests, Addition)
{
  linalg::Matrix<double> mat(2, 3);

  std::cout << mat.ToString() << std::endl;
  std::cout << mat.Row(0).ToString() << std::endl;
  std::cout << mat.Row(1).ToString() << std::endl;
  std::cout << mat.Column(0).ToString() << std::endl;
  std::cout << mat.Column(1).ToString() << std::endl;

  std::vector<linalg::Vector<double>> columns;
  for (int i = 0; i < 3; i++)
    columns.push_back({i, i + 1, i + 2});

  linalg::Matrix<double> mat3(columns);
  std::cout << mat3.ToString() << std::endl;
  std::cout << mat3.Column(2).ToString() << std::endl;

  linalg::Matrix<double> mat4({{1, 2, 3}, {4, 5, 6}, {7, 8, 9}});
  std::cout << mat4.ToString() << std::endl;

  std::cout << linalg::Identity<double>(2).ToString() << std::endl;
  std::cout << (-linalg::Identity<double>(3)).ToString() << std::endl;
  std::cout << (mat4 - linalg::Identity<double>(3)).ToString() << std::endl;

  EXPECT_TRUE(true);
}

int main(int argc, char** argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}