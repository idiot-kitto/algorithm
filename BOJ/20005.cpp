#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
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

int m, n, p, hp, cnt = 1;
int dir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
char arr[1001][1001];
int arr2[1001][1001], tmp[1001][1001];
map<char,int> damage;
map<char,int> dist;
set<char> ans;
void bfs(int x,int y)
{
    queue<pii> q;
    pii cur;
    q.push({x,y});
    arr2[x][y] = 1;
    while(!q.empty()){
        cur = q.front();
        q.pop();
        for(int i=0 ; i<4 ; i++){
            int nx = cur.first + dir[i][0];
            int ny = cur.second + dir[i][1];
            if(nx>=1 && nx<=m && ny>=1 && ny<=n){
                if(arr[nx][ny] == 'B'){
                    dist[arr[x][y]] = arr2[cur.first][cur.second];
                    return;
                }
                if(arr[nx][ny] != 'X' && arr2[nx][ny] == 0){
                    q.push({nx,ny});
                    arr2[nx][ny] = arr2[cur.first][cur.second] + 1;
                }
            }
        }
    }
}

int main()
{ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >> m >> n >> p;
    for(int i=1 ; i<=m ; i++){
        string s; cin >> s;
        for(int j=1 ; j<=n ; j++) {
            arr[i][j] = s[j-1];
            if(arr[i][j] == 'X') {arr2[i][j] = -1; tmp[i][j] = -1;}
        }
    }
    for(int i=0 ; i<p ; i++){
        char c; int dps; cin >> c >> dps;
        damage[c] = dps;
    } cin >> hp;

    for(int i=1 ; i<=m ; i++)
        for(int j=1 ; j<=n ; j++){
            if(arr[i][j] != '.' && arr[i][j] != 'X' && arr[i][j] != 'B'){
                memcpy(arr2,tmp,sizeof(arr2));
                bfs(i,j);
            }
        }

    while(1){
        if(hp <= 0) break;
        for(auto iter = dist.begin() ; iter != dist.end() ; iter++)
            if(iter->second <= cnt){
                ans.insert(iter->first);
                hp -= damage[iter->first];
            } cnt++;
    }
    cout << ans.size();
    return 0;
}
