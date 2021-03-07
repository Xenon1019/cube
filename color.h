//
// Created by xenon on 17/02/21.
//
#ifndef CUBE_CLION_COLOR_H
#define CUBE_CLION_COLOR_H
#include <string>

enum class Color
{
    Red,
    Orange,
    White,
    Yellow,
    Blue,
    Green,
    NA
};
std::string colorToString(Color color)
{
    switch(color)
    {
        case Color::Red:
            return "Red";
        case Color::Yellow:
            return "Yellow";
        case Color::White:
            return "White";
        case Color::Orange:
            return "Orange";
        case Color::Blue:
            return "Blue";
        case Color::Green:
            return "Green";
        default:
            return "NA";
    }
}
#endif //CUBE_CLION_COLOR_H
