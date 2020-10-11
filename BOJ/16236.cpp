#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define pb push_back
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<string, int> psi;
typedef pair<char, int> pci;
typedef pair<int, char> pic;
const int MOD = 1e9 + 7;
const long double PI = 3.141592653589793238462643383279502884197;

ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}

int n, sx, sy, shark = 2, cnt, ans, dist;
int arr[21][21];
int visited[21][21];
int dir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
vector<pair<int,pii>> v;
void bfs(int x,int y)
{
    dist = INT_MAX;
    v.clear();
    memset(visited,0,sizeof(visited));
    queue<pii> q; pii cur;
    q.push({x,y});
    while(!q.empty()){
        cur = q.front();
        q.pop();
        for(int i=0 ; i<4 ; i++){
            int nx = dir[i][0] + cur.first;
            int ny = dir[i][1] + cur.second;
            if(1<=nx && nx<=n && 1<=ny && ny<=n){
                if(visited[nx][ny] == 0 && shark >= arr[nx][ny]){
                    visited[nx][ny] = visited[cur.first][cur.second] + 1;
                    q.push({nx,ny});
                    if(arr[nx][ny] > 0 && arr[nx][ny] < shark){
                        if(dist >= visited[nx][ny]){
                            dist = visited[nx][ny];
                            v.pb({dist,{nx,ny}});
                        }
                    }
                }
            }
        }
    }
}

int main()
{ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >> n;
    for(int i=1 ; i<=n ; i++)
        for(int j=1 ; j<=n ; j++){
            cin >> arr[i][j];
            if(arr[i][j] == 9){sx = i; sy = j; arr[i][j] = 0;}
        }
    while(1){
        bfs(sx,sy);
        if(v.empty()) break;
        sort(all(v));
        cnt++;
        ans += v[0].first;
        arr[v[0].second.first][v[0].second.second] = 0;
        sx = v[0].second.first; sy = v[0].second.second;
        if(shark == cnt){shark++; cnt = 0;}
    }
    cout << ans;

    return 0;
}
