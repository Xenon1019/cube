//
// Created by xenon on 17/02/21.
//

#include "pieces.h"

void Edge::colorTile(Color cl1, Color cl2)
{
    colorTile(0, cl1);
    colorTile(1, cl2);
}

std::vector <std::reference_wrapper<Edge>> Edgelet::returnEdgeVector(int size, std::array<Color, 2> colors)
{
    std::vector<Edge> edges;
    for(int i{0}; i < size; i++)
        edges.push_back(*(new Edge(colors)));
    std::vector<std::reference_wrapper<Edge>> refEdges;
    for (auto edge: edges)
        refEdges.insert(refEdges.begin(), edge);
    return refEdges;
}

Color CenterSquare::getCenter() const
{
    if (c_size % 2 == 0)
        return Color::NA;
    else
    {
        int mid = (c_size + 1) / 2;
        return c_colors[mid][mid];
    }
}

