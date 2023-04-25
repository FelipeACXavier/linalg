#pragma once

#include <stdint.h>

#include <cmath>
#include <functional>
#include <initializer_list>
#include <string>
#include <vector>

namespace linalg
{
static double ToRadians(const double angle)
{
  return angle * M_PI / 180.0;
}

static double ToDegrees(const double angle)
{
  return angle * 180.0 / M_PI;
}

enum class Format
{
  Polar = 0,
  Rectangular
};

enum class AngleFormat
{
  Radians = 0,
  Degrees
};

template<class T>
class Vector
{
public:
  Vector(uint8_t size);
  Vector(T x, T y);
  Vector(T x, T y, T z);
  Vector(T x, T y, Format format);
  Vector(T x, T y, T z, Format format);
  Vector(std::vector<T> data);
  Vector(std::initializer_list<T> data);
  Vector(std::initializer_list<T> data, Format format);

  virtual ~Vector();

  T X() const;
  T Y() const;
  T Z() const;

  uint32_t Size() const;

  std::string ToString() const;

  bool operator==(const Vector<T>& v) const;
  bool operator!=(const Vector<T>& v) const;
  Vector<T> operator+(const Vector<T>& v) const;
  Vector<T> operator-(const Vector<T>& v) const;
  Vector<T> operator+(const T& v) const;
  Vector<T> operator-(const T& v) const;
  Vector<T> operator*(const T& v) const;
  Vector<T> operator/(const T& v) const;

  Vector<T>& operator++();
  Vector<T> operator++(int);
  Vector<T>& operator--();
  Vector<T> operator--(int);

  Vector<T> operator-();

  Vector<T>& operator+=(const Vector<T>& v);
  Vector<T>& operator+=(const T& v);
  Vector<T>& operator-=(const Vector<T>& v);
  Vector<T>& operator-=(const T& v);
  Vector<T>& operator*=(const T& v);
  Vector<T>& operator/=(const T& v);

  T& operator[](const size_t index);
  T At(const size_t index) const;

  double Mag() const;
  double Angle() const;
  double Angle(const Vector<T>& v) const;

  double Distance(const Vector<T>& v) const;

  double Dot(const Vector<T>& v) const;
  Vector<T> Cross(const Vector<T>& v) const;
  Vector<T> Projection(const Vector<T>& v) const;

  Vector<T> RotateX(double angle) const;
  Vector<T> RotateX(double angle, AngleFormat format) const;
  Vector<T> RotateY(double angle) const;
  Vector<T> RotateY(double angle, AngleFormat format) const;
  Vector<T> RotateZ(double angle) const;
  Vector<T> RotateZ(double angle, AngleFormat format) const;

  T Max() const;
  T Min() const;

  T Sum() const;
  T Product() const;

  Vector<T> Lerp(const Vector<T>& v, T amount) const;

  void Apply(std::function<void(T& v)> function);

private:
  std::vector<T> mData;

  uint32_t mSize;
  Format mFormat;

  std::string ToStringPolar() const;
  std::string ToStringRectangular() const;

  void Init2D(T x, T y);
  void Init3D(T x, T y, T z);
};

} // namespace linalg