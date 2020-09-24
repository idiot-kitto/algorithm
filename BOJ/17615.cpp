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

int n, R, B, ans = INT_MAX, tmp;
bool check;
string s;

int main()
{ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >> n >> s;
    for(int i=0 ; i<s.size() ; i++){
        if(s[i]=='R') R++;
        else B++;
    }
    if(!R || !B) {cout << 0; return 0;}
    else{
        tmp = 0; check = false;
        for(int i=0 ; i<s.size() ; i++){
            if(s[i] == 'R') check = true;
            if(check) if(s[i] == 'B') tmp++;
        } ans = min(ans, tmp);
        
        tmp = 0; check = false;
        for(int i=0 ; i<s.size() ; i++){
            if(s[i] == 'B') check = true;
            if(check) if(s[i] == 'R') tmp++;
        } ans = min(ans, tmp);

        tmp = 0; check = false;
        for(int i=s.size()-1 ; i>=0 ; i--){
            if(s[i] == 'R') check = true;
            if(check) if(s[i] == 'B') tmp++;
        } ans = min(ans, tmp);

        tmp = 0; check = false;
        for(int i=s.size()-1 ; i>=0 ; i--){
            if(s[i] == 'B') check = true;
            if(check) if(s[i] == 'R') tmp++;
        } ans = min(ans, tmp);
    }
    cout << ans;
    return 0;
}
