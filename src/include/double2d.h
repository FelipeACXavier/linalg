#include "vector.h"

namespace linalg
{

class Double2d : public Vector<double>
{
public:
  Double2d()
      : Vector<double>(2)
  {
  }

  Double2d(const Vector<double>& v)
      : Vector<double>(v)
  {
  }

  Double2d(double x, double y)
      : Vector<double>(x, y)
  {
  }

  Double2d(double x, double y, Format format)
      : Vector<double>(x, y, format)
  {
  }

  Double2d(std::initializer_list<double> data)
      : Vector<double>(data)
  {
  }

  Double2d(std::initializer_list<double> data, Format format)
      : Vector<double>(data, format)
  {
  }
};

} // namespace linalg