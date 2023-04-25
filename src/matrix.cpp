#include "matrix.h"

namespace linalg
{

template <class T>
Matrix<T>::Matrix(uint32_t rows, uint32_t columns)
  : mRows(rows)
  , mColumns(columns)
{
  for (uint32_t r = 0; r < mRows; ++r)
  {
    std::vector<T> row;
    for (uint32_t c = 0; c < mColumns; ++c)
      row.push_back(0);

    mData.push_back(row);
  }
}

template <class T>
Matrix<T>::Matrix(const std::vector<Vector<T>>& columns)
{
  mRows = columns.size();
  mColumns = columns.at(0).Size();

  for (uint32_t r = 0; r < mRows; ++r)
  {
    std::vector<T> row;
    for (uint32_t c = 0; c < mColumns; ++c)
      row.push_back(columns.at(r).At(c));

    mData.push_back(row);
  }
}

template <class T>
Matrix<T>::Matrix(std::initializer_list<std::initializer_list<T>> columns)
{
  mRows = columns.size();
  mColumns = columns.begin()->size();

  for (auto r = columns.begin(); r < columns.end(); ++r)
  {
    std::vector<T> row;
    for (auto c = r->begin(); c < r->end(); ++c)
      row.push_back(*c);

    mData.push_back(row);
  }
}

template <class T>
Matrix<T>::~Matrix()
{
}

template <class T>
std::string Matrix<T>::ToString() const
{
  std::string output;
  for (uint32_t r = 0; r < mRows; ++r)
  {
    output += "|";
    for (uint32_t c = 0; c < mColumns; ++c)
      output += std::to_string(mData[r][c]) + " ";

    output = output.substr(0, output.size() - 2) + "|\n";
  }

  return output;
}

template <class T>
Vector<T> Matrix<T>::Row(const uint32_t index) const
{
  return Vector<T>(mData.at(index));
}

template <class T>
Vector<T> Matrix<T>::Column(const uint32_t index) const
{
  Vector<T> vec(mRows);
  for (uint32_t i = 0; i < mRows; ++i)
    vec[i] = mData[i][index];

  return vec;
}

template <class T>
T& Matrix<T>::At(const uint32_t row, const uint32_t column)
{
  return mData[row][column];
}

template <class T>
std::vector<T> Matrix<T>::operator[](const uint32_t index) const
{
  return mData[index];
}

template <class T>
bool Matrix<T>::operator==(const Matrix<T>& v) const
{
  for (uint32_t r = 0; r < mRows; ++r)
    for (uint32_t c = 0; c < mColumns; ++c)
      if ((*this)[r][c] != v[r][c])
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
  Matrix<T> output(mRows, mColumns);

  for (uint32_t r = 0; r < mRows; ++r)
    for (uint32_t c = 0; c < mColumns; ++c)
      output.At(r, c) = (*this)[r][c] + v[r][c];

  return output;
}

template <class T>
Matrix<T> Matrix<T>::operator-(const Matrix<T>& v) const
{
  Matrix<T> output(mRows, mColumns);

  for (uint32_t r = 0; r < mRows; ++r)
    for (uint32_t c = 0; c < mColumns; ++c)
      output.At(r, c) = (*this)[r][c] - v[r][c];

  return output;
}

template <class T>
Matrix<T> Matrix<T>::operator+(const T& v) const
{
  Matrix<T> output(mRows, mColumns);

  for (uint32_t r = 0; r < mRows; ++r)
    for (uint32_t c = 0; c < mColumns; ++c)
      output.At(r, c) = (*this)[r][c] + v;

  return output;
}

template <class T>
Matrix<T> Matrix<T>::operator-(const T& v) const
{
  Matrix<T> output(mRows, mColumns);

  for (uint32_t r = 0; r < mRows; ++r)
    for (uint32_t c = 0; c < mColumns; ++c)
      output.At(r, c) = (*this)[r][c] - v;

  return output;
}

template <class T>
Matrix<T> Matrix<T>::operator*(const T& v) const
{
  Matrix<T> output(mRows, mColumns);

  for (uint32_t r = 0; r < mRows; ++r)
    for (uint32_t c = 0; c < mColumns; ++c)
      output.At(r, c) = (*this)[r][c] * v;

  return output;
}

template <class T>
Matrix<T> Matrix<T>::operator/(const T& v) const
{
  Matrix<T> output(mRows, mColumns);

  for (uint32_t r = 0; r < mRows; ++r)
    for (uint32_t c = 0; c < mColumns; ++c)
      output.At(r, c) = (*this)[r][c] / v;

  return output;
}

template <class T>
Matrix<T>& Matrix<T>::operator++()
{
  for (uint32_t r = 0; r < mRows; ++r)
    for (uint32_t c = 0; c < mColumns; ++c)
      ++At(r, c);

  return *this;
}

template <class T>
Matrix<T> Matrix<T>::operator++(int)
{
  Matrix<T> output(mRows, mColumns);

  for (uint32_t r = 0; r < mRows; ++r)
    for (uint32_t c = 0; c < mColumns; ++c)
      output.At(r, c)++;

  return output;
}

template <class T>
Matrix<T>& Matrix<T>::operator--()
{
  for (uint32_t r = 0; r < mRows; ++r)
    for (uint32_t c = 0; c < mColumns; ++c)
      --At(r, c);

  return *this;
}

template <class T>
Matrix<T> Matrix<T>::operator--(int)
{
  Matrix<T> output(mRows, mColumns);

  for (uint32_t r = 0; r < mRows; ++r)
    for (uint32_t c = 0; c < mColumns; ++c)
      output.At(r, c)--;

  return output;
}

template <class T>
Matrix<T> Matrix<T>::operator-()
{
  Matrix<T> output(mRows, mColumns);

  for (uint32_t r = 0; r < mRows; ++r)
    for (uint32_t c = 0; c < mColumns; ++c)
      output.At(r, c) = -At(r, c);

  return output;
}

template class Matrix<int>;
template class Matrix<double>;

} // namespace linalg
