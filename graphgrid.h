#pragma once
// to ensure its done once

class Graph
{
public:
    Graph(); // constructor here
    int graph[20][10];
    void buildgraph();
    void showgraph();

private:
    int rows, cols, size;
};