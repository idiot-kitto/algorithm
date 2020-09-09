#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll solution(int n, vector<int> times) {
    ll ans = 0;
    sort(times.begin(),times.end());
    ll l=n*times.front()/times.size(),h=n*times.back();
    while(l<=h){
        ll sum = 0;
        ll m=(l+h)/2;
        for(int i=0 ; i<times.size() ; i++)
            sum += m/times[i];
        if(sum<n) l=m+1;
        else{h=m-1;ans=h+1;}
    }
    return ans;
}
