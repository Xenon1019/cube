#include <iostream>
#include <array>
#include <functional>
#include <vector>
#include "cube.h"
#include "color.h"
#include "pieces.h"



void nCycle(std::vector<std::reference_wrapper<int>> &numArray, bool directon = true)
{
    int beginIndex{directon ? (static_cast<int>(numArray.size()) - 1) : 0};
    int endIndex{directon ? 0 : (static_cast<int>(numArray.size()) - 1)};
    const int step{directon ? -1 : 1};
    for (int i = beginIndex; i != endIndex; i += step)
        std::swap(numArray.at(i), numArray.at(i + step));
}

int main()
{
    Cube cube;
    return 0;
}