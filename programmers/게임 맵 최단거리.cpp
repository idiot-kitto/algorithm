#include <bits/stdc++.h>
using namespace std;

int dir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
int arr[101][101], check[101][101];

int solution(vector<vector<int> > maps)
{
    int answer = 0;
    int n = (int)maps.size(), m = (int)maps[0].size();
    
    auto solve = [&](int x, int y) {
        queue<pair<int,int>> q;
        q.push({x, y});
        int cnt = 0;
        while(!q.empty()) {
            if(cnt > n * m) break;
            int cx = q.front().first, cy = q.front().second; q.pop();
            for(int i=0 ; i<4 ; ++i) {
                int nx = cx + dir[i][0], ny = cy + dir[i][1];
                if(nx >= 0 && nx < n && ny >= 0 && ny < m) {
                    if(maps[nx][ny] && !arr[nx][ny] && !check[nx][ny]) {
                        if(nx == n - 1 && ny == m - 1) return arr[cx][cy] + 1;
                        arr[nx][ny] = arr[cx][cy] + 1;
                        q.push({nx, ny});
                        cnt++;
                    }
                }
            }
        } return -1;
    };
    check[0][0] = 1;
    arr[0][0] = 1;
    answer = solve(0 ,0);
    
    return answer;
}
