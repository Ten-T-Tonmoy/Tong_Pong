#include <iostream>
#include "graphgrid.h"

using namespace std;

Graph::Graph()
{

    rows = 20;
    cols = 10;
    size = 45;
    buildgraph();
}

void Graph::buildgraph()
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            graph[rows][cols] = 0;
        }
    }
}
void Graph::showgraph()
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << graph[rows][cols] << " ";
        }
        cout << endl;
    }
}