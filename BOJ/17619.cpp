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

typedef struct bridge{
    int x1, x2, idx;
};

int n, q;
vector<int> p(100010);
vector<bridge> v;

int find(int u){
    if(u == p[u]) return u;
    return p[u] = find(p[u]);
}
void merge(int u, int v){
    u = find(u); v = find(v);
    if(u==v) return;
    p[u] = v;
}

int main()
{ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >> n >> q;
    for(int i=1 ; i<=n ; i++){
        int x1, x2, y; cin >> x1 >> x2 >> y;
        v.push_back({x1,x2,i});
        p[i] = i;
    }
    sort(v.begin(),v.end(),[](bridge &b1, bridge &b2){
            return b1.x1 < b2.x1;
         });

    for(int i=0 ; i<n-1 ; i++)
        for(int j=i+1 ; j<n ; j++){
            if(v[j].x1 <= v[i].x2)
                merge(v[i].idx, v[j].idx);
            else break;
        }

    for(int i=0 ; i<q ; i++){
        int a, b; cin >> a >> b;
        if(find(a) == find(b)) cout << 1 << "\n";
        else cout << 0 << "\n";
    }
    return 0;
}
