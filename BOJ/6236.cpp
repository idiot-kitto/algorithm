#include <bits/stdc++.h>
using namespace std;
int n,m,sum,ans,arr[100001];
int solve(int val)
{
    int cnt=1;
    int k=val;
    for(int i=0 ; i<n ; i++){
        if(val<arr[i]) return 0;
        if(k<arr[i]){k=val;cnt++;}
        k-=arr[i];
    }
    return m>=cnt?1:0;
}
int main()
{ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for(int i=0 ; i<n ; i++){
        cin >> arr[i];
        sum+=arr[i];
    }
    int l=1,h=sum;
    while(l<=h){
        int m=(l+h)/2;
        if(solve(m)) {ans=m;h=m-1;}
        else l=m+1;
    }
    cout << ans;

    return 0;
}
