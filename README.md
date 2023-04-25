# LinAlg

Simple vector and matrix library inspired by [p5.js.Vector](https://p5js.org/reference/#/p5.Vector)

Option to work with 2D, in Polar or Rectangular coordinates, or 3D vectors:

```cpp
linalg::Vector<double> vec(1, 3);
linalg::Vector<double> vec(10, M_PI / 3, Format::Polar);

linalg::Vector<int> vec = {1, 4, 2};
```

Normal math:
```cpp
linalg::Vector<double> vec1(1, 3);
linalg::Vector<double> vec2(1, 4);

std::cout << "vec1 + vec2: " << vec1 + vec2 << std::endl;
std::cout << "vec1 - vec2: " << vec1 - vec2 << std::endl;
std::cout << "vec1 + 2:    " << vec1 + 2 << std::endl;
std::cout << "vec1 - 2:    " << vec1 - 2 << std::endl;

// Output
// vec1 + vec2: [2.0, 7.0]
// vec1 - vec2: [0.0, -1.0]
// vec1 + 2:    [3.0, 5.0]
// vec1 - 2:    [-1.0, 1.0]
```

Basic linear algebra facilities:
```cpp
linalg::Vector<double> vec1(1, 3);
linalg::Vector<double> vec2(1, 4);

std::cout << "Magnitude:     " << vec1.Mag() << std::endl;
std::cout << "Angle:         " << vec1.Angle() << std::endl;
std::cout << "Angle between: " << vec1.Angle(vec2) << std::endl;

// Output
// Magnitude: 
// Angle: 
// Angle between:

std::cout << "Distance:      " << vec1.Distance(vec2) << std::endl;
std::cout << "Dot product:   " << vec1.Dot(vec2) << std::endl;
std::cout << "Cross product: " << vec1.Cross(vec2).ToString() << std::endl;

// Output
// Distance: 
// Dot product: 
// Cross product:
```

Handy rotation matrices:
```cpp
linalg::Vector<double> vec1(1, 3, 4);

std::cout << "RotateX:     " << vec1.RotateX(M_PI / 4).ToString() << std::endl;
std::cout << "RotateY:     " << vec1.RotateY(M_PI / 4).ToString() << std::endl;
std::cout << "RotateZ:     " << vec1.RotateZ(15, AngleFormat::Degrees).ToString() << std::endl;

// Output
// RotateX: [2.0, 7.0]
// RotateY: [2.0, 7.0]
// RotateZ: [2.0, 7.0]
```