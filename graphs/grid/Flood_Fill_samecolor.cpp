#include<iostream>
#include<vector>
using namespace std;

void dfs(int i, int j, int initcolor, int newcolor, vector<vector<int>> &image) {
    int n = image.size();
    int m = image[i].size();
    if(i < 0 || j < 0) return;
    if(i >= n || j >= m) return;
    if(image[i][j] != initcolor) return;
    image[i][j] = newcolor;

    dfs(i, j+1, initcolor, newcolor, image);
    dfs(i-1, j, initcolor, newcolor, image);
    dfs(i, j-1, initcolor, newcolor, image);
    dfs(i+1, j, initcolor, newcolor, image);
}
vector<vector<int>> floodfill(vector<vector<int>> &image, int row, int col, int color) {
    if(image[row][col] != color)
        dfs(row, col, image[row][col], color, image);
    return image;
}
int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> image(n, vector<int> (m));
    for(int i=0; i<n; ++i) {
        for(int j=0; j<m; ++j)
            cin >> image[i][j];
    }
    int x, y, color;
    cin >> x >> y >> color;
    image = floodfill(image, x, y, color);
    return 0;
}
