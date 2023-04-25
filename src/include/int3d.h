#include "vector.h"

namespace linalg
{

class Int3d : public Vector<int>
{
public:
  Int3d()
      : Vector<int>(3)
  {
  }

  Int3d(const Vector<int>& v)
      : Vector<int>(v)
  {
  }

  Int3d(int x, int y, int z)
      : Vector<int>(x, y, z)
  {
  }

  Int3d(int x, int y, int z, Format format)
      : Vector<int>(x, y, z, format)
  {
  }

  Int3d(std::initializer_list<int> data)
      : Vector<int>(data)
  {
  }

  Int3d(std::initializer_list<int> data, Format format)
      : Vector<int>(data, format)
  {
  }
};

} // namespace linalg