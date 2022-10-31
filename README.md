# 3DCurves
1. Supports a few types of 3D geometric curves – circles, ellipses and 3D helixes. Each curve should be able to return a 3D point and a first derivative (3D
vector) per parameter t along the curve.
2. Populates a container (vector) of objects of these types created in random manner with random parameters.
3. Prints coordinates of points and derivatives of all curves in the container at t=PI/4.
4. Populates a second container that would contain only circles from the first container. The
second container shares (i.e. not clones) circles of the first one via pointers.
5. Sorts the second container in the ascending order of circles’ radii.
6. Computes and prints the total sum of radii of all curves (circles) in the second container.

# How to build
1. git clone or download source code from this repo.
2. run CMake GUI (or [download](https://cmake.org/download/) at least version 3.24.0. if dont have one).
3. select directory, containing CMakeLists.txt.
4. select directory, where CMake should build binaries - consider create a folder **build/** near CMakeLists.txt.
5. click *Configure* to start project configurating.
6. when asked, specify generator you want to use - originally used generator was MSYS Makefiles.
7. also recommended to specify C and C++ compilers you want to use for compiling by select *Specify native compilers*.
8. after configuring done, click *Generate* to generate specific generator files which you chose on step 6.
9. at the last step you want to build tcp_server and tcp_client binaries - you can use chosen generator, or you can do this using command line: just type in *cmake --build .* while you're in build/ directory
10. after building done you'll find executable *3DCurves* in *build-folder/*.

# How to use
1. run executable 3DCurves from *build-folder/*.
