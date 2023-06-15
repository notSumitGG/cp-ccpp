#include<iostream>
#include<vector>
#include<string>
#include<queue>
using namespace std;
// https://www.spoj.com/problems/NAKANJ/

pair<int, int> knight_moves[8] = {
    pair(2, 1), pair(1, 2), pair(-1, 2), pair(-2, 1),
    pair(-2, -1), pair(-1, -2), pair(1, -2), pair(2, -1)
};

int getX(string st) {
    return st[0] - 'a';
}
int getY(string st) {
    return st[1] - '1';
}
bool isvalid(int x, int y) {
    return x>=0 && x<8 && y>=0 && x<8;
}

int bfs(string src, string des) {
    int srcX = getX(src);
    int srcY = getY(src);
    int desX = getX(des);
    int desY = getY(des);

    vector<vector<int>> lvl(8, vector<int> (8, -1));
    queue<pair<int, int>> q;
    q.push({srcX, srcY});
    lvl[srcX][srcY] = 0;

    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i=0; i<8; i++) {
            int cx = x + knight_moves[i].first;
            int cy = y + knight_moves[i].second;
            if(isvalid(cx, cy) && lvl[cx][cy] == -1) {
                q.push({cx, cy});
                lvl[cx][cy] = lvl[x][y] + 1;
            }
        }
        if(lvl[desX][desY] != -1)
            break;
    }
    return lvl[desX][desY];
}

int main() {
    int q;
    cin >> q;
    while(q--) {
        string src, des;
        cin >> src >> des;
        cout << endl << bfs(src, des);
    }
    cout << endl;
    return 0;
}