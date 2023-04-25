#include "double2d.h"
#include <gtest/gtest.h>

#include <iostream>
#include <vector>

TEST(LinAlgTests, Addition)
{
  std::vector<linalg::Vector<double>> vectors;
  for (int i = 0; i < 10; i++)
    vectors.push_back(linalg::Vector<double>(i, i + 1));

  // Verify integer math
  for (auto& v : vectors)
  {
    linalg::Vector<double> prev = v;
    v = v + 2;
    EXPECT_EQ(v.X(), prev.X() + 2);
    EXPECT_EQ(v.Y(), prev.Y() + 2);
  }

  for (auto& v : vectors)
  {
    linalg::Vector<double> prev = v;
    ++v;
    v++;
    EXPECT_EQ(v.X(), prev.X() + 2);
    EXPECT_EQ(v.Y(), prev.Y() + 2);
  }

  // Verify vector math
  for (int i = 1; i < 10; i++)
  {
    auto a = vectors.at(i - 1);
    auto b = vectors.at(i);
    auto sum = a + b;

    EXPECT_EQ(sum.X(), a.X() + b.X());
    EXPECT_EQ(sum.Y(), a.Y() + b.Y());
  }
}

TEST(LinAlgTests, Subtraction)
{
  std::vector<linalg::Vector<double>> vectors;
  for (int i = 0; i < 10; i++)
    vectors.push_back(linalg::Vector<double>(i, i + 1));

  // Verify integer math
  for (auto& v : vectors)
  {
    linalg::Vector<double> prev = v;
    v = v - 2;
    EXPECT_EQ(v.X(), prev.X() - 2);
    EXPECT_EQ(v.Y(), prev.Y() - 2);
  }

  // Verify vector math
  for (int i = 1; i < 10; i++)
  {
    auto a = vectors.at(i - 1);
    auto b = vectors.at(i);
    auto sum = a - b;

    EXPECT_EQ(sum.X(), a.X() - b.X());
    EXPECT_EQ(sum.Y(), a.Y() - b.Y());
  }
}

TEST(LinAlgTests, IncrementDecrement)
{
  std::vector<linalg::Vector<double>> vectors;
  for (int i = 0; i < 10; i++)
    vectors.push_back(linalg::Vector<double>(i, i + 1));

  for (auto& v : vectors)
  {
    linalg::Vector<double> prev = v;
    ++v;
    EXPECT_EQ(v.X(), prev.X() + 1);
    EXPECT_EQ(v.Y(), prev.Y() + 1);
    v++;
    EXPECT_EQ(v.X(), prev.X() + 2);
    EXPECT_EQ(v.Y(), prev.Y() + 2);
  }

  for (auto& v : vectors)
  {
    linalg::Vector<double> prev = v;
    --v;
    EXPECT_EQ(v.X(), prev.X() - 1);
    EXPECT_EQ(v.Y(), prev.Y() - 1);
    v--;
    EXPECT_EQ(v.X(), prev.X() - 2);
    EXPECT_EQ(v.Y(), prev.Y() - 2);
  }
}

TEST(LinAlgTests, OperatorEqual)
{
  std::vector<linalg::Double2d> vectors;
  for (int i = 0; i < 10; i++)
    vectors.push_back(linalg::Double2d(i, i + 1));

  for (auto& v : vectors)
  {
    linalg::Vector<double> prev = v;
    v += 1;
    EXPECT_EQ(v.X(), prev.X() + 1);
    EXPECT_EQ(v.Y(), prev.Y() + 1);
    v += 2;
    EXPECT_EQ(v.X(), prev.X() + 3);
    EXPECT_EQ(v.Y(), prev.Y() + 3);
  }

  for (auto& v : vectors)
  {
    linalg::Vector<double> prev = v;
    v -= 2;
    EXPECT_EQ(v.X(), prev.X() - 2);
    EXPECT_EQ(v.Y(), prev.Y() - 2);
    v -= 1;
    EXPECT_EQ(v.X(), prev.X() - 3);
    EXPECT_EQ(v.Y(), prev.Y() - 3);
  }

  for (auto& v : vectors)
  {
    linalg::Vector<double> prev = v;
    v *= 2;
    EXPECT_EQ(v.X(), prev.X() * 2);
    EXPECT_EQ(v.Y(), prev.Y() * 2);
    v /= 2;
    EXPECT_EQ(v.X(), prev.X());
    EXPECT_EQ(v.Y(), prev.Y());
  }
}

TEST(LinAlgTests, Negate)
{
  std::vector<linalg::Vector<double>> vectors;
  for (int i = 0; i < 10; i++)
    vectors.push_back(linalg::Vector<double>(i, i + 1));

  // Verify integer math
  for (auto& v : vectors)
  {
    linalg::Vector<double> prev = v;
    v = -v;
    EXPECT_EQ(v, prev * -1);
  }
}

int main(int argc, char** argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}