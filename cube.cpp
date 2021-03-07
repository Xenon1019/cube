//
// Created by xenon on 17/02/21.
//

#include "cube.h"

void Face::colorFace(Color color = Color::NA)
{
    f_center->colorCenter(color);
    for (int i = 0; i < 4; i++)
    {
        f_corners.at(i)->colorTile(f_cornerDirIndex[i], color);
        f_edgelets.at(i)->colorTiles(f_edgeletDirIndex[i], color);
    }
}

std::array<Edgelet, 12> &Cube::initializeEdgelet(int size)
{
    std::array<Edgelet, 12> edgelets{};
    for (auto edgelet:edgelets)
        edgelet = Edgelet(size);
    return  edgelets;
}
