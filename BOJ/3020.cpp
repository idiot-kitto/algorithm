#include <bits/stdc++.h>
using namespace std;
int n,h,arr1[100001],arr2[100001];
int main()
{ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n>>h;
    for(int i=0;i<n/2;i++) cin>>arr1[i]>>arr2[i];
    sort(arr1,arr1+n/2);sort(arr2,arr2+n/2);
    
    int ans=INT_MAX,cnt=1;
    for(int i=1;i<=h;i++){
        int temp=n/2-(lower_bound(arr1,arr1+n/2,i)-arr1);
        temp+=n/2-(upper_bound(arr2,arr2+n/2,h-i)-arr2);
        
        if(ans==temp) cnt++;
        else if(temp<ans){ans=temp;cnt=1;}
    }
    cout<<ans<<" "<<cnt;
    return 0;
}
