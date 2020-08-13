#include <bits/stdc++.h>
using namespace std;
int t, w, h, cnt;
int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
char arr[1002][1002];
queue<pair<int,int>> fire_q, man_q, empty_q;

void bfs(){
    bool check = false;
    cnt = 1;
    pair<int,int> current;
    while(!man_q.empty()){
        if(check) break;
        cnt++;
        int tmp = fire_q.size();
        for(int i=0 ; i<tmp ; i++){
            current = fire_q.front();
            fire_q.pop();
            int nx, ny;
            for(int j=0 ; j<4 ; j++){
                nx = current.first + dir[j][0];
                ny = current.second + dir[j][1];
                if(0<=nx && nx<h && 0<=ny && ny<w)
                    if(arr[nx][ny] == '.' || arr[nx][ny] == '@'){
                        arr[nx][ny] = '*';
                        fire_q.push(make_pair(nx,ny));
                    }
            }
        }
        tmp = man_q.size();
        for(int i=0 ; i<tmp ; i++){
            current = man_q.front();
            man_q.pop();
            int nx, ny;
            for(int j=0 ; j<4 ; j++){
                nx = current.first + dir[j][0];
                ny = current.second + dir[j][1];
                if(0<=nx && nx<h && 0<=ny && ny<w && arr[nx][ny]=='.'){
                    arr[nx][ny] = '@';
                    man_q.push(make_pair(nx, ny));
                    if(nx == 0 || nx == h-1 || ny == 0 || ny == w-1)
                        check = true;
                }
            }
        }
    }
    if(check) cout << cnt << "\n";
    else cout << "IMPOSSIBLE\n";
}

void init(){
    for(int i=0 ; i<h ; i++)
        for(int j=0 ; j<w ; j++)
            arr[i][j] = '\0';
    fire_q = empty_q;
    man_q = empty_q;
}

int main()
{ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> w >> h;
        init();
        for(int i=0 ; i<h ; i++)
            for(int j=0 ; j<w  ; j++){
                cin >> arr[i][j];
                if(arr[i][j] == '@') man_q.push(make_pair(i,j));
                else if(arr[i][j] == '*') fire_q.push(make_pair(i,j));
            }
        if(man_q.front().first == 0 || man_q.front().first == h-1 || man_q.front().second == 0 || man_q.front().second == w-1) cout << "1\n";
        else bfs();
    }
    return 0;
}

/*
1초마다 불이 인접한 공간으로 번지고, 사람이 이동한다.
그 과정 중 한 공간에서 겹치는 경우가 있는데, 만약 사람이 먼저 이동하고 불이 번진다면 man_q에 그 위치가 쌓이고 다음 순서로 진행되기 때문에 오류가 발생한다.
따라서 불이 먼저 번지고, 사람이 다음 공간으로의 이동가능 여부를 확인하고 이동하도록 구현했다.
*/
