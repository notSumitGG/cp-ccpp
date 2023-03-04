#include<vector>
#include<queue>
#include<limits.h>
using namespace std;
// https://leetcode.com/problems/shortest-path-in-binary-matrix/
class Solution {
public:
    // my solution
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(n==1 && grid[0][0]==0) return 1; 
        if(grid[n-1][n-1] != 0 || grid[0][0] != 0) return -1;
        vector<pair<int, int>> mv = {
            {1, 0}, {1, 1}, {0, 1}, {-1, 1}, {-1, 0}, {-1, -1}, {0, -1}, {1, -1}
        };

        vector<vector<bool>> vis(n, vector<bool>(n, false));
        queue<pair<int, pair<int, int>>> q;
        q.push({1, {0, 0}});
        vis[0][0] = true;

        while(!q.empty()) {
            int wt = q.front().first;
            int x = q.front().second.first;
            int y = q.front().second.second;
            q.pop();
            for(auto &dir : mv) {
                int cx = x + dir.first;
                int cy = y + dir.second;
                if(cx>=0 && cx<n && cy>=0 && cy<n) {
                    if(grid[cx][cy] == 0 && !vis[cx][cy]) {
                        q.push({wt + 1, {cx, cy}});
                        vis[cx][cy] = true;

                        if(cx == n-1 && cy == n-1) 
                            return wt+1;    // because bfs finds the shorter path first
                    }
                }
            }
        }
        return -1;
    }
    // alisha solution
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        queue<pair<pair<int,int>,int>>q;
        q.push({{0,0},1});
        
        if(grid[0][0]==1)return -1;
        
        if(grid[0][0]==0 && grid.size()==1 && grid[0].size()==1) return 1;
        
        vector<vector<bool>>visited(grid.size(),vector<bool>(grid.size(),false));
        visited[0][0]=true;
        while(!q.empty()) {
            pair<int,int>p = q.front().first; //{0,0}
            int x = p.first; //0
            int y= p.second; //0
            int lengthOfPath = q.front().second; //1
            q.pop();
            
            vector<pair<int,int>>neighbours = {{0,1}, {0,-1}, {1,0}, {-1,0},
                                               {1,1}, {-1,-1}, {1,-1}, {-1,1}};
            
            for(pair<int,int>neighbour: neighbours) {
                int newx = neighbour.first + x;
                int newy = neighbour.second+ y;
                
                if(newx>=0 && newy>=0 && newx<grid.size() && newy<grid[0].size() && grid[newx][newy]==0 && !visited[newx][newy]) {
                    q.push({{newx,newy},lengthOfPath+1});
                    visited[newx][newy] = true;
                    
                    if(newx==grid.size()-1 && newy==grid[0].size()-1)
                        return lengthOfPath+1;
                }
            }
        }
        return -1;
    }
};
