#include "vector.h"

namespace linalg
{

class Double3d : public Vector<double>
{
public:
  Double3d()
      : Vector<double>(3)
  {
  }

  Double3d(const Vector<double>& v)
      : Vector<double>(v)
  {
  }

  Double3d(double x, double y, double z)
      : Vector<double>(x, y, z)
  {
  }

  Double3d(double x, double y, double z, Format format)
      : Vector<double>(x, y, z, format)
  {
  }

  Double3d(std::initializer_list<double> data)
      : Vector<double>(data)
  {
  }

  Double3d(std::initializer_list<double> data, Format format)
      : Vector<double>(data, format)
  {
  }
};

} // namespace linalg