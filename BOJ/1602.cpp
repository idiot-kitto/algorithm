#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define all(x) (x).begin(), (x).end()
#define pb push_back

typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef vector<char> vc;
typedef vector<string> vs;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<string, int> psi;
typedef pair<int, string> pis;
typedef pair<char, int> pci;
typedef pair<int, char> pic;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
const int mod = 1e9 + 7;
const long double PI = 3.141592653589793238462643383279502884197;
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b){return a*b/gcd(a,b);}
int dir[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};

ll d[510], v[510][510], t[510][510];
pll p[510];

int main(){fastio

    for(int i=0 ; i<510 ; i++)
        for(int j=0 ; j<510 ; j++) v[i][j] = t[i][j] = 1e17;

    int n, m, q; cin >> n >> m >> q;
    for(int i=1 ; i<=n ; i++) cin >> d[i], p[i].first = d[i], p[i].second = i;
    sort(p + 1, p + n + 1);
    while(m--){
        int a, b; ll c; cin >> a >> b >> c;
        v[a][b] = v[b][a] = c;
    }
    for(int e=1 ; e<=n ; e++){
        int k = p[e].second;
        for(int i=1 ; i<=n ; i++)
            for(int j=1 ; j<=n ; j++){
                v[i][j] = min(v[i][j], v[i][k] + v[k][j]);
                t[i][j] = min(t[i][j], v[i][j] + max(d[i], max(d[j], d[k])));
            }
    }

    while(q--){
        int a, b; cin >> a >> b;
        cout << (t[a][b] == 1e17 ? -1 : t[a][b]) << '\n';
    }
    return 0;
}

// '멍멍이가 원숭이를 괴롭히는 시간'을 저장한 배열을 따로 저장, 정렬하여 적은 시간부터 플로이드 계산
// 최단거리와는 별개의 따로 더해야하는 시간을 만들어 주는것이 아이디어
