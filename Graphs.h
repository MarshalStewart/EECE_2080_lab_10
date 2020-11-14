#pragma once
#include <vector>
#include <string>
#include <iostream>

#define MATRIX_SIZE 100

class Graph
{
public:
    Graph(int num_v);
    Graph(int num_v, bool adj_matrix[MATRIX_SIZE][MATRIX_SIZE]);
    ~Graph() {};

    bool addEdge(int n_1, int n_2); // Add edge (i,j) to E

    bool removeEdge(int n_1, int n_2); // Remove the edge (i,j) from E

    bool hasEdge(int n_1, int n_2); // check if edge (i,j) is in E

    std::vector<int> outEdges(int n); // returns list of ints such that (i,j) is in E

    std::vector<int> inEdges(int n); // returns list of ints such that (j,i) is in E

    std::string printGraph(); // Prints adjacency matrix
    
    bool isEmpty();

private:
    Graph(); // Unused
    int m_matrix_size;
    bool m_adj_matrix[MATRIX_SIZE][MATRIX_SIZE];

};