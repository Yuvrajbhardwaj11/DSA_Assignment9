#include <iostream>
#include <stack>
#include <cstring>
using namespace std;

bool visited[100][100];

void DFS_island(int grid[][100], int r, int c, int R, int C) {
    stack<pair<int,int>> st;
    st.push({r, c});

    while (!st.empty()) {
        auto [x, y] = st.top();
        st.pop();

        if (visited[x][y]) continue;
        visited[x][y] = true;

        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < R && ny >= 0 && ny < C &&
                grid[nx][ny] == 1 && !visited[nx][ny]) {
                st.push({nx, ny});
            }
        }
    }
}

int numIslands(int grid[][100], int R, int C) {
    memset(visited, false, sizeof(visited));
    int count = 0;

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (grid[i][j] == 1 && !visited[i][j]) {
                DFS_island(grid, i, j, R, C);
                count++;
            }
        }
    }

    return count;
}

int main() {
    int grid[100][100] = {
        {1,1,0},
        {0,1,0},
        {1,0,1}
    };

    cout << numIslands(grid, 3, 3);
}
