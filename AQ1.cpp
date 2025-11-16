#include <iostream>
#include <stack>
#include <cstring>
using namespace std;

void DFS_CC(int* graph[], int start, bool visited[]) {
    stack<int> st;
    st.push(start);

    while (!st.empty()) {
        int node = st.top();
        st.pop();

        if (!visited[node]) visited[node] = true;

        int count = 0;
        while (graph[node][count] != -1) count++;

        for (int i = count - 1; i >= 0; i--) {
            int neigh = graph[node][i];
            if (!visited[neigh]) st.push(neigh);
        }
    }
}

int countComponents(int* graph[], int V) {
    bool visited[100];
    memset(visited, false, sizeof(visited));

    int comp = 0;

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            DFS_CC(graph, i, visited);
            comp++;
        }
    }

    return comp;
}

int main() {
    int a0[] = {1, -1};
    int a1[] = {0, -1};
    int a2[] = {3, -1};
    int a3[] = {2, -1};
    int a4[] = {-1};

    int* graph[5] = {a0, a1, a2, a3, a4};

    cout << countComponents(graph, 5);
}
