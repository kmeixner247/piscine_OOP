#include "Graph.hpp"
void Graph::addPoint(const Vector2 &v)
{
    if (v.x < _size && v.y < _size)
    {
        _points.push_back(v);
    }
}

void Graph::addLine(const Line &l)
{
    if (l.start.x < _size && l.start.y < _size && l.end.x < _size && l.end.y < _size && l.start.x >= 0 && l.start.y >= 0 && l.end.x >= 0 && l.end.y >= 0)
    {
        _lines.push_back(l);
    }
}

std::ostream& operator<<(std::ostream& p_os, const Graph& p_graph)
{
    std::vector<std::vector<char> > pixels;
	for (int i = 0; i < p_graph._size; i++)
    {
        std::vector<char> line;
        for (int j = 0; j < p_graph._size; j++)
        {
            line.push_back('.');
        }
        pixels.push_back(line);
    }

    for (std::list<Vector2>::const_iterator it = p_graph._points.begin(); it != p_graph._points.end(); it++)
    {
        pixels[it->y][it->x] = 'X';
    }
    for (std::list<Line>::const_iterator it = p_graph._lines.begin(); it != p_graph._lines.end(); it++)
    {
        Graph::drawLine(pixels, *it);
    }
    for (int i = p_graph.getSize() - 1; i >= 0; i--)
    {
        p_os << i;
        for (int j = 0; j < p_graph.getSize(); j++)
        {
            p_os << ' ' << pixels[i][j]; 
        }
        p_os << std::endl;
    }
    p_os << ' ';
    for (int j = 0; j < p_graph.getSize(); j++)
    {
        p_os << ' ' << j; 
    }
    p_os << std::endl;
	return p_os;
}

void Graph::drawLine(std::vector<std::vector<char> > &pixels, const Line &l)
{
    float dx = l.end.x - l.start.x;
    float dy = l.end.y - l.start.y;
    if (dx > dy)
    {
        if (dx == 0)
            dy = 0;
        else
            dy = dy / dx;
        dx = 1;
    }
    else
    {
        if (dy == 0)
            dx = 0;
        else
            dx = dx / dy;
        dy = 1;
    }
    float x = l.start.x;
    float y = l.start.y;
    while (x <= l.end.x && y <= l.end.y)
    {
        pixels[round(y)][round(x)] = 'X';
        x += dx;
        y += dy;
    }
}