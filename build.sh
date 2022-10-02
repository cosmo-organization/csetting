echo Configuring
echo Making build directory
mkdir build
echo Compiliing extra/detectendianess.c
gcc extra/detectendianess.c -o extra/config
echo Generating endianess.h
extra/./config
cd build
echo Started building project
cmake ../ && cmake --build .
echo Bye