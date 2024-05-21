#include <iostream>
#include "Graph.hpp"
#include "Vector2.hpp"
#include "Line.hpp"
int main()
{
    Graph g(10);
    Vector2 v(4,3);
    
    g.addPoint(Vector2(0,0));    
    g.addPoint(Vector2(2,2));
    g.addPoint(Vector2(4,2));
    // g.addPoint(Vector2(2,4));
    Line l;
    l.start = (Vector2(0,2));
    l.end = (Vector2(9,7));
    g.addLine(l);
    std::cout << g;
}