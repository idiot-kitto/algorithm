#include <bits/stdc++.h>
using namespace std;
int t, n, arr[5];
int main()
{ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        for(int i=0 ; i<5 ; i++) arr[i] = 0;
        cin >> n;
        arr[0] += n/60;
        n %= 60;

        if(n<=5) arr[3]+=n;
        else if(n<=9) {arr[1]+=1; arr[4]+=10-n;}
        else if(n<=15) {arr[1]+=1; arr[3]+=n-10;}
        else if(n<=19) {arr[1]+=2; arr[4]+=10-(n-10);}
        else if(n<=25) {arr[1]+=2; arr[3]+=n-20;}
        else if(n<=29) {arr[1]+=3; arr[4]+=10-(n-20);}
        else if(n<=35) {arr[1]+=3; arr[3]+=n-30;}
        else if(n<=39) {arr[0]+=1; arr[2]+=2; arr[4]+=10-(n-30);}
        else if(n<=44) {arr[0]+=1; arr[2]+=2; arr[3]+=n-40;}
        else if(n<=49) {arr[0]+=1; arr[2]+=1; arr[4]+=10-(n-40);}
        else if(n<=54) {arr[0]+=1; arr[2]+=1; arr[3]+=n-50;}
        else if(n<=59) {arr[0]+=1; arr[4]+=10-(n-50);}

        for(int i=0 ; i<5 ; i++) cout << arr[i] << " ";
        cout << "\n";
    }
    return 0;
}

// 그래프로도 풀 수 있을듯.ㅎ
