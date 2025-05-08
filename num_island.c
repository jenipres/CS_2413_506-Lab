// DFS to mark connected land as visited
void dfs(char** x, int y, int z, int a, int b) {
    if (y < 0 || y >= a || z < 0 || z >= b || x[y][z] != '1')
        return;
    x[y][z] = '0'; // mark as visited

    dfs(x, y - 1, z, a, b); // up
    dfs(x, y + 1, z, a, b); // down
    dfs(x, y, z - 1, a, b); // left
    dfs(x, y, z + 1, a, b); // right
}

// Count number of islands
int numIslands(char** x, int y, int* z) {
    if (y == 0 || z == NULL)
        return 0;

    int a = 0; // island count
    for (int b = 0; b < y; b++) {
        for (int c = 0; c < z[b]; c++) {
            if (x[b][c] == '1') {
                a++; // found new island
                dfs(x, b, c, y, z[b]); // mark the whole island
            }
        }
    }
    return a;
}
