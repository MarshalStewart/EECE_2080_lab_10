#include <iostream>
#include <string>
#include <cstdlib>
#include "Graphs.cpp"

using namespace std;

int main()
{
    bool run = true;
    int input = 0;
    char use_matrix;
    std::string row = "";
    int n_1, n_2, n;
    std::vector<int> edges; 
    bool matrix[MATRIX_SIZE][MATRIX_SIZE];
    Graph graph(10);

    std::cout << "Load a matrix file? (y, n)" << std::endl;
    std::cin >> use_matrix;

    int count = 0;
    if(use_matrix == 'y')
    {
        std::cout << "Loading matrix file\n";
        for (int i=0; i<10; i++)
        {
            for (int j=0; j<10; j++)
            {
                std::cin >> row;
                matrix[i][j] = std::stoi(row);
            }

        }
    
        graph = Graph(10, matrix);
    }
    
    while(run)
    {
        std::cout <<
        "Press 1 to add an edge to graph" << std::endl << 
        "Press 2 remove an edge from graph" << std::endl << 
        "Press 3 Find an edge in the graph" << std::endl << 
        "Press 4 Find the out edges of a vertices" << std::endl << 
        "Press 5 Find the in edges of a vertices" << std::endl << 
        "Press 6 To Print out Adjacency Matrix" << std::endl << 
        "Press 7 to quit" << std::endl; 

        std::cin >> input;
        switch(input)
        {
            case 1:
                // Get input
                std::cout << "Enter the first node:" << std::endl;
                std::cin >> n_1;
                std::cout << "Enter the second node:" << std::endl;
                std::cin >> n_2;

                // Check if valid input
                if ((n_1 > 100 || n_1 < 0 ) || (n_2 > 100 || n_2 < 0))
                {
                    std::cout << "Invalid nodes\n";
                    break;
                }

                // add the edge
                if (graph.addEdge(n_1, n_2))
                    printf("Added edge from %d to %d\n", n_1, n_2);
                else
                    printf("Failed to add edge\n");
                
                break;
                
            case 2:
                // Get input
                std::cout << "Enter the first node:" << std::endl;
                std::cin >> n_1;
                std::cout << "Enter the second node:" << std::endl;
                std::cin >> n_2;

                // Check if valid input
                if ((n_1 > 100 || n_1 < 0 ) || (n_2 > 100 || n_2 < 0))
                {
                    std::cout << "Invalid nodes\n";
                    break;
                }

                // remove the edge
                if (graph.removeEdge(n_1, n_2))
                    printf("Removed edge from %d to %d\n", n_1, n_2);
                else
                    printf("Failed to remove edge\n");
                
                break;

            case 3:
            
                // Get input
                std::cout << "Enter the first node:" << std::endl;
                std::cin >> n_1;
                std::cout << "Enter the second node:" << std::endl;
                std::cin >> n_2;

                // Check if valid input
                if ((n_1 > 100 || n_1 < 0 ) || (n_2 > 100 || n_2 < 0))
                {
                    std::cout << "Invalid nodes\n";
                    break;
                }

                // Find the edge
                if (graph.hasEdge(n_1, n_2))
                    printf("Edge FOUND from %d to %d\n", n_1, n_2);
                else
                    printf("Edge NOT FOUND from %d to %d\n", n_1, n_2);
                
                break;

            case 4:
            
                // Get input
                std::cout << "Enter the node of interest:" << std::endl;
                std::cin >> n;

                // Check if valid input
                if (n > 100 || n < 0 )
                {
                    std::cout << "Invalid node\n";
                    break;
                }

                // Find out-edges
                edges = graph.outEdges(n);
                printf("Found nodes pointing outward towards %d\n", n);
                for (auto i : edges)
                {
                    std::cout << i << std::endl;
                }
                
                break;

            case 5:
                // Get input
                std::cout << "Enter the node of interest:" << std::endl;
                std::cin >> n;

                // Check if valid input
                if (n > 100 || n < 0 )
                {
                    std::cout << "Invalid node\n";
                    break;
                }

                // Find in-edges
                edges = graph.inEdges(n);
                printf("Found nodes pointing inward towards %d\n", n);
                for (auto i : edges)
                {
                    std::cout << i << std::endl;
                }
                
                break;
                
            case 6:
                std::cout << "Printing Matrix\n";
                if (graph.isEmpty())
                {
                    std::cout << "Graph is empty" << endl;
                    break;
                }
                graph.printGraph(); 
                break;
            
            case 7:
                run = false;
                break;
            
            default:
                std::cout << "Invalid input\n";
                break;
        }
    }

    std::cout << "Thanks for playing\n";

    return EXIT_SUCCESS;
}
