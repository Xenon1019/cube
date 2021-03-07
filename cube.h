#pragma clang diagnostic push
#pragma ide diagnostic ignored "OCUnusedGlobalDeclarationInspection"
#pragma ide diagnostic ignored "modernize-use-nodiscard"
//
// Created by xenon on 17/02/21.
//

#ifndef CUBE_CLION_CUBE_H
#define CUBE_CLION_CUBE_H

#include <vector>
#include <cassert>
#include <string>
#include "color.h"
#include "pieces.h"

class Face
{
private:
    std::array <Corner*, 4> f_corners;
    std::array <Edgelet*, 4> f_edgelets;
    CenterSquare* f_center;
    const int f_size;
    std::array<int, 4> f_cornerDirIndex;
    std::array<int, 4> f_edgeletDirIndex;
public:
    Face(int size, const std::array<Corner*, 4> &corners, const std::array<Edgelet*, 4> &edgelets, CenterSquare *centerSquare,
         std::array<int, 4> cornerIndex, std::array<int, 4> edgesIndex, Color color = Color::NA)
            :f_size{size},
             f_center{centerSquare},
             f_corners{corners},
             f_edgelets{edgelets},
             f_cornerDirIndex{cornerIndex},
             f_edgeletDirIndex{edgesIndex}
    {
        if (color != Color::NA)
            colorFace(color);
    }

    void colorFace(Color color = Color::NA);

    Color getColor() const
    { return f_center->getCenter(); }
};


class Cube
{
private:
    const int c_size;
    std::array <Corner, 8> c_corners;
    std::array <Edgelet, 12> c_edglets;
    std::array <CenterSquare, 6> c_centers;
    std::array <Face, 6> c_faces;


    //Static Arrays used to identify geometry of the cube.
    //More specifically to identify which index of corners and edges in which face.
    static constexpr std::array <std::array<int, 4>, 6> c_cornersIndex{{{0, 1, 2, 3},
                                                                               {1, 4, 3, 5},
                                                                               {4, 6, 5, 7},
                                                                               {6, 0, 7, 2},
                                                                               {2, 3, 7, 5},
                                                                               {6, 4, 0, 1}}};
    static constexpr std::array <std::array<int, 4>, 6> c_edgesIndex{{{0, 1, 2, 3},
                                                                             {4, 2, 5, 6},
                                                                             {7, 5, 8, 9},
                                                                             {10, 8, 1, 11},
                                                                             {3, 11, 6, 9},
                                                                             {7, 10, 4, 0}}};
    static constexpr std::array <std::array<int, 4>, 6> c_cornerTilesIndex{{{0, 0, 0, 0},
                                                                                   {1, 0, 1, 0},
                                                                                   {1, 0, 1, 0},
                                                                                   {1, 1, 1, 1},
                                                                                   {2, 2, 2, 2},
                                                                                   {2, 2, 2, 2}}};
    static constexpr std::array <std::array<int, 4>, 6> c_edgesTilesIndex{{{0, 0, 0, 0},
                                                                                  {0, 1, 0, 0},
                                                                                  {0, 1, 0, 0},
                                                                                  {0, 1, 1 ,0},
                                                                                  {1, 1, 1, 1},
                                                                                  {1, 1, 1, 1}}};


public:
    Cube(int size = 2, std::array <Color, 6> centerColors = {
            Color::Green, Color:: Orange,
            Color::Blue, Color::Red,
            Color::Yellow, Color::White})
        :c_size{size},
        c_centers{{CenterSquare(size - 2, centerColors.at(0)),
                   CenterSquare(size - 2, centerColors.at(1)),
                   CenterSquare(size - 2, centerColors.at(2)),
                   CenterSquare(size - 2, centerColors.at(3)),
                   CenterSquare(size - 2, centerColors.at(4)),
                   CenterSquare(size - 2, centerColors.at(5))}},

    {
        for (int i{0}; i < 6;i++)
            c_centers.at(i) = CenterSquare(c_size - 2, centerColors[i]);
        for (int i{0}; i < 8;i++)
            c_corners.at(i) = Corner();
        for (int i{0}; i < 12;i++)
            c_edglets.at(i) = Edgelet(c_size - 2);


        for(int i = 0;i < 6;i++)
            c_faces[i] = Face(c_size, getCorners(i), getEdges(i), &(c_centers[i]), c_cornerTilesIndex[i], c_edgesTilesIndex[i], centerColors[i]);

        for (int i = 0; i < 6; i++)
        {
            c_faces.at(i).colorFace(centerColors[i]);
        }

    }

    std::array <Corner*, 4> getCorners(int faceIndex)
    {
        std::array <Corner*, 4> cornerPointers{};
        for (int i{0}; i < 4; i++)
            cornerPointers.at(i) = &(c_corners.at(c_cornersIndex.at(faceIndex).at(i)));
        return cornerPointers;
    }

    std::array <Edgelet*, 4> getEdges(int faceIndex)
    {
        std::array <Edgelet* ,4> edgesPointers{};
        for (int i{0};i < 4;i++)
            edgesPointers.at(i) = &(c_edglets.at(c_edgesIndex.at(faceIndex).at(i)));
        return edgesPointers;
    }

    std::array<Edgelet, 12> &initializeEdgelet(int size);
};



#endif //CUBE_CLION_CUBE_H

#pragma clang diagnostic pop