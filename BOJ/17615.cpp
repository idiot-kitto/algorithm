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

int n, R, B, ans = INT_MAX;
string s;

void solve(int start, int end, char b1, char b2, int type)
{
    int tmp = 0; bool check = false;
    if(type){
        for(int i=start ; i<=end ; i++){
            if(s[i] == b1) check = true;
            if(check) if(s[i] == b2) tmp++;
        } ans = min(ans, tmp);
    } else{
        for(int i=start ; i>=end ; i--){
            if(s[i] == b1) check = true;
            if(check) if(s[i] == b2) tmp++;
        } ans = min(ans, tmp);
    }
}

int main()
{ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >> n >> s;
    for(int i=0 ; i<s.size() ; i++){
        if(s[i]=='R') R++;
        else B++;
    }
    if(!R || !B) {cout << 0; return 0;}
    else{
        solve(0,n-1,'R','B',1);
        solve(0,n-1,'B','R',1);
        solve(n-1,0,'R','B',0);
        solve(n-1,0,'B','R',0);
    }
    cout << ans;
    return 0;
}
