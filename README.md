# CPPND: Capstone Fractal Explorer Repo


## Dependencies for Running Locally
* cmake >= 3.7
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* OpenCV >= 4.1
  * The OpenCV 4.1.0 source code can be found [here](https://github.com/opencv/opencv/tree/4.1.0)
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory in the top level directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./FractalExplorer`.

## References

1. https://en.wikipedia.org/wiki/Mandelbrot_set
2. https://en.wikipedia.org/wiki/Julia_set
3. https://github.com/opencv/opencv/tree/master/samples/cpp
4. https://docs.opencv.org/master/


## Project Description

FractalExplorer is project selected as option: 'Capstone Option 1 - Mandelbrot Fractal or Creator'. 
Usage:
- `FractalExplorer [-h|--help][-f|--fullscreen][-p|--parallel][-j|--julia]`,
- `[-h|--help]` this help,
- `[-f|--fullscreen]` fullscreen mode,
- `[-p|--parallel]` multithreaded version,
- `[-j|--julia]` Julia fractal, default: Mandelbrot,
LMB: zoom in, RMB: zoom out.
- Class structure
  - Main class `FractalExplorer` parses command line and sets all parameters. 
  - All fractal clases implement interface AbstractFrac.
  - Multithreaded versions of fractal classes inherit from single-threaded, MandelbrotFracParallel extends MandelbrotFrac, JuliaFracParallel extends JuliaFrac.

### Project Rubric Points

#### README (All Rubric Points REQUIRED)

- [x] A README with instructions is included with the project
- [x] The README indicates which project is chosen.
- [x] The README includes information about each rubric point addressed.

#### Compiling and Testing (All Rubric Points REQUIRED)

- [x] The submission must compile and run.

#### Loops, Functions, I/O

- [x] The project demonstrates an understanding of C++ functions and control structures.
  - MandelbrotFrac.cpp line 42, 48, 
  - FractalExplorer.cpp line 16, 62
- [ ] The project reads data from a file and process the data, or the program writes data to a file.
- [x] The project accepts user input and processes the input.
  - Left and right mouse button clicks zoom in and out - FractalExplorer.cpp line 46

#### Object Oriented Programming

- [x] The project uses Object Oriented Programming techniques.
  - The main classes of the project are `FractalExplorer`, `MandelbrotFrac`, `MandelbrotFracParallel`, `JuliaFrac`, `JuliaFracParallel`
    - `FractalExplorer` object is created in main(), and it contains project logic. 
    - `MandelbrotFrac`, `MandelbrotFracParallel`, `JuliaFrac`, `JuliaFracParallel` implement common interface, that is used for drawing fractal.
  - Additional utility class `Stoper` is used to measure time of calculation.
- [x] Classes use appropriate access specifiers for class members.
  - FractalExplorer.h line 11, 14, AbstractFrac.h line 6, MandelbrotFrac.h line 7, 12, 28
- [x] Class constructors utilize member initialization lists.
  - MandelbrotFrac.cpp line 8, FractalExplorer.cpp line 14
- [x] Classes abstract implementation details from their interfaces.
  - `MandelbrotFrac` implements abstract interface AbstractFrac. MandelbrotFrac.h line 4
- [x] Classes encapsulate behavior.
  - MandelbrotFrac.h lines 12-30
- [x] Classes follow an appropriate inheritance hierarchy.
  - MandelbrotFrac extends AbstractFrac, MandelbrotFracParallel extends MandelbrotFrac.
  - MandelbrotFrac.h line 4, MandelbrotFracParallel.h line 4
- [ ] Overloaded functions allow the same function to operate on different parameters.
- [x] Derived class functions override virtual base class functions.
  - MandelbrotFrac.h lines 9-11, MandelbrotFracParallel.h line 8, JuliaFrac.h line 9, JuliaFracParallel.h line 10
- [ ] Templates generalize functions in the project.

#### Memory Management

- [x] The project makes use of references in function declarations.
  - MandelbrotFrac.h 26, AbstractFrac.h 7
- [x] The project uses destructors appropriately.
  - Stoper.h line 8
- [x] The project uses scope / Resource Acquisition Is Initialization (RAII) where appropriate.
  - FractalExplorer.cpp line 11, 74, 78, 85, 89
- [x] The project follows the Rule of 5.
  - all classes use default implementation of copy constructor, assignment operator etc.
- [x] The project uses move semantics to move data, instead of copying it, where possible.
  - MandelbrotFracParallel.cpp 15, JuliaFracParallel.cpp 14
- [x] The project uses smart pointers instead of raw pointers.
  - FractalExplorer.cpp line 74, 78, 85, 89

#### Concurrency

- [x] The project uses multithreading
  - JuliaFracParallel.cpp line 13, MandelbrotFracParallel.cpp line 14
- [x] A promise and future is used in the project.
  - JuliaFracParallel.cpp line 16, MandelbrotFracParallel.cpp line 17
- [ ] A mutex or lock is used in the project.
- [ ] A condition variable is used in the project.
