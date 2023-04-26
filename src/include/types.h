#include "vector.h"

namespace linalg
{

class Int2d : public Vector<int>
{
public:
  Int2d() : Vector<int>(2) {}
  Int2d(const Vector<int>& v) : Vector<int>(v) {}
  Int2d(int x, int y) : Vector<int>(x, y) {}
  Int2d(int x, int y, Format format) : Vector<int>(x, y, format) {}
  Int2d(std::initializer_list<int> data) : Vector<int>(data) {}
  Int2d(std::initializer_list<int> data, Format format) : Vector<int>(data, format) {}
};

class Int3d : public Vector<int>
{
public:
  Int3d() : Vector<int>(3) {}
  Int3d(const Vector<int>& v) : Vector<int>(v) {}
  Int3d(int x, int y) : Vector<int>(x, y) {}
  Int3d(int x, int y, Format format) : Vector<int>(x, y, format) {}
  Int3d(std::initializer_list<int> data) : Vector<int>(data) {}
  Int3d(std::initializer_list<int> data, Format format) : Vector<int>(data, format) {}
};

class Float2d : public Vector<float>
{
public:
  Float2d() : Vector<float>(2) {}
  Float2d(const Vector<float>& v) : Vector<float>(v) {}
  Float2d(float x, float y) : Vector<float>(x, y) {}
  Float2d(float x, float y, Format format) : Vector<float>(x, y, format) {}
  Float2d(std::initializer_list<float> data) : Vector<float>(data) {}
  Float2d(std::initializer_list<float> data, Format format) : Vector<float>(data, format) {}
};

class Float3d : public Vector<float>
{
public:
  Float3d() : Vector<float>(3) {}
  Float3d(const Vector<float>& v) : Vector<float>(v) {}
  Float3d(float x, float y) : Vector<float>(x, y) {}
  Float3d(float x, float y, Format format) : Vector<float>(x, y, format) {}
  Float3d(std::initializer_list<float> data) : Vector<float>(data) {}
  Float3d(std::initializer_list<float> data, Format format) : Vector<float>(data, format) {}
};

class Double2d : public Vector<double>
{
public:
  Double2d() : Vector<double>(2) {}
  Double2d(const Vector<double>& v) : Vector<double>(v) {}
  Double2d(double x, double y) : Vector<double>(x, y) {}
  Double2d(double x, double y, Format format) : Vector<double>(x, y, format) {}
  Double2d(std::initializer_list<double> data) : Vector<double>(data) {}
  Double2d(std::initializer_list<double> data, Format format) : Vector<double>(data, format) {}
};

class Double3d : public Vector<double>
{
public:
  Double3d() : Vector<double>(3) {}
  Double3d(const Vector<double>& v) : Vector<double>(v) {}
  Double3d(double x, double y) : Vector<double>(x, y) {}
  Double3d(double x, double y, Format format) : Vector<double>(x, y, format) {}
  Double3d(std::initializer_list<double> data) : Vector<double>(data) {}
  Double3d(std::initializer_list<double> data, Format format) : Vector<double>(data, format) {}
};

} // namespace linalg