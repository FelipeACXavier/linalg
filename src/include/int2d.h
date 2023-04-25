#include "vector.h"

namespace linalg
{

class Int2d : public Vector<int>
{
public:
  Int2d()
      : Vector<int>(2)
  {
  }

  Int2d(const Vector<int>& v)
      : Vector<int>(v)
  {
  }

  Int2d(int x, int y)
      : Vector<int>(x, y)
  {
  }

  Int2d(int x, int y, Format format)
      : Vector<int>(x, y, format)
  {
  }

  Int2d(std::initializer_list<int> data)
      : Vector<int>(data)
  {
  }

  Int2d(std::initializer_list<int> data, Format format)
      : Vector<int>(data, format)
  {
  }
};

} // namespace linalg