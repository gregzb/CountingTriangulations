# CountingTriangulations

### Warning
- Unfortunately, it currently fails in certain cases when a point in polygon check is done because it uses a horizontal line test, and this fails when the line intersects a vertex
- This could be fixed by using winding number instead

## Install Prerequisites
- Only tested on Linux, should work in wslG though
- gcc that supports C++17
- CMake (3.22 or higher)
- make
- SFML
  - `sudo apt install libsfml-dev`

## Compile Instructions
- cd into the root directory of the project
- `cmake -S . -B build -DCMAKE_BUILD_TYPE=Release`
- `cd build`
- `make`

## Run instructions
- After building in the previous step, you have one of two options
  - `./countingTriangulations`
  - `./countingTriangulations <file>`
    - The file should be a whitespace delimited list of floating point coordinates in ascii, alternating from x to y. (first x1 and y1, then x2 and y2, then x3 and y3)
