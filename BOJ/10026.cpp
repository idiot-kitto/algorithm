#include <bits/stdc++.h>
using namespace std;
int n, blindZone, nonblindZone;
int dir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
char temp[103][103], arr[103][103];
bool visited[103][103], empty[103][103];
queue<pair<int,int>> q;
void nonblind_bfs(int x, int y){
    nonblindZone++;
    visited[x][y] = true;
    q.push(make_pair(x,y));
    pair<int,int> current;
    while(!q.empty()){
        current = q.front();
        q.pop();
        for(int i=0 ; i<4 ; i++){
            int nx = current.first + dir[i][0];
            int ny = current.second + dir[i][1];
            if(0<=nx && nx<n && 0<=ny && ny<n)
                if(arr[x][y] == arr[nx][ny] && !visited[nx][ny]){
                    visited[nx][ny] = true;
                    q.push(make_pair(nx,ny));
                }
        }
    }
}
void blind_bfs(int x, int y){
    blindZone++;
    visited[x][y] = true;
    q.push(make_pair(x,y));
    pair<int,int> current;
    while(!q.empty()){
        current = q.front();
        q.pop();
        for(int i=0 ; i<4 ; i++){
            int nx = current.first + dir[i][0];
            int ny = current.second + dir[i][1];
            if(0<=nx && nx<n && 0<=ny && ny<n){
                if(arr[x][y] != 'B' && arr[nx][ny] !='B' && !visited[nx][ny]){
                    visited[nx][ny] = true;
                    q.push(make_pair(nx,ny));
                }
                else if(arr[x][y] == 'B' && arr[nx][ny] == arr[x][y] && !visited[nx][ny]){
                    visited[nx][ny] = true;
                    q.push(make_pair(nx,ny));
                }
            }
        }
    }
}

int main()
{ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >> n;
    for(int i=0 ; i<n ; i++)
        for(int j=0 ; j<n ; j++)
            cin >> temp[i][j];
    memcpy(arr, temp, sizeof(temp));
    for(int i=0 ; i<n ; i++)
        for(int j=0 ; j<n ; j++)
            if(!visited[i][j]) nonblind_bfs(i,j);
    cout << nonblindZone << " ";
    memcpy(arr, temp, sizeof(temp));
    memcpy(visited, empty, sizeof(empty));
    for(int i=0 ; i<n ; i++)
        for(int j=0 ; j<n ; j++)
            if(!visited[i][j]) blind_bfs(i,j);
    cout << blindZone;
    return 0;
}
