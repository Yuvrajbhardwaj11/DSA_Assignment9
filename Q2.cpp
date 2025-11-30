#include <iostream>
#include <stack>
using namespace std;

void DFS(int* graph[], int V, int start) {
    bool visited[100] = {false};
    stack<int> st;

    st.push(start);

    cout << "DFS (using stack): ";

    while (!st.empty()) {
        int node = st.top();
        st.pop();

        if (!visited[node]) {
            visited[node] = true;
            cout << node << " ";
        }

        int count = 0;
        while (graph[node][count] != -1) count++;

        for (int i = count - 1; i >= 0; i--) {
            int neigh = graph[node][i];
            if (!visited[neigh]) st.push(neigh);
        }
    }

    cout << endl;
}

int main() {
    int a0[] = {1, 3, -1};
    int a1[] = {0, 2, 4, -1};
    int a2[] = {1, 3, -1};
    int a3[] = {0, 2, 4, -1};
    int a4[] = {1, 3, -1};

    int* graph[5] = {a0, a1, a2, a3, a4};

    DFS(graph, 5, 0);
}



#include <bits/stdc++.h>
using namespace std;

void DFS(int* graph[], int V, int u, bool visited[]) {
    visited[u] = true;
    cout << u << " ";

    for (int i = 0; graph[u][i] != -1; i++) {
        int v = graph[u][i];
        if (!visited[v]) {
            DFS(graph, V, v, visited);
        }
    }
}

int main() {
    int arr0[] = {1, 3, -1};
    int arr1[] = {0, 2, 4, -1};
    int arr2[] = {1, 3, -1};
    int arr3[] = {0, 2, 4, -1};
    int arr4[] = {1, 3, -1};

    int* graph2[5] = {arr0, arr1, arr2, arr3, arr4};

    bool visited[100] = {false};

    DFS(graph2, 5, 4, visited);

    return 0;
}


