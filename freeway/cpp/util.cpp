#include <iostream>
#include <fstream>
#include <util.h>

template <typename T>
void print_debug(const T& info)
{
    std::cout << info;

    std::ofstream f('output.log');
    f << info;
    f.close();
}