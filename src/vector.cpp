#include "vector.h"

#include <cfloat>

namespace linalg
{
template <class T>
Vector<T>::Vector(uint8_t size)
    : mSize(size)
    , mFormat(Format::Rectangular)
{
  if (Size() == 2)
    Init2D(0, 0);
  else
    Init3D(0, 0, 0);
}

template <class T>
Vector<T>::Vector(T x, T y)
    : Vector(x, y, Format::Rectangular)
{
}

template <class T>
Vector<T>::Vector(T x, T y, T z)
    : Vector(x, y, z, Format::Rectangular)
{
}

template <class T>
Vector<T>::Vector(T x, T y, Format format)
    : mSize(2)
    , mFormat(format)
{
  Init2D(x, y);
}

template <class T>
Vector<T>::Vector(T x, T y, T z, Format format)
  : mSize(3)
  , mFormat(format)
{
  Init3D(x, y, z);
}

template <class T>
Vector<T>::Vector(std::vector<T> data)
    : mFormat(Format::Rectangular)
    , mSize(data.size())
{
  if (Size() == 2)
    Init2D(*data.begin(), *(data.begin() + 1));
  else if (Size() == 3)
    Init3D(*data.begin(), *(data.begin() + 1), *(data.begin() + 2));
}

template <class T>
Vector<T>::Vector(std::initializer_list<T> data)
    : Vector(data, Format::Rectangular)
{
}

template <class T>
Vector<T>::Vector(std::initializer_list<T> data, Format format)
    : mFormat(format)
    , mSize(data.size())
{
  if (Size() == 2)
    Init2D(*data.begin(), *(data.begin() + 1));
  else if (Size() == 3)
    Init3D(*data.begin(), *(data.begin() + 1), *(data.begin() + 2));
}

template <class T>
Vector<T>::~Vector()
{
}

template <class T>
void Vector<T>::Init2D(T x, T y)
{
  mData = std::vector<T>(4, 0);
  if (mFormat == Format::Rectangular)
  {
    mData[0] = x;
    mData[1] = y;
  }
  else
  {
    mData[0] = x * std::cos(y);
    mData[1] = x * std::sin(y);
  }
}

template <class T>
void Vector<T>::Init3D(T x, T y, T z)
{
  mData = std::vector<T>(4, 0);
  if (mFormat == Format::Rectangular)
  {
    mData[0] = x;
    mData[1] = y;
    mData[2] = z;
  }
  else
  {
    mData[0] = x * std::sin(y) * std::cos(z);
    mData[1] = x * std::sin(y) * std::sin(z);
    mData[2] = x * std::cos(y);
  }
}

template <class T>
typename std::vector<T>::iterator Vector<T>::begin()
{
  return mData.begin();
}

template <class T>
typename std::vector<T>::const_iterator Vector<T>::begin() const
{
  return mData.begin();
}

template <class T>
typename std::vector<T>::iterator Vector<T>::end()
{
  return mData.end();
}

template <class T>
typename std::vector<T>::const_iterator Vector<T>::end() const
{
  return mData.end();
}

template <class T>
bool Vector<T>::operator==(const Vector<T>& v) const
{
  return X() == v.X() &&
         Y() == v.Y() &&
         (Size() == 2 || Z() == v.Z());
}

template <class T>
bool Vector<T>::operator!=(const Vector<T>& v) const
{
  return !(*this == v);
}

template <class T>
Vector<T> Vector<T>::operator+(const Vector<T>& v) const
{
  if (Size() == 2)
    return Vector<T>(X() + v.X(), Y() + v.Y());

  return Vector<T>(X() + v.X(), Y() + v.Y(), Z() + v.Z());
}

template <class T>
Vector<T> Vector<T>::operator+(const T& v) const
{
  if (Size() == 2)
    return Vector<T>(X() + v, Y() + v);

  return Vector<T>(X() + v, Y() + v, Z() + v);
}

template <class T>
Vector<T> Vector<T>::operator-(const Vector<T>& v) const
{
  if (Size() == 2)
    return Vector<T>(X() - v.X(), Y() - v.Y());

  return Vector<T>(X() - v.X(), Y() - v.Y(), Z() - v.Z());
}

template <class T>
Vector<T> Vector<T>::operator-(const T& v) const
{
  if (Size() == 2)
    return Vector<T>(X() - v, Y() - v);

  return Vector<T>(X() - v, Y() - v, Z() - v);
}

template <class T>
Vector<T> Vector<T>::operator*(const T& v) const
{
  if (Size() == 2)
    return Vector<T>(X() * v, Y() * v);

  return Vector<T>(X() * v, Y() * v, Z() * v);
}

template <class T>
Vector<T> Vector<T>::operator/(const T& v) const
{
  if (Size() == 2)
    return Vector<T>(X() / v, Y() / v);

  return Vector<T>(X() / v, Y() / v, Z() / v);
}

template <class T>
T& Vector<T>::operator[](const size_t index)
{
  return mData[index];
}

template <class T>
Vector<T>& Vector<T>::operator++()
{
  for (uint32_t i = 0; i < Size(); ++i)
    ++mData[i];

  return *this;
}

template <class T>
Vector<T> Vector<T>::operator++(int)
{
  if (Size() == 2)
    return Vector<T>(mData[0]++, mData[1]++);

  return Vector<T>(mData[0]++, mData[1]++, mData[2]++);
}

template <class T>
Vector<T>& Vector<T>::operator--()
{
  for (uint32_t i = 0; i < Size(); ++i)
    --mData[i];

  return *this;
}

template <class T>
Vector<T> Vector<T>::operator--(int)
{
  if (Size() == 2)
    return Vector<T>(mData[0]--, mData[1]--);

  return Vector<T>(mData[0]--, mData[1]--, mData[2]--);
}

template <class T>
Vector<T> Vector<T>::operator-()
{
  if (Size() == 2)
    return Vector<T>(-mData[0], -mData[1]);

  return Vector<T>(-mData[0], -mData[1], -mData[2]);
}

template <class T>
Vector<T>& Vector<T>::operator+=(const Vector<T>& v)
{
  for (uint32_t i = 0; i < Size(); ++i)
    mData[i] += v.At(i);

  return *this;
}

template <class T>
Vector<T>& Vector<T>::operator+=(const T& v)
{
  for (uint32_t i = 0; i < Size(); ++i)
    mData[i] += v;

  return *this;
}

template <class T>
Vector<T>& Vector<T>::operator-=(const Vector<T>& v)
{
  for (uint32_t i = 0; i < Size(); ++i)
    mData[i] -= v.At(i);

  return *this;
}

template <class T>
Vector<T>& Vector<T>::operator-=(const T& v)
{
  for (uint32_t i = 0; i < Size(); ++i)
    mData[i] -= v;

  return *this;
}

template <class T>
Vector<T>& Vector<T>::operator*=(const T& v)
{
  for (uint32_t i = 0; i < Size(); ++i)
    mData[i] *= v;

  return *this;
}

template <class T>
Vector<T>& Vector<T>::operator/=(const T& v)
{
  for (uint32_t i = 0; i < Size(); ++i)
    mData[i] /= v;

  return *this;
}

template <class T>
T Vector<T>::X() const
{
  return mData.at(0);
}

template <class T>
T Vector<T>::Y() const
{
  return mData.at(1);
}

template <class T>
T Vector<T>::Z() const
{
  return mData.at(2);
}

template <class T>
uint32_t Vector<T>::Size() const
{
  return mSize;
}

template <class T>
std::string Vector<T>::ToString() const
{
  return mFormat == Format::Polar ? ToStringPolar() : ToStringRectangular();
}

template <class T>
std::string Vector<T>::ToStringPolar() const
{
  if (Size() == 2)
    return "[" + std::to_string(Mag()) + " - " + std::to_string(Angle()) + "]";

  return "No polar coordinates with 3D vector";
}

template <class T>
std::string Vector<T>::ToStringRectangular() const
{
  std::string output = "|";

  for (uint32_t i = 0; i < Size(); ++i)
    output += std::to_string(mData.at(i)) + ", ";

  return output.substr(0, output.size() - 2) + "|";
}

template <class T>
T Vector<T>::At(const size_t index) const
{
  return mData.at(index);
}

template <class T>
double Vector<T>::Mag() const
{
  return std::sqrt(std::pow(X(), 2) + std::pow(Y(), 2) + std::pow(Z(), 2));
}

template <class T>
double Vector<T>::Angle() const
{
  if (!Size() == 2)
    return DBL_MAX;

  return std::atan(Y() / X());
}

template <class T>
double Vector<T>::Angle(const Vector<T>& v) const
{
  return std::acos(Dot(v) / (Mag() * v.Mag()));
}

template <class T>
double Vector<T>::Distance(const Vector<T>& v) const
{
  return std::sqrt(std::pow(X() - v.X(), 2) + std::pow(Y() - v.Y(), 2) + std::pow(Z() - v.Z(), 2));
}

template <class T>
Vector<T> Vector<T>::Projection(const Vector<T>& v) const
{
  double multiplier = Dot(v) / (v.Mag() * v.Mag());
  return v * multiplier;
}

template <class T>
double Vector<T>::Dot(const Vector<T>& v) const
{
  if (Size() == 2)
    return (X() * v.X()) + (Y() * v.Y());

  return (X() * v.X()) + (Y() * v.Y()) + (Z() * v.Z());
}

template <class T>
Vector<T> Vector<T>::Cross(const Vector<T>& v) const
{
  T x = Y() * v.Z() - Z() * v.Y();
  T y = Z() * v.X() - X() * v.Z();
  T z = X() * v.Y() - Y() * v.X();

  if (Size() == 2)
    return Vector<T>(x, y);

  return Vector<T>(x, y, z);
}

template <class T>
Vector<T> Vector<T>::RotateX(double angle) const
{
  double y = Y() * std::cos(angle) - Z() * std::sin(angle);
  if (Size() == 2)
    return Vector<T>(X(), y);

  double z = Y() * std::sin(angle) + Z() * std::cos(angle);
  return Vector<T>(X(), y, z);
}

template <class T>
Vector<T> Vector<T>::RotateX(double angle, AngleFormat format) const
{
  if (format == AngleFormat::Degrees)
    angle = ToRadians(angle);

  return RotateX(angle);
}

template <class T>
Vector<T> Vector<T>::RotateY(double angle) const
{
  double x = X() * std::cos(angle) + Z() * std::sin(angle);
  if (Size() == 2)
    return Vector<T>(x, Y());

  double z = Z() * std::cos(angle) - X() * std::sin(angle);
  return Vector<T>(x, Y(), z);
}

template <class T>
Vector<T> Vector<T>::RotateY(double angle, AngleFormat format) const
{
  if (format == AngleFormat::Degrees)
    angle = ToRadians(angle);

  return RotateY(angle);
}

template <class T>
Vector<T> Vector<T>::RotateZ(double angle) const
{
  double x = X() * std::cos(angle) - Y() * std::sin(angle);
  double y = X() * std::sin(angle) + Y() * std::cos(angle);

  if (Size() == 2)
    return Vector<T>(x, y);

  return Vector<T>(x, y, Z());
}

template <class T>
Vector<T> Vector<T>::RotateZ(double angle, AngleFormat format) const
{
  if (format == AngleFormat::Degrees)
    angle = ToRadians(angle);

  return RotateZ(angle);
}

template <class T>
T Vector<T>::Max() const
{
  T max = mData.at(0);
  for (uint32_t i = 1; i < Size(); ++i)
    if (mData.at(i) > max)
      max = mData.at(i);

  return max;
}

template <class T>
T Vector<T>::Min() const
{
  T min = mData.at(0);
  for (uint32_t i = 1; i < Size(); ++i)
    if (mData.at(i) < min)
      min = mData.at(i);

  return min;
}

template <class T>
T Vector<T>::Sum() const
{
  T sum = 0;
  for (uint32_t i = 0; i < Size(); ++i)
    sum += mData.at(i);

  return sum;
}

template <class T>
T Vector<T>::Product() const
{
  T product = 0;
  for (uint32_t i = 0; i < Size(); ++i)
    product *= mData.at(i);

  return product;
}

template <class T>
Vector<T> Vector<T>::Lerp(const Vector<T>& v, T amount) const
{
  return Vector<T>((v - *this) * amount);
}

template <class T>
void Vector<T>::SetMagnitude(T magnitude)
{
  double mag = Mag();
  if (Size() > 2)
    return;

   mData[0] *= magnitude / mag;
   mData[1] *= magnitude / mag;
}

template <class T>
void Vector<T>::Limit(T limit)
{
  double mag = Mag();
  if (mag < limit || Size() > 2)
    return;

   auto f = std::min(mag, (double)limit) / mag;
   mData[0] *= f;
   mData[1] *= f;
}

template <class T>
void Vector<T>::Apply(std::function<void(T& v)> function)
{
  if (!function)
    return;

  for (uint32_t i = 0; i < Size(); ++i)
    function(mData[i]);
}

template class Vector<int>;
template class Vector<float>;
template class Vector<double>;

} // namespace linalg