#include<iostream>
#include<queue>
using namespace std;

void BFS(int* graph[], int vertices, int start){
    bool* visited = new bool[vertices]{false};
    queue<int> q;

    visited[start] = true;
    q.push(start);

    cout << "BFS Traversal starting from vertex " << start << ": ";

    while(!q.empty()){
        int curr = q.front();
        q.pop();
        cout << curr << " ";

        int idx = 0;
        // Each adjacency list is an int array terminated by -1
        while(graph[curr][idx] != -1){
            int neighbor = graph[curr][idx];
            if(neighbor >= 0 && neighbor < vertices && !visited[neighbor]){
                visited[neighbor] = true;
                q.push(neighbor);
            }
            ++idx;
        }
    }

    cout << endl;
    delete[] visited;
}
int main(){
    int arr0[] = {1, 3, -1};
    int arr1[] = {0, 2, 4, -1};
    int arr2[] = {1, 3, -1};
    int arr3[] = {0, 2, 4, -1};
    int arr4[] = {1, 3, -1};

    int* graph2[5] = {arr0, arr1, arr2, arr3, arr4};

    int startVertex = 4;
    BFS(graph2, 5, startVertex);

    return 0;
}




    // explore neighbors
    for (int i = 0; graph[u][i] != -1; i++) {
        int v = graph[u][i];
        if (!visited[v]) {
            DFS_rec(graph, visited, v);
        }
    }
}
