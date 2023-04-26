#pragma once

#include "vector.h"

namespace linalg
{

template<class T>
class Matrix
{
public:
  Matrix(uint32_t rows, uint32_t columns);
  Matrix(const std::vector<Vector<T>>& columns);
  Matrix(std::initializer_list<std::initializer_list<T>> rows);

  virtual ~Matrix();

  std::string ToString() const;

  uint32_t Rows() const;
  uint32_t Columns() const;

  Vector<T> Row(const uint32_t index) const;
  Vector<T> Column(const uint32_t index) const;

  typename std::vector<Vector<T>>::iterator begin();
  typename std::vector<Vector<T>>::const_iterator begin() const;
  typename std::vector<Vector<T>>::iterator end();
  typename std::vector<Vector<T>>::const_iterator end() const;

  T At(const uint32_t row, const uint32_t column) const;

  bool operator==(const Matrix<T>& v) const;
  bool operator!=(const Matrix<T>& v) const;
  Matrix<T> operator+(const Matrix<T>& v) const;
  Matrix<T> operator-(const Matrix<T>& v) const;
  Matrix<T> operator*(const Matrix<T>& v) const;

  Matrix<T> operator+(const T& v) const;
  Matrix<T> operator-(const T& v) const;
  Matrix<T> operator*(const T& v) const;
  Matrix<T> operator/(const T& v) const;

  Vector<T>& operator[](const uint32_t index);
  Matrix<T>& operator++();
  Matrix<T> operator++(int);
  Matrix<T>& operator--();
  Matrix<T> operator--(int);

  Matrix<T> operator-();

  Matrix<T>& operator+=(const Matrix<T>& v);
  Matrix<T>& operator+=(const T& v);
  Matrix<T>& operator-=(const Matrix<T>& v);
  Matrix<T>& operator-=(const T& v);
  Matrix<T>& operator*=(const T& v);
  Matrix<T>& operator/=(const T& v);

  friend std::ostream& operator<<(std::ostream& os, const Matrix<T>& m) { return os << m.ToString(); }

  Matrix<T> RotateX(double angle) const;
  Matrix<T> RotateX(double angle, AngleFormat format) const;
  Matrix<T> RotateY(double angle) const;
  Matrix<T> RotateY(double angle, AngleFormat format) const;
  Matrix<T> RotateZ(double angle) const;
  Matrix<T> RotateZ(double angle, AngleFormat format) const;

  double Determinant() const;
  Matrix<T> Transpose() const;

private:
  uint32_t mRows;
  uint32_t mColumns;

  std::vector<Vector<T>> mData;

  double Determinant2x2(const Matrix<T>& matrix) const;
};

template<class T>
static Matrix<T> Identity(const size_t size)
{
  Matrix<T> m(size, size);
  for (uint32_t i = 0; i < size; ++i)
    m[i][i] = 1;

  return m;
}

} // namespace linalg