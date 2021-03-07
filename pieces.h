//
// Created by xenon on 17/02/21.
//
#ifndef CUBE_CLION_PIECES_H
#define CUBE_CLION_PIECES_H

#include "color.h"
#include <array>
#include <vector>
#include <algorithm>
#include <functional>

class Edge
{
private:
    std::array<Color, 2> m_edge;
public:
    explicit Edge(Color cl1 = Color::NA, Color cl2 = Color::NA) : m_edge{{cl1, cl2}}
    {}

    explicit Edge(const std::array<Color, 2> &colors)
            : m_edge{{Color(colors[0]), Color(colors[1])}}
    {}

    void flip()
    { std::swap(m_edge[0], m_edge[1]); }


    std::reference_wrapper<Color> getColor(int index)
    { return m_edge.at(index); }

    void colorTile(int index, Color color)
    { m_edge[index] = color; }

    void colorTile(Color cl1, Color cl2);
};

class Corner
{
private:
    std::array<Color, 3> c_colors;
public:
    explicit Corner(Color cl1 = Color::NA, Color cl2 = Color::NA, Color cl3 =  Color::NA)
            :c_colors{std::array<Color, 3>{cl1, cl2, cl3}}
    {}

    explicit Corner (std::array<Color, 3> colors)
            :c_colors{colors}
    {}

    std::reference_wrapper<Color> getColor (int index)
    { return c_colors.at(index); }

    void colorTile(int index, Color color)
    { c_colors[index] = color; }
};

class Edgelet
{
private:
    const int e_size;
    std::vector<std::reference_wrapper<Edge>> e_edges;
public:
    explicit Edgelet (int size = 1, Color cl1 = Color::NA, Color cl2 = Color::NA):
        e_size{size},
        e_edges{returnEdgeVector(size, std::array<Color, 2> {{cl1, cl2}})}
    {}
    static std::vector <std::reference_wrapper<Edge>> returnEdgeVector(int size, std::array<Color, 2> colors);

    Edge& getEdge(int index)
    { return e_edges.at(index); }

    void flip()
    { for (auto edge:e_edges)
            edge.get().flip(); }

    int size() const
    { return e_size; }

    void colorTiles(int index, Color color)
    { for(auto edge:e_edges)
            edge.get().colorTile(index, color); }
    ~Edgelet()
    { for (auto edge:e_edges)
            delete &(edge.get()); }

};


class CenterSquare
{
private:
    const int c_size;
    std::vector<std::vector<Color>> c_colors;
public:
    explicit CenterSquare(int size = 1, Color color = Color::NA):
        c_size{size}
    {
        c_colors.resize(c_size);
        for (auto row: c_colors)
        {
            row.resize(c_size);
            for (auto cell: row)
                cell = color;
        }
    }

    void colorCenter(Color color)
    { for(auto row: c_colors)
            for(auto cell:row)
                cell = color;
    }

    Color getCenter() const;

    int size() const
    { return c_size; }

};

#endif //CUBE_CLION_PIECES_H
