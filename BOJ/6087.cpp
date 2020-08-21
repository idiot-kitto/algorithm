#include <bits/stdc++.h>
using namespace std;

int w, h, m1x = INT_MAX, m1y = INT_MAX, m2x = INT_MAX, m2y = INT_MAX;
int dir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
char arr[103][103];
int visited[103][103];
queue<pair<int,int>> q;
pair<int,int> current;

void bfs() {
    visited[m1x][m1y] = 1;
    q.push(make_pair(m1x,m1y));
    while(!q.empty()){
        current = q.front();
        int cx = current.first;
        int cy = current.second;
        if(cx == m2x && cy == m2y){
            cout << visited[cx][cy] - 2;
            return;
        }
        q.pop();
        for(int i=0 ; i<4 ; i++){
            int nx = cx;
            int ny = cy;
            while(1){
                nx += dir[i][0];
                ny += dir[i][1];
                if(0<=nx && nx<h && 0<=ny && ny<w){
                    if(arr[nx][ny] != '*'){
                        if(!visited[nx][ny]){
                            visited[nx][ny] = visited[current.first][current.second] + 1;
                            q.push(make_pair(nx,ny));
                        }
                    } else break;
                } else break;
            }
        }
    }

}

int main()
{ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >> w >> h;
    for(int i=0 ; i<h ; i++)
        for(int j=0 ; j<w ; j++){
            cin >> arr[i][j];
            if(arr[i][j] == 'C'){
                m1x == INT_MAX? m1x = i : m2x = i;
                m1y == INT_MAX? m1y = j : m2y = j;
            }
        }
    bfs();
    return 0;
}

/*
같은 방향으로 방문하면 같은 숫자로, 방향이 꺾이면 1만큼 증가된 숫자로 visited 배열을 채웠다.
일반적인 BFS같지 않게 35, 36번째 줄처럼 break를 잘 걸어주지 않으면 벽을 통과하는 레이저가 생길 수 있는데 그래서 시간이 좀 걸렸던 문제.
*/
