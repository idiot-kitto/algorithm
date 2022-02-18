#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool ok (ll aa) {
    if(aa == 1) return false;
    for(ll i=2 ; i*i<=aa ; ++i) if(aa % i == 0) return false;
    return true;
}

int solution(int n, int k) {
    string s = "";
    while(n) {
        s += to_string(n % k);
        n /= k;
    } reverse(s.begin(), s.end());
    
    string tmp = "";
    vector<ll> v;
    for(int i=0 ; i<s.size() ; ++i) {
        if(s[i] == '0') {
            if(tmp.size()) v.push_back(stoll(tmp));
            tmp = "";
        } else tmp += s[i];
    } if(tmp.size()) v.push_back(stoll(tmp));
    
    int ans = 0;
    for(auto a : v) if(ok(a)) ans++;
    
    return ans;
}