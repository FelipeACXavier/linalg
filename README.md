# LinAlg

Simple vector and matrix library inspired by [p5.js.Vector](https://p5js.org/reference/#/p5.Vector).  
Support is focused on 2d and 3d vectors but most methods are available for bigger vectors.

---
## Vectors
**Option to work with 2D, in Polar or Rectangular coordinates, or 3D vectors:**

```cpp
linalg::Vector<double> vec(1, 3);
linalg::Vector<double> vec(10, M_PI / 3, Format::Polar);

linalg::Vector<int> vec = {1, 4, 2};

linalg::Vector<int> vec = {1, 4, 2};
```

**Convenient aliases:**

```cpp
linalg::Int2d iVec2;
linalg::Int3d iVec3;

linalg::Float2d iVec2;
linalg::Float3d iVec3;

linalg::Double2d dVec2;
linalg::Double3d dVec3;
```

**Simplified vector math:**
```cpp
linalg::Vector<double> vec1(1, 3);
linalg::Vector<double> vec2(1, 4);

std::cout << "vec1 + vec2: " << vec1 + vec2 << std::endl;
std::cout << "vec1 - vec2: " << vec1 - vec2 << std::endl;
std::cout << "vec1 + 2:    " << vec1 + 2 << std::endl;
std::cout << "vec1 - 2:    " << vec1 - 2 << std::endl;

// Output
// vec1 + vec2: | 2.000000, 7.000000|
// vec1 - vec2: | 0.000000, -1.000000|
// vec1 + 2:    | 3.000000, 5.000000|
// vec1 - 2:    | -1.000000, 1.000000|
```

**Basic linear algebra facilities:**
```cpp
linalg::Vector<double> vec1(1, 3);
linalg::Vector<double> vec2(1, 4);

std::cout << "Magnitude:     " << vec1.Mag() << std::endl;
std::cout << "Angle:         " << vec1.Angle() << std::endl;
std::cout << "Angle between: " << vec1.Angle(vec2) << std::endl;

// Output
// Magnitude:     3.16228
// Angle:         1.24905
// Angle between: 0.0767719

std::cout << "Distance:      " << vec1.Distance(vec2) << std::endl;
std::cout << "Dot product:   " << vec1.Dot(vec2) << std::endl;
std::cout << "Cross product: " << vec1.Cross(vec2) << std::endl;

// Output
// Distance:      1
// Dot product:   13
// Cross product: |0.000000, 0.000000|
```

**Handy rotation matrices:**
```cpp
linalg::Vector<double> vec1(1, 3, 4);

std::cout << "RotateX:     " << vec1.RotateX(M_PI / 4) << std::endl;
std::cout << "RotateY:     " << vec1.RotateY(M_PI / 4) << std::endl;
std::cout << "RotateZ:     " << vec1.RotateZ(15, linalg::AngleFormat::Degrees) << std::endl;

// Output
// RotateX:     |1.000000, -0.707107, 4.949747|
// RotateY:     |3.535534, 3.000000, 2.121320|
// RotateZ:     |0.189469, 3.156597, 4.000000|
```

**Support for range based loop and std::function:**
```cpp
linalg::Vector<double> vec(1, 3, 4);

for (auto& element : vec)
  element = std::sqrt(element + 20);

// Apply lambda in all members of the vector
vec.Apply([](double& e){ e = std::sqrt(e + 20); });
```

---
## Matrices