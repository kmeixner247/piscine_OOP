#pragma once

#include "Vector2.hpp"
#include "Line.hpp"
#include <list>
#include <vector>
#include <iostream>
#include <cmath>
class Graph
{
private:
    int _size;
    std::list<Vector2> _points;
    std::list<Line> _lines;
public:
    static void drawLine(std::vector<std::vector<char> > &pixels, const Line &l);
    Graph(int size) : _size(size) {}
    int getSize() const {return _size;}
    void addPoint(const Vector2 &v);
    void addLine(const Line &l);

	friend std::ostream& operator<<(std::ostream& p_os, const Graph& p_graph);
};