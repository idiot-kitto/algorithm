#include <iostream>
#include <queue>
using namespace std;
typedef pair<int,int> pii;

int n, m, k, x1, y1, x2, y2;
int dir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
char arr[1004][1004];
int visited[1004][1004];
queue<pii> q;
pii current;

void solve()
{
    visited[x1][y1] = 1;
    q.push(make_pair(x1,y1));
    while(!q.empty()){
        current = q.front();
        int cx = current.first;
        int cy = current.second;
        if(cx == x2 && cy == y2){
            cout << visited[cx][cy] - 1;
            return;
        }
        q.pop();
        for(int i=0 ; i<4 ; i++){
            int nx = cx;
            int ny = cy;
            for(int j=0 ; j<k ; j++){
                nx += dir[i][0];
                ny += dir[i][1];
                if(0<nx && nx<=n && 0<ny && ny<=m && arr[nx][ny] == '.'){
                    if(visited[nx][ny] && visited[nx][ny] < visited[cx][cy] + 1) break;
                    if(!visited[nx][ny]){
                        q.push(make_pair(nx,ny));
                        visited[nx][ny] = visited[cx][cy] + 1;
                    }
                }
                else break;
            }
        }
    }
    cout << -1;
    return;
}

int main()
{ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >> n >> m >> k;
    for(int i=1 ; i<=n ; i++)
        for(int j=1 ; j<=m ; j++)
            cin >> arr[i][j];
    cin >> x1 >> y1 >> x2 >> y2;
    solve();
    return 0;
}

/*
BFS로 문제를 풀고 TLE가 났다. 33번째 조건을 추가하고 AC를 받았는데,
도착지점을 이미 방문한 상태이고, 1초안에(동일한 시간에) 이동할 수 있는 거리가 아니라면 더이상의 최소시간은 없다. 는 것을 생각 못했다.
*/
