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

ll v0, m, t, x, y;
vector<ll> v;
int main()
{ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >> v0 >> m >> t;
    y += v0; t -= 1;
    v.push_back(v0);
    while(1){
        v0 = v0 * m % 10;
        if(find(v.begin(),v.end(),v0) != v.end()){
            v.erase(v.begin(),find(v.begin(),v.end(),v0));
            break;
        }
        v.push_back(v0);
    }

    if(v.size() == 1){
        t %= 4;
        if(t >= 1) x += v[0];
        if(t >= 2) y -= v[0];
        if(t >= 3) x -= v[0];
    }else if(v.size() == 2){
        if(y == v[0]){
            t %= 4;
            if(t >= 1) x += v[1];
            if(t >= 2) y -= v[0];
            if(t >= 3) x -= v[1];
        }else{
            t %= 4;
            if(t >= 1) x += v[0];
            if(t >= 2) y -= v[1];
            if(t >= 3) x -= v[0];
        }
    }else if(v.size() == 4){
        if(y == v[0]){
            x += (v[1] * (t/4));
            y -= (v[2] * (t/4));
            x -= (v[3] * (t/4));
            y += (v[0] * (t/4));
            t %= 4;
            if(t >= 1) x += v[1];
            if(t >= 2) y -= v[2];
            if(t >= 3) x -= v[3];
        }else{
            x += (v[0] * (t/4));
            y -= (v[1] * (t/4));
            x -= (v[2] * (t/4));
            y += (v[3] * (t/4));
            t %= 4;
            if(t >= 1) x += v[0];
            if(t >= 2) y -= v[1];
            if(t >= 3) x -= v[2];
        }
    }

    cout << x << " " << y;
    return 0;
}
