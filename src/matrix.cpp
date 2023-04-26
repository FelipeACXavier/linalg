#include "matrix.h"

#include <cfloat>

namespace linalg
{

template <class T>
Matrix<T>::Matrix(uint32_t rows, uint32_t columns)
  : mRows(rows)
  , mColumns(columns)
{
  for (uint32_t r = 0; r < Columns(); ++r)
  {
    Vector<T> row(Rows());
    for (uint32_t i = 0; i < Rows(); ++i)
      row[i] = 0;

    mData.push_back(row);
  }
}

template <class T>
Matrix<T>::Matrix(const std::vector<Vector<T>>& columns)
{
  mRows = columns.size();
  mColumns = columns.at(0).Size();

  for (const auto& c : columns)
    mData.push_back(c);
}

template <class T>
Matrix<T>::Matrix(std::initializer_list<std::initializer_list<T>> columns)
{
  mRows = columns.begin()->size();
  mColumns = columns.size();

  for (auto c = columns.begin(); c < columns.end(); ++c)
    mData.push_back(Vector<T>(*c));
}

template <class T>
Matrix<T>::~Matrix()
{
}

template <class T>
uint32_t Matrix<T>::Rows() const
{
  return mRows;
}

template <class T>
uint32_t Matrix<T>::Columns() const
{
  return mColumns;
}

template <class T>
std::string Matrix<T>::ToString() const
{
  std::string output;
  Matrix<T> mat = Transpose();
  for (const auto& c : mData)
    output += c.ToString() + "\n";

  return output;
}

template <class T>
Vector<T> Matrix<T>::Row(const uint32_t index) const
{
  Vector<T> vec(Columns());
  for (uint32_t i = 0; i < Columns(); ++i)
    vec[i] = mData[i].At(index);

  return vec;
}

template <class T>
Vector<T> Matrix<T>::Column(const uint32_t index) const
{
  return Vector<T>(mData.at(index));
}

template <class T>
typename std::vector<Vector<T>>::iterator Matrix<T>::begin()
{
  return mData.begin();
}

template <class T>
typename std::vector<Vector<T>>::const_iterator Matrix<T>::begin() const
{
  return mData.begin();
}

template <class T>
typename std::vector<Vector<T>>::iterator Matrix<T>::end()
{
  return mData.end();
}

template <class T>
typename std::vector<Vector<T>>::const_iterator Matrix<T>::end() const
{
  return mData.end();
}

template <class T>
T Matrix<T>::At(const uint32_t row, const uint32_t column) const
{
  return Column(column).At(row);
}

template <class T>
Vector<T>& Matrix<T>::operator[](const uint32_t index)
{
  return mData[index];
}

template <class T>
bool Matrix<T>::operator==(const Matrix<T>& v) const
{
    for (uint32_t c = 0; c < Columns(); ++c)
      if (Column(c) != v.Column(c))
        return false;

  return true;
}

template <class T>
bool Matrix<T>::operator!=(const Matrix<T>& v) const
{
  return !(*this == v);
}

template <class T>
Matrix<T> Matrix<T>::operator+(const Matrix<T>& v) const
{
  Matrix<T> output(Rows(), Columns());

  for (uint32_t c = 0; c < Columns(); ++c)
    output[c] = Column(c) + v.Column(c);

  return output;
}

template <class T>
Matrix<T> Matrix<T>::operator-(const Matrix<T>& v) const
{
  Matrix<T> output(Rows(), Columns());

  for (uint32_t c = 0; c < Columns(); ++c)
    output[c] = Column(c) - v.Column(c);

  return output;
}

template <class T>
Matrix<T> Matrix<T>::operator+(const T& v) const
{
  Matrix<T> output(Rows(), Columns());

  for (uint32_t c = 0; c < Columns(); ++c)
    output[c] = Column(c) + v;

  return output;
}

template <class T>
Matrix<T> Matrix<T>::operator-(const T& v) const
{
  Matrix<T> output(Rows(), Columns());

  for (uint32_t c = 0; c < Columns(); ++c)
    output[c] = Column(c) - v;

  return output;
}

template <class T>
Matrix<T> Matrix<T>::operator*(const Matrix<T>& v) const
{
  Matrix<T> output(Rows(), v.Columns());

  for(uint32_t i = 0; i < Rows(); ++i)
    for(uint32_t j = 0; j < v.Columns(); ++j)
      for(uint32_t k = 0; k < Columns(); ++k)
          output[i][j] += this->At(i, k) * v.At(k, j);

  return output;
}

template <class T>
Matrix<T> Matrix<T>::operator*(const T& v) const
{
  Matrix<T> output(Rows(), Columns());

  for (uint32_t c = 0; c < Columns(); ++c)
    output[c] = Column(c) * v;

  return output;
}

template <class T>
Matrix<T> Matrix<T>::operator/(const T& v) const
{
  Matrix<T> output(Rows(), Columns());

  for (uint32_t c = 0; c < Columns(); ++c)
      output[c] = Column(c) / v;

  return output;
}

template <class T>
Matrix<T>& Matrix<T>::operator++()
{
  for (uint32_t c = 0; c < Columns(); ++c)
    ++Column(c);

  return *this;
}

template <class T>
Matrix<T> Matrix<T>::operator++(int)
{
  Matrix<T> output(Rows(), Columns());

  for (uint32_t c = 0; c < Columns(); ++c)
    mData[c]++;

  return output;
}

template <class T>
Matrix<T>& Matrix<T>::operator--()
{
  for (uint32_t c = 0; c < Columns(); ++c)
    --Column(c);

  return *this;
}

template <class T>
Matrix<T> Matrix<T>::operator--(int)
{
  Matrix<T> output(Rows(), Columns());

  for (uint32_t c = 0; c < Columns(); ++c)
    mData[c]--;

  return output;
}

template <class T>
Matrix<T> Matrix<T>::operator-()
{
  Matrix<T> output(Rows(), Columns());

  for (uint32_t c = 0; c < Columns(); ++c)
      output[c] = -Column(c);

  return output;
}

template <class T>
Matrix<T>& Matrix<T>::operator+=(const Matrix<T>& v)
{
  for (uint32_t c = 0; c < Columns(); ++c)
    (*this)[c] += v.Column(c);

  return *this;
}

template <class T>
Matrix<T>& Matrix<T>::operator+=(const T& v)
{
  for (uint32_t c = 0; c < Columns(); ++c)
    (*this)[c] += v;

  return *this;
}

template <class T>
Matrix<T>& Matrix<T>::operator-=(const Matrix<T>& v)
{
  for (uint32_t c = 0; c < Columns(); ++c)
    (*this)[c] -= v.Column(c);

  return *this;
}

template <class T>
Matrix<T>& Matrix<T>::operator-=(const T& v)
{
  for (uint32_t c = 0; c < Columns(); ++c)
    (*this)[c] -= v;

  return *this;
}

template <class T>
Matrix<T>& Matrix<T>::operator*=(const T& v)
{
  for (uint32_t c = 0; c < Columns(); ++c)
    (*this)[c] *= v;

  return *this;
}

template <class T>
Matrix<T>& Matrix<T>::operator/=(const T& v)
{
  for (uint32_t c = 0; c < Columns(); ++c)
    (*this)[c] /= v;

  return *this;
}

template <class T>
Matrix<T> Matrix<T>::Transpose() const
{
  Matrix<T> mat(Columns(), Rows());

  for(uint32_t r = 0; r < Rows(); ++r)
    for (uint32_t c = 0; c < Columns(); ++c)
      mat[r][c] = At(r, c);

  return mat;
}

template <class T>
double Matrix<T>::Determinant2x2(const Matrix<T>& v) const
{
  return (v.At(0, 0) * v.At(1, 1)) - (v.At(0, 1) * v.At(1, 0));
}

template <class T>
double Matrix<T>::Determinant() const
{
  if (Rows() != Columns())
    return DBL_MAX;

  if (Rows() == 2)
    return Determinant2x2(*this);

  return At(0, 0) * Determinant2x2({{At(1, 1), At(1, 2)},
                                    {At(2, 1), At(2, 2)}}) -
         At(0, 1) * Determinant2x2({{At(1, 0), At(1, 2)},
                                    {At(2, 0), At(2, 2)}}) +
         At(0, 2) * Determinant2x2({{At(1, 0), At(1, 1)},
                                    {At(2, 0), At(2, 1)}});
}

template <class T>
Matrix<T> Matrix<T>::RotateX(double angle) const
{
  Matrix<T> rotateX({{1,               0,                0},
                     {0, (T)std::cos(angle), -(T)std::sin(angle)},
                     {0, (T)std::sin(angle),  (T)std::cos(angle)}});

  return *this * rotateX;
}

template <class T>
Matrix<T> Matrix<T>::RotateX(double angle, AngleFormat format) const
{
  if (format == AngleFormat::Degrees)
    angle = ToRadians(angle);

  return RotateX(angle);
}

template <class T>
Matrix<T> Matrix<T>::RotateY(double angle) const
{
  Matrix<T> rotateY({{(T)std::cos(angle),  1, (T)std::sin(angle)},
                     {0,                1,               0},
                     {-(T)std::sin(angle), 0, (T)std::cos(angle)}});

  return *this * rotateY;
}

template <class T>
Matrix<T> Matrix<T>::RotateY(double angle, AngleFormat format) const
{
  if (format == AngleFormat::Degrees)
    angle = ToRadians(angle);

  return RotateY(angle);
}

template <class T>
Matrix<T> Matrix<T>::RotateZ(double angle) const
{
  Matrix<T> rotateZ({{(T)std::cos(angle), -(T)std::sin(angle), 1},
                     {(T)std::sin(angle),  (T)std::cos(angle), 0},
                     {              0,                0, 0}});

  return *this * rotateZ;
}

template <class T>
Matrix<T> Matrix<T>::RotateZ(double angle, AngleFormat format) const
{
  if (format == AngleFormat::Degrees)
    angle = ToRadians(angle);

  return RotateZ(angle);
}

template class Matrix<int>;
template class Vector<float>;
template class Matrix<double>;

} // namespace linalg
