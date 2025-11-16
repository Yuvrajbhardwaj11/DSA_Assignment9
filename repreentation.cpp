#include <iostream>
using namespace std;

void printGraph(int graph[][5], int vertices) {
    for (int i = 0; i < vertices; i++) {
        cout << "Vertex " << i << ": ";
        for (int j = 0; j < vertices; j++) {
            if (graph[i][j] == 1) {
                cout << j << " ";
            }
        }
        cout << endl;
    }
}

void printGraph_array_LL(int* graph[], int vertices) {
    for (int i = 0; i < vertices; i++) {
        cout << "Vertex " << i << ": ";

        int* temp = graph[i];

        while (*temp != -1) {   
            cout << *temp << " ";
            temp++;             
        }

        cout << endl;
    }
}

int main() {
    int graph1[5][5] = {
        {0, 1, 0, 1, 0},
        {0, 0, 0, 0, 0},
        {0, 1, 0, 0, 0},
        {0, 0, 1, 0, 1},
        {0, 1, 0, 0, 0}
    };

    cout << "Adjacency Matrix Representation:\n";
    printGraph(graph1, 5);



    int arr0[] = {1, 3, -1};
    int arr1[] = {0, 2, 4, -1};
    int arr2[] = {1, 3, -1};
    int arr3[] = {0, 2, 4, -1};
    int arr4[] = {1, 3, -1};

    int* graph2[5] = {arr0, arr1, arr2, arr3, arr4};

    cout << "\nAdjacency List Representation:\n";
    printGraph_array_LL(graph2, 5);

    return 0;
}
